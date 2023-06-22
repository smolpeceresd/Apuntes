#include <iostream>
#include <array>
using namespace std;

array<int, 6> sort(const array<int, 6> &a, int index_0, int index_1) // Método de la burbuja
{

    if (a.at(index_0) > a.at(index_1)) // si el número de la izquierda es mayor que el de la derecha
    {
        array<int, 6> a_ = a;            // genero una copia del array
        int aux = a_.at(index_1);        // guardo el número de la derecha
        a_.at(index_1) = a_.at(index_0); // cambio el número de la derecha por el de la izquierda
        a_.at(index_0) = aux;            // cambio el número de la izquierda por el de la derecha
        return sort(a_, 0, 1);
        /**
         * Como hemos hecho una modificaciónd el array, tenemos que volver a empezar
         * ¿por qué?
         * si tenemos {2, 8, 1} y hacemos el cambio, nos queda {2,1,8}
         *
         * Todavía nos queda pasar el 1 al principio, pero no podemos si no volvemos a empezar
         *
         */
    }
    else // si no tenemos que mdoificar el array
    {
        if (index_1 == a.size() - 1) // si hemos llegado al final
        {
            return a; // devolvemos el array
        }
        else
        {
            return sort(a, index_0 + 1, index_1 + 1); // si no hemos llegado al final, seguimos sin modificar el array
        }
    }
}

int factorial(int numero, int multiplicador)
{
    /**
     * Factorial = 5! = 5*4*3**2*1
     *
     * Utilizo "numero" para guardar el resultado y "multiplicador" para ir multiplicando
     *
     */
    if (numero == 1) // si el número es 1, devolvemos 1 es su factorial
    {
        return 1;
    }
    else // si es un número mayor que 1, tenemos que multiplicarlo por el número anterior
    {
        if (multiplicador == 1) // hemos multiplicado por todos los números hasta llegar a 1
        {
            return numero; // devolvemos el resultado
        }
        else
        {
            return factorial((numero * multiplicador), multiplicador - 1);
            // multiplicamos el número por el multiplicador y llamamos a la función con el número y el multiplicador - 1
        }
    }
}

bool isFibonacci(int numero, int n0, int n1)
{
    int resultado = n0 + n1;        // calculo el siguiente número de la serie de Fibonacci
    if (numero == 0 || numero == 1) // si el número es 0 o 1, pertenece a la serie de Fibonacci si o si
    {
        return true;
    }
    else if (resultado > numero) // si el número es mayor que el resultado, no pertenece a la serie de Fibonacci, nos hemos pasado
    {
        return false;
    }
    else if (resultado == numero) // si el número es igual que el resultado, pertenece a la serie de Fibonacci
    {
        return true;
    }
    else // si el número es menor que el resultado, tenemos que seguir calculando
    {
        return (isFibonacci(numero, n1, resultado));
    }
}

int main()
{
    /*8,1,2,5,9,4*/
    array<int, 6> numeros{8, 1, 2, 5, 9, 4};

    /*numeros.fill(0);
    cout<<"\n DAME 5 numeros:\n";
    for(int i=0;i<numeros.size();i++){
        cin>>numeros.at(i);
    }
    system("cls");
    */
    array<int, 6> orden = sort(numeros, 0, 1);
    cout << "\nNumeros: \n";
    for (const int &num : numeros)
    {
        cout << " " << num;
    }
    cout << "\n\nOrdenados Menor >> Mayor \n";
    for (const int &num : orden)
    {
        cout << " " << num;
    }
    cout << "\n\nOrdenados Mayor >> Menor \n";
    for (int i = static_cast<int>(orden.size()) - 1; i >= 0; i--)
    {
        cout << " " << orden.at(i);
    }
    cout << "\n\nFactoriales \n";
    for (int i = 0; i < orden.size(); i++)
    {
        cout << "\n"
             << orden.at(i) << "! = " << factorial(orden.at(i), (orden.at(i) - 1));
    }
    cout << "\n\nPertenece a Fibonacci\n";
    for (int i = 0; i < orden.size(); i++)
    {
        if (isFibonacci(orden.at(i), 0, 1) == true)
        {
            cout << "\n"
                 << orden.at(i) << " pertenece a la serie de Fibonacci";
        }
        else
        {
            cout << "\n"
                 << orden.at(i) << " no pertenece a la serie de Fibonacci";
        }
    }
    cout << "\n\n";
    return 0;
}
