#include "carre.h"

Carre::Carre(int x, int y, int cote) : Rectangle(x, y, cote, cote) {
};

Carre::~Carre() {
};

void Carre::afficher(ostream &s) {
    s << "Carre(x=" << getAncrage().x
      << ", y=" << getAncrage().y
      << ", c=" << getLargeur()
      << ", a=" << aire()
      << ")\n";
};
