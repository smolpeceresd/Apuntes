#include <iostream>

using namespace std;

//CARMEN SÁNCHEZ HERNÁNDEZ

//ejercicio 1
int menu() {
	int respuesta;
	do {
		cout << "\n";
		cout << " -------- FIBONACCI -------- " << "\n";
		cout << "1. Serie Fibonacci: " << "\n";
		cout << "0. Salir. " << "\n";
		cout << "Ingrese una opcion: ";
		cin >> respuesta;

		if (respuesta != 1 && respuesta != 0)
			cout << "\n\n\t La opcion no es valida. Por favor, vuelva a seleccionar otra opcion. ";
	} while (respuesta != 1 && respuesta != 0);

	return respuesta;
}

//Se debe realizar la función de Fibonacci de forma recursiva
int fibonacci(int N) {
	if (N <= 1) {
		return N;
	}
	return fibonacci(N - 1) + fibonacci(N - 2);
}

void mostrarFibonacciRecursivo(int n, int i) {
	//'n' es el numero FINAL 
	if (n <= 0) {
		cout << "El numero ingresado debe ser mayor o igual a 0. ";
		return;
	}

	//'i' es el numero INICIAL
	if (i <= n) {
		cout << fibonacci(i) << " ";
		mostrarFibonacciRecursivo(n, i + 1);
	}
}

int main() {

	int opcion = menu();

	while (opcion != 0) {
		int n; //el numero de elementos que va a imprimir
		cout << " Ingrese un numero: ";
		cin >> n;
		switch (opcion) {
		case 1:
			mostrarFibonacciRecursivo(n - 1, 0);
			break;
		default:
			cout << "Opcion invalida. Intente nuevamente." << "\n";
			return -1;
		}

		opcion = menu();
	}

	system("cls");

	cout << "saliendo...";

	return 0;
}
