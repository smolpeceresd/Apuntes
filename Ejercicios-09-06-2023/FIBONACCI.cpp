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

//Se debe realizar la función de Fibonazzi de forma recursiva
int fibonacci(unsigned int N) {
    if (N <= 1) {
        return N;
    }
    return fibonacci(N - 1) + fibonacci(N - 2);
}

int main() {

    int opcion = menu();

    while (opcion != 0) {
        int n; //el numero de elementos que va a imprimir
        cout << " Ingrese un numero: ";
        cin >> n;
        switch (opcion) {
        case 1:
            for (int i{ 0 }; i <= n; i++) {
                cout << fibonacci(i) << " ";
            }
            cout << "\n";
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