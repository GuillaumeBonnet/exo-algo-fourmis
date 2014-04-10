/*=========constantes=======*/

/*=========constantes - fin====*/



typedef struct Arc
{
int sdep;                                                    /*sommet de départ*/
int sarr;                                                     /*sommet d’arrivée*/
double d;                                                             /*distance entre les deux villes*/
double to;                                                            /*quantité de phéromones*/

} Arc;

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
    FileArcVoisin FileVoisin;
    int iVilleDep;     // indice de la ville de départ de la fourmi
    int iVilleCour;    // indice de la ville courrante de la fourmi

}Fourmi;


typedef struct Sommet
{
int num;
char* nom;
int x;
int y;
ListeArcVoisin ListeVoisin;
}Sommet;

typedef Sommet Ville;


typedef
     struct Arete
{
Arc arc12;                                          /*arc dans un sens*/
Arc arc21;                                          /*arc dans l’autre sens*/
} Arete;

typedef struct MaillonSommet
{
Sommet val;
struct MaillonSommet * suiv;

} MaillonSommet;

typedef MaillonSommet* ListeSommet;






/*_____________________________prototypes_____________________________________*/
ListeSommet creer_liste(void);             /*Validée!*/
int est_vide(ListeSommet L);                 /*Validée!*/
ListeSommet ajout_tete(Sommet e, ListeSommet L);       /*Validée!*/
ListeArcVoisin creer_ListeArcVoisin(void);                          /*Validée!*/
int est_videListeArcVoisin(ListeArcVoisin);                           /*Validée!*/
ListeArcVoisin ajout_teteArc(Arc e, ListeArcVoisin L);            /*Validée!*/

void affichedouble(double* t,int n);/*affiche un tableau de doubles*/     /*Validée!*/
double* initialisation(int n); /*renvoit un tableau de doubles initialisé a 2*/     /*Validée!*/
double* probatabu(double* t,ListeSommet tabu); /*renvoit un tableau avec les probas des villes dans tabu a 0*/     /*Validée!*/




void afficheListeSommet(ListeSommet tabu);         /*Validée!*/   
/*elle affiche les numeros des villes dans une ListeSommet*/    

int ville_next (ListeSommet tabu,int n, Sommet s);    /*renvoit le numéro de la prochaine ville */

    double* proba(Sommet s, ListeSommet tabu, ListeSommet villes, int n);
/*renvoit l’adresse d’un tableau contenant les probas si elles ne sont pas toutes parcourus (t[N-1]=p(N)),  NULL si l’allocation a échoué et un tableau avec que des 2 si toutes les villes sont parcourus*/    

     int ville_parcourue(ListeSommet tabu,ListeSommet villes, int N,int n); /*Validée!*/   
 /* renvoie 1 si la fourmi est passée par une ville, 0 si elle est pasee 
par toutes les villes et 2 si elle n’est pas encore passée*/


ListeSommet ajout_ville(ListeSommet tabu,ListeSommet villes, int N );      /*Validée!*/   
      /*elle rajoute une ville a tabu*/

ListeSommet depart(ListeSommet villes, int n);   /*Validée!*/   
    /*elle cree tabu avec une ville au hasard comme premier element*/




