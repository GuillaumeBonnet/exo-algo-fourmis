#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "readGraph.h"
#include "fonctionsPrincipales.h"
#include "listeSommetP.h"




/*=========constantes=======*/
#define M 10 //nombre total de fourmis de l'algorithme PS : faire en sorte que m=2*n.
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
	ListeArcP cheminMin=NULL; //Liste de pointeurs sur les Arcs du chemin le plus court


	int iCycle=0;
	for(iCycle = MAX_CYCLE-1;iCycle<MAX_CYCLE;iCycle++)
	{
		Fourmi* tabFourmi=NULL;
		tabFourmi = initFourmi(M, nbVille);//initialiser M fourmi sur les nbVille

	   	int iFourmi=0;
		for(iFourmi=0;iFourmi<1; iFourmi++)   /*pour chaque fourmi*/
		{
			ListeSommetP tabu=NULL; //liste de pointeurs sur  des villes parcourues par la fourmi courrante	
                                        //L:comme ca depend de la fourmi courante il faut les initialiser pour chaque fourmi
			//rajouter la ville de départ de la fourmi tabu
			tabu = ajout_teteSommetP(&tabVille[ (tabFourmi[iFourmi].iVilleDep) ], tabu);
			visualiser_listeSommetP(tabu);

			//tant que le circuit n'est pas bouclé
			do  
			{
				int villeSuiv=-1;
				//printf(" ville courante %d \n", tabVille[ (tabFourmi[iFourmi]).iVilleCour ]);//test
				villeSuiv = ville_next(tabu, nbVille, tabVille[ (tabFourmi[iFourmi]).iVilleCour ],tabVille);
				if (villeSuiv==-1)printf("allocation");
				tabu = ajout_teteSommetP(&tabVille[villeSuiv], tabu);
				tabFourmi[iFourmi].iVilleCour = villeSuiv;
				//printf(" ville suivante %d \n", villeSuiv);//test
			}while(ville_parcourue(tabu,(tabFourmi[iFourmi]).iVilleCour,nbVille)!=0);
			printf("visuSom : "); visualiser_listeSommetP(tabu);printf("finVsomme\n");//test
			//penser a faire free(tabu)
			tabFourmi[iFourmi].solution = parcours_fourmi(tabFourmi[iFourmi], tabu);
			printf("visuArc : ");	visualiser_listeArcP(tabFourmi[iFourmi].solution);printf("finVArc\n");//test
			tabFourmi[iFourmi].solution->suiv->val->to = 7.8;
			printf("visuArc : ");	visualiser_listeArcP(tabFourmi[iFourmi].solution);printf("finVArc\n");//test
			afficheSommet(&tabVille[2]);

			if(Lchemin(tabFourmi[iFourmi].solution)-Lchemin(cheminMin)<0.00000001)
				printf("Il y a au moins deux solutions possibles");
			//L:pourquoi? -> G : J'me disais qu'il ya  des graphs avec plusieurs solutions possibles
		

			
			if(Lchemin(tabFourmi[iFourmi].solution)<Lchemin(cheminMin))
			{
				free_fileArcP(cheminMin);
				cheminMin=tabuArc;
				tabuArc=NULL;
			}

		}
		printf("====================================\n");
	//dépot des pheromones
	//depotPheromone(tabFourmi, M);
	/*int i=0;
	for(i=0;i<nbVille;i++)
	{
		printf("i: %d, num: %d, x: %lf, y :%lf, nom: %s\n", i, tabVille[i].num, tabVille[i].x, tabVille[i].y, tabVille[i].nom);

		visualiser_listeArc( tabVille[i].ListeVoisin );
	}*/


	}
	//penser à tout free


}

