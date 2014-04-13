#ifndef READGRAPH_H
#define READGRAPH_H
#include "structure.h"


int nbDeVilles(char nomFichier[]); 
int nbArcs(char nomFichier[]);
ListeSommet creer_n_sommets(char nomFichier[]); //créer une liste de sommet dans l'ordre du fichier
Arc** creer_tableau_arc(char nomFichier[]);//table[i][j] est l'arc de la ville i vers j. si table[i][j].d==0 l'arc n'éxiste pas.
ListeArc* creer_table_arc(char nomFichier[]);

#endif
