#include <stdio.h>
#include <stdlib.h>
#include "listeArc.h"
#include "structure.h"
//partie qui dépend du du fait que ELEM est un Arc

void affiche(Arc* elem)
{
	printf("sdep:%d sarr:%d d:%lf \n",elem->sdep, elem->sarr, elem->d);
}
//partie qui dépend du type du champ val - fin

ListeArc creer_liste(void)
{
	return NULL;
}

int est_vide(ListeArc L)
{
	return !L; //!pointeurDiffDeNULL = 0 et !NULL=1
}

void visualiser_liste(ListeArc L)
{
	ListeArc Li=NULL;
	for(Li=L;Li!=NULL;Li=Li->suiv)
		affiche(&Li->val);
}

ListeArc ajout_tete(Arc elem, ListeArc L)
{
	MaillonArc* pc=NULL;
	pc = calloc(1, sizeof(*pc));
	if(pc==NULL) return NULL;
	
	pc->val=elem;


	pc->suiv=L;
	return pc;
}

ListeArc supprimer_tete(ListeArc L)
{
	if(!est_vide(L))
	{
		ListeArc tmpL = L;
		L=L->suiv;
		free(tmpL); // to free or not to free?
		return L;
	}
	else
		return NULL;
}

ListeArc ajout_queue(Arc elem, ListeArc L)
{
	MaillonArc* pc=NULL;
	pc = calloc(1, sizeof(*pc));
	if(pc==NULL) return NULL;
	
	pc->val=elem;
	pc->suiv=NULL;

	MaillonArc* ic=NULL;
	if(!est_vide(L))
	{
		for(ic=L;ic->suiv!=NULL;ic=ic->suiv){}
		ic->suiv=pc;
		return L;
	}
	else
		return pc;	
}

Arc supprimer_queue(ListeArc L)
{
	ListeArc ic=NULL;
	if(!est_vide(L))
	{int i=0;
		for(ic=L;ic->suiv->suiv!=NULL;ic=ic->suiv){i++;}
		Arc elem=ic->suiv->val;
		free(ic->suiv);
		ic->suiv=NULL;
		return elem;
	}	
}


ListeArc supprimen(int n, ListeArc L)
{
	int i=0; 
	MaillonArc* ipc=L;
	if(n==1)
		L=supprimer_tete(L);
	else
	{
		for(i=1;i<n-1;i++)
		{
			ipc=ipc->suiv;
		}
		MaillonArc* pcn=ipc->suiv;
		ipc->suiv=ipc->suiv->suiv;
		free(pcn);
		
	}
	return L;
}

ListeArc concat(ListeArc l1, ListeArc l2)
{
	MaillonArc* ic=NULL;
	ic=copie(l1);
	MaillonArc* retour=ic;
	for(ic;ic->suiv!=NULL;ic=ic->suiv){}
	ic->suiv=copie(l2);
			
	return retour;
}

ListeArc copie(ListeArc l)
{
	MaillonArc* im=NULL;
	MaillonArc* ip=NULL;
	ListeArc retour=NULL;
	if(!est_vide(l))
	{
		retour=calloc(1,sizeof(*retour));
		ip=retour;
		ip->val=l->val;

		for(im=l;im->suiv!=NULL;im=im->suiv)
		{	
			ip->suiv=calloc(1,sizeof(*ip));				
			ip->val=im->val;
			ip=ip->suiv;		
		}
			ip->suiv=calloc(1,sizeof(*ip));				
			ip->val=im->val;			
			ip->suiv=NULL;	
		return retour;
	}
}



