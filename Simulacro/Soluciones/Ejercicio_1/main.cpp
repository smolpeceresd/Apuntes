#include <iostream>
#include <array>
using namespace std;

array<int,15> Fibonacci(const array<int,15> &a, int n0,int n1,int iteracion){
    /**
     * a_ para ir guardando los resultados
     * n0 primer operador
     * n1 el segundo operador
     * iteracion, el número de veces que he de operear, como necesito 15,
     * He de tener en cuenta que las array se llenan con las posiciones
     * por tanto son 15-1 == size-1 = 14
     * Luego necesito llegar a las 14 iteraciones.
     * si llego a las 14 iteraciones == Caso de exito.
     *
     *
     * Fibonacci es la sucesion en la que los factores son la suma de los ultimos resultados
     * es decir
     * 1º iteracion 0 = n0 + 1 = n1 => R1= 1 => / 0 1 1  = n0 + n1  R1
     *
     * 2º iteracion = R1 = 1 + n1 = 1 => R2 = 2 / 0 1 1 2 = n0 n1 + R1 R2
     *
     * 3º iteracion = R2 = 2 + R1 = 1 => R3 = 3 / 0 1 1 2 3 = n0 n1 R1 + R2 R3
     *
     * 4º iteracion = R3 = 3 + R2 = 2 = R4 = 5  / 0 1 1 2 3 5 = n0 n1 R1 R2 + R3 R4
     *
     * ...
     */
    cout<<"\nSumando "<<n0<<" con "<<n1;
    int resultado=n0+n1;
    array<int,15> a_=a;
    if(iteracion==14){
        a_.at(iteracion)=resultado;
        return a_;
    }else{
        a_.at(iteracion)=resultado;
        return Fibonacci(a_,n1,resultado,iteracion+1);
    }
}

int main()
{
    cout <<"\n\nLa serie de Fibonacci Calculo \n";
    array<int,15> fibonacci;fibonacci.fill(0);
    fibonacci[1]=1;
    fibonacci=Fibonacci(fibonacci,0,1,2);
    int pares=0,impares=0;
    cout <<"\n\nLa serie de Fibonacci\n";
    for(int i=0; i<fibonacci.size();i++){
        if(fibonacci.at(i)%2==0){
            pares+=fibonacci.at(i);
        }else{
            impares+=fibonacci.at(i);
        }
        cout<<" "<<fibonacci.at(i);
    }

    cout<<"\n La suma de los pares es: "<<pares;
    cout<<"\n La suma de los impares es: "<<impares;
    return 0;
}
