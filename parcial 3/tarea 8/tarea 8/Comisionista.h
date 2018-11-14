#ifndef Comisionista_h
#define Comisionista_h
#include "Empleado.h"
using namespace std;
class Comisionista:public Empleado{ // hereda de la clase Empleado
private:
    double cantVendida;
public:
    Comisionista();
    Comisionista(double,string,string,int,double);
    void setCantVendida(double);
    double getCantVendida();
    double CalcularPago();
    void mostrar();
};
//  Constructores
Comisionista::Comisionista():Empleado(){
    cantVendida=0;
}
Comisionista::Comisionista(double cantV,string nomb,string ape,int nomi,double sBase):Empleado(nomb,ape,nomi,sBase){
    cantVendida=cantV;
}
//  Metodos set y get
void Comisionista::setCantVendida(double cantV){
    cantVendida=cantV;
}
double Comisionista::getCantVendida(){
    return cantVendida;
}
//  Metodos para la tarea: Como Empleados es abstracta, estos metodos se definen aqui
//                         para que tenga funciones unicas a esta clase.
double Comisionista::CalcularPago(){
    double pago;
    if (cantVendida>35000)      // si se ganaron mas de 35,000 en ventas,
        pago=(sueldoBase*.1);   // el empleado recibe 10% de comision
    else if( (cantVendida>=15000)&&(cantVendida<=35000) )   // si se ganaron mas de 15,000 y menos de
        pago=(sueldoBase*.06);                              // 35,000 en ventas,recibe 6% de comision
    else
        pago=0;
    return sueldoBase+pago;
}
void Comisionista::mostrar(){
    cout<<"Nomina: "<<nomina<<endl;
    cout<<"Nombre: "<<nombre+" "+apellidos<<endl;
    cout<<"Sueldo Base: "<< sueldoBase <<endl;
    double pago=CalcularPago()-sueldoBase;
    cout<<"Sueldo por Comision: "<< pago <<endl;
    cout<<"Sueldo Total: "<< CalcularPago() <<endl;
}
#endif /* Comisionista_h */
