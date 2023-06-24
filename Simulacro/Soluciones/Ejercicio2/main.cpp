#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string text{"Las flores crecen en primavera y las alergias se disparan."};

    vector<int> poss_space;

    for(int i =0; i<text.size();i++){
        if(text.at(i)==' '){
            poss_space.push_back(i);
        }
    }
    cout<<"Texto:\n"<<text;
    cout<<"\n Los espacios estan en las posiciones: ";
    for(const int &elem:poss_space){
        cout<<" "<<elem;
    }
    cout<<"\n El numero de palabras es: "<<poss_space.size()+1;
    cout<<"\n\n";
    return 0;
}
