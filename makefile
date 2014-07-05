DIRSDL=/users/prog1a/C/librairie/2011
CFLAGS=-c -g -I$(DIRSDL)/include/SDL -I$(DIRSDL)/include
#LFLAGS=-L$(DIRSDL)/lib -lm -lSDLmain -lSDL -lSDL_ttf -lSDL_image -lSDL_draw #poste phelma#
LFLAGS=-L$(DIRSDL)/lib -lm -lSDLmain -lSDL#poste guillaume#



all : algorithmeGeneral afficheGraph creerGraphe fonctions_pour_les_statistiques

algorithmeGeneral : algorithmeGeneral.o listeSommetP.o listeArcP.o fonctionsPrincipales.o readGraph.o listeArc.o listeSommet.o
	gcc -o $@  $^ $(LFLAGS)
%.o: %.c
	gcc $(CFLAGS) $<

afficheGraph : afficheGraph.o fonctionsPrincipales.o readGraph.o listeArc.o listeSommet.o listeArcP.o listeSommetP.o
	gcc -o $@  $^ $(LFLAGS)
%.o: %.c
	gcc $(CFLAGS) $<

creerGraphe : creerGraphe.o fonctionsPrincipales.o readGraph.o listeArc.o listeSommet.o listeArcP.o listeSommetP.o
	gcc -o $@  $^ $(LFLAGS)
%.o: %.c
	gcc $(CFLAGS) $<

fonctions_pour_les_statistiques : fonctions_pour_les_statistiques.o fonctionsPrincipales.o readGraph.o listeArc.o listeSommet.o listeArcP.o listeSommetP.o
	gcc -o $@  $^ $(LFLAGS)
%.o: %.c
	gcc $(CFLAGS) $<






clean : 
	rm *.o
tilde : 
	rm *.*~

