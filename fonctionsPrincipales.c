/*toutes les fonctions marchent*/





#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "structure.h"


ListeSommet creer_liste()
{return(NULL);

}
int est_vide(ListeSommet L)
{ return !L; /* la liste vide est representée par NULL */
}

ListeArcVoisin creer_ListeArcVoisin(void)
{return(NULL);}

ListeArc creer_ListeArc(void)
{return(NULL);}

int est_videListeArc(ListeArc L)
{ return !L; /* la liste vide est representée par NULL */
}

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

ListeArc ajout_teteArc(Arc e, ListeArc L)
{ ListeArc p=calloc(1,sizeof(*p));
 if (p==NULL) return NULL;
 p->val=e;
 p->suiv=L;
 return p;
}

ListeArcVoisin ajout_teteArcVoisin(Arc e, ListeArcVoisin L)
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



 ListeSommet ajout_ville(ListeSommet tabu,Sommet* villes, int N ) /*ok*/
    {Sommet q; ListeSommet p=creer_liste();

     q.num=(villes[N]).num;
     q.x=(villes[N]).x;
     q.y=(villes[N]).y;
     q.ListeVoisin=(villes[N]).ListeVoisin;
     q.nom=(villes[N]).nom;

    p=ajout_tete(q,tabu);

    return(p);
}

int ville_parcourue(ListeSommet tabu, int N,int n)  //ok
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

 ListeSommet depart(Sommet* villes, int n)//ok
    { int i=0;
    ListeSommet p=creer_liste();

    i =rand() %(n);
    printf("%d\n",i);
    p=ajout_ville(p,villes,i);

return (p);
}


 ListeSommet init(ListeSommet* tabu, int nbVille)	//initailise *tabFourmi
 {
 	int boolVille[nbVille]; //tableau statique local
 	int i=0, numVille=0;
 	for(i=0;i<M;i++)
 	{
 		 numVille =rand()%nbVille;

 	}
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
 {t[((p->val).num)]=0;

  p=p->suiv;
 }

   return(t);
}



double* proba(Sommet s, ListeSommet tabu, Sommet* villes, int n)                    /*non testée*/
    {double* t;int i=0;
ListeArcVoisin q=creer_ListeArc();
double somme=0;

    t=initialisation(n);        /*on crée le tableau et on l’initialise à -1*/


    i=ville_parcourue( tabu,s.num,n) ;     /*si toutes les villes sont parcourues renvoit t initialisé
                                                    à -1*/
if(i==0)return (t);

i=0;

t=probatabu(t,tabu); /*si la ville est dans tabu proba =0*/


  /*si elle est dans les arcs voisins et*/
/*pas dans tabu on place la
pondération correspondante et on fait la somme terme a terme*/

q=s.ListeVoisin;

if(est_videListeArc(q))
{printf("Pas de voisins! Le voyage est fini :/ \n");
somme=1;
}

while (!est_videListeArc(q))
{

    if(t[ (q->val).sarr]<0)
        {t[ (q->val).sarr]= pow((q->val).to,ALPHA)/pow( (q->val).d ,BETA);
        somme=somme + t[(q->val).sarr];
        }

q=q->suiv;
 }
    i=0;
    for(i=0;i<n;i++)
{if(t[i]<0) /*pour les villes non voisines et non parcourrues
p=0 aussi*/
t[i]=0;
        t[i]=t[i]/somme;    /* enfin on divise tout par la somme des pondérations*/
    }
    return(t);
}




int ville_next (ListeSommet tabu,int n, Sommet s, Sommet* villes)                    //ok
    {double* t=proba(s, tabu,villes, n);
int i=0; int N=0; double p=0;
    if (t==NULL) return (-1);
    if (t[0]==-1)
    {int j=0;
     ListeSommet q=tabu;
         while(!est_vide(q))
         {j=(q->val).num;

            q=q->suiv;
         }



        return (j);
    }
    for (i=0; i<n; i++)
        {if (t[i]>p)
            {p=t[i]; N=i;
}
}
    return(N);
}





ListeArc parcours_fourmi(Fourmi f, ListeSommet tabu)
{ListeArc q=creer_ListeArc;   int Narr=0;

    if (est_vide(tabu)) return(f.solution);
    if (est_vide (tabu->suiv))return(f.solution);

    Narr=(tabu->val).num;
    q=(((tabu->suiv)->val).ListeVoisin);

    while(!est_vide(q))
    {
        if((q->val).sarr==Narr)
        { f.solution=ajout_teteArc(q->val,f.solution);

        }
       q=q->suiv;
    }

    f.solution=parcours_fourmi(f,tabu->suiv);


}
