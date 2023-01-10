#include <cmath>
#include "forme.h"

class Cercle:Forme {
  private:
    int Rayon;
  public:

    Cercle(int x, int y, int r):Forme(x,y),Rayon(r) {
      Coordonnee t = {x,y};
      setAncrage(t);
      SetRayon(r);

    };

    void afficher(ostream & s);
    int GetRayon(){return Rayon;};
    void SetRayon(int r){Rayon=r;};
    double aire(){return M_PI*Rayon*Rayon;};
    double perimetre(){return 2*M_PI*Rayon;};
};

void Cercle::afficher(ostream & s) {
  s << "Cercle (x=" << getAncrage().x
    << ", y=" << getAncrage().y
    << ", r=" << GetRayon() << ", aire=" << aire() << ")";
};
