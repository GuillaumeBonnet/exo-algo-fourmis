#ifndef LISTE_ARC_H
#define LISTE_ARC_H

#include "structure.h"




void afficheArc(Arc* elem);
ListeArc creer_listeArc(void);
int est_videArc(ListeArc L );
void visualiser_listeArc(ListeArc L );
ListeArc ajout_teteArc(Arc elem , ListeArc L);
ListeArc supprimer_teteArc(ListeArc L ) ;
ListeArc ajout_queueArc(Arc elem , ListeArc L );
Arc supprimer_queueArc(ListeArc L);
ListeArc supprimenArc(int n, ListeArc l);
ListeArc concatArc(ListeArc l1, ListeArc l2);
ListeArc copieArc(ListeArc l);





#endif

