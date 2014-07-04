#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structure.h"
#include "readGraph.h"
#include "fonctionsPrincipales.h"
#include "listeSommetP.h"
#include "math.h"

/*=========constantes=======*/

#define RHO 0.5 //coef d'évaporation des phéromones
#define ALPHA 1 //Coefficient régulant l'importance des phéromones pour le choix d'une ville
#define BETA 2 //Coefficient régulant l'importance de la visibilité pour le choix d'une ville
#define EPS 0.00001 //Valeur initiale non nulle de phéromones sur les arcs
#define Q 1 //Constante servant à calculer la quantité de phéromones à déposer pour chaque fourmi
#define Mmin 2
#define Mmax 60
#define Mpas 1
#define MAX_CYCLEmin  10
#define MAX_CYCLEmax  200
#define MAX_CYCLEpas  1
#define Xmin 2
#define Xmax 60
#define Xpas 1
#define MODE 1
#define REPET 50

/*=========constantes - fin====*/






double algo_general(int M, int MAX_CYCLE )
{

	char nomFichier[100]="graphe14.txt"; //à remplacer par argv[1] à la fin
	Sommet* tabVille = NULL; int nbVille = 0; int iVille=0; int iFourmi=0;
	remplirTable(nomFichier, &tabVille, &nbVille,EPS); //on remplit la table qui contient tous les Sommets et Arcs depuis le fichier
	ListeArcP cheminMin=NULL; //Liste de pointeurs sur les Arcs du chemin le plus court
	double Lmin=Lchemin(cheminMin); //longueur la plus petite rencontrée initialisée à une grande valeur
    double L=0;//Constante pour stocker le chemin de la fourmi courante (afin de ne pas le recalculer a chaque fois)



	int iCycle=0;
	for(iCycle = 0;iCycle<MAX_CYCLE;iCycle++)
	{
		Fourmi* tabFourmi=NULL;
		tabFourmi = initFourmi(M, nbVille);//initialiser M fourmi sur les nbVille

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
				tabu = ajout_teteSommetP(&tabVille[villeSuiv], tabu);
				tabFourmi[iFourmi].iVilleCour = villeSuiv;

			}while(ville_parcourue(tabu,(tabFourmi[iFourmi]).iVilleCour,nbVille)!=0);

               tabu=ajout_teteSommetP(&(tabVille[(tabFourmi[iFourmi]).iVilleDep]), tabu);//On rajoute la ville de départ pour faire un parcours fermé

			tabFourmi[iFourmi].solution = parcours_fourmi(tabFourmi[iFourmi], tabu);

            free_listeSommetP(tabu);

			 L=Lchemin(tabFourmi[iFourmi].solution);
			if(L<Lmin)
			{
				free_listeArcP(cheminMin);
				cheminMin=copieArcP(tabFourmi[iFourmi].solution);
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



	return(Lmin);

	//penser à tout free

	for(iVille=0;iVille<nbVille;iVille++)
	{free_listeArc(tabVille[iVille].ListeVoisin);
	 free(tabVille[iVille].nom);
	}
	free(tabVille);
	free_listeArcP(cheminMin);
}



double elitistes(int M, int MAX_CYCLE, int X)
{



	char nomFichier[100]="Quatar194.txt"; //à remplacer par argv[1] à la fin
	Sommet* tabVille = NULL; int nbVille = 0; int iVille=0; int iFourmi=0;
	remplirTable(nomFichier, &tabVille, &nbVille,EPS); //on remplit la table qui contient tous les Sommets et Arcs depuis le fichier
	ListeArcP cheminMin=NULL; //Liste de pointeurs sur les Arcs du chemin le plus court
	double Lmin=Lchemin(cheminMin); //longueur la plus petite rencontrée initialisée à une grande valeur
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

			//rajouter la ville de départ de la fourmi tabu
			tabu = ajout_teteSommetP(&tabVille[ (tabFourmi[iFourmi].iVilleDep) ], tabu);
			//tant que le circuit n'est pas bouclé

			do
			{
				int villeSuiv=-1;
				villeSuiv = ville_next(tabu, nbVille, tabVille[ (tabFourmi[iFourmi]).iVilleCour ],tabVille, ALPHA,BETA,tabFourmi[iFourmi].iVilleDep);
				if (villeSuiv==-1)printf("allocation");
				tabu = ajout_teteSommetP(&tabVille[villeSuiv], tabu);
				tabFourmi[iFourmi].iVilleCour = villeSuiv;

			}while(ville_parcourue(tabu,(tabFourmi[iFourmi]).iVilleCour,nbVille)!=0);

               tabu=ajout_teteSommetP(&(tabVille[(tabFourmi[iFourmi]).iVilleDep]), tabu);//On rajoute la ville de départ pour faire un parcours fermé

			tabFourmi[iFourmi].solution = parcours_fourmi(tabFourmi[iFourmi], tabu);

            free_listeSommetP(tabu);

            Ltab[iFourmi]=Lchemin(tabFourmi[iFourmi].solution);
			if(Ltab[iFourmi]<Lmin)
			{
			    free_listeArcP(cheminMin);
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



return(Lmin);

//penser à tout free

for(iVille=0;iVille<nbVille;iVille++)
{free_listeArc(tabVille[iVille].ListeVoisin);
}
free(tabVille);
free_listeArcP(cheminMin);
}

main()
{int i,j,n; int k=Xmin; double l=1000; int m,mc; int x=0; float t=1000;
double L;
char nom_donnees[100]="Donnees.txt";
FILE* f;
if ( (f=fopen("Donnees.txt","w")) ==NULL)
    printf("erreur d'ouverture du fichier");
else
{   clock_t debutchargement, finchargement ;

    fprintf(f,"\t Lmin \t\t M \t  MAX_CYCLE \t X \t temps\n");

    for(n=0;n<REPET;n++)
    {fprintf(f,"\nrepetition %d\n",n+1 );
    if(MODE==1)
        {
        for(i=MAX_CYCLEmin;i<=MAX_CYCLEmax; i=i+MAX_CYCLEpas)
        {printf("\n\nMAX_CYCLE: %d \n\n",i);
            for(j=Mmin;j<=Mmax;j=j+Mpas)
            {printf("\nM: %d\n\n",j);

                while(k<=Xmax && k<=j)
                {printf("X: %d\n",k);
                    debutchargement=clock();
                    L=elitistes(j,i,k);
                    finchargement=clock();
                    if(L<l)
                    {l=L; m=j; x=k; mc=i; }

                    fprintf(f,"\t %lf;\t %d;\t %d;\t\t %d;\t %f; \n", L,j,i,k,((double)finchargement-debutchargement)/CLOCKS_PER_SEC);
                    k=k+Xpas;
                }

            k=Xmin;
            }

        }
        }

    else
    {for(i=MAX_CYCLEmin;i<=MAX_CYCLEmax; i=i+MAX_CYCLEpas)
    {printf("\n\nMAX_CYCLE: %d \n\n",i);
        for(j=Mmin;j<=Mmax;j=j+Mpas)
        {printf("\nM: %d\n\n",j);

                debutchargement=clock();
                L=algo_general(j,i);
                finchargement=clock();
                if(L<l)
                {l=L; m=j; mc=i; }

                fprintf(f,"\t %lf;\t %d;\t %d;\t\t %d;\t %f; \n", L,j,i,j,((double)finchargement-debutchargement)/CLOCKS_PER_SEC);
        }
    }

    }

    }
    fprintf(f,"\n\n\nchemin min trouve dans cette serie de mesures %lf pour M: %d MAX_CYCLE: %d X: %d ",l,m,mc,x);
    if ( fclose( f ) != 0 ) printf( "Une erreur s’est produite à la fermeture" ) ;
}


}
