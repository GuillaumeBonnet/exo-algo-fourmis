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
void remplirTable(char nomFichier[], Sommet** table, int* nbVille,double EPS)
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
	Arc tmpArc;
	while(fscanf(fichier, "%d %d %lf\n", &sdep, &sarr, &d) != EOF)
	{
		tmpArc.sdep=sdep; tmpArc.sarr=sarr; tmpArc.d=d; tmpArc.to=EPS;
		((*table)+sdep)->ListeVoisin=ajout_teteArc(tmpArc, ((*table)+sdep)->ListeVoisin);

		tmpArc.sdep=sarr; tmpArc.sarr=sdep; tmpArc.d=d; tmpArc.to=EPS;
		((*table)+sarr)->ListeVoisin=ajout_teteArc(tmpArc, ((*table)+sarr)->ListeVoisin);
	}
	fclose(fichier);
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
		//rentrer la premi�re ville dans la file ListeSommet solution si on l'utilise
	}

	
	for(i=fin;i<nbFourmi;i++)
	{
		tab[i].iVilleDep = rand()%nbVille;
		tab[i].iVilleCour =tab[i].iVilleDep ;
		int j=0;
		for(j=fin;j<i;j++)
			if(tab[i].iVilleDep==tab[j].iVilleDep)
				i--;
	}
	return tab;
}





