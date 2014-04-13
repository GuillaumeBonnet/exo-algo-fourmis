CFLAGS=-c -g
LFLAGS= -lm

all : readGraph_test liste_test

fonctionsPrincipales_test : fonctionsPrincipales_test.o fonctionsPrincipales.o
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
