#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct Arc
{
int sdep;                                                    /*sommet de départ*/
int sarr;                                                     /*sommet d’arrivée*/
double d;                                                             /*distance entre les deux villes*/
double to;                                                            /*quantité de phéromones*/

}Arc;

struct MaillonArc
{
    Arc val;
    struct MaillonArc *suiv;
};
typedef struct MaillonArc* ListeArc;

struct ArcVoisin
{
    Arc val;
    struct ArcVoisin * suiv;
};
typedef struct ArcVoisin ArcVoisin;
typedef ArcVoisin* ListeArcVoisin;
typedef  ListeArcVoisin FileArcVoisin;

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
