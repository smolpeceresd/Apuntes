#include <iostream>
#include <string>
#include <vector>

using namespace std;

//CARMEN SÁNCHEZ HERNÁNDEZ 

struct Palabra {
    string palabra;
    int vecesRepet;
};

int main() {

    string palabra;
    vector<Palabra> guardarPalabra {};

    do {
        cout << "Ingresa una palabra (escribe 'Salir' para terminar): "; 
        cin >> palabra; 

        if (palabra != "Salir") {
            // Buscar si la palabra ya existe en el vector 'guardarPalabra'
            bool palabraExistente = false; 
            for (auto& palabra_estudio : guardarPalabra) {
                if (palabra_estudio.palabra == palabra) { 
                    palabra_estudio.vecesRepet++; 
                    palabraExistente = true;
                    break;
                }
            }

            // Si la palabra no existe, agregarla al vector
            if (!palabraExistente) {
                //instanciar: 
                Palabra newPalabra; 
                newPalabra.palabra = palabra; 
                newPalabra.vecesRepet = 1; 
                //guardamos en el vector
                guardarPalabra.push_back(newPalabra);
            }
        }
    } while (palabra != "Salir");

    cout << "Palabras - Repeticiones: " << "\n";
    for (const auto& palabraIngresada : guardarPalabra) {
        cout << "Palabra: " << palabraIngresada.palabra << " - Repeticiones: " << palabraIngresada.vecesRepet << "\n";
    }

    return 0;

}