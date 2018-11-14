#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
#include "Reserva.h"
using namespace std;

class Servicio:public Reserva{
public:
    //Constructores
    Servicio();
    Servicio(string,int,Fecha,int,string,char,double,string);
    //Metodos de Acceso
    string getClave();
    char getTipo();
    double getcostoXDia();
    string getDescripcion();
    //Metodos de Modificacion
    void setClave(string);
    void setTipo(char);
    void setCostoXDia(double);
    void setDescripcion(string);
    //Metodos Operativos
    virtual double calculaCosto(int) = 0;
    virtual void muestra() = 0;
protected:
    string clave;
    char tipo;
    double costoXDia;
    string descripcion;
};

///METODOS Y CONSTRUCTORES
//Constructores
Servicio::Servicio():Reserva(){
    clave="";
    tipo='a';
    costoXDia=0;
    descripcion="";
}
Servicio::Servicio(string cs, int id, Fecha f, int dd, string cl, char t, double csd, string d):Reserva(cs,id,f,dd){
    clave=cl;
    tipo=t;
    costoXDia=csd;
    descripcion=d;
}
//Metodos de Acceso
string Servicio::getClave(){
    return clave;
}
char Servicio::getTipo(){
    return tipo;
}
double Servicio::getcostoXDia(){
    return costoXDia;
}
string Servicio::getDescripcion(){
    return descripcion;
}
//Metodos de Modificacion
void Servicio::setClave(string cl){
    clave=cl;
}
void Servicio::setTipo(char t){
    tipo=t;
}
void Servicio::setCostoXDia(double csd){
    costoXDia=csd;
}
void Servicio::setDescripcion(string d){
    descripcion=d;
}
#endif // SERVICIO_H_INCLUDED
