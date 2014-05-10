#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "listeArc.h"
//partie qui dépend du du fait que ELEM est un Arc

void afficheSommet(Sommet* elem)
{
	ListeArc q=elem->ListeVoisin;
	printf("num:%d nom:%s x:%lf y:%lf \n",elem->num, elem->nom, elem->x,elem->y);
	printf("Liste des arcs voisins: \n{\n"); visualiser_listeArc(elem->ListeVoisin); printf("}\n");
	
}

//partie qui dépend du type du champ val - fin

ListeSommet creer_listeSommet(void)
{
	return NULL;
}

int est_videSommet(ListeSommet L)
{
	return !L; //!pointeurDiffDeNULL = 0 et !NULL=1
}

void visualiser_listeSommet(ListeSommet L)
{
	ListeSommet Li=NULL;
	for(Li=L;Li!=NULL;Li=Li->suiv)
		afficheSommet(&Li->val);
}

ListeSommet ajout_teteSommet(Sommet elem, ListeSommet L)
{
	MaillonSommet* pc=NULL;
	pc = calloc(1, sizeof(*pc));
	if(pc==NULL) return NULL;

	pc->val=elem;


	pc->suiv=L;
	return pc;
}

ListeSommet supprimer_teteSommet(ListeSommet L)
{
	if(!est_videSommet(L))
	{
		ListeSommet tmpL = L;
		L=L->suiv;
		free(tmpL); // to free or not to free?
		return L;
	}
	else
		return NULL;
}

ListeSommet ajout_queueSommet(Sommet elem, ListeSommet L)
{
	MaillonSommet* pc=NULL;
	pc = calloc(1, sizeof(*pc));
	if(pc==NULL) return NULL;

	pc->val=elem;
	pc->suiv=NULL;

	MaillonSommet* ic=NULL;
	if(!est_videSommet(L))
	{
		for(ic=L;ic->suiv!=NULL;ic=ic->suiv){}
		ic->suiv=pc;
		return L;
	}
	else
		return pc;
}

Sommet supprimer_queueSommet(ListeSommet L)
{
	ListeSommet ic=NULL;
	if(!est_videSommet(L))
	{int i=0;
		for(ic=L;ic->suiv->suiv!=NULL;ic=ic->suiv){i++;}
		Sommet elem=ic->suiv->val;
		free(ic->suiv);
		ic->suiv=NULL;
		return elem;
	}
}


ListeSommet supprimenSommet(int n, ListeSommet L)
{
	int i=0;
	MaillonSommet* ipc=L;
	if(n==1)
		L=supprimer_teteSommet(L);
	else
	{
		for(i=1;i<n-1;i++)
		{
			ipc=ipc->suiv;
		}
		MaillonSommet* pcn=ipc->suiv;
		ipc->suiv=ipc->suiv->suiv;
		free(pcn);

	}
	return L;
}



ListeSommet copieSommet(ListeSommet l)
{
	MaillonSommet* im=NULL;
	MaillonSommet* ip=NULL;
	ListeSommet retour=NULL;
	if(!est_videSommet(l))
	{
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
ListeSommet concatSommet(ListeSommet l1, ListeSommet l2)
{
	MaillonSommet* ic=NULL;
	ic=copieSommet(l1);
	MaillonSommet* retour=ic;
	for(ic;ic->suiv!=NULL;ic=ic->suiv){}
	ic->suiv=copieSommet(l2);

	return retour;
}

void free_fileSommet(ListeSommet L)
{
	while(!est_videSommet(L))
		L= supprimer_teteSommet(L);		
}
