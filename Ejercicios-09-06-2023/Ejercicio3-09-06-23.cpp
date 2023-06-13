#include <iostream>
#include <string>
#include <vector>

using namespace std;

//CARMEN SÁNCHEZ HERNÁNDEZ 

struct Letra {
    char letra;
    int vecesRepetLetra;
};

struct Palabra {
    string palabra;
    int vecesRepet;
    vector<Letra> letrasRepetidas;
};

//funcion para contar las letras de las palabras introducidas por el usuario
void contarLetras(const string& palabra, vector<Letra>& letra_a_guardar) {
    for (char c : palabra) {
        bool letraExistente = false; 
        for (auto& letra_estudio : letra_a_guardar) { 
            if (letra_estudio.letra == c) {  
                letra_estudio.vecesRepetLetra++; 
                letraExistente = true; 
                break;
            }
        }
        if (!letraExistente) {
            //instanciamos: 
            Letra newLetra; 
            newLetra.letra = c; 
            newLetra.vecesRepetLetra = 1; 
            //guardamos en el vector 'letra_a_guardar'
            letra_a_guardar.push_back(newLetra);  
        }
    }
}

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
                
                //llamada a la funcion de contar las letras para mirar sus repeticiones 
                contarLetras(palabra, newPalabra.letrasRepetidas);

                //guardamos en el vector
                guardarPalabra.push_back(newPalabra);

            }
        }
    } while (palabra != "Salir");

    cout << "Palabras - Repeticiones: " << "\n"; 
    for (const auto& palabraIngresada : guardarPalabra) { 
        cout << "Palabra: " << palabraIngresada.palabra << " - Repeticiones: " << palabraIngresada.vecesRepet << "\n"; 
        
        cout << "Letras - Repeticiones: " << "\n"; 
        for (const auto& letra : palabraIngresada.letrasRepetidas) {
            cout << "Letra: " << letra.letra << " - Repeticiones: " << letra.vecesRepetLetra << "\n"; 
        }
        cout << "\n"; 
    }

    return 0;

}
