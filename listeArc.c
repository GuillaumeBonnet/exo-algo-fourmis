#include <stdio.h>
#include <stdlib.h>
#include "listeArc.h"
#include "structure.h"
//partie qui dépend du du fait que ELEM est un Arc

void affiche(ELEMENT* elem)
{
	printf("sdep:%d sarr:%d d:%lf \n",elem->sdep, elem->sarr, elem->d);
}
//partie qui dépend du type du champ val - fin

Liste creer_liste(void)
{
	return NULL;
}

int est_vide(Liste L)
{
	return !L; //!pointeurDiffDeNULL = 0 et !NULL=1
}

void visualiser_liste(Liste L)
{
	Liste Li=NULL;
	for(Li=L;Li!=NULL;Li=Li->suiv)
		affiche(&Li->val);
}

Liste ajout_tete(ELEMENT elem, Liste L)
{
	Maillon* pc=NULL;
	pc = calloc(1, sizeof(*pc));
	if(pc==NULL) return NULL;
	
	pc->val=elem;


	pc->suiv=L;
	return pc;
}

Liste supprimer_tete(Liste L)
{
	if(!est_vide(L))
	{
		Liste tmpL = L;
		L=L->suiv;
		free(tmpL); // to free or not to free?
		return L;
	}
	else
		return NULL;
}

Liste ajout_queue(ELEMENT elem, Liste L)
{
	Maillon* pc=NULL;
	pc = calloc(1, sizeof(*pc));
	if(pc==NULL) return NULL;
	
	pc->val=elem;
	pc->suiv=NULL;

	Maillon* ic=NULL;
	if(!est_vide(L))
	{
		for(ic=L;ic->suiv!=NULL;ic=ic->suiv){}
		ic->suiv=pc;
		return L;
	}
	else
		return pc;	
}

ELEMENT supprimer_queue(Liste L)
{
	Liste ic=NULL;
	if(!est_vide(L))
	{int i=0;
		for(ic=L;ic->suiv->suiv!=NULL;ic=ic->suiv){i++;}
		ELEMENT elem=ic->suiv->val;
		free(ic->suiv);
		ic->suiv=NULL;
		return elem;
	}	
}


Liste supprimen(int n, Liste L)
{
	int i=0; 
	Maillon* ipc=L;
	if(n==1)
		L=supprimer_tete(L);
	else
	{
		for(i=1;i<n-1;i++)
		{
			ipc=ipc->suiv;
		}
		Maillon* pcn=ipc->suiv;
		ipc->suiv=ipc->suiv->suiv;
		free(pcn);
		
	}
	return L;
}

Liste concat(Liste l1, Liste l2)
{
	Maillon* ic=NULL;
	ic=copie(l1);
	Maillon* retour=ic;
	for(ic;ic->suiv!=NULL;ic=ic->suiv){}
	ic->suiv=copie(l2);
			
	return retour;
}

Liste copie(Liste l)
{
	Maillon* im=NULL;
	Maillon* ip=NULL;
	Liste retour=NULL;
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



