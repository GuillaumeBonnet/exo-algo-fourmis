#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "structure.h"
#include "listeSommet.h"
#include "listeArc.h"


void affichedouble(double* t,int n);/*affiche un tableau de doubles*/     /*Validée!*/
double* initialisation(int n); /*renvoit un tableau de doubles initialisé a 2*/     /*Validée!*/
double* probatabu(double* t,ListeSommet tabu); /*renvoit un tableau avec les probas des villes dans tabu a 0*/     /*Validée!*/


void afficheListeSommet(ListeSommet tabu);         /*Validée!*/
/*elle affiche les numeros des villes dans une ListeSommet*/

int ville_next (ListeSommet tabu,int n, Sommet s, Sommet* villes);
  /*renvoit le numéro de la prochaine ville (si toutes les villes sont parcourues elle renvoit le numéro de la ville de départ)
  elle renvoit -1 si il y a un problème d'allocation */




double* proba(Sommet s, ListeSommet tabu, Sommet* villes, int n);
/*renvoit l’adresse d’un tableau contenant les probas si elles ne sont pas toutes parcourus (t[N-1]=p(N)),  NULL si l’allocation a échoué et un tableau avec que des -1 si toutes les villes sont parcourus*/

int ville_parcourue(ListeSommet tabu,int N,int n);
//n est le nombre total de ville (=nbVille dans le main)
 /* renvoie 1 si la fourmi est passée par une ville (de numéro N), 0 si elle est passée
par toutes les villes et 2 si elle n’est pas encore passée*/

double Lchemin(ListeArc tabuArc);
void depotPheromone(ListeSommet tabu, Arc** table);

ListeSommet ajout_ville(ListeSommet tabu,Sommet* villes, int N );
      /*elle rajoute une ville a tabu*/

ListeSommet depart(Sommet* villes, int n);   /*Validée!*/
    /*elle cree tabu avec une ville au hasard comme premier element*/

ListeArc parcours_fourmi(Fourmi f, ListeSommet tabu);
/*elle met le parcours de la fourmi dans l'ordre  (la tete de la liste est le premier arc parcouru)*/
