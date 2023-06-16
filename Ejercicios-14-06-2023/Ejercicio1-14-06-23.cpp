#include <iostream>
#include <array>
#include <vector>

//CARMEN SÁNCHEZ HERNÁNDEZ

using namespace std;

/*
 ***** RECURSIVIDAD *****
 funcion1(parametros) {
    if caso de exito
        return( );
    else
        llamada recurisva a la funcion 'funcion1'(parametros);
 }
 */

//suma de todos los numeros del conjunto 
float suma (float numero, vector<float> conjunto, int index) {
    if (index == conjunto.size() - 1) { 
        return conjunto.at(index) + numero; 
    }
    else { 
        float resultado = numero + conjunto.at(index); 
        return suma(resultado, conjunto, index + 1);
    }
}

//resta de todos los numeros del conjunto 
float resta(float numero, vector<float> conjunto, int index) {
    if (index == conjunto.size() - 1) {
        return numero - conjunto.at(index);
    }
    else {
        float resultado = numero - conjunto.at(index);
        return resta(resultado, conjunto, index + 1);
    }
}

//obtener numero maximo de todos los numeros del conjunto 
float obtenerMaximo(const vector<float>& conjunto, int index, float maximo) {
    if (index == conjunto.size()) {
        return maximo;
    }
    else {
        if (conjunto[index] > maximo) {
            maximo = conjunto[index];
        }
        return obtenerMaximo(conjunto, index + 1, maximo);
    }
}

//obtener numero minimo de todos los numeros del conjunto 
float obtenerMinimo(const vector<float>& conjunto, int index, float minimo) {
    if (index == conjunto.size()) {
        return minimo;
    }
    else {
        if (conjunto[index] < minimo) { 
            minimo = conjunto[index]; 
        }
        return obtenerMinimo(conjunto, index + 1, minimo);
    }
}

int main() {  

    //los conjuntos: 
    vector<float> conjunto1{1.1, 2.2, 3.3};
    vector<float> conjunto2{3.3, 5.5};
    vector<float> conjunto3{1.1, 1.1, 1.1, 1.1};

    array<vector<float>, 3> conjuntoTotal {conjunto1, conjunto2, conjunto3};

    //CONJUNTO 1
    cout << "\n Conjunto 1 {1.1, 2.2, 3.3 } ";
    cout << "\n La suma del conjunto 1: " << suma(0.0, conjunto1, 0); 
    cout << "\n La resta del conjunto 1: " << resta(1.1, conjunto1, 1); 
    cout << "\n El minimo del conjunto 1: " << obtenerMinimo(conjunto1, 0, conjunto1[0]);
    cout << "\n El maximo del conjunto 1: " << obtenerMaximo(conjunto1, 0, conjunto1[0]);
    
    cout << "\n\n";

    //CONJUNTO 2
    cout << "\n Conjunto 2 {3.3, 5.5} "; 
    cout << "\n La suma del conjunto 2: " << suma(0.0, conjunto2, 0);  
    cout << "\n La resta del conjunto 2: " << resta(3.3, conjunto2, 1); 
    cout << "\n El minimo del conjunto 2: " << obtenerMinimo(conjunto2, 0, conjunto2[0]);
    cout << "\n El maximo del conjunto 2: " << obtenerMaximo(conjunto2, 0, conjunto2[0]);
    
    cout << "\n\n"; 

    //CONJUNTO 3
    cout << "\n Conjunto 3 {1.1, 1.1, 1.1, 1.1} ";
    cout << "\n La suma del conjunto 3: " << suma(0.0, conjunto3, 0);
    cout << "\n La resta del conjunto 3: " << resta(1.1, conjunto3, 1);
    cout << "\n El minimo del conjunto 3: " << obtenerMinimo(conjunto3, 0, conjunto3[0]);
    cout << "\n El maximo del conjunto 3: " << obtenerMaximo(conjunto3, 0, conjunto3[0]); 
    
    cout << "\n\n";

    return 0; 

}
