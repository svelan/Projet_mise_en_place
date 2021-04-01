#pragma once
#include "Vecteur2D.h"
#include "Montagne.h"
#include <vector>

class Potentiel{
private:
    Vecteur2D potentiel;
    Vecteur2D laplacien;

public:
    Potentiel(Vecteur2D pot, Vecteur2D lap)
            : potentiel(pot), laplacien(lap){}
    Vecteur2D get_potentiel() const {return potentiel;}
    Vecteur2D get_laplacien() const {return laplacien;}
};

class Champ_potentiel {
private:
    // A, le champ de vecteurs potentiel
    std::vector<std::vector<std::vector<Potentiel>>> collection3D;
    unsigned int Nx, Ny, Nz;
    std::vector<double> X, Y, Z;
    double lambda;

public:
    //Constructeur par défaut si nécessaire + permis d'être initialisé
    //On choisit d'initialiser le nombre de cubes dans chaque côté
    //et le lambda, puis on exprimes les Li en fonction des Ni et lambda;

    Champ_potentiel(unsigned int Nx = 0, unsigned int Ny = 0.0, unsigned int Nz = 0.0,
                    double lambda = 0.0): Nx(Nx), Ny(Ny), Nz(Nz), lambda(lambda){}

    // petites méthodes initialisant les Lx,Ly,Lz et renvoyant leur valeur
    double set_Lx();
    double set_Ly();
    double set_Lz();

    //initialise
    void initialise(double const& v_infini, Montagne const& everest);

    // tableau pour classer les xi/yj/zk
    void set_x_y_z();
    void calcule_laplaciens();

    // méthode qui affiche les vecteurs potentiels et les laplaciens
    void affichage();


};