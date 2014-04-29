#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "structure.h"
#include "listeSommet.h"
#include "listeArc.h"
#include "listeSommetP.h"
#include "listeArcP.h"



ListeSommet ajout_ville(ListeSommet tabu,Sommet* villes, int N )
{
	Sommet q; ListeSommet p=creer_listeSommet();

	q.num=(villes[N]).num;
	q.x=(villes[N]).x;
	q.y=(villes[N]).y;
	q.ListeVoisin=(villes[N]).ListeVoisin;
	q.nom=(villes[N]).nom;

	p=ajout_teteSommet(q,tabu);

	return(p);
}

//n est le nombre total de ville (=nbVille dans le main)
 /* renvoie 1 si la fourmi est passée par la ville de numéro N, 0 si elle est passée
par toutes les villes et 2 si elle n’est pas encore passée*/
int ville_parcourue(ListeSommetP tabu, int N,int n)  //ok
{
	int i=0; int j=0; ListeSommetP p=NULL;

	if (est_videSommetP(tabu))
		return(2);

	p=tabu;
	while (!est_videSommetP(p))
	{
		 i=i+1;
		 if(p->val->num==N) j=1;
		 p=p->suiv;
	}

	if (i==n) return (0);

	if (j==1) return (1);

	return (2);
}
//memo : n = nbVille
 ListeSommet depart(Sommet* villes, int n)//ok
{
	int i=0;
	ListeSommet p=creer_listeSommet();

	i =rand() %(n);
	printf("%d\n",i);
	p=ajout_ville(p,villes,i);

	return (p);
}



void afficheListeSommet(ListeSommet tabu)
{
	ListeSommet p=tabu;
	while (!est_videSommet(p))
	{
		printf("\t tabu %d \n",(p->val).num);
		p=p->suiv;
	}
}


double* initialisation(int n)
{
	double* t; int i=0;

	t=calloc(n, sizeof(*t));        /*on crée le tableau et on l’initialise à -1*/
	if (t==NULL) return (NULL);
	for (i=0; i<n; i++)
		t[i]=-1;
	return(t);
}

void affichedouble(double* t,int n)
{
	int i=0;
	for(i=0;i<n;i++)
		printf("\t %lf \n",t[i]);
}


double* probatabu(double* t,ListeSommetP tabu)
{
	ListeSommetP p=NULL;
	p=tabu;
	while (!est_videSommetP(p)) /*si la ville est dans tabu proba=0*/
	{
		t[(p->val->num)]=0;
		p=p->suiv;
	}

	return(t);
}



double* proba(Sommet s, ListeSommetP tabu, Sommet* villes, int n, double ALPHA, double BETA)
{
	double* t;int i=0;
	ListeArc q=creer_listeArc();
	double somme=0;

	t=initialisation(n);        /*on crée le tableau et on l’initialise à -1*/


	i=ville_parcourue( tabu,s.num,n) ;
	if(i==0) return (t);				/*si toutes les villes sont parcourues renvoit t initialisé à -1*/

	i=0;

	t=probatabu(t,tabu); /*si la ville est dans tabu proba =0*/


	/*si elle est dans les arcs voisins et*/
	/*pas dans tabu on place la
	pondération correspondante et on fait la somme terme a terme*/

	q=s.ListeVoisin;

	if(est_videArc(q))
	{
		printf("Pas de voisins! Le voyage est fini :/ \n");
		somme=1;
	}

	while (!est_videArc(q))
	{

		if(t[ (q->val).sarr]<0)
		{
			t[ (q->val).sarr]= pow((q->val).to,ALPHA)/pow( (q->val).d ,BETA);
			somme=somme + t[(q->val).sarr];
		}

		q=q->suiv;
	}
	i=0;
	for(i=0;i<n;i++)
	{
		if(t[i]<0) /*pour les villes non voisines et non parcourrues
		p=0 aussi*/
		t[i]=0;
		t[i]=t[i]/somme;    /* enfin on divise tout par la somme des pondérations*/
	}
	return(t);
}




