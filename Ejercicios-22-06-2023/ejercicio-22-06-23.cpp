#include <iostream>
#include <string>
#include <array>

using namespace std;

//CARMEN SÁNCHEZ HERNÁNDEZ 

void OrdenarEnInverso(array<string, 5> palabrasInversas) { 
    for (int i{ 4 }; i >= 0; i--) {
        cout << palabrasInversas[i] << "\n";
    }
}

void OrdenarAlfabeticamente(array<string, 5> palabrasEnOrden) {
    for (int i{ 0 }; i < palabrasEnOrden.size(); i++) {
        //if (palabrasEnOrden[i] == ) {           }
    }
}

void OrdenarAlfabeticamenteAlReves(array<string, 5> palabrasOrdenadasAlReves) {

}

void encontrarPalabraMasLarga(const array<string, 5> & palabras, int indice, string& palabraMasLarga) {
    if (indice >= palabras.size()) { 
        return;
    }
    if (palabras[indice].size() > palabraMasLarga.size()) {
        palabraMasLarga = palabras[indice];
    }
    return encontrarPalabraMasLarga(palabras, indice + 1, palabraMasLarga);
}

void encontrarPalabraMasCorta(const array<string, 5>& palabras, int indice, string& palabraMasCorta) {
    if (indice >= palabras.size()) {
        return;
    }
    if (palabras[indice].size() < palabraMasCorta.size()) {
        palabraMasCorta = palabras[indice];
    }
    encontrarPalabraMasCorta(palabras, indice + 1, palabraMasCorta);
}

bool esPalindroma(const string palabra, int inicio, int final) {
    if (inicio == final) {
        return true;
    }
    if (palabra[inicio] != palabra[final]) {
        return false;
    }
    return esPalindroma(palabra, inicio + 1, final - 1);
}

int main() {

    array<string, 5> palabras{}; 
    //array<string, 5> palabras{ "reconocer", "romance", "somos", "atar", "roma" };

    cout << "Ingrese 5 palabras:\n"; 
    for (int i{ 0 }; i < 5; i++) { 
        string palabraPedida; 
        cin >> palabraPedida; 
        palabras[i] = palabraPedida; 
    }
    
    cout << "Las palabras en inverso son: \n";
    OrdenarEnInverso(palabras);

    cout << "Palabras ordenadas alfabeticamente: \n";
    OrdenarAlfabeticamente(palabras);

    cout << "Palabas ordenadas alfabeticamente al reves: \n";
    OrdenarAlfabeticamenteAlReves(palabras);

    cout << "\n";
    string palabraMasLarga = palabras[0];
    encontrarPalabraMasLarga(palabras, 0, palabraMasLarga);
    cout << "La palabra con el mayor numero de letras es: " << palabraMasLarga << "\n";

    string palabraMasCorta = palabras[0];
    encontrarPalabraMasCorta(palabras, 0, palabraMasCorta);
    cout << "La palabra con el menor numero de letras es: " << palabraMasCorta << "\n";
    
    cout << "\n";

    for (const string& palabra : palabras) {
        if (esPalindroma(palabra, 0, palabra.size() - 1)) {
            cout << palabra << " es un palindromo." << "\n";
        }
        else {
            cout << palabra << " no es un palindromo. " << "\n";
        }
    }

    return 0;

}

