#ifndef Agua_h
#define Agua_h
#include "Envase.h"
using namespace std;
class Agua:public Envase{
private:
    int sodio;
public:
    Agua();
    Agua(Capacidad,string,int);
    void desplegar();
};
Agua::Agua():Envase(){
    sodio=0;
}
Agua::Agua(Capacidad c,string tipo,int s):Envase(c,tipo){
    sodio=s;
}
void Agua::desplegar(){
    cout<<"Sodio = "<<sodio<<endl;
    cout<<"Capacidad = "<<contenido.getLitros()<<"."<<contenido.getML()<<endl;
    cout<<"Tipo = "<<tipo<<endl;
}
#endif /* Agua_h */
