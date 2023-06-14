#include <iostream>
#include <array>
#include <vector>

//CARMEN SÁNCHEZ HERNÁNDEZ

using namespace std;

//suma de todos los numeros 
float suma (int numero1, vector<float> conjunto, int index) {
    if (index == conjunto.size()) {
        return conjunto.at(0) + numero1; 
    }
    else { 
        float resultado = conjunto.at(index) + numero1;  
        return suma(resultado, conjunto, index + 1);  
    }
}

int main() { 

    vector<float> conjunto1{1.1, 2.2, 3.3 };
    vector<float> conjunto2{3.3, 5.5};
    vector<float> conjunto3{1.1, 1.1, 1.1, 1.1};

    array<vector<float>, 3> conjuntoTotal {conjunto1, conjunto2, conjunto3};

    cout << "\n la suma de todos los numeros del conjunto 1: " << suma(0, conjunto1, 0);
    //cout << "\n la suma de todos los numeros del conjunto 2: " << suma(0, conjunto2, 0);
    //cout << "\n la suma de todos los numeros del conjunto 3: " << suma(0, conjunto3, 0);

    return 0; 



}

