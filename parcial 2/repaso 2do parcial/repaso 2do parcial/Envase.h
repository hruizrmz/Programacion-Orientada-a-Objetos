#ifndef Envase_h
#define Envase_h
#include "Capacidad.h"
using namespace std;
class Envase{
protected:
    Capacidad contenido;
    string tipo;
public:
    Envase();
    Envase(Capacidad,string);
    void setContenido(Capacidad);
    void setTipo(string);
    Capacidad getContenido();
    string getTipo();
    void desplegar();
    friend Capacidad operator+(Envase,Envase);
};
Envase::Envase(){
    Capacidad contenido;
    tipo="";
}
Envase::Envase(Capacidad c,string t){
    contenido=c;
    tipo=t;
}
void Envase::setContenido(Capacidad c){
    contenido=c;
}
void Envase::setTipo(string t){
    tipo=t;
}
Capacidad Envase::getContenido(){
    return contenido;
}
string Envase::getTipo(){
    return tipo;
}
void Envase::desplegar(){
    cout<<"Capacidad = "<<contenido.getLitros()<<"."<<contenido.getML()<<endl;
    cout<<"Tipo = "<<tipo<<endl;
}
Capacidad operator+(Envase e1, Envase e2){
    int l=e1.contenido.getLitros()+e2.contenido.getLitros();
    int ml=e1.contenido.getML()+e2.contenido.getML();
    Capacidad cont(l,ml);
    return cont;
}
#endif /* Envase_h */
