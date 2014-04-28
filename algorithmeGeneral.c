#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "readGraph.h"
#include "fonctionsPrincipales.h"




/*=========constantes=======*/
#define M 10 //nombre total de fourmis de l'algorithme PS : faire en sort que m=2*n.
#define RHO 0.5 //coef d'évaporation des phéromones
#define ALPHA 1 //Coefficient régulant l'importance des phéromones pour le choix d'une ville
#define BETA 2 //Coefficient régulant l'importance de la visibilité pour le choix d'une ville
#define EPS 0.00001 //Valeur initiale non nulle de phéromones sur les arcs
#define Q 1 //Constante servant à calculer la quantité de phéromones à déposer pour chaque fourmi
#define MAX_CYCLE 10 //Constante, nombre maximum de cycles autorisés.
/*=========constantes - fin====*/

int main(int argc, char *argv[])
{



	char nomFichier[100]="graphe11.txt"; //à remplacer par argv[1] à la fin
	Sommet* tabVille = NULL; int nbVille = 0;
	remplirTable(nomFichier, &tabVille, &nbVille); //on remplit la table qui contient tous les Sommets et Arcs depuis le fichier
	ListeArc cheminMin=NULL; //Le chemin le plus court


	int iCycle=0;
	for(iCycle = MAX_CYCLE-1;iCycle<MAX_CYCLE;iCycle++)
	{
		Fourmi* tabFourmi=NULL;
		tabFourmi = initFourmi(M, nbVille);//initialiser M fourmi sur les nbVille

	   	int iFourmi=0;
		for(iFourmi=0;iFourmi<M; iFourmi++)   /*pour chaque fourmi*/
		{
		    ListeSommet tabu=NULL; //liste de ville parcourue par la fourmi courrante
            ListeSommet tabuArc=NULL; //idem mais avec les arc qui sont entre les villes
                                        //L:comme ca depend de l fourmi courante il faut les initialiser pour chaque fourmi
			//rajouter la ville de départ de la fourmi tabu
			tabu = ajout_ville(tabu,tabVille,tabFourmi[iFourmi].iVilleDep);

			//tant que le circuit n'est pas bouclé
			while(tabFourmi[iFourmi].iVilleDep !=	tabFourmi[iFourmi].iVilleCour)
			{
				int villeSuiv=-1;
				printf("%d \n", tabVille[ (tabFourmi[iFourmi]).iVilleCour ]);
				villeSuiv = ville_next(tabu, nbVille, tabVille[ (tabFourmi[iFourmi]).iVilleCour ],tabVille);
				if (villeSuiv==-1)printf("allocation");
				tabu = ajout_ville(tabu, tabVille, villeSuiv);
				tabFourmi[iFourmi].iVilleCour = villeSuiv;
			}
			visualiser_listeSommet(tabu); //test
/*			tabuArc = parcours_fourmi(tabFourmi[iFourmi], tabu);
			visualiser_listeArc(tabuArc); //test

			if(Lchemin(tabuArc)<Lchemin(cheminMin))
			{
				lib_fileArc(cheminMin);
				cheminMin=tabuArc;
				tabuArc=NULL;
			}
			if(Lchemin(tabuArc)-Lchemin(cheminMin)<0.00000001)
				printf("Il y a au moins deux solutions possibles");
*/
		}
	   //dépot des pheromones


	}
	//penser à tout free
}

