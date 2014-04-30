#include "readGraph.h"
#include "fonctionsPrincipales.h"
#include "listeSommetP.h"
#include "math.h"





/*=========constantes=======*/
#define M 10 //nombre total de fourmis de l'algorithme PS : faire en sorte que m=2*n.
#define RHO 0.5 //coef d'�vaporation des ph�romones
#define ALPHA 1 //Coefficient r�gulant l'importance des ph�romones pour le choix d'une ville
#define BETA 2 //Coefficient r�gulant l'importance de la visibilit� pour le choix d'une ville
#define EPS 0.00001 //Valeur initiale non nulle de ph�romones sur les arcs
#define Q 1 //Constante servant � calculer la quantit� de ph�romones � d�poser pour chaque fourmi
#define MAX_CYCLE 10 //Constante, nombre maximum de cycles autoris�s.
#define X 20       // Nb de fourmis intelligentes a consid�rer
/*=========constantes - fin====*/

int main(int argc, char *argv[])
{



	char nomFichier[100]="graphe14.txt"; //� remplacer par argv[1] � la fin
	Sommet* tabVille = NULL; int nbVille = 0; int iVille=0; int iFourmi=0;
	remplirTable(nomFichier, &tabVille, &nbVille,EPS); //on remplit la table qui contient tous les Sommets et Arcs depuis le fichier
	ListeArcP cheminMin=NULL; //Liste de pointeurs sur les Arcs du chemin le plus court
	double Lmin=Lchemin(cheminMin); //longueur la plus petite rencontr�e initialis�e � une grande valeur
    double* Ltab=calloc(M,sizeof(*Ltab));//tableua contenant les parcours
        for(iFourmi=0;iFourmi<M; iFourmi++)
            Ltab[iFourmi]=0;



	int iCycle=0;
	for(iCycle = 0;iCycle<MAX_CYCLE;iCycle++)
	{
		Fourmi* tabFourmi=NULL;
		tabFourmi = initFourmi(M, nbVille);//initialiser M fourmi sur les nbVille

	   	 iFourmi=0;
		for(iFourmi=0;iFourmi<M; iFourmi++)   /*pour chaque fourmi*/
		{
			ListeSommetP tabu=NULL; //liste de pointeurs sur  des villes parcourues par la fourmi courrante

			//rajouter la ville de d�part de la fourmi tabu
			tabu = ajout_teteSommetP(&tabVille[ (tabFourmi[iFourmi].iVilleDep) ], tabu);
			//tant que le circuit n'est pas boucl�

			do
			{
				int villeSuiv=-1;
				villeSuiv = ville_next(tabu, nbVille, tabVille[ (tabFourmi[iFourmi]).iVilleCour ],tabVille, ALPHA,BETA);
				if (villeSuiv==-1)printf("allocation");
				tabu = ajout_teteSommetP(&tabVille[villeSuiv], tabu);
				tabFourmi[iFourmi].iVilleCour = villeSuiv;

			}while(ville_parcourue(tabu,(tabFourmi[iFourmi]).iVilleCour,nbVille)!=0);

               tabu=ajout_teteSommetP(&(tabVille[(tabFourmi[iFourmi]).iVilleDep]), tabu);//On rajoute la ville de d�part pour faire un parcours ferm�

			tabFourmi[iFourmi].solution = parcours_fourmi(tabFourmi[iFourmi], tabu);

            free_listeSommetP(tabu);

            Ltab[iFourmi]=Lchemin(tabFourmi[iFourmi].solution);
			if(Ltab[iFourmi]<Lmin)
			{
				cheminMin=copieArcP(tabFourmi[iFourmi].solution);
				Lmin=Ltab[iFourmi];
			}

		}//boucle fourmis

        triFourmi(tabFourmi, M , Ltab);

		evapPheromone(tabVille, nbVille, RHO);
		depotPheromone_Fourmis_intelligentes(tabFourmi, M, X,Q);

        for(iFourmi=0;iFourmi<M;iFourmi++)
        {free_listeArcP(tabFourmi[iFourmi].solution);
        }
        free(tabFourmi);

	}//boucle cycles


visualiser_listeArcP(cheminMin);
printf("chemin le plus court: %lf", Lmin);

//penser � tout free

for(iVille=0;iVille<nbVille;iVille++)
{free_listeArc(tabVille[iVille].ListeVoisin);
}
free(tabVille);

}


