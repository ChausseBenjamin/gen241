#include "vecteur.h"

Vecteur::Vecteur(){
  capacite = 1;
  taille = 0;
  formes = new Forme*[capacite];
}

Vecteur::~Vecteur(){
  vider();
  delete[] formes;
}

bool Vecteur::estVide(){
  return (taille == 0);
};

Forme *Vecteur::getForme(int index){
  return (index < 0 || index >= taille) ? NULL : formes[index];
};

int Vecteur::getTaille(){
  return taille;
};

int Vecteur::getCapacite(){
  return capacite;
};

void Vecteur::afficher(ostream &s){
  for (int i = 0; i < taille; i++) {
    formes[i]->afficher(s);
  }
};

bool Vecteur::ajouterForme(Forme *f) {
  if (f == NULL) return false;
  if (taille == capacite) {
    // Double the size of the array
    int newCapacite = capacite * 2;
    Forme **newFormes = new (nothrow) Forme*[newCapacite];
    if(newFormes==nullptr) return false;
    for (int i = 0; i < taille; i++) {
      newFormes[i] = formes[i];
    }
    capacite = newCapacite;
    delete[] formes;
    formes = newFormes;
  }
  formes[taille] = f;
  taille++;
  return true;
};

Forme *Vecteur::supprimerForme(int index) {
  Forme *f = formes[index];
  while (index < taille) {
    formes[index] = formes[index + 1];
    index++;
  }
  formes[taille] = NULL;
  taille--;
  return f;
};

void Vecteur::vider() {
  for (int i = 0; i < taille; i++) {
    delete formes[i];
  }
  capacite = 1;
  taille = 0;
  Forme **newFormes = new Forme*[capacite];
  delete[] formes;
  formes = newFormes;
}
