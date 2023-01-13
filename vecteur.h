#include <iostream>
#include "forme.h"

using namespace std;

// - [x] Items stockés sont des pointeurs de Forme
// - [ ] Items toujours contigus en mémoire
// - [ ] connaître la capacité maximale du vecteur
// - [ ] connaître la taille courante du vecteur
// - [ ] Lorsqu'il manque d'espace pour ajouter une forme,
//       le vecteur double sa capacité
// - [ ] vider le vecteur en un seul appel
// - [ ] lorsque le vecteur est vidé, détruire ses formes
// - [ ] savoir si le vecteur est vide (bool)
// - [ ] ajouter une forme à la fin du vecteur (true si ok)
// - [ ] supprimer une forme à un index (retourne la forme) NULL on error
// - [ ] récupérer une forme à un index (retourne la forme) NULL on error
// - [ ] afficher le vecteur en utilisant Forme::afficher()

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
    void afficher(ostream &s);
    // Manipulations
    bool ajouterForme(Forme *f);
    Forme *supprimerForme(int index);
    void vider();
};

