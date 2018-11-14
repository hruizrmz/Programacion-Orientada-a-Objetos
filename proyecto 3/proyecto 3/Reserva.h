#ifndef RESERVA_H_INCLUDED
#define RESERVA_H_INCLUDED
#include "Fecha.h"
using namespace std;

class Reserva{
public:
    //Constructores
    Reserva();
    Reserva(string,int,Fecha,int);
    //Metodos de Acceso
    string getClaveServicio();
    int getIDCliente();
    Fecha getFechaContrato();
    int getDiasDuracion();
    //Metodos de Modificacion
    void setClaveServicio(string);
    void setIDCliente(int);
    void setFechaContrato(Fecha);
    void setDiasDuracion(int);
    //Metodos Operativos
    Fecha calcularFinContrato();
    //Operadores de Sobrecarga
    friend ostream& operator<<(ostream &os, Reserva r);
protected:
    string claveServicio;
    int idCliente, diasDuracion;
    Fecha fechaContrato;
};

///METODOS Y CONSTRUCTORES
//Constructores
Reserva::Reserva(){
    claveServicio="";
    idCliente=0;
    Fecha f;
    fechaContrato=f;
    diasDuracion=0;
}
Reserva::Reserva(string cs, int id, Fecha f, int dd){
    claveServicio+=cs;
    idCliente=id;
    fechaContrato=f;
    diasDuracion=dd;
}
//Metodos de Acceso
string Reserva::getClaveServicio(){
    return claveServicio;
}
int Reserva::getIDCliente(){
    return idCliente;
}
Fecha Reserva::getFechaContrato(){
    return fechaContrato;
}
int Reserva::getDiasDuracion(){
    return diasDuracion;
}
//Metodos de Modificacion
void Reserva::setClaveServicio(string cs){
    claveServicio=cs;
}
void Reserva::setIDCliente(int id){
    idCliente=id;
}
void Reserva::setFechaContrato(Fecha f){
    fechaContrato=f;
}
void Reserva::setDiasDuracion(int dd){
    diasDuracion=dd;
}
//Metodos Operativos
Fecha Reserva::calcularFinContrato(){
    Fecha newContrato = fechaContrato + diasDuracion;
    return newContrato;
}
//Operadores de sobrecarga
ostream& operator<<(ostream &os, Reserva r){
    os << r.claveServicio << " " << r.idCliente << " " << r.fechaContrato << " " << r.diasDuracion << endl;
    return os;
}
#endif // RESERVA_H_INCLUDED
