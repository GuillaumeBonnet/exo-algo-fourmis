DIRSDL=/users/prog1a/C/librairie/2011
CFLAGS=-c -g -I$(DIRSDL)/include/SDL -I$(DIRSDL)/include
LFLAGS=-L$(DIRSDL)/lib -lSDLmain -lSDL -lSDL_ttf -lSDL_image -lSDL_phelma -lSDL_draw


all : algorithmeGeneral afficheGraph creerGraphe fonctionsPrincipales_test readGraph_test listeArc_test

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

fonctionsPrincipales_test : fonctionsPrincipales_test.o fonctionsPrincipales.o readGraph.o listeArc.o listeSommet.o
	gcc -o $@  $^ $(LFLAGS)
%.o: %.c
	gcc $(CFLAGS) $<

readGraph_test : readGraph_test.o readGraph.o listeArc.o
	gcc -o $@  $^
%.o: %.c
	gcc $(CFLAGS) $<

listeArc_test : listeArc_test.o listeArc.o
	gcc -o $@  $^
%.o: %.c
	gcc $(CFLAGS) $<


clean : 
	rm *.o
tilde : 
	rm *.*~

