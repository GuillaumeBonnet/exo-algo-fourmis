#include <stdio.h>
#include <stdlib.h>
#include "listeArc.h"
#include "structure.h"
//testéé le 12/04/2014
int main()
{
	Arc arc1, arc2, arc3, arc4;
	arc1.sdep=1;
	arc1.sarr=1;
	arc1.d=1.5;

	arc2.sdep=2;
	arc2.sarr=2;
	arc2.d=2.5;

	arc3.sdep=3;
	arc3.sarr=3;
	arc3.d=3.5;

	arc4.sdep=4;
	arc4.sarr=4;
	arc4.d=4.5;

	Liste liste = NULL;
	liste = ajout_tete(arc2, liste);
	liste = ajout_tete(arc1, liste);
	liste = ajout_queue(arc3, liste);	
	visualiser_liste(liste);
	
	printf("\n");
	Arc test = supprimer_queue(liste);	
	liste = ajout_queue(arc4, liste);	
	visualiser_liste(liste);

	printf("\n");
	liste = supprimer_tete(liste);
	visualiser_liste(liste);

	printf("test\n");
	affiche(&test);
	
	return 1;	
}
