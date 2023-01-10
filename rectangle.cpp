#include "forme.h"

class Rectangle:Forme{
  private:
    int Largeur;
    int Hauteur;

  public:

    Rectangle(int x, int y, int l, int h):Forme(x,y),Largeur(l),Hauteur(h){
      Coordonnee t = {x,y};
      setAncrage(t);
      SetHauteur(h);
      SetLargeur(l);
    };

    int GetLargeur(){return Largeur;};
    int GetHauteur(){return Hauteur;};
    void SetLargeur(int l){Largeur=l;};
    void SetHauteur(int h){Hauteur=h;};
    double aire(){return Largeur*Hauteur;};
    void afficher(ostream &s);
};

void Rectangle::afficher(ostream &s){
  // Resultat: "Rectangle (x=2, y=3, h=4, l=5, aire=5)"
  s << "Rectangle (x=" << getAncrage().x
    << ", y="          << getAncrage().y
    << ", h="          << GetHauteur()
    << ", l="          << GetLargeur()
    << ", aire="       << aire()
    << ")\n";
    /* << ")" << endl; */
};

class Carre:Rectangle{
  public:

    Carre(int x, int y, int c):Rectangle(x,y,c,c){};

    void afficher(ostream &s);
};

Carre::afficher(osstream &s){
  // Resultat: "Carre (x=2, y=3, c=4, aire=5)"
  s << "Carre (x=" << getAncrage().x
    << ", y="       << getAncrage().y
    << ", c="       << GetHauteur()
    << ", aire="    << aire()
    << ")\n";
    /* << ")" << endl; */
};
