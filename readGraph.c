#include <stdio.h>
#include <stdlib.h>
#include "readGraph.h"
#include "structure.h"
#include "string.h"
#include "listeArc.h"

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
Arc** creer_table_arc(char nomFichier[])
{
	FILE *fichier=NULL;
	if((fichier=fopen(nomFichier,"r"))==NULL)
	{
		printf("Erreur ouverture fichier %s\n", nomFichier);
		return NULL;
	}

	int nbVille=0, i=0; char tmpChaine[100];
	fscanf(fichier,"%d",&nbVille);
	fgets(tmpChaine, 100, fichier);
	fgets(tmpChaine, 100, fichier);
	for(i=0;i<=nbVille;i++)
		fgets(tmpChaine, 100, fichier);
	fgets(tmpChaine, 100, fichier);

	Arc** table=NULL;
	table = calloc(nbVille, sizeof(*table));
	for(i=0;i<nbVille;i++)
		*(table+i) = calloc(nbVille, sizeof(**table));
	
	
	int sdep=0, sarr=0; double d=0;
	
	while(fscanf(fichier, "%d %d %lf\n", &sdep, &sarr, &d) != EOF)
	{			
		table[sdep][sarr].sdep=sdep;
		table[sdep][sarr].sarr=sarr;
		table[sdep][sarr].d=d;
		table[sdep][sarr].to=EPS;
	 
		table[sarr][sdep].sdep=sdep;
		table[sarr][sdep].sarr=sarr;
		table[sarr][sdep].d=d;
		table[sarr][sdep].to=EPS;
	}// si table[i][j].d==0 il n'y a pas d'arc entre les villes i et j(sens i vers j)

	return table;
}













