#ifndef Refresco_h
#define Refresco_h
#include "Envase.h"
using namespace std;
class Refresco:public Envase{
private:
    int azucar,calorias;
public:
    Refresco();
    Refresco(Capacidad,string,int,int);
    void desplegar();
};
Refresco::Refresco():Envase(){
    azucar=0;
    calorias=0;
}
Refresco::Refresco(Capacidad contenido,string tipo,int a,int c): Envase(contenido,tipo){
    azucar=a;
    calorias=c;
}
void Refresco::desplegar(){
    cout<<"Azucar = "<<azucar<<endl;
    cout<<"Calorias ="<<calorias<<endl;
    cout<<"Capacidad = "<<contenido.getLitros()<<"."<<contenido.getML()<<endl;
    cout<<"Tipo = "<<tipo<<endl;
}
#endif /* Refresco_h */
