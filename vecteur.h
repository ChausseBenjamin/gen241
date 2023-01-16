#ifndef __VECTEUR_H__
#define __VECTEUR_H__

#include <iostream>
#include "forme.h"

using namespace std;

class Vecteur {
  private:
    int   capacite; // capacité maximale actuelle du vecteur
    int   taille;   // nombre d'éléments actuellement dans le vecteur
    Forme **formes; // dynamic array of pointers to Forme
  public:
    Vecteur();
    ~Vecteur();
    bool  estVide();
    Forme *getForme(int index);
    int   getTaille();
    int   getCapacite();
    void  afficher(ostream &s);
    bool  ajouterForme(Forme *f);
    Forme *supprimerForme(int index);
    void  vider();
};

#endif
