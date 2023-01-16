/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

Couche::Couche() {
  state = STATE_INIT;
  Vecteur vecteur;
};

Couche::~Couche() {
  vecteur.vider();
};

int Couche::getEtat() {
  return state;
};

Forme *Couche::getForme(int index) {
  return vecteur.getForme(index);
};

double Couche::aire() {
  double aire = 0;
  for (int i = 0; i < vecteur.getTaille(); i++) {
    aire += vecteur.getForme(i)->aire();
  };
  return aire;
};

void Couche::afficher(ostream &s) {
  if (state == STATE_INIT) {
    s << "Couche initialisée\n";
  } else {
    vecteur.afficher(s);
  };
};

bool Couche::changerEtat(int newState) {
  if ( newState>=STATE_INIT && newState<=STATE_INACTIVE ) {
    state = newState;
    return true;
  };
  return false;
};

bool Couche::translater(int deltaX, int deltaY) {
  if (state != STATE_ACTIVE) return false;
  for (int i = 0; i < vecteur.getTaille(); i++)
    vecteur.getForme(i)->translater(deltaX, deltaY);
  return true;
};

bool Couche::ajouterForme(Forme *f) {
  if (state != STATE_ACTIVE) return false;
  return vecteur.ajouterForme(f);
};

Forme *Couche::supprimerForme(int index) {
  if (state != STATE_ACTIVE) {
    return NULL;
  } else {
    return vecteur.supprimerForme(index);
  };
  return vecteur.supprimerForme(index);
};

bool Couche::reinitialiser() {
  state = STATE_INIT;
  vecteur.vider();
  return true;
};


