#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED
#include <ctype.h>
#include "Servicio.h"
using namespace std;
class Autos:public Servicio{
public:
    //Constructor
    Autos();
    Autos(string,int,Fecha,int,string,char,double,string,bool,bool);
    //Metodos de Acceso
    bool getChofer();
    bool getBlindado();
    //Metodos de Modificacion
    void setChofer(bool);
    void setBlindado(bool);
    //Metodos Operativos
    double calculaCosto(int);
    void muestra();
private:
    bool chofer;
    bool blindado;
};

///METODOS Y CONSTRUCTORES
//Constructor
Autos::Autos():Servicio(){
    chofer=false;
    blindado=false;
}
Autos::Autos(string cs, int id, Fecha f, int dd, string c, char t, double csd, string d, bool ch, bool bl):Servicio(cs,id,f,dd,c,t,csd,d){
    chofer=ch;
    blindado=bl;
}
//Metodos de Acceso
bool Autos::getChofer(){
    return chofer;
}
bool Autos::getBlindado(){
    return blindado;
}
//Metodos de Modificacion
void Autos::setChofer(bool ch){
    chofer=ch;
}
void Autos::setBlindado(bool bl){
    blindado=bl;
}
//Metodos Operativos
double Autos::calculaCosto (int diasDuracion){
    double costo=0;
    tipo = toupper(tipo);
    switch(tipo){
        case 'S':
            costoXDia=800;
            if(chofer==true)
                costoXDia+=400;
            if(blindado==true)
                costoXDia*=1.40;
            break;
            
        case 'M':
            costoXDia=600;
            if(chofer==true)
                costoXDia+=400;
            if(blindado==true)
                costoXDia*=1.40;
            break;
            
        case 'T':
            costoXDia=400;
            if(chofer==true)
                costoXDia+=400;
            if(blindado==true)
                costoXDia*=1.40;
            break;
    }
    costo=diasDuracion*costoXDia;
    return costo;
}
void Autos::muestra(){
    cout << "###SERVICIO###" << endl;
    cout << "Clave: " << clave << endl;
    cout << "Costo por dia: " << costoXDia << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "Chofer: ";
    if(chofer==true)
        cout << "Si" << endl;
    else
        cout << "No" << endl;
    cout << "Blindado: ";
    if(blindado==true)
        cout << "Si" << endl;
    else
        cout << "No" << endl;
    cout << endl;
}
#endif // AUTOS_H_INCLUDED
