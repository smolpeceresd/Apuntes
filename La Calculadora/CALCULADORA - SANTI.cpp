#include <iostream>
#include <math.h> 
#include <string>

using namespace std;

//CARMEN SÁNCHEZ HERNÁNDEZ 

int menu();
float sumar(float a, float b);
float restar(float a, float b);
float multiplicar(float a, float b);
float dividir(float a, float b);
float realizarOperacion(float operando1, float operando2, char operador);
float evaluarExpresion(const string& expresion);

int menu() {
	int respuesta;
	do {
		cout << " \n -------- CALCULADORA -------- " << "\n";
		cout << "1. CALCULAR EXPRESION: " << "\n";
		cout << "0. SALIR: " << "\n";
		cout << "Ingrese una opcion: ";
		cin >> respuesta;

		if (respuesta != 1 && respuesta != 0)
			cout << "\n\n\t La opcion no es valida. Por favor, vuelva a seleccionar otra opcion. ";
	} while (respuesta != 1 && respuesta != 0);

	return respuesta;
}

float sumar(float a, float b) {
	return a + b;
}

float restar(float a, float b) {
	return a - b;
}

float multiplicar(float a, float b) {
	return a * b;
}

float dividir(float a, float b) {
	if (b == 0) {
		throw string {"No es posible una operacion dividida entre 0. "};
	}
	return a / b;
}

float realizarOperacion(float operando1, float operando2, char operador) {
	switch (operador) {
	case '+':
		return sumar(operando1, operando2);
	case '-':
		return restar(operando1, operando2);
	case '*':
		return multiplicar(operando1, operando2);
	case '/':
		return dividir(operando1, operando2);
	default:
		throw runtime_error("Operador invalido.");
	}
}

float evaluarExpresion(const string& expresion) { 
	float resultado = 0.0; 
	float operando = 0.0;
	char operador = '+';
	bool siguienteOperador = false;

	for (char c : expresion) {
		if (c == '+' || c == '-' || c == '*' || c == '/') { //si 'c' es igual a los simbolos... 
			resultado = realizarOperacion(resultado, operando, operador); 
			operador = c; 
			operando = 0.0; 
			siguienteOperador = true;
		}
		else if (c >= '0' && c <= '9') { //se verigfica si el 'c' es un numero...
			operando = operando * 10 + (c - '0');
		}
		else if (c == '.') { //si encuentra un '.', el numero es decimal

		}
		else if (c == '=') { //si el caracter 'c' es un '=',...
			resultado = realizarOperacion(resultado, operando, operador); 
			operando = 0.0;
			siguienteOperador = false; 
		}
		else { //sino se cumple lo anterior...
			throw runtime_error("Caracter invalido en la expresion.");
		}
	}

	if (siguienteOperador) { //se espera otro operador,...
		resultado = realizarOperacion(resultado, operando, operador); 
	}

	return resultado;

}

int main() {
	int opcion;
	string expresion{};

	do {
		opcion = menu();

		if (opcion == 1) {
			cout << "Ingrese una expresion matematica: ";
			cin >> expresion;
			try {
				float resultado = evaluarExpresion(expresion);
				cout << "Resultado: " << resultado << "\n";
			}
			catch (const string& e) {
				cout << "Error: " << e << "\n";
			}
		}
	} while (opcion != 0);
	
	cout << "Saliendo..." << "\n";

	return 0;

}
