#pragma once

//définitions et classe

class Vecteur2D{
private:
    double x;
    double y;

public:
    double get_x() const{
        return x;
    }
    double get_y() const{
        return y;
    }
    void set_coord(double x1, double y1);

    bool compare(Vecteur2D v1) const;

    Vecteur2D addition(Vecteur2D autre);
    Vecteur2D soustraction(Vecteur2D autre);
    Vecteur2D oppose() const;
    Vecteur2D mult(double scal) const;
    double prod_scal(Vecteur2D autre) const;
    Vecteur2D unitaire();
    Vecteur2D(double x, double y);
    Vecteur2D();
    Vecteur2D(Vecteur2D const& autre);

    void affiche(std::ostream& sortie) const;

    bool operator==(const Vecteur2D& v);

    Vecteur2D& operator+=(const Vecteur2D& v1);
    Vecteur2D& operator-=(const Vecteur2D& v1);
    Vecteur2D& operator*=(double a);

    double norme() const;
    double norme2() const;

};

//définition des opérateurs en dehors de la classe Vecteur2D;

std::ostream& operator<<(std::ostream&, Vecteur2D const&);

const Vecteur2D operator*(double, const Vecteur2D&);
const Vecteur2D operator*(Vecteur2D, double);
const Vecteur2D operator+(Vecteur2D, const Vecteur2D&);
const Vecteur2D operator-(Vecteur2D, const Vecteur2D&);
const Vecteur2D operator-(Vecteur2D);
const Vecteur2D operator~(Vecteur2D);

double operator*(const Vecteur2D& un, const Vecteur2D& deux);
