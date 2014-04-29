#ifndef STRUCTURE_H
#define STRUCTURE_H


/*=========constantes=======*/







/*=========constantes - fin====*/
//====types relatifs aux Arcs
	typedef struct Arc
	{
		int sdep;                             /*sommet de départ*/
		int sarr;                             /*sommet d’arrivée*/
		double d;                             /*distance entre les deux villes*/
		double to;                            /*quantité de phéromones*/

	}Arc;
	//liste avec éléments Arcs
	struct CelluleArc
	{
		Arc val;
		struct CelluleArc* suiv;
	};
	typedef struct CelluleArc MaillonArc;
	typedef MaillonArc* ListeArc;
	//liste avec éléments pointeurs sur Arcs
	struct CelluleArcP
	{
		Arc* val;
		struct CelluleArcP* suiv;
	};
	typedef struct CelluleArcP MaillonArcP;
	typedef MaillonArcP* ListeArcP;

//====fourmi
	typedef struct Fourmi
	{
		ListeArcP solution;
		int iVilleDep;     // indice de la ville de départ de la fourmi
		int iVilleCour;    // indice de la ville courrante de la fourmi
	}Fourmi;

//====types relatifs aux Sommets
	typedef struct Sommet
	{
		int num;
		char* nom;
		double x;
		double y;
		ListeArc ListeVoisin;
	}Sommet;
	typedef Sommet Ville;

	//liste avec élément Sommets
	typedef struct MaillonSommet
	{
		Sommet val;
		struct MaillonSommet * suiv;

	} MaillonSommet;
	typedef MaillonSommet* ListeSommet;

	//liste avec élément pointeurs sur Sommets
	typedef struct MaillonSommetP
	{
		Sommet* val;
		struct MaillonSommetP * suiv;

	} MaillonSommetP;
	typedef MaillonSommetP* ListeSommetP;
#endif
