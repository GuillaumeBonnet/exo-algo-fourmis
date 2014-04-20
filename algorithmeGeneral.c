#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "readGraph.h"
#include "fonctionsPrincipales.h"

/*=========constantes=======*/
#define M 10 //nombre total de fourmis de l'algorithme PS : faire en sort que m=2*n.
#define RHO 0.5 //coef d'évaporation des phéromones
#define ALPHA 1 //Coefficient régulant l'importance des phéromones pour le choix d'une ville
#define BETA 2 //Coefficient régulant l'importance de la visibilité pour le choix d'une ville
#define EPS 0.00001 //Valeur initiale non nulle de phéromones sur les arcs
#define Q 1 //Constante servant à calculer la quantité de phéromones à déposer pour chaque fourmi
#define MAX_CYCLE 10 //Constante, nombre maximum de cycles autorisés.
/*=========constantes - fin====*/



int iCycle=0, kFourmi=0;

char nomFichier[100]="graphe11.txt"; //à remplacer par argv[1] à la fin
Sommet* table = NULL; int nbVille = 0;
remplirTable(nomFichier, &table, &nbVille); //on remplit la table de tous les Sommets et Arcs depuis le fichier



ListeSommet tabu=NULL;

for(iCycle = MAX_CYCLE-1;iCycle<MAX_CYCLE;iCycle++)
{
   //initialiser M fourmi sur les nbVille : Fourmi* initFourmi(int nbFourmi); dans readGraph

   
   for (kFourmi=M-1;kFourmis<M; kFourmi++)   /*pour chaque fourmie*/
   {
      //déposer une fourmie sur une ville au hasard (départ fourmie)
      tabu = depart(Sommet* villes, int n);
      //rajouter cette ville a tabu (depart fourmie) 
       
      /*tant que toutes les villes ne sont pas parcourue*/
      {
         //choix prochaine ville  (ville_next) L=L+darc
         
      }
   }
   
   // dépot des pheromones (tabu,L)
   //si (L<Lpluscourtcourrant) 
   //Lpluscourtcourrant=L; p=tabu;
   //free(&tabu);
    
}
//renvoit p

//penser à tout free


