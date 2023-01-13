#ifndef __CARRE_H__
#define __CARRE_H__

#include "rectangle.h"

class Carre : public Rectangle {
public:
    Carre(int x, int y, int cote);
    ~Carre();
    void afficher(ostream &s);
};

#endif
