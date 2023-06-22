#include <iostream>
#include <array>
#include <set>
using namespace std;

string compare(const array<string, 5> &a, int index_devolver, int index_operacion, int min_max)
{

    if (min_max == 0)
    {                                        // busco la minima
        if (index_operacion == a.size() - 1) // si llegamos al final
        {
            if (a.at(index_devolver).size() < a.at(index_operacion).size()) // si la palabra que me he guardado es menor que al ultima palabra
            {
                return a.at(index_devolver); // devuelvo la palabra que me he guardado
            }
            else
            {
                return a.at(index_operacion); // la ultima palabra es la buena
            }
        }
        else
        {
            if (a.at(index_devolver).size() < a.at(index_operacion).size()) // si la palabra que me he guardado es menor que la palabra que estoy mirando
            {
                return compare(a, index_devolver, index_operacion + 1, 0); // me llevo la palabra que me llevo guardando de antes
            }
            else
            {
                return compare(a, index_operacion, index_operacion + 1, 0); // me llevo la palabra nueva que es menor que la que tenía guardada
            }
        }
    }
    else
    {                                        // busco la máxima
        if (index_operacion == a.size() - 1) // si llegamos al final
        {
            if (a.at(index_devolver).size() > a.at(index_operacion).size()) // si la palabra que me he guardado es mayor que al ultima palabra
            {
                return a.at(index_devolver); // devuelvo la palabra que me he guardado de antes
            }
            else
            {
                return a.at(index_operacion); // la ultima palabra es la buena
            }
        }
        else
        {
            if (a.at(index_devolver).size() > a.at(index_operacion).size()) // si la palabra que me he guardado es mayor que la palabra que estoy mirando
            {
                return compare(a, index_devolver, index_operacion + 1, 1); // me llevo la palabra que me llevo guardando de antes
            }
            else
            {
                return compare(a, index_operacion, index_operacion + 1, 1); // me llevo la palabra nueva que es mayor que la que tenía guardada
            }
        }
    }
}

bool palindromo(const string &a, int index_front, int index_back)
{
    if (a.size() % 2 == 0) // si la palabra tiene un numero par de letras
    {
        if ((index_front + 1) == index_back) // la ultima comparación deben ser las dos letras centrales, es decir coger una y sumar uno y ver si se encuentran
        {
            if (a.at(index_front) == a.at(index_back)) // si son iguales es palindromo
            {
                return true;
            }
            else // si no son iguales no es palindromo
            {
                return false;
            }
        }
        else // si no estamos en la ultima comparación, es decir esta lejos el inicio del final
        {
            if (a.at(index_front) == a.at(index_back))
            {
                return palindromo(a, index_front + 1, index_back - 1);
            }
            else // en el momento que dejen de ser iguales, no es palindromo
            {
                return false;
            }
        }
    }
    else // si la palabra tiene un numero impar de letras
    {
        if (index_front == index_back) // si estamos en la ultima comparación, es decir estamos en la letra central
        {
            return true;
        }
        else
        {
            if (a.at(index_front) == a.at(index_back)) // si son iguales podemos seguir comparando
            {
                return palindromo(a, index_front + 1, index_back - 1);
            }
            else // en el momento que dejen de ser iguales, no es palindromo
            {
                return false;
            }
        }
    }
}

int main()
{
    array<string, 5> palabras{"amor", "reconocer", "somos", "lamina", "atar"};
    /*
    palabras.fill("");
    cout<<"\n Dame 5 palabras:\n";
    for(int i =0; i < palabras.size();i++){
        cin>>palabras.at(i);
    }*/

    /* Mostrar */

    cout << "\n\nPalabras\n";
    for (int i = 0; i < palabras.size(); i++)
    {
        cout << " " << palabras.at(i);
    }

    /* Inverso */

    cout << "\n\nOrden Inverso\n";
    for (int i = static_cast<int>(palabras.size()) - 1; i >= 0; i--)
    {
        cout << " " << palabras.at(i);
    }

    /* Alfavéticamente */

    set<string> alfabet;
    for (const string &elem : palabras)
    {
        alfabet.insert(elem);
    }
    cout << "\n\nOrden Alfabetico\n";
    for (const string &elem : alfabet)
    {
        cout << " " << elem;
    }

    /* Alfabéticamente Inverso */
    cout << "\n\nOrden Alfabetico Inverso\n";
    array<string, 5> inverso;
    inverso.fill("");
    int count = 4;
    for (const string &elem : alfabet)
    {
        inverso.at(count) = elem;
        count--;
    }
    for (const string &elem : inverso)
    {
        cout << " " << elem;
    }

    /* Menor & Mayor número de letras */
    cout << "\n\nMenor & Mayor \n";
    cout << "\nPalabra con Menor numero de letras: " << compare(palabras, 0, 1, 0)
         << "\nPalabra con Mayor numero de letras: " << compare(palabras, 0, 1, 1);

    /* Palindromo*/
    cout << "\n\nPalindromos \n";
    for (const string &elem : palabras)
    {
        if (palindromo(elem, 0, elem.size() - 1) == true)
        {
            cout << "\n La palabra \"" << elem << "\" es palindromo";
        }
        else
        {
            cout << "\n La palabra \"" << elem << "\" no es palindromo";
        }
    }
    cout << "\n\n";

    return 0;
}
