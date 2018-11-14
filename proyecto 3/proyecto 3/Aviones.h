#ifndef AVIONES_H_INCLUDED
#define AVIONES_H_INCLUDED
#include <cstring>
#include "Servicio.h"
using namespace std;

class Aviones:public Servicio{
public:
    //Constructores
    Aviones();
    Aviones(string,int,Fecha,int,string,char,double,string,int,int);
    //Metodos de Acceso
    int getCantPersonas();
    int getAdicional();
    //Metodos de Modificacion
    void setCantPersonas(int);
    void setAdicional(int);
    //Metodos Operativos
    double calculaCosto(int);
    void muestra();
private:
    int cantPersonas;
    int adicional;
};

///METODOS Y CONSTRUCTORES
//Constructores
Aviones::Aviones():Servicio(){
    cantPersonas=0;
    adicional=0;
}
Aviones::Aviones(string cs, int id, Fecha f, int dd, string c, char t, double csd, string d, int cp, int adi):Servicio(cs,id,f,dd,c,t,csd,d){
    cantPersonas=cp;
    adicional=adi;
}
//Metodos de Acceso
int Aviones::getCantPersonas(){
    return cantPersonas;
}
int Aviones::getAdicional(){
    return adicional;
}
//Metodos de Modificacion
void Aviones::setCantPersonas(int cp){
    cantPersonas=cp;
}
void Aviones::setAdicional(int adi){
    adicional=adi;
}
//Metodos Operativos
double Aviones::calculaCosto(int diasDuracion){
    double costo=0;
    tipo=toupper(tipo);
    switch(tipo){
        case 'H':
            costoXDia=50000;
            if(cantPersonas+adicional>6)
                costoXDia=costoXDia*(adicional*0.04);
            break;
            
        case 'J':
            costoXDia=120000;
            if(cantPersonas+adicional>20)
                costoXDia=costoXDia*(adicional*0.04);
            break;
            
        case 'A':
            costoXDia=80000;
            if(cantPersonas+adicional>10)
                costoXDia=costoXDia*(adicional*0.04);
            break;
    }
    costo=diasDuracion*costoXDia;
    return costo;
}
void Aviones::muestra(){
    cout << "###SERVICIO###" << endl;
    cout << "Clave: " << clave << endl;
    cout << "Costo por dia: " << costoXDia << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "Cantidad de Personas: " << cantPersonas << endl;
    cout << "Adicional: " << adicional << endl;
    cout << endl;
}
#endif // AVIONES_H_INCLUDED
