#include <iostream>
#include "Circulo.h"
#include "Triangulo.h"
#include "Rectangulo.h"
using namespace std;
int main() {
    double rad,b,h;
    Figura* f[6];
    cout<<"Valores del circulo..."<<endl;
    cout<<"Radio 1: ";
    cin>>rad;
    Circulo c1(rad);
    f[0]=&c1;
    cout<<"Radio 2: ";
    cin>>rad;
    Circulo c2(rad);
    f[1]=&c2;
    cout<<"--------------------------"<<endl;
    cout<<"Valores del triangulo..."<<endl;
    cout<<"Base 1: ";
    cin>>b;
    cout<<"Altura 1: ";
    cin>>h;
    Triangulo t1(b,h);
    f[2]=&t1;
    cout<<"Base 2: ";
    cin>>b;
    cout<<"Altura 2: ";
    cin>>h;
    Triangulo t2(b,h);
    f[3]=&t2;
    cout<<"--------------------------"<<endl;
    
    
}
