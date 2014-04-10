
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






 ListeSommet ajout_ville(ListeSommet tabu,ListeSommet villes, int N )                    /*non testée*/
    {ListeSommet q=villes; ListeSommet p=creer_liste();Sommet s;int j=0;

    for (j=1; j<N; j++ ) q=q->suiv;

    s.num=(q->val).num;
    s.nom=(q->val).nom;
    s.x=(q->val).x;
    s.y=(q->val).y;
    s.ListeVoisin=(q->val).ListeVoisin;

    p=ajout_tete(s,tabu);
    return(p);
}

int ville_parcourue(ListeSommet tabu,ListeSommet villes, int N,int n)                                    /*non testée*/
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

 ListeSommet depart(ListeSommet villes, int n)                                        /*non testée*/
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

    t=calloc(n, sizeof(*t));        /*on crée le tableau et on l’initialise à 2*/
    if (t==NULL) return (NULL);
    for (i=0; i<n; i++)
t[i]=2;
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



double* proba(Sommet s, ListeSommet tabu, ListeSommet villes, int n)                    /*non testée*/
    {double* t;int i=0;
ListeArcVoisin q=creer_ListeArcVoisin();
int a=1; int b=1; double somme=0;

    t=initialisation(n);        /*on crée le tableau et on l’initialise à 2*/


    i=ville_parcourue( tabu,villes,s.num,n) ;     /*si toutes les villes sont parcourues renvoit t initialisé
                                                    à 2*/
if(i==0) return (t);

i=0;

t=probatabu(t,tabu); /*si la ville est dans tabu proba =0*/


  /*si elle es dans les arcs voisins et*/
/*pas dans tabu on place la
pondération correspondante et on fait la somme terme a terme*/

q=s.ListeVoisin;

if(est_videListeArcVoisin(q))
{printf("Pas de voisins! Le voyage est fini :/ \n");
somme=1;
}

while (!est_videListeArcVoisin(q))
{

    if(t[ (q->val).sarr-1]==2)
        {t[ (q->val).sarr-1]= pow((q->val).to,a)/pow( (q->val).d ,b);
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
    if (t[0]==2) return (s.num);

    for (i=0; i<n; i++)
        {if (t[i]>p)
            {p=t[i]; N=i+1;
}
}
    return(N);
}








______________________________________________________________________________

test:

ajout_ville

main()
{ListeSommet p=creer_liste(); ListeSommet q=creer_liste();
  Sommet s3;
 s3.num=3;
 s3.nom='a';
 s3.x=5;
 s3.y=3;
 s3.ListeVoisin=NULL;
 p=ajout_tete(s3,p);
  Sommet s2;
 s2.num=2;
 s2.nom='a';
 s2.x=5;
 s2.y=3;
 s2.ListeVoisin=NULL;
 p=ajout_tete(s2,p);
 Sommet s1;
 s1.num=1;
 s1.nom='a';
 s1.x=2;
 s1.y=1;
 s1.ListeVoisin=NULL;
 p=ajout_tete(s1,p);

 q=ajout_ville(q,p,1);
  printf("ok2");
if(p==NULL||q==NULL)printf("allocation");
 printf("%d %d %d",(q->val).num,(q->val).x, (q->val).y);
}





ville parcourue

main()
{ListeSommet villes=creer_liste(); ListeSommet tabu=creer_liste(); int i=0; int j=0;
  Sommet s3;
 s3.num=3;
 s3.nom='a';
 s3.x=5;
 s3.y=3;
 s3.ListeVoisin=NULL;
 villes=ajout_tete(s3,villes);
  Sommet s2;
 s2.num=2;
 s2.nom='a';
 s2.x=5;
 s2.y=3;
 s2.ListeVoisin=NULL;
 villes=ajout_tete(s2,villes);
 Sommet s1;
 s1.num=1;
 s1.nom='a';
 s1.x=2;
 s1.y=1;
 s1.ListeVoisin=NULL;
 villes=ajout_tete(s1,villes);

 tabu=ajout_ville(tabu,villes,2);
 tabu=ajout_ville(tabu,villes,3);

if(villes==NULL||tabu==NULL)printf("allocation");
printf("tabu villes %d %d \n", (tabu->val).num,((tabu->suiv)->val).num);
i=ville_parcourue(tabu,villes,2,3);
j=ville_parcourue(tabu,villes,1,3);
printf("%d  %d",i,j);
}


depart

main()
{ListeSommet villes=creer_liste(); ListeSommet tabu=creer_liste(); ListeSommet tabu2=creer_liste(); ListeSommet tabu3=creer_liste();
ListeSommet tabu4=creer_liste(); ListeSommet tabu5=creer_liste();
  Sommet s4;
 s4.num=4;
 s4.nom='a';
 s4.x=6;
 s4.y=1;
 s4.ListeVoisin=NULL;
 villes=ajout_tete(s4,villes);
  Sommet s3;
 s3.num=3;
 s3.nom='a';
 s3.x=5;
 s3.y=3;
 s3.ListeVoisin=NULL;
 villes=ajout_tete(s3,villes);
  Sommet s2;
 s2.num=2;
 s2.nom='a';
 s2.x=5;
 s2.y=3;
 s2.ListeVoisin=NULL;
 villes=ajout_tete(s2,villes);
 Sommet s1;
 s1.num=1;
 s1.nom='a';
 s1.x=2;
 s1.y=1;
 s1.ListeVoisin=NULL;
 villes=ajout_tete(s1,villes);

 tabu=depart(villes, 4);
 tabu2=depart(villes, 4);
 tabu3=depart(villes, 4);
 tabu4=depart(villes, 4);
 tabu5=depart(villes, 4);

if(villes==NULL||tabu==NULL)printf("allocation");
printf("tabu villes %d tabu2 %d tabu3 %d tabu4 %d tabu5 %d\n", (tabu->val).num, (tabu2->val).num, (tabu3->val).num, (tabu4->val).num, (tabu5->val).num);

}

