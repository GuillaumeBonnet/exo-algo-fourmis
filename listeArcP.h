#ifndef LISTE_ARCP_H
#define LISTE_ARCP_H

#include "structure.h"




void afficheArcP(Arc* elem);
void free_fileArcP(ListeArcP L);
ListeArcP creer_listeArcP(void);
int est_videArcP(ListeArcP L );
void visualiser_listeArcP(ListeArcP L );
ListeArcP ajout_teteArcP(Arc* elem , ListeArcP L);
ListeArcP supprimer_teteArcP(ListeArcP L ) ;
ListeArcP ajout_queueArcP(Arc* elem , ListeArcP L );
Arc* supprimer_queueArcP(ListeArcP L);
ListeArcP supprimenArcP(int n, ListeArcP l);
ListeArcP concatArcP(ListeArcP l1, ListeArcP l2);
ListeArcP copieArcP(ListeArcP l);





#endif

