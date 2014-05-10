#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "listeArc.h"
//partie qui dépend du du fait que ELEM est un Arc

void afficheSommetP(Sommet* elem)
{
	ListeArc q=elem->ListeVoisin;
	printf("num:%d nom:%s x:%lf y:%lf \n",elem->num, elem->nom, elem->x,elem->y);
	printf("Liste des arcs voisins: \n{\n"); visualiser_listeArc(elem->ListeVoisin); printf("}\n");

}
//partie qui dépend du type du champ val - fin

ListeSommetP creer_listeSommetP(void)
{
	return NULL;
}

int est_videSommetP(ListeSommetP L)
{
	return !L; //!pointeurDiffDeNULL = 0 et !NULL=1
}

void visualiser_listeSommetP(ListeSommetP L)
{
	ListeSommetP Li=NULL;
	for(Li=L;Li!=NULL;Li=Li->suiv)
		afficheSommetP(Li->val);
}

ListeSommetP ajout_teteSommetP(Sommet* elem, ListeSommetP L)
{
	MaillonSommetP* pc=NULL;
	pc = calloc(1, sizeof(*pc));
	if(pc==NULL) return NULL;

	pc->val=elem;


	pc->suiv=L;
	return pc;
}

ListeSommetP supprimer_teteSommetP(ListeSommetP L)
{
	if(!est_videSommetP(L))
	{
		ListeSommetP tmpL = L;
		L=L->suiv;
		free(tmpL); // to free or not to free?
		return L;
	}
	else
		return NULL;
}

ListeSommetP ajout_queueSommetP(Sommet* elem, ListeSommetP L)
{
	MaillonSommetP* pc=NULL;
	pc = calloc(1, sizeof(*pc));
	if(pc==NULL) return NULL;

	pc->val=elem;
	pc->suiv=NULL;

	MaillonSommetP* ic=NULL;
	if(!est_videSommetP(L))
	{
		for(ic=L;ic->suiv!=NULL;ic=ic->suiv){}
		ic->suiv=pc;
		return L;
	}
	else
		return pc;
}

Sommet* supprimer_queueSommetP(ListeSommetP L)
{
	ListeSommetP ic=NULL;
	if(!est_videSommetP(L))
	{int i=0;
		for(ic=L;ic->suiv->suiv!=NULL;ic=ic->suiv){i++;}
		Sommet* elem=ic->suiv->val;
		free(ic->suiv);
		ic->suiv=NULL;
		return elem;
	}
}


ListeSommetP supprimenSommetP(int n, ListeSommetP L)
{
	int i=0;
	MaillonSommetP* ipc=L;
	if(n==1)
		L=supprimer_teteSommetP(L);
	else
	{
		for(i=1;i<n-1;i++)
		{
			ipc=ipc->suiv;
		}
		MaillonSommetP* pcn=ipc->suiv;
		ipc->suiv=ipc->suiv->suiv;
		free(pcn);

	}
	return L;
}



ListeSommetP copieSommetP(ListeSommetP l)
{
	MaillonSommetP* im=NULL;
	MaillonSommetP* ip=NULL;
	ListeSommetP retour=NULL;
	if(!est_videSommetP(l))
	{
		retour=calloc(1,sizeof(*retour));
		retour = calloc(1,sizeof(*retour));
		retour->val=l->val;
		ip=retour;

		for(im=l->suiv;im!=NULL;im=im->suiv)
		{
			ip->suiv=calloc(1,sizeof(*ip));
			ip=ip->suiv;
			ip->val=im->val;			
		}
		return retour;
	}
	return retour;
}

ListeSommetP concatSommetP(ListeSommetP l1, ListeSommetP l2)
{
	MaillonSommetP* ic=NULL;
	ic=copieSommetP(l1);
	MaillonSommetP* retour=ic;
	for(ic;ic->suiv!=NULL;ic=ic->suiv){}
	ic->suiv=copieSommetP(l2);

	return retour;
}
void free_listeSommetP(ListeSommetP L)
{
	while(!est_videSommetP(L))
		L = supprimer_teteSommetP(L);
}
