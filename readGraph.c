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


Arc** creer_tableau_arc(char nomFichier[])
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
Arc* creerArc(int sdep, int sarr, double d)
{
	Arc* arc = NULL;
	arc = malloc(sizeof(*arc));
	arc->sdep=sdep;
	arc->sarr=sarr;
	arc->d=d;
	arc->to=EPS;

	return arc;
}

void remplirTable(char nomFichier[], Sommet** table, int* nbVille)
{
	FILE *fichier=NULL;
	if((fichier=fopen(nomFichier,"r"))==NULL)
		printf("Erreur ouverture fichier %s\n", nomFichier);

	char tmpChaine[100]; int nbArrete;
	fscanf(fichier,"%d", nbVille);
	fgets(tmpChaine, 100, fichier);
	fgets(tmpChaine, 100, fichier);
	//villes
	*table = calloc(*nbVille, sizeof(**table));
	int i=0; int num=0; double x=0,y=0; char nom[100] ="";
	for(i=0;i<*nbVille;i++)
	{
		fscanf(fichier,"%d %lf %lf %s\n", &num, &x, &y, nom);
		(*table)[i].num = num;
		(*table)[i].x = x;
		(*table)[i].y = y;
		(*table)[i].nom = calloc(100, sizeof(char));
		strcpy((*table)[i].nom, nom);
	}

	//Arcs
	int sdep=0, sarr=0; double d=0;
	fgets(tmpChaine, 100, fichier); Arc* arc= NULL;
	while(fscanf(fichier, "%d %d %lf\n", &sdep, &sarr, &d) != EOF)
	{
		arc = creerArc(sdep, sarr, d);
		((*table)+sdep)->ListeVoisin=ajout_teteArc(*arc, ((*table)+sdep)->ListeVoisin);

		arc = creerArc(sarr, sdep, d);
		((*table)+sarr)->ListeVoisin=ajout_teteArc(*arc, ((*table)+sarr)->ListeVoisin);
	}
	close(fichier);
	return;
}


Fourmi* initFourmi(int nbFourmi, int nbVille)
{
	Fourmi* tab = NULL;
	tab = calloc(nbFourmi, sizeof(*tab));
	int i=0;
	int fin=nbFourmi- nbFourmi%nbVille;
	for(i=0;i<fin;i++)
	{
		tab[i].iVilleDep=i%nbVille;
		tab[i].iVilleCour=tab[i].iVilleDep;
		//rentrer la première ville dans la file ListeSommet solution si on l'utilise
	}

	// initialisation de rand : srand(time(NULL));

	for(i=fin;i<nbFourmi;i++)
	{
		tab[i].iVilleDep = rand()%nbVille;
		tab[i].iVilleCour = -1;
		int j=0;
		for(j=fin;j<i;j++)
			if(tab[i].iVilleDep==tab[j].iVilleDep)
				i--;
	}
	return tab;
}



















