/*toutes les fonctions marchent sauf proba (j'ai pas pu la tester encore*/





#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "structure.h"


ListeSommet creer_liste()
{return(NULL);

}
int est_vide(ListeSommet L)
{ return !L; /* la liste vide est representée par NULL */
}

ListeArcVoisin creer_ListeArcVoisin(void)
{return(NULL);}

int est_videListeArcVoisin(ListeArcVoisin L)
{ return !L; /* la liste vide est representée par NULL */
}

ListeSommet ajout_tete(Sommet e, ListeSommet L)
{ ListeSommet p=calloc(1,sizeof(*p));
 if (p==NULL) return NULL;
 p->val=e;
 p->suiv=L;
 return p;
}
ListeArcVoisin ajout_teteArc(Arc e, ListeArcVoisin L)
{ListeArcVoisin p=calloc(1,sizeof(*p));
 if (p==NULL) return NULL;
 p->val=e;
 p->suiv=L;
 return p;
}


double Lchemin(ListeSommet tabu, Arc** table)
{
	ListeSommet iL=NULL; double somme=0;
	for(iL=tabu;iL->suiv!=NULL;iL=iL->suiv)
	{
		somme+=table[iL->val.num][iL->suiv->val.num].d;
	}

}

void depotPheromone(ListeSommet tabu, Arc** table)
{
	double dTo = Q/Lchemin(tabu, table);
	ListeSommet iL=NULL;
	for(iL=tabu;iL->suiv!=NULL;iL=iL->suiv)
	{
		table[iL->val.num][iL->suiv->val.num].to=RHO * table[iL->val.num][iL->suiv->val.num].to + dTo ;
	}
}



 ListeSommet ajout_ville(ListeSommet tabu,Sommet* villes, int N )
    {Sommet q=villes[N-1]; ListeSommet p=creer_liste();

    p=ajout_tete(q,tabu);
    return(p);
}

int ville_parcourue(ListeSommet tabu, int N,int n)
	{int i=0; int j=0; ListeSommet p=creer_liste();

	if (est_vide(tabu))
		return(2);

	p=tabu;
	 while (!est_vide(p)) {
		 i=i+1;
		 if((p->val).num==N) j=1;
		 p=p->suiv;
	 }

	if (i==n) return (0);

	if (j==1) return (1);

	return (2);
}

 ListeSommet depart(Sommet* villes, int n)
    { int i=0;
    ListeSommet p=creer_liste();

    i =rand() %(n+1);
    p=ajout_ville(p,villes,i);
return (p);
}

void afficheListeSommet(ListeSommet tabu)
    {ListeSommet p=tabu;
     while (!est_vide(p))
{
 printf("\t tabu %d \n",(p->val).num);
     p=p->suiv;
 }
}


double* initialisation(int n)
{double* t; int i=0;

    t=calloc(n, sizeof(*t));        /*on crée le tableau et on l’initialise à -1*/
    if (t==NULL) return (NULL);
    for (i=0; i<n; i++)
t[i]=-1;
return(t);
}

void affichedouble(double* t,int n)
{int i=0;
for(i=0;i<n;i++)
    printf("\t %lf \n",t[i]);
}


double* probatabu(double* t,ListeSommet tabu)
{ListeSommet p=creer_liste();
p=tabu;
 while (!est_vide(p)) /*si la ville est dans tabu proba=0*/
 {t[((p->val).num)-1]=0;

  p=p->suiv;
 }

   return(t);
}



double* proba(Sommet s, ListeSommet tabu, Sommet* villes, int n)                    /*non testée*/
    {double* t;int i=0;
ListeArcVoisin q=creer_ListeArcVoisin();
double somme=0;

    t=initialisation(n);        /*on crée le tableau et on l’initialise à -1*/


    i=ville_parcourue( tabu,s.num,n) ;     /*si toutes les villes sont parcourues renvoit t initialisé
                                                    à -1*/
if(i==0) return (t);

i=0;

t=probatabu(t,tabu); /*si la ville est dans tabu proba =0*/


  /*si elle est dans les arcs voisins et*/
/*pas dans tabu on place la
pondération correspondante et on fait la somme terme a terme*/

q=s.ListeVoisin;

if(est_videListeArcVoisin(q))
{printf("Pas de voisins! Le voyage est fini :/ \n");
somme=1;
}

while (!est_videListeArcVoisin(q))
{

    if(t[ (q->val).sarr-1]<0)
        {t[ (q->val).sarr-1]= pow((q->val).to,ALPHA)/pow( (q->val).d ,BETA);
        somme=somme + t[(q->val).sarr-1];
        }

q=q->suiv;
 }
    i=0;
    for(i=0;i<n;i++)
{if(t[i]==2) /*pour les villes non voisines et non parcourrues
p=0 aussi*/
t[i]=0;
        t[i]=t[i]/somme;    /* enfin on divise tout par la somme des pondérations*/
    }
    return(t);
}




int ville_next (ListeSommet tabu,int n, Sommet s)                    /*non testée*/
    {double* t=proba(Sommet s, tabu, n);
int i=0; int N=0; double p=0;
    if (t==NULL) return (0);
    if (t[0]==-1) return (s.num);

    for (i=0; i<n; i++)
        {if (t[i]>p)
            {p=t[i]; N=i+1;
}
}
    return(N);
}
