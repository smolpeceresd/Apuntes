#include <iostream>
#include <vector>
using namespace std;


bool isPrimo(int numero,int operador){
    if(operador==1){
        return true;
    }else{
        if(numero%operador == 0){
            return false;
        }else{
            return isPrimo(numero,operador-1);
        }
    }
}


vector<int> Factoriales(const vector<int> &v,int numero, int iteraciones){
    vector<int> v_=v;
    if(numero<=2){
        v_.push_back(numero);
        return v_;
    }else if(iteraciones==1){
        return v;
    }else{
        int resultado=(numero*iteraciones);
        v_.push_back(resultado);
        return Factoriales(v_,resultado,iteraciones-1);
    }
}

int main()
{
    int numero=4;
    vector<int> factoriales = Factoriales({},numero,numero-1);
    cout<<"\n Los numeros que forman el factorial de "<<numero<<" son: ";
    int pares{0},impares{0};
    for(const int &elem:factoriales){
        if(elem%2 ==0){
            cout<<"\n El numero "<<elem<<" que es par";
            if(isPrimo(elem,elem/2) == true ){
                cout<<" y primo ";
            }else{
                cout<<" y no es primo";
            }
            pares++;
        }else{
            cout<<"\n El numero "<<elem<<" que es impar";
            if(isPrimo(elem,elem/2)==true){
                cout<<" y primo";
            }else{
                cout<<" y no es primo";
            }
            impares++;
        }
    }
    cout<<"\n Pares "<<pares<<" Impares "<<impares;

    cout<<"\n\n";

    return 0;
}
