/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"
#include "math.h"


// Tests sur les formes geometriques {{{
void Tests::tests_unitaires_formes() {
  cout << "----- Tests des formes geometriques -----\n";

  cout << "\n--- Tests sur le rectangle ---\n";

  cout << "Initialisation rectangle 3x4 en (1,2): \n\t";
  Rectangle r1(1, 2, 3, 4);
  r1.afficher(cout);

  cout << "Translation de (-1,2) pour arriver à (0,4): \n\t";
  r1.translater(-1, 2);
  r1.afficher(cout);

  cout << "Initialisation rectangle par defaut (1x1 en (0,0)): \n\t";
  Rectangle r2;
  r2.afficher(cout);
  cout << "\n";

  cout << "\n--- Tests sur le carre ---\n";

  cout << "Initialisation carre de cote=12 en (-2,-2): \n\t";
  Carre cr1(-2, -2, 12);
  cr1.afficher(cout);

  cout << "Initialisation carre par defaut (1x1 en (0,0)): \n\t";
  Carre cr2;
  cr2.afficher(cout);
  cout << "\n";


  cout << "\n--- Tests sur le cercle ---\n";
  cout << "Initialisation cercle de rayon 5 en (0,0): \n\t";
  Cercle cc1(0, 0, 5);
  cc1.afficher(cout);

  cout << "Initialisation cercle par defaut (rayon=1 en (0,0)): \n\t";
  Cercle cc2;
  cc2.afficher(cout);
  cout << "\n";
}; // }}}

// Tests sur la classe Vecteur {{{
void Tests::tests_unitaires_vecteur() {
  cout << "----- Tests de la classe Vecteur -----\n\n";

  cout << "--- Initialisation d\'un vecteur vide ---";
  Vecteur v1;
  cout << "\nVide: " << ((v1.estVide())? "Oui" : "Non")
       << "\nTaille: " << v1.getTaille()
       << "\nCapacite: " << v1.getCapacite()
       << "\nAffichage: {\n";
  v1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Ajout d'une forme (sans redimensionnement) ---";
  v1.ajouterForme(new Rectangle() ); // a=1
  cout << "\nVide: " << ((v1.estVide())? "Oui" : "Non")
       << "\nTaille: " << v1.getTaille()
       << "\nCapacite: " << v1.getCapacite()
       << "\nAffichage: {\n";
  v1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Ajout des autres formes (redimensionnement necessaire) ---";
  v1.ajouterForme( new Rectangle(1, 2, 8, 3) );
  v1.ajouterForme( new Carre(5, 6, 5) );
  v1.ajouterForme( new Cercle(0, 0, 1) );
  v1.ajouterForme( new Rectangle(-1,-1,95,10) );
  cout << "\nTaille: " << v1.getTaille()
       << "\nCapacite: " << v1.getCapacite()
       << "\nAffichage: {\n";
  v1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Suppression de la forme 4 (sans deplacement) ---";
  Forme* f1 = v1.supprimerForme(4);
  cout << "\nForme supprimee: ";
  f1->afficher(cout);
  cout << "Taille: " << v1.getTaille()
       << "\nCapacite: " << v1.getCapacite()
       << "\nAffichage: {\n";
  v1.afficher(cout);
  cout << "}\n";

  cout << "--- Suppression de la forme 1 (avec deplacement) ---";
  cout << "\nForme supprimee: ";
  delete f1;
  f1 = v1.supprimerForme(1);
  f1->afficher(cout);
  cout << "Taille: " << v1.getTaille()
       << "\nCapacite: " << v1.getCapacite()
       << "\nAffichage: {\n";
  v1.afficher(cout);
  cout << "}\n";
  delete f1;

  cout << "--- Reinitialisation du vecteur ---";
  v1.vider();
  cout << "\nVide: " << ((v1.estVide())? "Oui" : "Non")
       << "\nTaille: " << v1.getTaille()
       << "\nCapacite: " << v1.getCapacite()
       << "\nAffichage: {\n";
  v1.afficher(cout);
  cout << "}\n";
}; // }}}

