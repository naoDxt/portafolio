#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Ingrese un entero (decimal): ";
    cin >> n;

    if (n == 0) {
        cout << "Binario: 0\n";
        return 0;
    }

    bool negativo = false;
    if (n < 0) {
        negativo = true;
        n = -n;
    }

    string bits = "";
    while (n > 0) {
        int resto = n % 2;
        char bit;
        if (resto == 1) bit = '1';
        else bit = '0';
        bits = bits + bit;
        n = n / 2;
    }

    if (negativo) cout << "-";
    cout << "Binario: ";
    for (int i = (int)bits.size() - 1; i >= 0; --i) cout << bits[i];
    cout << "\n";
    return 0;
}
