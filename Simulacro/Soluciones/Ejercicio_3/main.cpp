#include <iostream>
#include <array>
using namespace std;

struct Letra{
    char letra;
    int repeticiones;
};


int main()
{
    string texto {"Las flores crecen en primavera y las alergias se disparan."};
    Letra a{'a',0},e{'e',0},i{'i',0},o{'o',0},u{'u',0};
    array<Letra,5> letras_{a,e,i,o,u};

    for(const char &letra:texto){
        switch (letra) {
        case 'a':
            letras_.at(0).repeticiones++;
            break;
        case 'e':
            letras_.at(1).repeticiones++;
            break;
        case 'i':
            letras_.at(2).repeticiones++;
            break;
        case 'o':
            letras_.at(3).repeticiones++;
            break;
        case 'u':
            letras_.at(4).repeticiones++;
            break;
        default:
            break;
        }
    }
   cout<<"\nTexto: \n"<<texto;
   for(const Letra &letra:letras_){
       cout<<"\nLetra "<<letra.letra<<" se repite "<<letra.repeticiones<<" veces";
   }
return 0;

}