// Tests sur la classe Couche {{{
void Tests::tests_unitaires_couche() {
  cout << "----- Tests de la classe Couche -----\n";

  cout << "\n--- Initialisation d'une couche ---";
  Couche c1;
  cout << "\nEtat: " << c1.getEtat()
       << "\nAffichage: {\n";
  c1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Ajout d'une forme dans une couche initialisée ---";
  cout << "\nReussite: " << ( (c1.ajouterForme(new Carre()))? "Oui":"Non")
       << "\nEtat: " << STATES[c1.getEtat()]
       << "\nAffichage: {\n";
  c1.afficher(cout);
  cout << "}\n\n";


  cout << "--- Changement de l\'etat de la couche (inactif) ---";
  cout << "\nReussite: " << (c1.changerEtat(STATE_INACTIVE)?"Oui":"Non")
       << "\nEtat: " << STATES[c1.getEtat()]
       << "\nAffichage: {\n";
  c1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Ajout d'une forme dans une couche active ---";
  c1.changerEtat(STATE_ACTIVE);
  cout << "\nReussite: " << (c1.ajouterForme(new Carre())? "Oui":"Non")
       << "\nEtat: " << STATES[c1.getEtat()]
       << "\nAffichage: {\n";
  c1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Changement pour un etat invalide (ex: 3) ---";
  cout << "\nReussite: " << (c1.changerEtat(STATE_INACTIVE+1)?"Oui":"Non")
       << "\nEtat: " << STATES[c1.getEtat()]
       << "\nAffichage: {\n";
  c1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Suppression d'une forme dans une couche inactive ---";
  c1.changerEtat(STATE_INACTIVE);
  cout << "\nReussite: " << ((c1.supprimerForme(0) != NULL)? "Oui":"Non")
       << "\nEtat: " << STATES[c1.getEtat()]
       << "\nAffichage: {\n";
  c1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Translation d'une couche inactive (1,2) ---";
  cout << "\nReussite: " << (c1.translater(1, 2)?"Oui":"Non")
       << "\nEtat: " << STATES[c1.getEtat()]
       << "\nAffichage: {\n";
  c1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Translation d'une couche active (1,2) ---";
  c1.changerEtat(STATE_ACTIVE);
  cout << "\nReussite: " << (c1.translater(1, 2)?"Oui":"Non")
       << "\nEtat: " << STATES[c1.getEtat()]
       << "\nAffichage: {\n";
  c1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Suppression d'une forme dans une couche active ---";
  cout << "\nReussite: " << ((c1.supprimerForme(0) != NULL)? "Oui":"Non")
       << "\nEtat: " << STATES[c1.getEtat()]
       << "\nAffichage: {\n";
  c1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Reinitialisation de la couche ---";
  c1.reinitialiser();
  cout << "\nEtat: " << STATES[c1.getEtat()]
       << "\nAffichage: {\n";
  c1.afficher(cout);
  cout << "}\n\n";
}; // }}}

// Tests sur la classe Canevas {{{
void Tests::tests_unitaires_canevas() {
  cout << "----- Tests de la classe Canevas -----\n\n";

  cout << "--- Initialisation d'un canevas ---\n";
  Canevas c1;
  cout << "Couches: ";
  c1.getEtats(cout);
  cout << "Affichage: {\n";
  c1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Ajout d'une forme (doit aller dans la couche 0) ---\n";
  cout << "Couches: ";
  c1.getEtats(cout);
  cout << "Reussite: " << (c1.ajouterForme(new Carre())? "Oui":"Non")
       << "\nAffichage: {\n";
  c1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Activation de la couche 3 ---\n";
  cout << "Reussite: " << (c1.activerCouche(3)? "Oui":"Non")
       << "\nCouches: ";
  c1.getEtats(cout);
  cout << "Affichage: {\n";
  c1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Ajout de forme (doit aller dans la couche 3) ---\n";
  cout << "Reussite: " << (c1.ajouterForme(new Carre())? "Oui":"Non")
       << "\nCouches: ";
  c1.getEtats(cout);
  cout << "Affichage: {\n";
  c1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Reinitialisation de la couche active (3) ---\n";
  cout << "Reussite: " << (c1.reinitialiserCouche(3)? "Oui":"Non")
       << "\nCouches: ";
  c1.getEtats(cout);
  cout << "Affichage: {\n";
  c1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Translation de couche initialisée (couche 3 par 1,2) ---\n";
  cout << "Reussite: " << (c1.translater(1, 2)? "Oui":"Non")
       << "\nCouches: ";
  c1.getEtats(cout);
  cout << "Affichage: {\n";
  c1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Translation d'une couche active (couche 0 par 1,2) ---\n";
  c1.activerCouche(0);
  cout << "Reussite: " << (c1.translater(1, 2)? "Oui":"Non")
       << "\nCouches: ";
  c1.getEtats(cout);
  cout << "Affichage: {\n";
  c1.afficher(cout);
  cout << "}\n\n";

  cout << "--- Réinitialisation du canevas ---\n";
  cout << "Reussite: " << (c1.reinitialiser()? "Oui":"Non")
       << "\nCouches: ";
  c1.getEtats(cout);
  cout << "Affichage: {\n";
  c1.afficher(cout);
  cout << "}\n";


}; // }}}

