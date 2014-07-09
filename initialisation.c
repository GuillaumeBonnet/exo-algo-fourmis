#include <stdio.h>
#include <stdlib.h>
#include "initialisation.h"
#include "structure.h"
#include "string.h"
#include "listeArc.h"

int nbDeVilles(char nomFichier[]) //donner l'extension avec le nom
{
	FILE *fichier=NULL;
	if((fichier=fopen(nomFichier,"r"))==NULL)
		printf("Erreur ouverture fichier %s\n", nomFichier);

	int nbVille=0;
	fflush(stdin);
	fscanf(fichier,"%5d", &nbVille); //%5d 5 caractères [0-9] peuvent êtres saisis au maximum
	fclose(fichier);
	return nbVille;
}

int nbArcs(char nomFichier[])
{
	FILE *fichier=NULL;
	if((fichier=fopen(nomFichier,"r"))==NULL)
		printf("Erreur ouverture fichier %s\n", nomFichier);

	int nbArrete=0, nbArc=0;
	fflush(stdin);
	fscanf(fichier,"%10d %10d",&nbArc, &nbArrete);
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
	//scanf("%*[^\n]"); //vide le tampon/buffer stdin
	fscanf(fichier,"%5d", nbVille);
	fgets(tmpChaine, 100, fichier);
	fgets(tmpChaine, 100, fichier);
	//villes
	*table = calloc(*nbVille, sizeof(**table));
	if(*table==NULL) {printf("Erreur alloc table initialisation.c/remplirtable()"); return NULL); }
	int i=0; int num=0; double x=0,y=0; char nom[100] ="";
	for(i=0;i<*nbVille;i++)
	{
		//scanf("%*[^\n]%*c"); //vide le tampon/buffer stdin
		fscanf(fichier,"%5d %20lf %20lf %100s\n", &num, &x, &y, nom);
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
	//scanf("%*[^\n]%*c"); //vide le tampon/buffer stdin
	while(fscanf(fichier, "%5d %5d %20lf\n", &sdep, &sarr, &d) != EOF)
	{
		tmpArc.sdep=sdep; tmpArc.sarr=sarr; tmpArc.d=d; tmpArc.to=EPS;
		((*table)+sdep)->ListeVoisin=ajout_teteArc(tmpArc, ((*table)+sdep)->ListeVoisin);

		tmpArc.sdep=sarr; tmpArc.sarr=sdep; tmpArc.d=d; tmpArc.to=EPS;
		((*table)+sarr)->ListeVoisin=ajout_teteArc(tmpArc, ((*table)+sarr)->ListeVoisin);
		//scanf("%*[^\n]%*c"); //vide le tampon/buffer stdin
	}
	fclose(fichier);
	return;
}


Fourmi* initFourmi(int nbFourmi, int nbVille)
{
	Fourmi* tab = NULL;
	tab = calloc(nbFourmi, sizeof(*tab));
	if(tab==NULL) {printf("Erreur alloc tabFourmi initialisation.c/initFourmi()"); return NULL); }
	int i=0;
	int fin=nbFourmi- nbFourmi%nbVille;
	for(i=0;i<fin;i++)
	{
		tab[i].iVilleDep=i%nbVille;
		tab[i].iVilleCour=tab[i].iVilleDep;
		//rentrer la première ville dans la file ListeSommet solution si on l'utilise
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





