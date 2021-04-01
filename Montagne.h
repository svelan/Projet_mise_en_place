#ifndef MONTAGNES_MONTAGNE_H
#define MONTAGNES_MONTAGNE_H
#pragma once

class Montagne {
private:
    double x0;
    double y0;
    double h;
    double sigma_x;
    double sigma_y;
public:
    double altitude(double x, double y) const;

    Montagne(double x_0=0.0, double y_0=0.0, double h=0.0, double et_x=0.0, double et_y=0.0)
            : x0(x_0), y0(y_0),h(h), sigma_x(et_x), sigma_y(et_y){
    }
    void affiche(double a, double b);
};


#endif //MONTAGNES_MONTAGNE_H
