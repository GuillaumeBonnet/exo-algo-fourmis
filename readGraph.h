#ifndef READGRAPH_H
#define READGRAPH_H
#include "structure.h"


int nbDeVilles(char nomFichier[]); 
int nbArcs(char nomFichier[]);
Arc** creer_tableau_arc(char nomFichier[]);//table[i][j] est l'arc de la ville i vers j. si table[i][j].d==0 l'arc n'éxiste pas.
Arc* creerArc(int sdep, int sarr, double d);
void remplirTable(char nomFichier[], Sommet** table, int* nbVille);


#endif
