#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_draw.h"
#include "structure.h"
#include "readGraph.h"
#include "fonctionsPrincipales.h"
#include "listeSommetP.h"
#include "math.h"

#define W_FENETRE 1000
#define H_FENETRE 800

/*=========constantes=======*/
#define M 10 //nombre total de fourmis de l'algorithme PS : faire en sorte que m=2*n.
#define RHO 0.5 //coef d'évaporation des phéromones
#define ALPHA 1 //Coefficient régulant l'importance des phéromones pour le choix d'une ville
#define BETA 2 //Coefficient régulant l'importance de la visibilité pour le choix d'une ville
#define EPS 0.00001 //Valeur initiale non nulle de phéromones sur les arcs
#define Q 1 //Constante servant à calculer la quantité de phéromones à déposer pour chaque fourmi
#define MAX_CYCLE 10 //Constante, nombre maximum de cycles autorisés.
/*=========constantes - fin====*/


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


int main(int argc, char *argv[])
{
	Sommet* tabVille = NULL; int nbVille = 0; int iVille=0; int iFourmi=0;
	remplirTable(argv[1], &tabVille, &nbVille,EPS); //on remplit la table qui contient tous les Sommets et Arcs depuis le fichier
	ListeArcP cheminMin=NULL; //Liste de pointeurs sur les Arcs du chemin le plus court
	double Lmin=Lchemin(cheminMin); //longueur la plus petite rencontrée initialisée à une grande valeur
    double L=0;//Constante pour stocker le chemin de la fourmi courante (afin de ne pas le recalculer a chaque fois)



	int iCycle=0;
	for(iCycle = 0;iCycle<MAX_CYCLE;iCycle++)
	{
		Fourmi* tabFourmi=NULL;
		tabFourmi = initFourmi(M, nbVille);//initialiser M fourmi sur les nbVille

	   	int iFourmi=0;
		for(iFourmi=0;iFourmi<M; iFourmi++)   /*pour chaque fourmi*/
		{
			ListeSommetP tabu=NULL; //liste de pointeurs sur  des villes parcourues par la fourmi courrante

			//rajouter la ville de départ de la fourmi tabu
			tabu = ajout_teteSommetP(&tabVille[ (tabFourmi[iFourmi].iVilleDep) ], tabu);
			//tant que le circuit n'est pas bouclé

			do
			{
				int villeSuiv=-1;
				villeSuiv = ville_next(tabu, nbVille, tabVille[ (tabFourmi[iFourmi]).iVilleCour ],tabVille,ALPHA,BETA,tabFourmi[iFourmi].iVilleDep);
				if (villeSuiv==-1)printf("allocation");
				tabu = ajout_teteSommetP(&tabVille[villeSuiv], tabu);
				tabFourmi[iFourmi].iVilleCour = villeSuiv;

			}while(ville_parcourue(tabu,(tabFourmi[iFourmi]).iVilleCour,nbVille)!=0);

               tabu=ajout_teteSommetP(&(tabVille[(tabFourmi[iFourmi]).iVilleDep]), tabu);//On rajoute la ville de départ pour faire un parcours fermé

			tabFourmi[iFourmi].solution = parcours_fourmi(tabFourmi[iFourmi], tabu);

            free_listeSommetP(tabu);

			 L=Lchemin(tabFourmi[iFourmi].solution);
			if(L<Lmin)
			{
				free_listeArcP(cheminMin);
				cheminMin=copieArcP(tabFourmi[iFourmi].solution);
				Lmin=L;
			}

		}//boucle fourmis

		evapPheromone(tabVille, nbVille,RHO);
		depotPheromone(tabFourmi, M, Q);

        for(iFourmi=0;iFourmi<M;iFourmi++)
        {free_listeArcP(tabFourmi[iFourmi].solution);
        }
        free(tabFourmi);

	}//boucle cycles


	visualiser_listeArcP(cheminMin);
	printf("\n\n\n\tchemin le plus court: %lf \n \n \n", Lmin);	

//==================================affichage graphique
	
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

	

	int i=0, j=0, k=0;
	//affichage ville
	for(i=0;i<nbVille;i++)
	{		
		Draw_FillCircle(screen, 6+tabVille[i].x*(W_FENETRE-12), 6+tabVille[i].y*(H_FENETRE-12), 3, SDL_MapRGB(screen->format, 255, 85, 0));				
	}

	//affichage arrete graph
	for(j=0;j<nbVille;j++)
		for(k=j;k<nbVille;k++)
			Draw_Line(screen, 6+tabVille[j].x*(W_FENETRE-12) , 6+tabVille[j].y*(H_FENETRE-12) , 6+tabVille[k].x*(W_FENETRE-12) , 6+tabVille[k].y*(H_FENETRE-12) , SDL_MapRGB(screen->format, 253, 236, 122));

	//affichage arrete solution
	ListeArcP tmpAp=NULL;
	for(tmpAp=cheminMin;tmpAp!=NULL;tmpAp=tmpAp->suiv)		
		Draw_Line(screen, 6 + tabVille[tmpAp->val->sdep].x*(W_FENETRE-12) , 6+tabVille[tmpAp->val->sdep].y*(H_FENETRE-12) , 6+tabVille[tmpAp->val->sarr].x*(W_FENETRE-12) , 6+tabVille[tmpAp->val->sarr].y*(H_FENETRE-12) , SDL_MapRGB(screen->format, 255, 0, 0));
// printf("toto:%lf %lf\n",tabVille[tmpAp->val->sdep].x, tabVille[tmpAp->val->sdep].y);
	
	SDL_Flip( screen );// maj de l'affichage sur écran
	
	pause(); // attente fermeture de fenêtre
	
	SDL_Quit();	//libère mémoire

	//penser à tout free

	for(iVille=0;iVille<nbVille;iVille++)
	{free_listeArc(tabVille[iVille].ListeVoisin);
	 free(tabVille[iVille].nom);
	}
	free(tabVille);
	free_listeArcP(cheminMin);
	return;
}
