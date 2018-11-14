#include "Animal.h"
using namespace std;
class Gato: public Animal{
public:
    Gato(string,int);
    void muestra();
    void habla();
};
Gato::Gato(string nom,int bday):Animal(nom,bday){
}
void Gato::muestra(){
    cout<<"Soy el gato "<<nombre<<" y tengo "<<calculaEdad()<<" años."<<endl;
}
void Gato::habla(){
    cout<<"MIAU"<<endl;
}
