#include <stdio.h>
#include <stdlib.h>
#include "readGraph.h"
//#include "structure.h"

int nbDeVilles(char nomFichier[]) //donner l'extension avec le nom
{
	FILE *fichier=NULL;
	if((fichier=fopen(nomFichier,"r"))==NULL)
		printf("Erreur ouverture fichier %s\n", nomFichier);

	int nbVille=0;
	fscanf(fichier,"%d", &nbVille);
	fclose(fichier);
	return nbVille;
}
