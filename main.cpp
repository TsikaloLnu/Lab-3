#include "Dyhotomia_class.h"
#include "Newton_class.h"

int main(){

    setlocale(LC_ALL, "Ukrainian");

    cout << "Метод Дихотомії: " << endl;
    Dyhotomia_class * dyh = new Dyhotomia_class();
    dyh -> setVolumes(3, 4); // межі функції
    dyh -> setTolerance( 1e-6 ); // точність
    

    double root;
    int steps = dyh -> count(root);

    cout << "Знайдений корінь: x = " << root << endl;
    cout << "Кількість ітерацій: " << steps << endl;

    delete dyh;

    cout << "\nМетод Ньютона" << endl;
    Newton_class* newton = new Newton_class();
    newton -> setStart(3.0);
    newton -> setTolerance(1e-9);

    double root2;
    int steps2 = newton->count(root2); 
    
    cout << "Знайдений корінь: х = " << root2 << endl;
    cout << "Кількість ітерацій: " << steps2 << endl;

    delete newton;

    return 0;
}

