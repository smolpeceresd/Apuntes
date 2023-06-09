#include <iostream>
#include <string>
#include <vector>

using namespace std;

//CARMEN SÁNCHEZ HERNÁNDEZ 

//ejercicio 1
int letraUnica(const string &texto) {
    for (int i{ 0 }; i < texto.size(); i++) {  //para recorrer el texto
        int contador{ 0 };
        for (char c : texto) {  //para saber cuantas veces se repite 
            if (texto.at(i) == c) { 
                contador++; 
            }

        }
        if (contador == 1) { //exito. una letra no se repite 
            return i;
        }
    }
    return -1;//la posicion no exite, elemento fallido 
}

//ejercicio 2
struct letra {
    char letraTexto;
    int vecesRepet; 
};

bool busqueda(vector<letra> lista, char letrita) {
    for (const auto& recorrido : lista) { //recorre el vector lista 
        if (recorrido.letraTexto == letrita) {
            return true;
        }
    }
    return false;
}

void imprimirLetras(const string &texto) { 
    vector<letra> lista;  
    letra letra_mas_repetida{};

    for (char letra_estudio : texto) {  //recorre el texto  
        if (!busqueda(lista, letra_estudio)) {  
            int repeticiones{ 0 };
            for (auto letra_recorrido : texto) { 
                if (letra_recorrido == letra_estudio) {  //para mirar las veces que se repite 
                    repeticiones++;
                } 
            } 
            //instanciar: 
            letra new_letra{};
            new_letra.letraTexto = letra_estudio;
            new_letra.vecesRepet = repeticiones;

            //introducirlo al vector:
            lista.push_back(new_letra); 

            //mostrar letra - repet:
            cout << "\n Letra: " << new_letra.letraTexto << " - Repeticiones: " << new_letra.vecesRepet << "\n";
            
            //letra con mas repeticiones: 
            
        }
    }

    //letra con mas repeticiones:
    cout << "\n Letra con mas repeticiones: " << letra_mas_repetida.letraTexto << " - Repeticiones: " << letra_mas_repetida.vecesRepet << "\n";

}

int main() {
    
    string texto; 
    cout << "Ingrese un texto: "; 
    getline(cin, texto);  

    //ejercicio 1 
    int letra = letraUnica(texto);  
    if (letra != -1) {
        cout << "\n la primera letra que no se repite es: " << texto.at(letra) << "\n";
    }else{
        cout << "\n se repiten";
    }

    //ejercicio 2
    imprimirLetras(texto);

    return 0;

}
