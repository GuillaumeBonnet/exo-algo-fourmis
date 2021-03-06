#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_draw.h"
#include "structure.h"
#include "listeSommet.h"

#define W_FENETRE 640
#define H_FENETRE 480

void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}


Sommet* creerTabSommet(int nbSommet, int wFenetre, int hFenetre)
{
	//initalisation SDL:
	SDL_Init( SDL_INIT_EVERYTHING ); 
	SDL_Surface* screen = NULL;
	screen = SDL_SetVideoMode( W_FENETRE, H_FENETRE, 32, SDL_SWSURFACE ); //init fenetre
	if (screen == NULL)
    	{
        	fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        	exit(EXIT_FAILURE);
    	}

	SDL_WM_SetCaption("InterfaceGraphique de l'exo Voyageur de Commerce", NULL); //titre fenetre
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 122,153,253)); //colorer fond
	SDL_Flip( screen );
	
	Sommet* tab = NULL;
	tab = calloc(nbSommet, sizeof(*tab));
	SDL_Event event; 
	int i=0;
	for(i=0;i<nbSommet;i++)
	{
		printf("Cliquer pour enregistrer la ville %d : \n",i);
		tab[i].num = i;
		char* nom;
		nom = calloc(100, sizeof(*nom));
		sprintf(nom,"%s%d","sommet",i);
		tab[i].nom=nom;
		int continuer=1;
		while(continuer)
		{
			SDL_WaitEvent(&event);
			switch(event.type)
			{
			case SDL_QUIT:			
				free(tab);
				continuer=0;
				return NULL;
				break;
			case SDL_MOUSEBUTTONUP:
				tab[i].x = (double)event.button.x/wFenetre;
				tab[i].y = (double)event.button.y/hFenetre;
				//affichage ville	
				Draw_FillCircle(screen, 6+tab[i].x*(wFenetre-12), 6+tab[i].y*(hFenetre-12), 3, SDL_MapRGB(screen->format, 255, 85,0));				
				SDL_Flip( screen );
				continuer=0;
		    	break;
			}
		}
	}
	printf("Fermer la fenêtre SDL.\n");

	return tab;
}

double distance(Sommet som1, Sommet som2)
{
	return sqrt( pow(som1.x-som2.x,2) + pow(som1.y-som2.y,2) );
}

int main()
{
	int nbVille =0; Sommet *table = NULL;
	printf("Entrer le nombre de ville du graphe\n");
	fflush(stdin);
	scanf("%5d",&nbVille);
	table = creerTabSommet(nbVille, W_FENETRE, H_FENETRE);
	pause(); // attente fermeture de fenêtre		
	SDL_Quit();	//libère mémoire


	printf("Taper le nom du ficher de sortie:\n");
	char nomFichier[100] = "";  
	fflush(stdin);
	scanf("%100s", nomFichier);
	FILE *fichier = NULL;
	if( (fichier = fopen(nomFichier, "w")) ==NULL) { printf("Erreur ouv fichier\n"); return; }
	int i=0;
	fprintf(fichier,"%d %d\n",nbVille, nbVille*(nbVille-1)/2);
	fprintf(fichier,"Sommets du graphe\n");
	for(i=0;i<nbVille;i++)
		fprintf(fichier,"%d %lf %lf %s\n",i, table[i].x, table[i].y, table[i].nom);

	fprintf(fichier,"Arêtes du graphe : noeud1 noeud2 valeur\n");

	for(i=0;i<nbVille;i++)
	{
		int j=0;
		for(j=nbVille-1;j>i;j--)
			fprintf(fichier,"%d %d %lf\n", i, j, distance(table[i],table[j]));
	}	
	fclose(fichier);
	return 1;
}
















