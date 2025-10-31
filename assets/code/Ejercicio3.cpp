#include <iostream>
#include <string>
using namespace std;

char minuscula(char c) {
    if (c >= 'A' && c <= 'Z') return (char)(c - 'A' + 'a');
    return c;
}

int main() {
    string s1, s2;
    cout << "Ingrese la primera palabra (sin espacios): ";
    cin >> s1;
    cout << "Ingrese la segunda palabra (sin espacios): ";
    cin >> s2;

    if (s1 == s2) {
        cout << "Falso: son iguales, no anagramas\n";
        return 0;
    }

    if (s1.size() != s2.size()) {
        cout << "Falso: distinta longitud\n";
        return 0;
    }

    for (int i = 0; i < s1.size(); ++i) s1[i] = minuscula(s1[i]);
    for (int i = 0; i < s2.size(); ++i) s2[i] = minuscula(s2[i]);

    for (int i = 0; i < s1.size(); ++i) {
        char c = s1[i];
        bool encontrado = false;
        for (int j = 0; j < s2.size(); ++j) {
            if (s2[j] == c) {
                s2[j] = '#'; // marcar como usado
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "Falso: no son anagramas\n";
            return 0;
        }
    }

    cout << "Verdadero: son anagramas\n";
    return 0;
}
