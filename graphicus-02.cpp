/********
 * Fichier: graphicus-02.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/
#include "tests.h"

using namespace std;

int main() {
  Tests tests;

  /* tests.tests_unitaires(); */
  tests.tests_application_cas_01();

  return 0;
}

