#include "Newton_class.h"
#include <cmath>

Newton_class::Newton_class(){}
Newton_class::~Newton_class(){}

void Newton_class::setStart(double start){
    x0 = start;
}

void Newton_class::setTolerance(double vol_eps){
    eps = vol_eps;
}

double Newton_class::f(double x) {

    if (x <= 0) {
        cerr << "Помилка: логарифм визначений тільки для x > 0" << endl;
    }

    return exp(x) + log(x) - 10 * x;
}


double Newton_class::df(double x) {

    if (x <= 0) {
        cerr << "Помилка: похідна визначена тільки для x > 0" << endl;
        return NAN; 
    }

    return exp(x) + 1 / x - 10;
}

int Newton_class::count(double &x) {
    int iter = 0;
    int maxIter = 100;
    x = x0;

    while (iter < maxIter) {
        double dx = df(x);

        // Перевірка на NaN
        if (isnan(x) || isnan(f(x)) || isnan(dx)) {
            cerr << "Помилка: значення x стало NaN на ітерації " << iter << endl;
            return -1;
        }

        // Перевірка на ділення на нуль
        if (fabs(dx) < 1e-12) {
            cerr << "Помилка: похідна занадто мала або нульова" << endl;
            return -1;
        }

        x = x - f(x) / dx;
        ++iter;

        if (fabs(f(x)) < eps) {
            return iter;
        }
    }

    cerr << "Перевищено кількість ітерацій (" << maxIter << ")." << endl;
    return maxIter;
}
