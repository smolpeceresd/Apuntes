#include <iostream>
#include <string>
#include <vector>

using namespace std;

// CARMEN SÁNCHEZ HERNÁNDEZ

int cantidadLetras(const string &texto, vector<char> &letra_a_guardar)
{
    int contador{};
    for (char letra : texto)
    {
        bool letraExistente = false;
        for (char letra_estudio : letra_a_guardar)
        {
            if (letra_estudio == letra)
            {
                letraExistente = true; /*Al reves si la tengo no la incorporo*/
                contador++;
            }
        }

        if (!letraExistente)
        { /*incrementas 2 veces*/
            letra_a_guardar.push_back(letra);
            contador++;
        }
    }
    return contador;
}

int cantidadPalabras(const string &texto)
{
    int contador{};
    for (int i{0}; i < texto.size(); i++)
    {
        if (texto[i] == ' ' && texto[i] == '.')
        {
            /* Si es un punto y hay un espacio
             *
             * Si es punto final ( poss punto = size-1)
             *
             * si es simplemente espacio*/
        }
    }

    return contador;
}

string encontrarPalabraMasLarga(string texto, int longitud)
{

    /**
     * Trocear la palabra
     * coger el size
     * comparar (texto, ultimo indice de un espacio o punto , max)
     * return esta funcion hasta llegar a la ultima palabra y ver si el size es >
     **/
    return "";
}

string encontrarPalabraMasCorta(string texto, int longitud)
{
    /**
     * Trocear la palabra
     * coger el size
     * comparar (texto, ultimo indice de un espacio o punto , min)
     * return esta funcion hasta llegar a la ultima palabra y ver si el size es <
     **/
}

int main()
{

    string texto{"el rey de constantinopla esta constantinoplizado. consta que constanza, no lo pudo desconstantinoplizar. el desconstantinoplizador que desconstantinoplizare al rey de constantinopla buen desconstantinoplizador sera."};
    cout << texto;

    vector<char> letras_guardadas;
    int longitud{};

    int letras_repetidas = cantidadLetras(texto, letras_guardadas);
    int palabras_repetidas = cantidadPalabras(texto);

    cout << "\n"
         << letras_repetidas;
    cout << "\n"
         << palabras_repetidas;

    string palabra_mas_larga = encontrarPalabraMasLarga(texto, longitud);
    string palabra_mas_corta = encontrarPalabraMasCorta(texto, longitud);

    cout << "\n Palabra mas larga : " << palabra_mas_larga;
    cout << "\n Palabra mas corta : " << palabra_mas_corta;

    return 0;
}