// Execution de tout les tests unitaires {{{
void Tests::tests_unitaires() {
  // Fait tous les tests unitaires
  tests_unitaires_formes();
  tests_unitaires_vecteur();
  tests_unitaires_couche();
  tests_unitaires_canevas();
}; // }}}

// Execution de tout les tests de mise en application {{{
void Tests::tests_application() {
  // Fait tous les tests applicatifs
  tests_application_cas_01();
  tests_application_cas_02();
}; // }}}

// Premiere application {{{
void Tests::tests_application_cas_01() {
  // Mise en place
  int etape = 1;
  Canevas c;

  cout << "TESTS APPLICATION (CAS 01)" << endl;
  // Il faut ajouter les operations realisant ce scenario de test.
  //
  cout << "Etape " << etape++
       << ": Activation de la couche 1" << endl;
  c.activerCouche(1);

  cout << "Etape " << etape++
       << ": Ajout des trois formes géométriques suivantes" << endl;
  cout << "\t* Un rectangle (x=0, y=0, largeur=2, hauteur=3)" << endl;
  c.ajouterForme(new Rectangle(0,0,2,3));
  cout << "\t* Un carré (x=2, y=3, cote=4)" << endl;
  c.ajouterForme(new Carre(2,3,4));
  cout << "\t* Un cercle (x=7, y=8, rayon=6)" << endl;
  c.ajouterForme(new Cercle(7,8,6));

  cout << "Etape " << etape++
       << ": Activer la couche 2" << endl;
  c.activerCouche(2);

  cout << "Etape " << etape++
       << ": Ajouter la forme géométrique suivante" << endl;
  cout << "\t* Un rectangle (x=0, y=0, largeur=4, hauteur=5)" << endl;
  c.ajouterForme(new Rectangle(0,0,4,5));

  cout << "Etape " << etape++
       << ": Afficher le canevas" << endl;
  c.afficher(cout);

  cout << "Etape " << etape++
       << ": Afficher l'aire du canevas" << endl;
  cout << "\t* Aire du canevas: " << c.aire() << endl;

  cout << "Etape " << etape++
       << ": Activer la couche 0 et ajouter les formes suivantes" << endl;
  c.activerCouche(0);
  cout << "\t* Un rectangle (x=0, y=0, largeur=1, hauteur=1)" << endl;
  c.ajouterForme(new Rectangle());
  cout << "\t* Un carré (x=0, y=0, cote=1)" << endl;
  c.ajouterForme(new Carre());
  cout << "\t* Un cercle (x=0, y=0, rayon=1)" << endl;
  c.ajouterForme(new Cercle());

  cout << "Etape " << etape++
       << ": Translater les formes de la couche selon x=5, y=5 pour obtenir les formes suivantes lorsque affiché" << endl;
  c.translater(5, 5);
  cout << "\t* Un rectangle (x=5, y=5, largeur=1, hauteur=1)" << endl;
  cout << "\t* Un carré (x=5, y=5, cote=1)" << endl;
  cout << "\t* Un cercle (x=5, y=5, rayon=1)" << endl;
  c.afficher(cout);



  cout << "Etape " << etape++
       << ": Couche 2 - initialisée" << endl;
  c.reinitialiserCouche(2);

  cout << "Etape " << etape++
       << ": Couche 3 - initialisée" << endl;
  c.reinitialiserCouche(3);

  cout << "Etape " << etape++
       << ": Couche 4 - initialisée" << endl;
  c.reinitialiserCouche(4);

  cout << "Etape " << etape++
       << ": Afficher le canevas" << endl;
  c.afficher(cout);

  cout << "Etape " << etape++
       << ": Afficher l'aire du canevas" << endl;

  cout << "Etape " << etape++
       << ": Retirer la première forme de la couche 1" << endl;
  c.activerCouche(1);
  c.retirerForme(0);

  cout << "Etape " << etape++
       << ": Afficher le canevas" << endl;
  c.afficher(cout);

  cout << "Etape " << etape++
       << ": Afficher l'aire du canevas" << endl;
  cout << "\t* Aire du canevas: " << c.aire() << endl;

  cout << "Etape " << etape++
       << ": Réinitialiser le canevas" << endl;
  c.reinitialiser();

  cout << "Etape " << etape++
       << ": Afficher le canevas" << endl;
  c.afficher(cout);

  cout << "Etape " << etape++
       << ": Afficher l'aire du canevas" << endl;
  cout << "\t* Aire du canevas: " << c.aire() << endl;
}; // }}}

