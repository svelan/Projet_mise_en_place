#include <iostream>
#include "Champpotentiel.h"
#include "Vecteur2D.h"
#include <vector>
#include "Montagne.h"
using namespace std;

double Champ_potentiel:: set_Lx(){
    double Lx;
    Lx = lambda * (Nx-1);
    return Lx;
}
double Champ_potentiel:: set_Ly(){
    double Ly;
    Ly = lambda * (Ny-1);
    return Ly;
}
double Champ_potentiel:: set_Lz(){
    double Lz;
    Lz = lambda * (Nz-1);
    return Lz;
}


// méthode initialisant le tableau contenant les coordonnées xi yj et zk
void Champ_potentiel:: set_x_y_z(){

    for(int i(0); i < Nx; ++i){
        X.push_back(i*lambda);
    }
    for(int j(0); j < Ny; ++j){
        Y.push_back(j*lambda - (lambda*(Ny-1))/2);
    }
    for(int k(0); k < Nz; ++k){
        Z.push_back(k*lambda);
    }
}
// méthode initialisant le potentiel vecteur en tout point (xi,yj,zk)
void Champ_potentiel:: initialise(double const& v_infini, Montagne const& M) {
    Vecteur2D laplacien;
    Vecteur2D a(2.3,4);
     //directement initialisé au vecteur nul par le constructeur
    //initialisation du potentiel vecteur en tout point
    for (int i(0); i < Nx; ++i){
        for (int j(0); j < Ny; ++j){
            for (int k(0); k < Nz; ++k){
                cout<<"ok"<<endl;
                cout<<Nx<<endl;
                cout<<Ny<<endl;
                cout<<Nz<<endl;
                cout<<collection3D[i][j][k].get_potentiel()<<endl;
                //collection3D[i][j][k].get_potentiel().set_coord((-v_infini/2) * Z[k],(-v_infini/2) * Y[j]);
                //collection3D[i][j][k].get_laplacien().set_coord(0,0);
                //if((Z[k] <= M.altitude(X[i], Y[j]) and (i != 0) and (i != Nx - 1) and (j != 0) and (Ny - 1 != j))){
                  //  collection3D[i][j][k].get_potentiel().set_coord(0,0);
                //}
            }
        }
    }

}


void Champ_potentiel:: calcule_laplaciens(){
    for (int i(1); i < Nx; ++i){
        for (int j(1); j < Ny; ++j){
            for (int k(1); k < Nz; ++k){
                collection3D[i][j][k].get_laplacien() = collection3D[i-1][j][k].get_potentiel()+ collection3D[i][j-1][k].get_potentiel()
                                                        + collection3D[i][j][k-1].get_potentiel() - 6 * collection3D[i][j][k].get_potentiel()
                                                        + collection3D[i+1][j][k].get_potentiel() + collection3D[i][j+1][k].get_potentiel()
                                                        + collection3D[i][j][k+1].get_potentiel();
            }
        }
    }
}
// méthode affichage des vecteurs potentiels et des laplaciens
void Champ_potentiel:: affichage(){

    for (int i(0); i < Nx; ++i){
        for (int j(0); j < Ny; ++j){
            for (int k(0); k < Nz; ++k){
                cout << i << " " << j << " " << k << " "<<endl;
                //cout << collection3D[i][j][k].get_potentiel() << collection3D[i][j][k].get_laplacien() << endl;

            }
        }
    }
}
