#ifndef LISTE_SOMMET_H
#define LISTE_SOMMET_H

#include "structure.h"




void afficheSommet(Sommet* elem);
ListeSommet creer_listeSommet(void);
int est_videSommet(ListeSommet L);
void visualiser_listeSommet(ListeSommet L);
ListeSommet ajout_teteSommet(Sommet elem, ListeSommet L);
ListeSommet supprimer_teteSommet(ListeSommet L) ;
ListeSommet ajout_queueSommet(Sommet elem, ListeSommet L );
Sommet supprimer_queueSommet(ListeSommet L);
ListeSommet supprimenSommet(int n, ListeSommet l);
ListeSommet concatSommet(ListeSommet l1, ListeSommet l2);
ListeSommet copieSommet(ListeSommet l);





#endif

