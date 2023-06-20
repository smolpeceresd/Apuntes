#include <iostream>
#include <array>
#include <set>
#include <vector>

//CARMEN SÁNCHEZ HERNÁNDEZ 

using namespace std;

bool esFibonacci(int numero) {
	int num1{ 0 };
	int num2{ 1 };

	while (numero > num2) {
		int resultado = num2;
		num2 = num2 + num1;
		num1 = resultado; 
	}
	return num2 = numero;
}

int generarNumeroAleatorio(int numInicial, int numFinal) {
	int num = rand() % 500; 
	return num;
}

void mostrarNumerosAleatorios() {
	vector<int> numerosAleatorios{}; 
	vector<int> numerosSerieFibonacci{};

	for (int i{ 0 }; i < 40; i++) {
		int num = generarNumeroAleatorio(1, 500);
		numerosAleatorios.push_back(num); 
		
		if (esFibonacci(num)) {
			numerosSerieFibonacci.push_back(num);
		}
	}

	cout << "Los numeros generados son: ";
	for (int numeroGenerado : numerosAleatorios) {
		cout << numeroGenerado << "\n";
	}

	cout << "Los numeros de la serie Fibonacci ordenados son: "; 
	for (int numFib : numerosSerieFibonacci) {
		cout << numFib << " " << "\n";
	}

}

int main() {

	cout << "\n numeros aleatorios: ";
	mostrarNumerosAleatorios();

	return 0;
}