#include <iostream>
#include <cmath>
#include "Montagne.h"
#include "Vecteur2D.h"
#include "Champpotentiel.h"

using namespace std;

double Montagne::altitude(double x, double y) const{

    if ((h*exp(-(((x-x0)*(x-x0))/(2*sigma_x*sigma_x))-((y-y0)*(y-y0))/(2*sigma_y*sigma_y)))<0.5){
        return 0;
    }else{
        return h*exp(-(((x-x0)*(x-x0))/(2*sigma_x*sigma_x))-((y-y0)*(y-y0))/(2*sigma_y*sigma_y));
    }
}

void Montagne::affiche(double a, double b){
    for (int i = 0; i <a; ++i) {

        for (int j = 0; j <b; ++j) {
            cout<<i<<" "<<j<<" "<<altitude(i,j)<<endl;
        }
        cout<<endl;
    }
}