#ifndef STRUCTURE_H
#define STRUCTURE_H


/*=========constantes=======*/
#define M 10 //nombre total de fourmis de l'algorithme PS : faire en sort que m=2*n.
#define RHO 0.5 //coef d'évaporation des phéromones
#define ALPHA 1 //Coefficient régulant l'importance des phéromones pour le choix d'une ville
#define BETA 2 //Coefficient régulant l'importance de la visibilité pour le choix d'une ville
#define EPS 0.00001 //Valeur initiale non nulle de phéromones sur les arcs
#define Q 1 //Constante servant à calculer la quantité de phéromones à déposer pour chaque fourmi
#define MAX_CYCLE 10 //Constante, nombre maximum de cycles autorisés.
/*=========constantes - fin====*/

typedef struct Arc
{
	int sdep;                             /*sommet de départ*/
	int sarr;                             /*sommet d’arrivée*/
	double d;                             /*distance entre les deux villes*/
	double to;                            /*quantité de phéromones*/

}Arc;

struct CelluleArc
{
	Arc val;
	struct CelluleArc* suiv;
};
typedef struct CelluleArc MaillonArc;
typedef MaillonArc* ListeArc;


typedef struct Fourmi
{
	ListeArc solution;
	int iVilleDep;     // indice de la ville de départ de la fourmi
	int iVilleCour;    // indice de la ville courrante de la fourmi
}Fourmi;


typedef struct Sommet
{
	int num;
	char* nom;
	double x;
	double y;
	ListeArc ListeVoisin;
}Sommet;

typedef Sommet Ville;

typedef struct MaillonSommet
{
	Sommet val;
	struct MaillonSommet * suiv;

} MaillonSommet;

typedef MaillonSommet* ListeSommet;
typedef struct Arete
{
	Arc arc12;                                          /*arc dans un sens*/
	Arc arc21;                                          /*arc dans l’autre sens*/
}Arete;


#endif
