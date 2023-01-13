#include "rectangle.h"

class Carre : public Rectangle {
public:
    Carre(int x, int y, int cote);
    ~Carre();
    void afficher(ostream &s);
};
