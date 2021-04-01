#include <iostream>
#include "Vecteur2D.h"
#include "Montagne.h"
#include "Champpotentiel.h"
using namespace std;


int main() {
    Montagne Himalaya(3, 3, 0.4, 3, 3);
    Champ_potentiel CP(30,30,30,20/29);
    CP.set_x_y_z();
    CP.initialise(15,Himalaya);
    CP.calcule_laplaciens();
    CP.affichage();

    return 0;
}
