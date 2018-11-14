#include <iostream>
#include "Pila.h"
using namespace std;

int main(){
    Pila <int> entero;
    Pila <double> doble;
    Pila <char> carac;
    
    ///pila de enteros
    entero.meter(8);
    entero.meter(10);
    entero.observa();
    entero.meter(7);
    entero.sacar();
    entero.meter(9);
    
    ///pila de dobles
    doble.meter(12.5);
    doble.meter(9.5);
    doble.observa();
    doble.sacar();
    doble.sacar();
    doble.observa();
    
    ///Pila de caracteres
    carac.meter('B');
    carac.meter('G');
    carac.observa();
    carac.meter('L');
    carac.meter('T');
    carac.sacar();
    carac.observa();
    return 0;
}
