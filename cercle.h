#ifndef __CERCLE_H__
#define __CERCLE_H__

#include "forme.h"

class Cercle:Forme {
  private:
    int rayon;
  public:
    Cercle(int x, int y, int r);
    ~Cercle();
    void   setRayon(int r);
    int    getRayon();
    double aire();
    double getPerimetre();
    void   afficher(ostream & s);
};

#endif
