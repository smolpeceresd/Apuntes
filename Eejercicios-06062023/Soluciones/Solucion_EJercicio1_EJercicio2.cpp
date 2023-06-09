#include <iostream>
#include <vector>

using namespace std;

struct Letras
{
    char letra;
    int repeticiones;
};

int LetraUnica(const string &texto);
void Ejercicio1(const string &texto);
void Ejercicio2(const string &texto);
bool search(const vector<Letras> &letras, char letra_b);
void print(const vector<Letras> listado);

int main()
{
    int opcion{1};
    do
    {
        cout << "Texto a anlizar: ";
        string texto;
        cin >> texto;
        // Ejercicio 1
        Ejercicio1(texto);
        // Ejercicio 2
        Ejercicio2(texto);

        cout << "\n Quieres volver a hacerlo? 1 SI 0 No \n Eleccion: ";
        cin >> opcion;
        system("cls");
    } while (opcion != 0);
    cout << "\n Chaooo";
    return 0;
}

void Ejercicio1(const string &texto)
{
    int letra = LetraUnica(texto);
    cout << "\n letra:" << letra;
    if (letra != -1)
    {
        cout << "\nLa primera letra que no se repite es: " << texto[letra] << "\n";
    }
    else
    {
        cout << "\n Todas las letras se repiten ";
    };
}

void Ejercicio2(const string &texto)
{
    vector<Letras> Letras_del_texto;
    for (int i = 0; i < texto.size(); i++)
    {
        int contador = 0;
        bool registrado = search(Letras_del_texto, texto.at(i));
        if (registrado == 0)
        {
            for (int j = 0; j < texto.size(); j++)
            {
                if (texto.at(i) == texto.at(j))
                {
                    contador++;
                }
            }

            Letras letra{
                texto.at(i),
                contador};
            Letras_del_texto.push_back(letra);
        }
    }
    print(Letras_del_texto);
}

int LetraUnica(const string &texto)
{
    for (int i = 0; i < texto.size(); i++)
    { // Recorremos el texto para analizar cada letra
        int contador = 0;
        for (int j = 0; j < texto.size(); j++)
        { // Recorrer el texto apra comparar las letras
            if (texto.at(i) == texto.at(j))
            { // ¿H=H?
                contador += 1;
            }
        }
        if (contador == 1)
        {             // ¿Se repite solo una vez?
            return i; // si
        }
    } // si se repite más veces, veremos si hay otra letra que se repita solo una vez
    return -1;
}

bool search(const vector<Letras> &letras, char letra_b)
{
    for (const Letras &letra : letras)
    {
        if (letra.letra == letra_b)
        {
            return 1;
        }
    }
    return 0;
}

void print(const vector<Letras> listado)
{
    cout << "\n Letra - Contaidad \n";
    for (const Letras &letra : listado)
    {
        cout << "\n  " << letra.letra << " - " << letra.repeticiones;
    }

    cout << "\n";
}
