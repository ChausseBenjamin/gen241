#ifndef __CERCLE_H__
#define __CERCLE_H__

#include "forme.h"

class Cercle:public Forme {
  private:
    int rayon;
  public:
    Cercle(int x=0, int y=0, int r=1);
    ~Cercle();
    void   setRayon(int r);
    int    getRayon();
    double aire();
    double getPerimetre();
    void   afficher(ostream & s);
};

#endif
