#include <stdio.h>
#include <stdlib.h>
#include "listeArcP.h"
#include "structure.h"
//partie qui dépend du du fait que ELEM est un ArcP

void afficheArcP(Arc* elem)
{
	printf("sdep:%d sarr:%d d:%lf to: %lf\n",elem->sdep, elem->sarr, elem->d, elem->to);
}
//partie qui dépend du type du champ val - fin



ListeArcP creer_listeArcP(void)
{
	return NULL;
}

int est_videArcP(ListeArcP L)
{
	return !L; //!pointeurDiffDeNULL = 0 et !NULL=1
}

void visualiser_listeArcP(ListeArcP L)
{
	ListeArcP Li=NULL;
	for(Li=L;Li!=NULL;Li=Li->suiv)
		afficheArcP(Li->val);
}

ListeArcP ajout_teteArcP(Arc* elem, ListeArcP L)
{
	MaillonArcP* pc=NULL;
	pc = calloc(1, sizeof(*pc));
	if(pc==NULL) return NULL;

	pc->val=elem;


	pc->suiv=L;
	return pc;
}

ListeArcP supprimer_teteArcP(ListeArcP L)
{
	if(!est_videArcP(L))
	{
		ListeArcP tmpL = L;
		L=L->suiv;
		free(tmpL); // to free or not to free?
		return L;
	}
	else
		return NULL;
}

ListeArcP ajout_queueArcP(Arc* elem, ListeArcP L)
{
	MaillonArcP* pc=NULL;
	pc = calloc(1, sizeof(*pc));
	if(pc==NULL) return NULL;

	pc->val=elem;
	pc->suiv=NULL;

	MaillonArcP* ic=NULL;
	if(!est_videArcP(L))
	{
		for(ic=L;ic->suiv!=NULL;ic=ic->suiv){}
		ic->suiv=pc;
		return L;
	}
	else
		return pc;
}

Arc* supprimer_queueArcP(ListeArcP L)
{
	ListeArcP ic=NULL;
	if(!est_videArcP(L))
	{int i=0;
		for(ic=L;ic->suiv->suiv!=NULL;ic=ic->suiv){i++;}
		Arc* elem=ic->suiv->val;
		free(ic->suiv);
		ic->suiv=NULL;
		return elem;
	}
}


ListeArcP supprimenArcP(int n, ListeArcP L)
{
	int i=0;
	MaillonArcP* ipc=L;
	if(n==1)
		L=supprimer_teteArcP(L);
	else
	{
		for(i=1;i<n-1;i++)
		{
			ipc=ipc->suiv;
		}
		MaillonArcP* pcn=ipc->suiv;
		ipc->suiv=ipc->suiv->suiv;
		free(pcn);

	}
	return L;
}

ListeArcP concatArcP(ListeArcP l1, ListeArcP l2)
{
	MaillonArcP* ic=NULL;
	ic=copieArcP(l1);
	MaillonArcP* retour=ic;
	for(ic;ic->suiv!=NULL;ic=ic->suiv){}
	ic->suiv=copieArcP(l2);

	return retour;
}

ListeArcP copieArcP(ListeArcP l)
{
	MaillonArcP* im=NULL;
	MaillonArcP* ip=NULL;
	ListeArcP retour=NULL;
	if(!est_videArcP(l))
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
	return retour;
}


void free_listeArcP(ListeArcP L)
{
	while(!est_videArcP(L))
		L= supprimer_teteArcP(L);
}
