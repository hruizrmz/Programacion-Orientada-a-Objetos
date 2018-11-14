#ifndef TiempoParcial_h
#define TiempoParcial_h
#include "Empleado.h"
using namespace std;
class TiempoParcial:public Empleado{    // hereda de la clase Empleado
private:
    int horasExtra;
public:
    TiempoParcial();
    TiempoParcial(int,string,string,int,double);
    void setHoras(int);
    int getHoras();
    double CalcularPago();
    void mostrar();
};
//  Constructores
TiempoParcial::TiempoParcial():Empleado(){
    horasExtra=0;
}
TiempoParcial::TiempoParcial(int horas,string nomb,string ape,int nomi,double sBase):Empleado(nomb,ape,nomi,sBase){
    horasExtra=horas;
}
//  Metodos set y get
void TiempoParcial::setHoras(int horas){
    horasExtra=horas;
}
int TiempoParcial::getHoras(){
    return horasExtra;
}
//  Metodos para la tarea: Como Empleados es abstracta, estos metodos se definen aqui
//                         para que tenga funciones unicas a esta clase.
double TiempoParcial::CalcularPago(){
    double pago=horasExtra*250;
    return sueldoBase+pago;
}
void TiempoParcial::mostrar(){
    cout<<"Nomina: "<<nomina<<endl;
    cout<<"Nombre: "<<nombre+" "+apellidos<<endl;
    cout<<"Sueldo Base: "<< sueldoBase <<endl;
    double mHoras=CalcularPago()-sueldoBase;
    cout<<"Monto por Horas Extra: "<< mHoras <<endl;
    cout<<"Sueldo Total: "<< CalcularPago() <<endl;
}
#endif /* TiempoParcial_h */
