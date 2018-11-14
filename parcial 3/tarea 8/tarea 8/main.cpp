#include <iostream>
#include <string>
#include "Comisionista.h"
#include "TiempoParcial.h"
using namespace std;
int main() {
    string nomb,ape;
    int nomi,horas;
    double sBase,cantV;
    Empleado* e[4];
    Comisionista c1,c2;
    TiempoParcial t1,t2;
    //  se apuntan las casillas del arreglo Empleado e hacia los
    //  objetos de los empleados 1 y 2
    e[0]=&c1;
    e[1]=&t1;
    e[2]=&c2;
    e[3]=&t2;
    //  mete los datos del usuario para el empleado 1 en los objetos de
    //  tipo Comisionista y Tiempo Parcial que se encuentran en e[0] y e[2]
    cout<<"Datos del Empleado 1..."<<endl;
    cout<<"Nomina: ";
    cin>>nomi;
    c1.setNomina(nomi);
    t1.setNomina(nomi);
    cout<<"Nombre: ";
    cin>>nomb;
    c1.setNombre(nomb);
    t1.setNombre(nomb);
    cout<<"Apellidos: ";
    cin.ignore();
    getline(cin,ape);
    c1.setApellido(ape);
    t1.setApellido(ape);
    cout<<"Saldo Base: ";
    cin>>sBase;
    c1.setSueldoB(sBase);
    t1.setSueldoB(sBase);
    cout<<"Cantidad Vendida: ";
    cin>>cantV;
    c1.setCantVendida(cantV);
    cout<<"Horas Extra: ";
    cin>>horas;
    t1.setHoras(horas);
    cout<<endl;
    //  mete los datos del usuario para el empleado 2 en los objetos de
    //  tipo Comisionista y Tiempo Parcial que se encuentran en e[0] y e[2]
    cout<<"Datos del Empleado 2..."<<endl;
    cout<<"Nomina: ";
    cin>>nomi;
    c2.setNomina(nomi);
    t2.setNomina(nomi);
    cout<<"Nombre: ";
    cin>>nomb;
    c2.setNombre(nomb);
    t2.setNombre(nomb);
    cout<<"Apellidos: ";
    cin.ignore();
    getline(cin,ape);
    c2.setApellido(ape);
    t2.setApellido(ape);
    cout<<"Saldo Base: ";
    cin>>sBase;
    c2.setSueldoB(sBase);
    t2.setSueldoB(sBase);
    cout<<"Cantidad Vendida: ";
    cin>>cantV;
    c2.setCantVendida(cantV);
    cout<<"Horas Extra: ";
    cin>>horas;
    t2.setHoras(horas);
    cout<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<endl;
    //  ahora se manda a llamar el metodo muestra para mostrar el sueldo
    //  de los empleados por la comision y el tiempo extra
    for (int i=0;i<4;i++){
        e[i]->mostrar();
        cout<<endl;
    }
    return 0;
}
