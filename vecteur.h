#ifndef __VECTEUR_H__
#define __VECTEUR_H__

#include <iostream>
#include "forme.h"

using namespace std;

class Vecteur {
  private:
    int capacite; // capacité maximale actuelle du vecteur
    int taille;
    // dynamic array of pointers to Forme
    Forme **formes;
  public:
    Vecteur();
    ~Vecteur();
    // Informations
    bool estVide();
    Forme *getForme(int index);
    int getTaille();
    int getCapacite();
    void afficher(ostream &s);
    // Manipulations
    bool ajouterForme(Forme *f);
    Forme *supprimerForme(int index);
    void vider();
};

#endif
