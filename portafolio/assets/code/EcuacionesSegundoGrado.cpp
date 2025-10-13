#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cout << "Ecuacion cuadratica (ax^2 + bx + c = 0)\n";
    cout << "Ingrese a: "; cin >> a;
    cout << "Ingrese b: "; cin >> b;
    cout << "Ingrese c: "; cin >> c;

    if (a == 0.0) {
        // No es cuadrática
        if (b == 0.0) {
            if (c == 0.0)
                cout << "Infinitas soluciones (0 = 0)\n";
            else
                cout << "No tiene solucion (ecuacion inconsistente)\n";
        }
        else {
            double x = -c / b;
            cout << "Ecuacion lineal. Solucion: x = " << x << endl;
        }
    }
    else {
        double D = b*b - 4.0*a*c; // discriminante
        if (D > 0.0) {
            double x1 = (-b + sqrt(D)) / (2.0*a);
            double x2 = (-b - sqrt(D)) / (2.0*a);
            cout << "Dos soluciones reales:\n";
            cout << "x1 = " << x1 << "\n";
            cout << "x2 = " << x2 << "\n";
        }
        else if (D == 0.0) {
            double x = -b / (2.0*a);
            cout << "Una solucion real doble: x = " << x << "\n";
        }
        else { // D < 0
            double realPart = -b / (2.0*a);
            double imagPart = sqrt(-D) / (2.0*a);
            cout << "Raices complejas:\n";
            cout << "x1 = " << realPart << " + " << imagPart << "i\n";
            cout << "x2 = " << realPart << " - " << imagPart << "i\n";
        }
    }

    return 0;
}