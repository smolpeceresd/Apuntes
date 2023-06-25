#include <iostream>
#include <array>
#include <set> //ORDENA DE MENOR A MAYOR!!! 

using namespace std;

//CARMEN SÁNCHEZ HERNÁNDEZ 

int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

bool esFibonacci(int numero) {
    int num1{ 0 };
    int num2{ 1 };

    while (numero > num2) {
        int resultado = num2;
        num2 = num2 + num1;
        num1 = resultado;
    }
    return num2 == numero;
}

int main() {
    
    //numeros{8, 1, 2, 5, 9};  

    array<int, 5> numeros{}; 
    set<int> numerosOrdenados;
    cout << "Ingrese 5 numeros: \n";
    for (int i{ 0 }; i < 5; i++) {
        int numerosPedidos;  
        cin >> numerosPedidos; 
        numeros[i] = numerosPedidos;
        numerosOrdenados.insert(numerosPedidos); 
    }

    cout << "Los numeros ordenados de MENOR A MAYOR: \n";
    for (int num : numerosOrdenados) {
        cout << "  " << num << "\n";
    }

    cout << "Los numeros ordenador de MAYOR A MENOR: \n";
    array<int, 5> numerosOrdenadorAlReves{};
    int counter{ 4 };
    for (const int &num : numerosOrdenados) {
        numerosOrdenadorAlReves.at(counter) = num;
        counter--;
    }

    for (const int& elem : numerosOrdenadorAlReves) {
        cout << " " << elem << "\n";
    }

    cout << "\n El factorial de los numeros: \n";
    for (int num : numerosOrdenados) { 
        int factorialNumero = factorial(num);
        cout << num << "! = " << factorialNumero << "\n";
    }

    cout << "Numeros pertenecientes a la serie de Fibonacci: \n";
    for (int num : numerosOrdenados) { 
        if (esFibonacci(num)) { 
            cout << num << " " << "pertenece a la serie de Fibonacci" << "\n"; 
        }
        else {
            cout << num << " " << "no pertenece a la serie de Fibonacci" << ""; 
        }
    }

    cout << "\n\n";

    return 0;
}

