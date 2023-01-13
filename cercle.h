#include "forme.h"

class Cercle:Forme {
  private:
    int rayon;
  public:
    Cercle(int x, int y, int r);
    ~Cercle();
    void   setRayon(int r);
    int    getRayon();
    double getAire();
    double getPerimetre();
    void   afficher(ostream & s);
};
