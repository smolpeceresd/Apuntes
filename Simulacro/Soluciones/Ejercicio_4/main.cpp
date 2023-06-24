#include <iostream>
#include <array>
#include <set>
using namespace std;

int Factorial ( int numero,int operador){
    if(operador == 1 || numero == 0| numero  ==1){
        return numero;
    }else{
        return Factorial((numero*operador),operador-1);
    }
}

int main()
{
    array <int,5> numeros{1,4,2,6,9},orden_inv;orden_inv.fill(0);
    set<int> orden;
    float media=0.0;
    cout<<"\nNumeros: ";
    for(const int &elem:numeros){
        cout<<" "<<elem; // muestro los numeros normales
        orden.insert(elem);
        media+=elem; // da igual donde , así que ya calculo la primera parte de la media
    }


    cout<<"\n\nOrdenados de Menor >> Mayor";
    int contador=4;
    for(const int &elem:orden){
        cout<<" "<<elem;
        orden_inv.at(contador)=elem;
        contador--; // ya que los muestro ordenados, puedo meterlos invertidos
    }

    cout<<"\n\nOrdenados de Mayor >> Menor";
    for(const int &elem:orden_inv){
        cout<<" "<<elem;
    }

    cout<<"\n\nLa media es "<<media/numeros.size()<<"\n"; // completo la media


    for(const int &elem:orden){
        cout<<"\nEl factorial de "<<elem<<" es: "<<Factorial(elem,elem-1);
    }
    cout<<"\n\n";
    return 0;
}
