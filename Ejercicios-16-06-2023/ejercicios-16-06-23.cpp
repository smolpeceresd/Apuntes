#include <iostream>
#include <string>
#include <vector>

using namespace std;

//CARMEN SÁNCHEZ HERNÁNDEZ 

//ejercicio2
vector<char> encontrarLetra(const string& texto2, const string& texto1) {
	vector<char> letraComun = {};

	for (char letra1 : texto2) { //recorremos texto 1
		for (char letra2 : texto1) { //recorremos todo el texto 2 con el char del 1
			if (letra1 == letra2) {// si coinciden...
				/*
	Si la letra no esta ya incluida en el vector -> introduzo , si lo esta -> paso
*/
				bool encontrada = false; 
				for (char letraEncontrada : letraComun) {//recorremos el vector 
					if (letra1 == letraEncontrada) {
						encontrada = true; //esta dentro del vector
                        //aqui estaba el fallo. no era dos '==', sino que habia que poner solo '='
					}
				}
				if (encontrada == false) {  
					letraComun.push_back(letra1); 
				}
			}
		}
	}

	return letraComun;
}

int main() {

	string texto{ "una puerta" };
	string texto2{ "un perro come" };

	cout << texto << "\n"; 
	cout << texto2 << "\n"; 

	vector<char> encontrado = encontrarLetra(texto, texto2);

	for (auto final : encontrado) {
		cout << "\n *" << final;
	}

	return 0;

}
