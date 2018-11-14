//  Helena Ruiz Ramirez
//  A01282531
//  22/marzo/2018
//  Tarea 7: Herencia
//  Descripcion: Header de la clase Empleado. Hereda de Persona y esta compuesto con Tiempo.
#ifndef Empleado_h
#define Empleado_h
#include "Persona.h"
#include "Tiempo.h"
using namespace std;
class Empleado:public Persona{
public:
    Empleado();
    Empleado(int,string,Tiempo,Tiempo);
    void setHoraEnt(Tiempo);
    void setHoraSal(Tiempo);
    void setDepto(int);
    Tiempo getHoraEnt();
    Tiempo getHoraSal();
    int getDepto();
    void muestraEmp();
private:
    Tiempo horaEntrada;
    Tiempo horaSalida;
    int depto;
};
//  Constructores Default
Empleado::Empleado():Persona(){
    Tiempo ent(0,0,0);
    horaEntrada=ent;
    Tiempo sal(0,0,0);
    horaSalida=sal;
}
Empleado::Empleado(int ident, string nom, Tiempo ent,Tiempo sal):Persona(ident,nom){
    horaEntrada=ent;
    horaSalida=sal;
}
//  Metodos de Modificacion
void Empleado::setHoraEnt(Tiempo ent){
    horaEntrada=ent;
}
void Empleado::setHoraSal(Tiempo sal){
    horaSalida=sal;
}
void Empleado::setDepto(int depto){
    this->depto=depto;
}
//  Metodos de Acceso
Tiempo Empleado::getHoraEnt(){
    return horaEntrada;
}
Tiempo Empleado::getHoraSal(){
    return horaSalida;
}
int Empleado::getDepto(){
    return depto;
}
//  Metodo de Muestra
void Empleado::muestraEmp(){
    muestraPer();
    cout<<"Departamento: "<<depto<<endl;
    cout<<"Hora de Entrada: ";
    horaEntrada.muestraTiempo();
    cout<<"Hor&a de Salida: ";
    horaSalida.muestraTiempo();
}
#endif /* Empleado_h */
