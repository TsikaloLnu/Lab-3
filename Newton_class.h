#ifndef NEWTON_CLASS_H
#define NEWTON_CLASS_N

#include <cmath>
#include <iostream>

using namespace std;

class Newton_class {
    private:
        double x0; // початкове наближення
        double eps; // точність


    public:
        Newton_class();
        ~Newton_class();

        double f( double x); // функція 
        double df( double x); // похідна від функції

        void setStart (double start);
        void setTolerance (double vol_eps);
        int count (double &x);
};

#endif