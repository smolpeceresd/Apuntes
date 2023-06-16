#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> encontrarCadena(const string &cadena, const string &subcadena) { 
    vector<string> palabrasComunes;
    string palabra_buscar;

    for (auto elem: palabra_buscar) {
        cout <<"\n palabra: " << elem;
    }

    return palabrasComunes;

}

int main() {

    string texto{"pepe toma un te \n"};
    string subcadena{"el toma te \n"};

    cout << texto; 
    cout << subcadena; 

    vector<string> encontrado = encontrarCadena(texto, subcadena);

    return 0;
    
}

