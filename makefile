CFLAGS=-c -g
LFLAGS= -lm -lSDL

all : algorithmeGeneral fonctionsPrincipales_test readGraph_test listeArc_test

algorithmeGeneral : algorithmeGeneral.o listeSommetP.o listeArcP.o fonctionsPrincipales.o readGraph.o listeArc.o listeSommet.o
	gcc -o $@  $^ $(LFLAGS)
%.o: %.c
	gcc $(CFLAGS) $<

fonctionsPrincipales_test : fonctionsPrincipales_test.o fonctionsPrincipales.o readGraph.o listeArc.o listeSommet.o
	gcc -o $@  $^ $(LFLAGS)
%.o: %.c
	gcc $(CFLAGS) $<

afficheGraph_test : afficheGraph_test.o afficheGraph.o fonctionsPrincipales.o readGraph.o listeArc.o listeSommet.o
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
