#include <iostream>
#include "Perro.h"
#include "Gato.h"
int main() {
    Animal* pet[3];
    Gato g1("Silvestre",1947);
    Perro p("Fido",2000);
    Gato g2("Tom",1940);
    pet[0]=&g1;
    pet[1]=&p;
    pet[2]=&g2;
    for (int i=0;i<3;i++){
        pet[i]->muestra();
        pet[i]->habla();
        cout<<endl;
    }
    return 0;
}
