#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "initialisation.h"
#include "fonctionsPrincipales.h"
#include "listeSommetP.h"
#include "math.h"




/*=========constantes=======*/
#define M 10 //nombre total de fourmis de l'algorithme PS : faire en sorte que m=2*n.
#define RHO 0.5 //coef d'évaporation des phéromones
#define ALPHA 1 //Coefficient régulant l'importance des phéromones pour le choix d'une ville
#define BETA 2 //Coefficient régulant l'importance de la visibilité pour le choix d'une ville
#define EPS 0.0001 //Valeur initiale non nulle de phéromones sur les arcs
#define Q 1 //Constante servant à calculer la quantité de phéromones à déposer pour chaque fourmi
#define MAX_CYCLE 100 //Constante, nombre maximum de cycles autorisés.
/*=========constantes - fin====*/

int main(int argc, char *argv[])
{
	/* initialisation de rand : */srand(time(NULL));
char nomFichier[100]="Quatar194.txt";
	Sommet* tabVille = NULL; int nbVille = 0; int iVille=0; int iFourmi=0; int vp;
	remplirTable(nomFichier, &tabVille, &nbVille,EPS); //on remplit la table qui contient tous les Sommets et Arcs depuis le fichier
	if(tabVille==NULL) return NULL;

	ListeArcP cheminMin=NULL; //Liste de pointeurs sur les Arcs du chemin le plus court
	double Lmin=Lchemin(cheminMin); //longueur la plus petite rencontrée initialisée à une grande valeur
    double L=0;//Constante pour stocker le chemin de la fourmi courante (afin de ne pas le recalculer a chaque fois)


printf("nbVilles %d\n",nbVille);
	int iCycle=0;
	for(iCycle = 0;iCycle<MAX_CYCLE;iCycle++)
	{
		Fourmi* tabFourmi=NULL;
		tabFourmi = initFourmi(M, nbVille);//initialiser M fourmi sur les nbVille
		if(tabFourmi==NULL) return NULL;
	   	int iFourmi=0;
		for(iFourmi=0;iFourmi<M; iFourmi++)   /*pour chaque fourmi*/
		{
			ListeSommetP tabu=NULL; //liste de pointeurs sur  des villes parcourues par la fourmi courrante

			//rajouter la ville de départ de la fourmi tabu
			tabu = ajout_teteSommetP(&tabVille[ (tabFourmi[iFourmi].iVilleDep) ], tabu);
			//tant que le circuit n'est pas bouclé

			do
			{
				int villeSuiv=-1;
				villeSuiv = ville_next(tabu, nbVille, tabVille[ (tabFourmi[iFourmi]).iVilleCour ],tabVille,ALPHA,BETA,tabFourmi[iFourmi].iVilleDep);
				if (villeSuiv==-1)printf("allocation");
				if(villeSuiv!=-42)
				{tabu = ajout_teteSommetP(&tabVille[villeSuiv], tabu);
				tabFourmi[iFourmi].iVilleCour = villeSuiv;
                }
                else vp=0;
			}while(vp!=0 && ville_parcourue(tabu,(tabFourmi[iFourmi]).iVilleCour,nbVille)!=0);

               tabu=ajout_teteSommetP(&(tabVille[(tabFourmi[iFourmi]).iVilleDep]), tabu);//On rajoute la ville de départ pour faire un parcours fermé

			tabFourmi[iFourmi].solution = parcours_fourmi(tabFourmi[iFourmi], tabu);

            free_listeSommetP(tabu);

			 L=Lchemin(tabFourmi[iFourmi].solution);
			if(L<Lmin&&vp!=0)
			{
				free_listeArcP(cheminMin);
				cheminMin=(ListeArcP)copieArcP(tabFourmi[iFourmi].solution);
				Lmin=L;
			}


		}//boucle fourmis

		evapPheromone(tabVille, nbVille,RHO);
		depotPheromone(tabFourmi, M, Q);

        for(iFourmi=0;iFourmi<M;iFourmi++)
        {free_listeArcP(tabFourmi[iFourmi].solution);
        }
        free(tabFourmi);

	}//boucle cycles


	visualiser_listeArcP(cheminMin);
	printf("\n\n\n\tchemin le plus court: %lf \n \n \n", Lmin);

	//penser à tout free

	for(iVille=0;iVille<nbVille;iVille++)
	{free_listeArc(tabVille[iVille].ListeVoisin);
	 free(tabVille[iVille].nom);
	}
	free(tabVille);
	free_listeArcP(cheminMin);
}



