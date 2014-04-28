/*toutes les fonctions marchent*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "structure.h"
#include "listeSommet.h"
#include "listeArc.h"



ListeSommet ajout_ville(ListeSommet tabu,Sommet* villes, int N ) /*ok*/
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
int ville_parcourue(ListeSommet tabu, int N,int n)  //ok
{
	int i=0; int j=0; ListeSommet p=creer_listeSommet();

	if (est_videSommet(tabu))
		return(2);

	p=tabu;
	while (!est_videSommet(p))
	{
		 i=i+1;
		 if((p->val).num==N) j=1;
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

//g  : j'ai écrit cette fonction dans readGraph.c
ListeSommet init(ListeSommet* tabu, int nbVille)	//initailise *tabFourmi
{
	int boolVille[nbVille]; //tableau statique local
	int i=0, numVille=0;
	for(i=0;i<M;i++) //g : est-ce que la constante M est définie à l'intérieur de cette fonction
	{
		numVille =rand()%nbVille; 
	}
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


double* probatabu(double* t,ListeSommet tabu)
{
	ListeSommet p=creer_listeSommet();
	p=tabu;
	while (!est_videSommet(p)) /*si la ville est dans tabu proba=0*/
	{
		t[((p->val).num)]=0;
		p=p->suiv;
	}

	return(t);
}



double* proba(Sommet s, ListeSommet tabu, Sommet* villes, int n)                    /*non testée*/
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




int ville_next (ListeSommet tabu,int n, Sommet s, Sommet* villes)                    //ok
{
	double* t=proba(s, tabu,villes, n);
	int i=0; int N=0; double p=0;
	if (t==NULL) return (-1);
	if (t[0]==-1)
	{
		int j=0;
		ListeSommet q=tabu;
		while(!est_videSommet(q))
		{
			j=(q->val).num;
			q=q->suiv;
		}
		return (j);
	}
	for (i=0; i<n; i++)
	{
		if (t[i]>p)
		{
			p=t[i]; N=i;
		}
	}
    	return(N);
}





ListeArc parcours_fourmi(Fourmi f, ListeSommet tabu)
{
	ListeArc q=creer_listeArc();   int Narr=0;

	if (est_videSommet(tabu)) return(f.solution);
	if (est_videSommet (tabu->suiv))return(f.solution);

	Narr=(tabu->val).num;
	q=(((tabu->suiv)->val).ListeVoisin);

	while(!est_videArc(q))
	{
		if((q->val).sarr==Narr)
		{
			f.solution=ajout_teteArc(q->val,f.solution);
		}
		q=q->suiv;
	}

	f.solution=parcours_fourmi(f,tabu->suiv);
}

double Lchemin(ListeArc tabuArc)//testé numériquement 28/04
{
	ListeArc iL=NULL; double somme=0;
	for(iL=tabuArc;iL!=NULL;iL=iL->suiv)
	{
		somme+=iL->val.d;
	}
	return somme;

}

void depotPheromone(Fourmi* tabFourmi, int nbFourmi)
{
	int i=0;	
	double dTo = Q/Lchemin(tabFourmi[i].solution);
	ListeArc iL=NULL;
	for(i=0;i<nbFourmi;i++)
	{	
		for(iL=tabFourmi[i].solution;iL!=NULL;iL=iL->suiv)//idéalement : chaque liste solution ne contient que des pointeurs qui pointent vers les listes contenues dans tabVille. Donc les changements seffectuent dans tabVille.
		{
			iL->val.to = RHO * iL->val.to + dTo ;//pas bon je pense.
		}
	}
}//g : vérifier portée des constantes

