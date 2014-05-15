#ifndef READGRAPH_H
#define READGRAPH_H
#include "structure.h"


int nbDeVilles(char nomFichier[]);
int nbArcs(char nomFichier[]);
void remplirTable(char nomFichier[], Sommet** table, int* nbVille,double EPS);
Fourmi* initFourmi(int nbFourmi, int nbVille);

#endif
