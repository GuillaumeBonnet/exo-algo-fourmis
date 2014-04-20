#ifndef LISTE_H
#define LISTE_H

#include "structure.h"




void affiche(Arc* elem);
ListeArc creer_liste(void);
int est_vide(ListeArc );
void visualiser_liste(ListeArc );
ListeArc ajout_tete(Arc , ListeArc );
ListeArc supprimer_tete(ListeArc ) ;
ListeArc ajout_queue(Arc , ListeArc );
Arc supprimer_queue(ListeArc L);
ListeArc supprimen(int n, ListeArc l);
ListeArc concat(ListeArc l1, ListeArc l2);
ListeArc copie(ListeArc l);





#endif

