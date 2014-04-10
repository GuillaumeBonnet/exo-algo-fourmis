#include <stdio.h>
#include <stdlib.h>
#include "readGraph.h"
//#include "structure.h"
/** fonction nbDeVille(); testée le 10/04 **/
int main()
{
	char nomFichier[100]="graphe12.txt";
	printf("Il y a %d villes dans le fichier %s\n", nbDeVilles(nomFichier), nomFichier); 
	
	return 1;
}

