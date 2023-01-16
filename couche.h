/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe Couche gere un vecteur de pointeur de formes
 *    geometriques en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef __COUCHE_H__
#define __COUCHE_H__

#define STATE_INIT 0 // Couche initialisee mais vide
#define STATE_ACTIVE 1 // Couche active (peut-etre modifiee)
#define STATE_INACTIVE 2 // Couche inactive (non modifiable)

#include "vecteur.h"

class Couche {
  private:
    int     state;
    Vecteur vecteur;
  public:
    Couche();
    ~Couche();
    int    getEtat();
    Forme  *getForme(int index);
    double aire();
    void   afficher(ostream &s);
    bool   changerEtat(int newState);
    bool   translater(int deltaX, int deltaY);
    bool   ajouterForme(Forme *f);
    Forme  *supprimerForme(int index);
    bool   reinitialiser();

};

static const char* const STATES[] = {
    "initialisee",
    "actif",
    "inactif"
};


#endif
