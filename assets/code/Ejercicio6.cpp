#include <iostream>
using namespace std;

int mcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a == 0) return b;
    if (b == 0) return a;
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int mcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    int g = mcd(a,b);
    return (a / g) * b;
}

int main() {
    int x, y;
    cout << "Ingrese un numero entero: ";
    cin >> x;
    cout << "Ingrese otro numero entero: ";
    cin >> y;
    cout << "MCD (Maximo comun divisor) = " << mcd(x,y) << "\n";
    cout << "MCM (Minimo comun multiplo) = " << mcm(x,y) << "\n";
    return 0;
}
