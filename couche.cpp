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
  vecteur = Vecteur();
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
  if (state == STATE_INIT) return false;
  state = newState;
  return true;
};

bool Couche::translater(int deltaX, int deltaY) {
  if (state != STATE_ACTIVE) return false;
  for (int i = 0; i < vecteur.getTaille(); i++)
    vecteur.getForme(i)->translater(deltaX, deltaY);
  return true;
};

bool Couche::ajouterForme(Forme *f) {
  int initialState = getEtat();
  if (initialState == STATE_INACTIVE) return false;
  bool success = vecteur.ajouterForme(f);
  if (success) {
    changerEtat(STATE_ACTIVE);
  };
  return success;
};

Forme *Couche::supprimerForme(int index) {
  if (state != STATE_ACTIVE) return NULL;
  return vecteur.supprimerForme(index);
};

bool Couche::reinitialiser() {
  if (state == STATE_INIT) return false;
  state = STATE_INIT;
  vecteur.vider();
  return true;
};


