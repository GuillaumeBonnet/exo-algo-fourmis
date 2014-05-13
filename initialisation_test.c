#include <stdio.h>
#include <stdlib.h>
#include "initialisation.h"
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
	// fonction creer_tableau_arc(); testée le 13/04
	char nomFichier[100]="graphe11.txt";

	Arc** table = creer_tableau_arc(nomFichier);
	int i=0, j=0;
	while(i>=0 && j>=0)
	{
		printf("i? :\n");
		scanf("%d",&i);
		printf("j? :\n");
		scanf("%d",&j);
		affiche(&table[i][j]);
	}

	return 1;
}
*/
/*
int main()
{
	//fonction remplirTable(); testée le 17/04/14 sur le fichier 11
	char nomFichier[100]="graphe11.txt";
	Sommet* table = NULL; int nbVille = 0;

	remplirTable(nomFichier, &table, &nbVille);

	int i=0;
	for(i=0;i<nbVille;i++)
	{
		printf("i: %d, num: %d, x: %lf, y :%lf, nom: %s\n", i, table[i].num, table[i].x, table[i].y, table[i].nom);

		visualiser_liste( (table+i)->ListeVoisin );
	}


	return 1;
}
*/

int main()
{
	//fonction initFourmi(int nbFourmi, int nbVille);
	Fourmi* tab = NULL;
	int nbFourmi=10, i=0, nbVille=3;
	while(nbFourmi>=0 && nbVille>=0)
	{
		fflush(stdin);	scanf("%d",&nbFourmi);
		fflush(stdin);  scanf("%d",&nbVille);
		tab = initFourmi(nbFourmi,nbVille);
		for(i=0;i<nbFourmi;i++)
			printf("i:%d, VilleDep:%d, VilleCour:%d\n", i, tab[i].iVilleDep, tab[i].iVilleCour);
	}

	return 1;
}








