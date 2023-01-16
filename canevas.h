/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration de la classe Canevas. La classe gere un
 *    tableau de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef __DESSIN_H__
#define __DESSIN_H__

#include <iostream>
#include "forme.h"
#include "couche.h"

const int MAX_COUCHES = 5;

using namespace std;

class Canevas {
public:
   Canevas();
   ~Canevas();
   bool   reinitialiser();
   bool   activerCouche(int index);
   bool   ajouterForme(Forme *p_forme);
   bool   retirerForme(int index);
   double aire();
   bool   translater(int deltaX, int deltaY);
   void   afficher(ostream &s);
   void   getEtats(ostream &s);
   bool   reinitialiserCouche(int index);
private:
   Couche couches[MAX_COUCHES];
};

#endif
