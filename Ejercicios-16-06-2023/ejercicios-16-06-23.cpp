#include <iostream>
#include <string>
#include <vector>

using namespace std;

//CARMEN SÁNCHEZ HERNÁNDEZ 

//ejercicio2
vector<char> encontrarLetra(const string &texto1, const string &texto2) {
    vector<char> letraComun;
    char letra_a_buscar{};
    bool letraExistente = false;

    for (char letra1 : texto2) { 
        for (char letra2 : texto1) {
            if (letra1 == letra2) {
                letraComun.push_back(letra1);
            }
            if (letra_a_buscar == letra1) { 
                letraExistente = true; 
            }
        }
    }

    return letraComun;
}

int main() {

    string texto{"\n una puerta \n"};
    string subcadena{"\n un perro come \n"};

    cout << texto; 
    cout << subcadena;

    vector<char> encontrado = encontrarLetra(texto, subcadena);

    for (auto final : encontrado) {
        cout << final << "   "; 
    }

    return 0;
    
}
