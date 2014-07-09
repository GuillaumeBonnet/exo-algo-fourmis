
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "structure.h"
#include "fonctionsPrincipales.h"
#include "readGraph.h"
#include "listeArc.h"
#include "listeSommet.h"


///test:

//ajout_ville
/*
main()
{
	Sommet* p=calloc(4,sizeof(*p)); ListeSommet q=creer_listeSommet();
if( p==NULL) printf("alloc");

	(p[3]).num=4;
 (p[3]).nom="b";
 (p[3]).x=6;
 (p[3]).y=1;
 (p[3]).ListeVoisin=NULL;

	 p[2].num=3;
	 p[2].nom="a";
	 p[2].x=6;
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


	 q=ajout_ville(q,p,1);
	  printf("ok2\n");
	if(q==NULL)printf("allocation");
	 printf("%d \n %lf\n %lf \n  %s",(q->val).num,(q->val).x, (q->val).y, (q->val).nom );
	 if (est_videSommet((q->val).ListeVoisin)) printf("ok!");
}
*/


/*
ville parcourue

main()
{ListeSommet villes=creer_listeSommet(); ListeSommet tabu=creer_listeSommet(); int i=0; int j=0;
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

/*main()
{Sommet* p=calloc(4,sizeof(*p)); ListeSommet tabu=creer_listeSommet(); ListeSommet tabu2=creer_listeSommet(); ListeSommet tabu3=creer_listeSommet();
ListeSommet tabu4=creer_listeSommet(); ListeSommet tabu5=creer_listeSommet();
if(p==NULL)printf("allocation");
 (p[3]).num=4;
 (p[3]).nom="asdffg";
 (p[3]).x=6;
 (p[3]).y=1;
 (p[3]).ListeVoisin=NULL;

 (p[2]).num=3;
 (p[2]).nom="c";
 (p[2]).x=5;
 (p[2]).y=3;
 (p[2]).ListeVoisin=NULL;


 (p[1]).num=2;
 (p[1]).nom="b";
 (p[1]).x=5;
 (p[1]).y=3;
 (p[1]).ListeVoisin=NULL;

 (p[0]).num=1;
 (p[0]).nom="a";
 (p[0]).x=2;
 (p[0]).y=1;
 (p[0]).ListeVoisin=NULL;

 tabu=depart(p,4);
 tabu2=depart(p,4);
 tabu3=depart(p,4);
 tabu4=depart(p,4);
 tabu5=depart(p,4);


if(p==NULL||tabu==NULL)printf("allocation");
printf("tabu ville %d %s \n  tabu2  %d %s \n tabu3 %d %s \n tabu4 %d %s \n tabu5 %d %s \n ", (tabu->val).num,(tabu->val).nom, (tabu2->val).num,(tabu2->val).nom, (tabu3->val).num,(tabu3->val).nom, (tabu4->val).num,(tabu4->val).nom, (tabu5->val).num,(tabu5->val).nom);

}

*/


/*main()
{char* s1="abcd";char* s2="efg";
printf("s1= %s s2=%s \n",s1,s2);
strcpy(*s1,*s2);
printf("s1= %s s2=%s \n",s1,s2);

}
*/
//proba

main()
{char nom_fichier[100]="graphe11.txt";
int nbvilles=0; int i=0; int N;
Sommet* t=NULL;
remplirTable(nom_fichier,&t,&nbvilles,0.00001);

printf("%d",nbvilles);
ListeSommetP tabu=creer_listeSommetP();

tabu=ajout_teteSommetP(&t[1], tabu);
tabu=ajout_teteSommetP(&t[0], tabu);
tabu=ajout_teteSommetP(&t[3], tabu);

double* pro=repartition(*(tabu->val),tabu,t,nbvilles,1,2);
affichedouble(pro,nbvilles);

for(i=0;i<10;i++)
{N=ville_next(tabu,nbvilles,t[3],t,1,2,5);
printf("prochaine ville: %d \n",N);}
}



//parcours fourmi

/*main()
{char nom_fichier[100]="graphe11.txt";
int nbvilles=0;
Sommet* t=NULL;
remplirTable(nom_fichier,&t,&nbvilles);
Fourmi f;

f.solution=NULL;




ListeSommet tabu=creer_listeSommet();
tabu=ajout_ville(tabu,t,5);
tabu=ajout_ville(tabu,t,3);
tabu=ajout_ville(tabu,t,2);
tabu=ajout_ville(tabu,t,1);
tabu=ajout_ville(tabu,t,0);
tabu=ajout_ville(tabu,t,4);




f.solution=parcours_fourmi(f,tabu);

ListeArc q=f.solution;
while (!est_videArc(q))
    {printf("\t %d -> %d\n",(q->val).sdep,(q->val).sarr);
    q=q->suiv;
    }
}
*/


/*int main() //test de Lchemin(), comparaisons numériques
{
	char nomFichier[100]="graphe11.txt";
	Sommet* table = NULL; int nbVille = 0;

	remplirTable(nomFichier, &table, &nbVille);

	int i=0;
	for(i=0;i<nbVille;i++)
	{
		printf("i: %d, num: %d, x: %lf, y :%lf, nom: %s\n", i, table[i].num, table[i].x, table[i].y, table[i].nom);

		visualiser_listeArc( (table+i)->ListeVoisin );
		printf("L = %lf\n", Lchemin((table+i)->ListeVoisin) );
	}
	return 1;
}
*/




















