#include <iostream>
#include <string>
using namespace std;

char minuscula(char c) {
    if (c >= 'A' && c <= 'Z') return (char)(c - 'A' + 'a');
    return c;
}

bool letra_o_num(char c) {
    if (c >= '0' && c <= '9') return true;
    if (c >= 'A' && c <= 'Z') return true;
    if (c >= 'a' && c <= 'z') return true;
    return false;
}

int main() {
    string line;
    cout << "Ingrese texto (puede tener espacios):\n";
    getline(cin, line);
    if (line.size() == 0) {
        getline(cin, line);
    }

    string clean = "";
    for (int i = 0; i < line.size(); ++i) {
        char c = line[i];
        if (letra_o_num(c)) {
            clean.push_back(minuscula(c));
        }
    }

    int i = 0;
    int j = (int)clean.size() - 1;
    bool palindromo = true;
    while (i < j) {
        if (clean[i] != clean[j]) {
            palindromo = false; 
            break; 
        }
        ++i; --j;
    }

    if (palindromo) cout << "Verdadero: es palindromo\n";
    else cout << "Falso: no es palindromo\n";

    return 0;
}
