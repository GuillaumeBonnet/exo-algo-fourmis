#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "structure.h"

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

void afficheGraph(Sommet* table, int tailleTable)
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
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 210,180,140)); //colorer fond
	
	//variables pour afficher disque
	SDL_Surface* disque;
	SDL_Rect posDisque;
	disque = SDL_LoadBMP("ville.bmp"); // image de D=20px
		if (disque == NULL)
		    	{
				fprintf(stderr, "Impossible de charger l'image disque : %s\n", SDL_GetError());
				exit(EXIT_FAILURE);
		    	}
	int i=0;
	for(i=0;i<tailleTable;i++)
	{
		//affichage ville		
		posDisque.x=table[i].x*W_FENETRE;
		posDisque.y=table[i].y*H_FENETRE;
		SDL_SetColorKey(disque, SDL_SRCCOLORKEY, SDL_MapRGB(disque->format, 255, 255, 255));//effacer le fond blanc de l'image
		SDL_BlitSurface(disque, NULL, screen, &posDisque); //coller le disque sur le fond

		//affichage arcs

	}
	
	SDL_Flip( screen );// maj de l'affichage sur écran
	
	pause(); // attente fermeture de fenêtre
	
	SDL_Quit();	//libère mémoire
	return;
} 
