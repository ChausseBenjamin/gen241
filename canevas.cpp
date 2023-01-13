/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"

Canevas::Canevas() {
 Couche couches[MAX_COUCHES];
 for (int i = 0; i < MAX_COUCHES; i++) {
  couches[i] = Couche();
 };
 couches[0].changerEtat(STATE_ACTIVE);
}

Canevas::~Canevas() {
  reinitialiser();
}

bool Canevas::reinitialiser() {
  for (int i = 0; i < MAX_COUCHES; i++) {
    if (!couches[i].reinitialiser()) {
      return false;
    }
  }
  return true;
}

bool Canevas::activerCouche(int index) {
  if (index < 0 || index >= MAX_COUCHES)
    return false;
  for (int i = 0; i < MAX_COUCHES; i++) {
    if (couches[i].getEtat() == STATE_ACTIVE) {
      couches[i].changerEtat(STATE_INACTIVE);
    };
  };
  return couches[index].changerEtat(STATE_ACTIVE);
};

bool Canevas::cacherCouche(int index) {
  if (index < 0 || index >= MAX_COUCHES)
    return false;
  couches[index].changerEtat(STATE_INACTIVE);
 return true;
};

bool Canevas::ajouterForme(Forme *p_forme) {
  int active = -1;
  for (int i = 0; i < MAX_COUCHES; i++)
    active = (couches[i].getEtat() == STATE_ACTIVE) ? i : active;
  if (active == -1)
    return false;
  return couches[active].ajouterForme(p_forme);
};

bool Canevas::retirerForme(int index) {
  int active = -1;
  for (int i = 0; i < MAX_COUCHES; i++)
    active = (couches[i].getEtat() == STATE_ACTIVE) ? i : active;
  if (active == -1)
    return false;
  if (couches[active].supprimerForme(index)==NULL)
    return false;
  return true;
};

double Canevas::aire() {
  double aire = 0;
  for (int i = 0; i < MAX_COUCHES; i++) {
    if (couches[i].getEtat() == STATE_ACTIVE) {
      aire += couches[i].aire();
    };
  };
  return aire;
};

bool Canevas::translater(int deltaX, int deltaY) {
  int active = -1;
  for (int i = 0; i < MAX_COUCHES; i++)
    active = (couches[i].getEtat() == STATE_ACTIVE) ? i : active;
  if (active == -1)
    return false;
  return couches[active].translater(deltaX, deltaY);
};

void Canevas::afficher(ostream & s) {
  for (int i = 0; i < MAX_COUCHES; i++) {
    s << "----- Couche " << i << "\n";
    couches[i].afficher(s);
  };
};
