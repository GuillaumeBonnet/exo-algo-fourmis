#ifndef LISTE_SOMMETP_H
#define LISTE_SOMMETP_H

#include "structure.h"




void afficheSommetP(Sommet* elem);
ListeSommetP creer_listeSommetP(void);
int est_videSommetP(ListeSommetP L);
void visualiser_listeSommetP(ListeSommetP L);
ListeSommetP ajout_teteSommetP(Sommet* elem, ListeSommetP L);
ListeSommetP supprimer_teteSommetP(ListeSommetP L) ;
ListeSommetP ajout_queueSommetP(Sommet* elem, ListeSommetP L );
Sommet* supprimer_queueSommetP(ListeSommetP L);
ListeSommetP supprimenSommetP(int n, ListeSommetP l);
ListeSommetP concatSommetP(ListeSommetP l1, ListeSommetP l2);
ListeSommetP copieSommetP(ListeSommetP l);
void free_listeSommetP(ListeSommetP L);




#endif

