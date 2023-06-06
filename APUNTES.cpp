#include <iostream>
#include <string>

using namespace std;

//ejercicio 1
char letraUnica(string texto) {
    int contador = { 0 }; 
    char letra{ };

    for (int i{ 0 }; i < texto.size() - 1; i++) { //NO ME SALEEE
        if (i == letra) {
            contador++;
        }
        if (texto.size() == 1) {
            return i;
        }
    }
    return ' ';
}


//ejercicio 2
void imprimirLetras(const string &texto) {
    cout << "Texto: " << texto << "\n";
    cout << "Letra - Cantidad" << "\n";

    for (char letra : texto) { 
        if (letra >= 'a' && letra <= 'z') {
            int contador = 0; 

            for (char c : texto) {
                if (c == letra) {
                    contador++; 
                }
            }

            cout << letra << " - " << contador << "\n";
        }
    }

}



int main() {
    
    string texto;
    cout << "Ingrese un texto: ";
    getline(cin, texto);

    char letra = letraUnica(texto);
    if (letra != ' ') {
        cout << "La primera letra no repetida es: " << letra << "\n";
    }
    else {
        cout << "No hay ninguna letra que no se repita. " << "\n";
    }


    imprimirLetras(texto);

    return 0;

}
