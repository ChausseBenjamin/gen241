#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "forme.h"

class Rectangle:public Forme{
  private:
    int largeur;
    int hauteur;
  public:
    Rectangle(int x, int y, int l, int h);
    ~Rectangle();
    int getLargeur();
    int getHauteur();
    Coordonnee getAncrageForme();
    void setLargeur(int l);
    void setHauteur(int h);
    double aire();
    void afficher(ostream &s);
};

#endif
