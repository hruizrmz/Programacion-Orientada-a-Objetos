//  Helena Ruiz Ramirez
//  A01282531
//  Enero 11, 2018
//  Strings: Ejercicio 1
//  Programa que checa si una frase es palindromo o no


#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main() {
    
    long l,s;
    bool estado=true;
    string frase;
    cout<<"Frase: ";
    getline(cin,frase);
    cout<<endl;
    
    while (frase.find(" ")!= -1) {
        s=frase.find(" ");
        frase.erase(s,1);
    }
    cout<<frase<<endl;
    
    l=frase.length();
    for (int i=0;(i<(l/2))&&(estado);i++) {
        if (toupper(frase[i])!=toupper(frase[l-1-i])) {
            estado=false;
            cout<< "No es un palindromo."<<endl;
        }
    }
    if (estado==true){
        cout<<"Si es palindromo."<<endl;
    }
    cout<<endl;
    return 0;
}
