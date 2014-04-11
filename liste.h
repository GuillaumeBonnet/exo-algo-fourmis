#ifndef LISTE_H
#define LISTE_H

struct Cellule
{
	ELEMENT val;
	struct Cellule* suiv;
};
typedef struct Cellule Maillon;
typedef Maillon* Liste;



Liste creer_liste(void);
int est_vide(Liste );
void visualiser_liste(Liste );
Liste ajout_tete(ELEMENT , Liste );
Liste supprimer_tete(Liste ) ;
Liste ajout_queue(ELEMENT , Liste );
Liste supprimen(int n, Liste l);
Liste concat(Liste l1, Liste l2);
Liste copie(Liste l);





#endif
