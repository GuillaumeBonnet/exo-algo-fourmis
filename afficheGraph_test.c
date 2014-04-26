#include <stdio.h>
#include <stdlib.h>
#include "readGraph.h"
#include "structure.h"
#include "afficheGraph.h"


int main(int argc, char *argv[])
{
	//fonction afficheGraph(); 
//	char nomFichier[100]= NULL;
//	nomFichier = argv[1];
	Sommet* table = NULL; int nbVille = 0;

	remplirTable(argv[1], &table, &nbVille);	
	afficheGraph(table, nbVille);
	


	return 1;
}








