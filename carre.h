#ifndef __CARRE_H__
#define __CARRE_H__

#include "rectangle.h"

class Carre : public Rectangle {
public:
    Carre(int x=0, int y=0, int cote=1);
    ~Carre();
    void afficher(ostream &s);
};

#endif
