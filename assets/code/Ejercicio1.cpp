#include <iostream>
using namespace std;

void usandoWhile(int dias) {
    int anios = 0, meses = 0, semanas = 0;
    int d = dias;
    while (d >= 365) { 
        anios++; d -= 365;
    }
    while (d >= 30) {
        meses++; d -= 30; 
    }
    while (d >= 7) { 
        semanas++; d -= 7; 
    }
    cout << "[while] " << dias << " dias = " << anios << " anios, " << meses << " meses, " 
         << semanas << " semanas, " << d << " dias\n";
}

void usandoDoWhile(int dias) {
    int anios = 0, meses = 0, semanas = 0;
    int d = dias;
    if (d >= 365) {
        do { 
            anios++; d -= 365; 
        } while (d >= 365);
    }
    if (d >= 30) {
        do { 
            meses++; d -= 30; 
        } while (d >= 30);
    }
    if (d >= 7) {
        do { 
            semanas++; d -= 7; 
        } while (d >= 7);
    }
    cout << "[do-while] " << dias << " dias = " << anios << " anios, " << meses << " meses, " 
         << semanas << " semanas, " << d << " dias\n";
}

int main() {
    int dias;
    cout << "Ingrese numero de dias: ";
    cin >> dias;
    usandoWhile(dias);
    usandoDoWhile(dias);
    return 0;
}
