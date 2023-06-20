#include <iostream>
#include <string>
#include <vector>

using namespace std;

//CARMEN SÁNCHEZ HERNÁNDEZ 

int cantidadLetras(const string& texto, vector<char>& letra_a_guardar) {
	int contador{};
	for (char letra : texto) {
		bool letraExistente = false;
		for (char letra_estudio : letra_a_guardar) {
			if (letra_estudio == letra) {
				letraExistente = true;
				contador++;
			}
		}

		if (!letraExistente) {
			letra_a_guardar.push_back(letra);
			contador++;
		}
	}
	return contador;
}

int cantidadPalabras(const string& texto) {
	int contador{};
	bool palabraExistente = false;
	for (int i{ 0 }; i < texto.size(); i++) { 
		if (texto[i] != ' ' && texto[i] != '.') {
			if (!palabraExistente) {
				contador++;
				palabraExistente = true;
			}
		}
		else {
			palabraExistente = false;
		}
	}

	return contador;
}

string encontrarPalabraMasLarga(string texto, int longitud) {
	char espacio = texto.find(' ');
	string palabra{};

	int longitudPalabra = palabra.length();
	if (longitudPalabra > longitud) {
		longitud = longitudPalabra;
		return palabra;
	}
	else {
		return encontrarPalabraMasLarga(texto, longitud);
	}
}

string encontrarPalabraMasCorta(string texto, int longitud) {
	char espacio = texto.find(' '); 
	string palabra{}; 

	int longitudPalabra = palabra.length();
	if (longitudPalabra < longitud) {
		longitud = longitudPalabra; 
		return palabra; 
	}
	else {
		return encontrarPalabraMasCorta(texto, longitud);
	}
}

int main() {

	string texto{ "el rey de constantinopla esta constantinoplizado. consta que constanza, no lo pudo desconstantinoplizar. el desconstantinoplizador que desconstantinoplizare al rey de constantinopla buen desconstantinoplizador sera." };
	cout << texto;

	vector<char> letras_guardadas; 
	int longitud{}; 

	int letras_repetidas = cantidadLetras(texto, letras_guardadas); 
	int palabras_repetidas = cantidadPalabras(texto); 

	cout << "\n" << letras_repetidas;
	cout << "\n" << palabras_repetidas;

	string palabra_mas_larga = encontrarPalabraMasLarga(texto, longitud); 
	string palabra_mas_corta = encontrarPalabraMasCorta(texto, longitud);
	
	cout << "\n Palabra mas larga : " << palabra_mas_larga;
	cout << "\n Palabra mas corta : " << palabra_mas_corta;

	return 0;

}
