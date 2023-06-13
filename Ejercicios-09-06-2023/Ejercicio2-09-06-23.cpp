#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//CARMEN SÁNCHEZ HERNÁNDEZ 

//PRIMERA MANERA SIN .FIND()
void buscarSubCadenaSinFind(const string& texto, const string& subcadena) { 
    int contador{ 0 }; 
    int pos = subcadena.size();

    for (int i{ 0 }; i <= texto.size() - pos; i++) { //recorremos el texto con el bucle 
        bool encontrada = true; 
        for (int j{ 0 }; j < pos; j++) {
            if (tolower(texto[i + j]) != tolower(subcadena[j])) { //'tolower' para convertir las letras
                encontrada = false;
                break;
            }
        }
        if (encontrada) {
            cout << "\n Ocurrencia encontrada en la posicion: " << i << "\n";
            contador++;
        }
    }
    cout << "\n Numero total de ocurrencias: " << contador << "\n";
}

//SEGUNDA MANERA .FIND()
void buscarSubCadenaFind(const string& texto, const string& subcadena) {
    string texto_lower = texto;
    transform(texto_lower.begin(), texto_lower.end(), texto_lower.begin(), ::tolower); //para convertir las letras del texto 

    string subcadena_lower = subcadena;
    transform(subcadena_lower.begin(), subcadena_lower.end(), subcadena_lower.begin(), ::tolower); //para convertir las letras de la cadena que queremos 

    int posiciones = texto_lower.find(subcadena_lower); 
    int contador{ 0 }; 

    while (posiciones != -1) { 
        cout << "\n Ocurrencia encontrada en la posicion: " << posiciones << "\n";
        posiciones = texto_lower.find(subcadena_lower, posiciones + 1); 
        contador++; 
    }

    cout << "\n Numero total de ocurrencias: " << contador << "\n";
}

int main() {

    string texto = "El rey de Constantinopla esta constantinoplizado. Consta que Constanza, no lo pudo desconstantinoplizar. El desconstantinoplizador que desconstantinoplizare al rey de Constantinopla, buen desconstantinoplizador sera." ;
    string subcadena{};

    cout << texto << "\n\n";

    cout << "Ingrese la subcadena a buscar: " << "\n";
    getline(cin, subcadena); 

    //PRIMERA MANERA: 
    cout << "\n\n Ocurrencias sin find: " << "\n";
    buscarSubCadenaSinFind(texto, subcadena);

    //SEGUNDA MANERA:
    cout << "\n\n Ocurrencias con find: " << "\n";
    buscarSubCadenaFind(texto, subcadena); 
    
    return 0;

}
