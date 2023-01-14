#
# Auteur: C.-A. Brunet
# Date: 08 janvier 2018
# Description: compilation de graphicus-02. Ce fichier fait partie de
#	la distribution de Graphicus.
#

ALL := graphicus-02.o tests.o canevas.o couche.o forme.o vecteur.o cercle.o rectangle.o carre.o

CFLAGS := -flto -Ofast -march=native

# graphicus-02: $(ALL)
# 	g++ $(CFLAGS) -o $@ $^ && strip $@ $^

graphicus-02: $(ALL)
	g++ $(CFLAGS) -o $@ $^


tests.o: tests.cpp tests.h canevas.h couche.h forme.h
	g++ $(CFLAGS) -c tests.cpp

canevas.o: canevas.cpp canevas.h couche.h forme.h
	g++ $(CFLAGS) -c canevas.cpp

couche.o: couche.cpp couche.h forme.h
	g++ $(CFLAGS) -c couche.cpp

forme.o: forme.cpp forme.h
	g++ $(CFLAGS) -c forme.cpp

vecteur.o: vecteur.cpp vecteur.h coordonnee.h
	g++ $(CFLAGS) -c vecteur.cpp

rectangle.o: rectangle.cpp rectangle.h forme.h
	g++ $(CFLAGS) -c rectangle.cpp

carre.o: carre.cpp carre.h rectangle.h forme.h
	g++ $(CFLAGS) -c carre.cpp

cercle.o: cercle.cpp cercle.h forme.h
	g++ $(CFLAGS) -c cercle.cpp

graphicus-02.o: graphicus-02.cpp canevas.h couche.h forme.h
	g++ $(CFLAGS) -c graphicus-02.cpp

clean:
	rm  -f *.o

options:
	@echo "Option de compilation de GRAPHICUS:"
	@echo "    graphicus-02: Construction de l'executable dans sa totalité"
	@echo "    clean: Nettoyage des fichiers temporaires '.o'"
	@echo "    *.o: Construction des fichiers objets"

