#ifndef LISTE_H
#define LISTE_H

#include "structure.h"

typedef Arc ELEMENT;

struct Cellule
{
	ELEMENT val;
	struct Cellule* suiv;
};
typedef struct Cellule Maillon;
typedef Maillon* Liste;


void affiche(ELEMENT* elem);
Liste creer_liste(void);
int est_vide(Liste );
void visualiser_liste(Liste );
Liste ajout_tete(ELEMENT , Liste );
Liste supprimer_tete(Liste ) ;
Liste ajout_queue(ELEMENT , Liste );
ELEMENT supprimer_queue(Liste L);
Liste supprimen(int n, Liste l);
Liste concat(Liste l1, Liste l2);
Liste copie(Liste l);





#endif

