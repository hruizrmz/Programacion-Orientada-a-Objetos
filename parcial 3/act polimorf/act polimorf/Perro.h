#include "Animal.h"
using namespace std;
class Perro: public Animal{
public:
    Perro(string,int);
    void muestra();
    void habla();
};
Perro::Perro(string nom,int bday):Animal(nom,bday){
}
void Perro::muestra(){
    cout<<"Soy el perro "<<nombre<<" y tengo "<<calculaEdad()<<" años."<<endl;
}
void Perro::habla(){
    cout<<"GUAU"<<endl;
}
