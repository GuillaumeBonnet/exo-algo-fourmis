#include <stdio.h>
#include <stdlib.h>
#include "readGraph.h"
#include "structure.h"
#include "string.h"

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

int nbArcs(char nomFichier[])
{
	FILE *fichier=NULL;
	if((fichier=fopen(nomFichier,"r"))==NULL)
		printf("Erreur ouverture fichier %s\n", nomFichier);
	
	int nbArrete=0, nbArc=0;
	fscanf(fichier,"%d %d",&nbArc, &nbArrete);
	fclose(fichier);
	nbArc = 2*nbArrete;
	return nbArc;	
}

ListeSommet creer_n_sommets(char nomFichier[])
{
	ListeSommet liste = NULL;
	liste = malloc(sizeof(*liste));

	FILE *fichier=NULL;
	if((fichier=fopen(nomFichier,"r"))==NULL)
		printf("Erreur ouverture fichier %s\n", nomFichier);

	int nbVille=0; char tmpChaine[100];
	fscanf(fichier,"%d",&nbVille);
	fgets(tmpChaine, 100, fichier);
	fgets(tmpChaine, 100, fichier);
	
	int i=0; 
	ListeSommet iListe=liste;
	for(i=0;i<nbVille-1;i++)
	{
		iListe->val.nom = calloc(100, sizeof(*(iListe->val.nom)));
		fscanf(fichier,"%d %lf %lf %s\n", &(iListe->val.num), &(iListe->val.x), &(iListe->val.y), iListe->val.nom);		
		iListe->suiv = malloc(sizeof(*iListe));
		iListe=iListe->suiv;
	}

		iListe->val.nom = calloc(100, sizeof(*(iListe->val.nom)));
		fscanf(fichier,"%d %lf %lf %s\n", &(iListe->val.num), &(iListe->val.x), &(iListe->val.y), iListe->val.nom);
		

	fclose(fichier);
	return liste;	
}


