int ville_next (ListeSommetP tabu,int n, Sommet s, Sommet* villes, double ALPHA,double BETA)   //n est le nombre de villes total
{
	double* t=proba(s, tabu,villes, n,ALPHA,BETA);
	int i=0; int N=0; double p=0;
	if (t==NULL) return (-1);

	if (t[0]==-1)
	{
		int j=0;
		ListeSommetP q=tabu;
		while(!est_videSommetP(q))
		{
			j=q->val->num;
			q=q->suiv;
		}
		free(t);
		return (j);
	}
	for (i=0; i<n; i++)
	{
		if (t[i]>p)
		{
			p=t[i]; N=i;
		}
	}
	free(t);
    	return(N);
}





ListeArcP parcours_fourmi(Fourmi f, ListeSommetP tabu)
{
	ListeArc q=creer_listeArc();   int Narr=0;


	if (est_videSommetP(tabu)) return(f.solution);
	if (est_videSommetP (tabu->suiv))return(f.solution);

	Narr=tabu->val->num;
	q=((tabu->suiv)->val->ListeVoisin);

	while(!est_videArc(q))
	{
		if(q->val.sarr==Narr)
		{
			f.solution=ajout_teteArcP(&(q->val),f.solution);
		}
		q=q->suiv;
	}

	f.solution=parcours_fourmi(f,tabu->suiv);

return(f.solution);
}

double Lchemin(ListeArcP tabuArc)//testé numériquement 28/04
{
	if(est_videArcP(tabuArc)) return 1000000000000000000;	//utile au début quand cheminMin est vide
	ListeArcP iL=NULL; double somme=0;
	iL=tabuArc;
	while(!est_videArcP(iL))
	{
		somme= somme +(iL->val)->d;
       iL=iL->suiv;
	}
	return somme;
}
void evapPheromone(Sommet* tabVille, int nbVille,double RHO) //testée numériquement le 28/02
{
	int i=0; ListeArc iL=NULL;
	for(i=0;i<nbVille;i++)
	{iL=tabVille[i].ListeVoisin;
		while(!est_videArc(iL))
			{iL->val.to*=RHO;
			iL=iL->suiv;
			}
	}
}

void depotPheromone(Fourmi* tabFourmi, int nbFourmi, double Q)
{
	int i=0;
	ListeArcP iL=NULL;

	for(i=0;i<nbFourmi;i++)
	{
		double dTo = Q/Lchemin((tabFourmi[i]).solution);

		for(iL=tabFourmi[i].solution;iL!=NULL;iL=iL->suiv)
		{
			iL->val->to +=  dTo;
		}
	}
}

void depotPheromone_Fourmis_intelligentes(Fourmi* tabFourmi, int nbFourmi, int x, double Q)
{if (x>nbFourmi)
    {
        depotPheromone(tabFourmi, nbFourmi,Q);
    }
  else
	{int i=0;
	ListeArcP iL=NULL;

	for(i=0;i<x;i++)
	  {
		double dTo = Q/Lchemin((tabFourmi[i]).solution);

		for(iL=tabFourmi[i].solution;iL!=NULL;iL=iL->suiv)
		{
			iL->val->to +=  dTo;
		}
	  }
	}
}


triFourmi(Fourmi* tabFourmi, int nbFourmi , double* Ltab)
{ int i=0; Fourmi f; double L;
if(nbFourmi>1)
   {

    for(i=0;i<nbFourmi-1;i++)
    {if(Ltab[i]>Ltab[i+1] )
     {L=Ltab[i]; Ltab[i]=Ltab[i+1]; Ltab[i+1]=L;
          f.iVilleCour=tabFourmi[i].iVilleCour;
          f.iVilleDep=tabFourmi[i].iVilleDep;
          f.solution=tabFourmi[i].solution;

          tabFourmi[i].iVilleCour=tabFourmi[i+1].iVilleCour;
          tabFourmi[i].iVilleDep=tabFourmi[i+1].iVilleDep;
          tabFourmi[i].solution=tabFourmi[i+1].solution;

          tabFourmi[i+1].iVilleCour=f.iVilleCour;
          tabFourmi[i+1].iVilleDep=f.iVilleDep;
          tabFourmi[i+1].solution=f.solution;

     }
    }
    triFourmi(tabFourmi,nbFourmi-1,Ltab);
   }
}




