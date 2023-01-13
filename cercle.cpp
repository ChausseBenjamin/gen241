#include "cercle.h"
#include <math.h>

Cercle::Cercle(int x, int y, int r):Forme(x,y) {
  setRayon(r);
};

Cercle::~Cercle() {
};

void Cercle::setRayon(int r) {
  rayon = r;
};

int Cercle::getRayon() {
  return rayon;
};

double Cercle::aire() {
  return M_PI*pow(rayon,2);
};

double Cercle::getPerimetre() {
  return 2*M_PI*rayon;
};

void Cercle::afficher(ostream & s) {
  s << "Cercle (x=" << getAncrage().x
    << ", y="       << getAncrage().y
    << ", r="       << getRayon()
    << ", aire="    << aire() << ")\n";
};
