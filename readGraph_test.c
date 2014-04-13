#include <stdio.h>
#include <stdlib.h>
#include "readGraph.h"
#include "structure.h"


/*
int main()
{
	// fonction nbDeVille(); testée le 10/04

	char nomFichier[100]="graphe12.txt";
	printf("Il y a %d villes dans le fichier %s\n", nbDeVilles(nomFichier), nomFichier); 


	return 1;
}
*/

/*
int main()
{
	// fonction nbArcs(); testée le 12/04

	char nomFichier[100]="graphe12.txt";
	printf("Il y a %d arcs dans le fichier %s\n", nbArcs(nomFichier), nomFichier); 

	return 1;
}
*/

/*
int main()
{
	// fonction creer_n_sommets(); testée le 12/04 avec ddd sur un seul fichier texte
	char nomFichier[100]="graphe12.txt";
	ListeSommet liste=NULL;
	liste = creer_n_sommets(nomFichier);

	return 1;
}
*/

int main()
{
	// fonction creer_table_arc();
	char nomFichier[100]="graphe12.txt";
	
	ListeArc* table = creer_table_arc(nomFichier);

	return 1;
}

