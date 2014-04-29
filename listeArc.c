#include <stdio.h>
#include <stdlib.h>
#include "listeArc.h"
#include "structure.h"
//partie qui dépend du du fait que ELEM est un Arc

void afficheArc(Arc* elem)
{
	printf("sdep:%d sarr:%d d:%lf to: %lf\n",elem->sdep, elem->sarr, elem->d, elem->to);
}
//partie qui dépend du type du champ val - fin

void free_listeArc(ListeArc L)
{
	while(!est_videArc(L))
		L= supprimer_teteArc(L);
}

ListeArc creer_listeArc(void)
{
	return NULL;
}

int est_videArc(ListeArc L)
{
	return !L; //!pointeurDiffDeNULL = 0 et !NULL=1
}

void visualiser_listeArc(ListeArc L)
{
	ListeArc Li=NULL;
	for(Li=L;Li!=NULL;Li=Li->suiv)
		afficheArc(&Li->val);
}

ListeArc ajout_teteArc(Arc elem, ListeArc L)
{
	MaillonArc* pc=NULL;
	pc = calloc(1, sizeof(*pc));
	if(pc==NULL) return NULL;

	pc->val=elem;


	pc->suiv=L;
	return pc;
}

ListeArc supprimer_teteArc(ListeArc L)
{
	if(!est_videArc(L))
	{
		ListeArc tmpL = L;
		L=L->suiv;
		free(tmpL);
		return L;
	}
	else
		return NULL;
}

ListeArc ajout_queueArc(Arc elem, ListeArc L)
{
	MaillonArc* pc=NULL;
	pc = calloc(1, sizeof(*pc));
	if(pc==NULL) return NULL;

	pc->val=elem;
	pc->suiv=NULL;

	MaillonArc* ic=NULL;
	if(!est_videArc(L))
	{
		for(ic=L;ic->suiv!=NULL;ic=ic->suiv){}
		ic->suiv=pc;
		return L;
	}
	else
		return pc;
}

Arc supprimer_queueArc(ListeArc L)
{
	ListeArc ic=NULL;
	if(!est_videArc(L))
	{int i=0;
		for(ic=L;ic->suiv->suiv!=NULL;ic=ic->suiv){i++;}
		Arc elem=ic->suiv->val;
		free(ic->suiv);
		ic->suiv=NULL;
		return elem;
	}
}


ListeArc supprimenArc(int n, ListeArc L)
{
	int i=0;
	MaillonArc* ipc=L;
	if(n==1)
		L=supprimer_teteArc(L);
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

ListeArc concatArc(ListeArc l1, ListeArc l2)
{
	MaillonArc* ic=NULL;
	ic=copieArc(l1);
	MaillonArc* retour=ic;
	for(ic;ic->suiv!=NULL;ic=ic->suiv){}
	ic->suiv=copieArc(l2);

	return retour;
}

ListeArc copieArc(ListeArc l)
{
	MaillonArc* im=NULL;
	MaillonArc* ip=NULL;
	ListeArc retour=NULL;
	if(!est_videArc(l))
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



