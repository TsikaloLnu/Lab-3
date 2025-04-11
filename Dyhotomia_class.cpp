#include "Dyhotomia_class.h"

Dyhotomia_class::Dyhotomia_class(){}
Dyhotomia_class::~Dyhotomia_class(){}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b){
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance (double vol_eps){
    eps = vol_eps; 
}

double Dyhotomia_class::f(double x){
    return exp(x) + log(x) - 10 * x;
}

int Dyhotomia_class::count(double &x){
    int iterat = 0;

    double a_local = a;
    double b_local = b;

    while (fabs(b_local - a_local) > eps){
        double c = (a_local + b_local ) / 2.0; // середина відрізка
        double fa = f(a_local); // лівий кінець ф-ції
        double fc = f(c);   // середина ф-ції

        if (fa * fc < 0){
            b_local = c;
        }else{
            a_local = c;
        }

        ++ iterat;

        x = (a_local + b_local) / 2.0;
        return iterat;

    }

    return 0;
}


