#include <iostream>
#include <array>
#include <vector>
using namespace std;

vector<int> Factoriales(const vector<int> &v, int numero, int operador){
    vector<int> v_=v;
    if(numero<=2){
        v_.push_back(numero);
        return v_;
    }else if(operador==1){
        return v;
    }else{
        int resultado=numero*operador;
        v_.push_back(resultado);
        return Factoriales(v_,resultado,operador-1);
    }
}


int main()
{
    array<int,3> numeros={1,2,4};
    array<vector<int>,3> factoriales{};factoriales.fill({});
    for(int i=0;i<numeros.size();i++){
        factoriales.at(i)=Factoriales({},numeros.at(i),numeros.at(i)-1);
    }
    int par_total{0},impar_total{0},par,impar;
    for(int i=0;i<factoriales.size();i++){
        par=0;impar=0;
        cout<<"\n\nFactoriales del numero "<<numeros.at(i)<<" :";
        for(int j=0;j<factoriales.at(i).size();j++){
            cout<<"\n El numero "<<factoriales.at(i).at(j);
            if(factoriales.at(i).at(j)%2==0){
                par++;par_total++;
                cout<<" que es par";
            }else{
                impar++;impar_total++;
                cout<<" que no es par";
            }
        }
        cout<<"\nNumeros pares del conjunto: "<<par<<" impares: "<<impar;
    }
    cout<<"\n\nNumeros pares Totales: "<<par_total<<" impares: "<<impar_total;
    cout<<"\n\n";
    return 0;
}
