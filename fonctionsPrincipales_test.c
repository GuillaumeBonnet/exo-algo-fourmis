
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "structure.h"
#include "fonctionsPrincipales.h"


///test:

//ajout_ville

/*main()
{
	Sommet* p=calloc(3,sizeof(*p)); ListeSommet q=creer_liste();
if( p==NULL) printf("alloc");
	 p[2].num=3;
	 p[2].nom="a";
	 p[2].x=5;
	 p[2].y=3;
	 p[2].ListeVoisin=NULL;


	 p[1].num=2;
	 p[1].nom="a";
	 p[1].x=5;
	 p[1].y=3;
	 p[1].ListeVoisin=NULL;

	 p[0].num=1;
	 p[0].nom="a";
	 p[0].x=2;
	 p[0].y=1;
	 p[0].ListeVoisin=NULL;


	 q=ajout_ville(q,p,2);
	  printf("ok2\n");
	if(q==NULL)printf("allocation");
	 printf("%d \n %lf\n %lf \n  %s",(q->val).num,(q->val).x, (q->val).y, (q->val).nom );
	 if (est_vide((q->val).ListeVoisin)) printf("ok!");
}
*/


/*

ville parcourue

main()
{ListeSommet villes=creer_liste(); ListeSommet tabu=creer_liste(); int i=0; int j=0;
  Sommet s3;
 s3.num=3;
 s3.nom='a';
 s3.x=5;
 s3.y=3;
 s3.ListeVoisin=NULL;
 villes=ajout_tete(s3,villes);
  Sommet s2;
 s2.num=2;
 s2.nom='a';
 s2.x=5;
 s2.y=3;
 s2.ListeVoisin=NULL;
 villes=ajout_tete(s2,villes);
 Sommet s1;
 s1.num=1;
 s1.nom='a';
 s1.x=2;
 s1.y=1;
 s1.ListeVoisin=NULL;
 villes=ajout_tete(s1,villes);

 tabu=ajout_ville(tabu,villes,2);
 tabu=ajout_ville(tabu,villes,3);

if(villes==NULL||tabu==NULL)printf("allocation");
printf("tabu villes %d %d \n", (tabu->val).num,((tabu->suiv)->val).num);
i=ville_parcourue(tabu,villes,2,3);
j=ville_parcourue(tabu,villes,1,3);
printf("%d  %d",i,j);
}
*/

//depart
/*
main()
{ListeSommet villes=creer_liste(); ListeSommet tabu=creer_liste(); ListeSommet tabu2=creer_liste(); ListeSommet tabu3=creer_liste();
ListeSommet tabu4=creer_liste(); ListeSommet tabu5=creer_liste();
  Sommet s4;
 s4.num=4;
 s4.nom='a';
 s4.x=6;
 s4.y=1;
 s4.ListeVoisin=NULL;
 villes=ajout_tete(s4,villes);
  Sommet s3;
 s3.num=3;
 s3.nom='a';
 s3.x=5;
 s3.y=3;
 s3.ListeVoisin=NULL;
 villes=ajout_tete(s3,villes);
  Sommet s2;
 s2.num=2;
 s2.nom='a';
 s2.x=5;
 s2.y=3;
 s2.ListeVoisin=NULL;
 villes=ajout_tete(s2,villes);
 Sommet s1;
 s1.num=1;
 s1.nom='a';
 s1.x=2;
 s1.y=1;
 s1.ListeVoisin=NULL;
 villes=ajout_tete(s1,villes);

 tabu=depart(villes, 4);
 tabu2=depart(villes, 4);
 tabu3=depart(villes, 4);
 tabu4=depart(villes, 4);
 tabu5=depart(villes, 4);

if(villes==NULL||tabu==NULL)printf("allocation");
printf("tabu villes %d tabu2 %d tabu3 %d tabu4 %d tabu5 %d\n", (tabu->val).num, (tabu2->val).num, (tabu3->val).num, (tabu4->val).num, (tabu5->val).num);

}

*/