// takes an int pointer and increments it, prints the message: "Step i: msg\n"
void step(string msg, int *i) {
    cout << "Étape " << *i << ": " << msg << endl;
    (*i)++;
}

// Deuxieme application {{{
void Tests::tests_application_cas_02() {
  cout << "TESTS APPLICATION (CAS 02)" << endl;
  // Mise en place
  Canevas c;
  int etape = 1;


  step("Activer la couche d'index 4", &etape);
  c.activerCouche(4);

  step("Ajouter les formes suivantes au canevas:", &etape);
  cout << "\t- Un cercle    (x= 1, y= 2, rayon=1/sqrt(pi) )\n"
       << "\t- Un rectangle (x= 3, y= 4, largeur=3, hauteur=4)\n"
       << "\t- Un carré     (x=-1, y=-1, cote=2)\n";
  c.ajouterForme(new Cercle(1, 2, 1/sqrt(M_PI)));
  c.ajouterForme(new Rectangle(3, 4, 3, 4));
  c.ajouterForme(new Carre(-1, -1, 2));

  step("Afficher le canevas", &etape);
  c.afficher(cout);

  step("Imprimer l'aire du canevas (doit etre egale a 1+12+4 soit 17)", &etape);
  cout << "\t* Aire du canevas: " << c.aire() << endl;

  step("Activer la couche d'index 3", &etape);
  c.activerCouche(3);

  step("Ajouter les formes par défaut au canevas. Soit:", &etape);
  cout << "\t- Un cercle    (x=0, y=0, rayon=1)\n"
       << "\t- Un rectangle (x=0, y=0, largeur=1, hauteur=1)\n"
       << "\t- Un carre     (x=0, y=0, cote=1)\n";
  c.ajouterForme(new Cercle());
  c.ajouterForme(new Rectangle());
  c.ajouterForme(new Carre());

  step("Afficher le canevas", &etape);
  c.afficher(cout);

  step("Translater la couche active de (1,1)", &etape);
  c.translater(1, 1);

  step("Afficher le canevas", &etape);
  c.afficher(cout);

  step("Supprimer la forme d'index 0 (la premiere)", &etape);
  c.retirerForme(0);

  step("Activer la couche d'index 4", &etape);
  c.activerCouche(4);

  step("Supprimer la forme d'index 2 (la dernière)", &etape);
  c.retirerForme(2);

  step("Afficher le canevas", &etape);
  c.afficher(cout);

  step("Initialiser la couche d'index 4", &etape);
  c.reinitialiserCouche(4);

  step("Afficher le canevas", &etape);
  c.afficher(cout);

  step("Imprimer l'aire du canevas", &etape);
  cout << "\t* Aire du canevas: " << c.aire() << endl;

  step("Réinitialiser le canevas", &etape);
  c.reinitialiser();

  step("Afficher le canevas", &etape);
  c.afficher(cout);

}; // }}}
