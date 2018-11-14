#include <iostream>
#include "Reloj.h"

int main() {
    Reloj hrInicial;
    Reloj hrFinal;
    int hr1,min1,hr2,min2;
    
    cout<<"Hora inicial: ";
    cin>>hr1;
    hrInicial.setHora(hr1);
    cout<<"Minutos iniciales: ";
    cin>>min1;
    hrInicial.setMinu(min1);
    cout<<endl;
    
    cout<<"Hora final: ";
    cin>>hr2;
    hrFinal.setHora(hr2);
    cout<<"Minutos finales: ";
    cin>>min2;
    hrFinal.setMinu(min2);
    cout<<endl;
    
    cout<<"Hora inicial: ";
    hrInicial.muestra(hr1,min1);
    cout<<endl;
    cout<<"Hora final: ";
    hrFinal.muestra(hr2,min2);
    
    cout<<endl;
    return 0;
}
