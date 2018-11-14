//  Helena Ruiz Ramirez
//  A01282531
//  Febrero 1, 2018

//  Tarea 3: Clases y Objetos
//  Ejercicio 2: Inscripciones de alumnos
//  Descripcion: Programa para inscribir alumnos a clases checando
//               la capacidad de los salones y espacios disponibles.

#include <iostream>
#include "Salon.h"
using namespace std;

int main() {
    int op, cap, salon;
    string clase;
    Salon o;
    
    //  el usuario llena los datos de la clase donde quiere inscribir los alumnos
    cout<<"Bienvenido al programa de inscripciones. Por favor escriba los datos siguientes..."<<endl;
    cout<<"Nombre de la clase: ";
    cin>>clase;
    o.setNombreClase(clase);
    cout<<"Capacidad de alumnos: ";
    cin>>cap;
    o.setCapacidad(cap);
    cout<<"Salon: ";
    cin>>salon;
    Salon(cap,salon,clase);
    cout<<endl;
    
    do {
        int alumnos;
        cout<<"¿Que desea hacer?"<<endl;
        cout<<"1) Inscribir alumnos"<<endl;
        cout<<"2) Terminar la sesion"<<endl;
        cin>>op;
        cout<<endl;
        //  el switch permite al usuario repetir el proceso varias veces
        //  hasta que el escoga terminar el programa. los valores del
        //  objeto se guardan siempre y cuando no se acabe la sesion
        switch(op) {
            case 1:
                cout<<"¿Cuantos alumnos desea inscribir?: ";
                cin>>alumnos;
                //  tomando los valores del objeto, el programa verifica si hay suficiente
                //  espacio para inscribir el numero de alumnos que especifico el usuario.
                //  dependiendo de si sobrepasan o no la capacidad de la clase le aparecera
                //  un mensaje de confirmacion o de error.
                if ((o.getInscritos()+alumnos)<=o.getCapacidad()){
                    o.InscribirAlumnos(alumnos);
                    cout<<"Se inscribieron "<<alumnos<<" alumnos."<<endl;
                }
                else if ((o.getInscritos()+alumnos)>o.getCapacidad())
                    cout<<"No hay suficientes lugares."<<endl;
                cout<<"Quedan "<<(o.getCapacidad()-o.getInscritos())<<" lugares disponibles para inscribir alumnos en la clase ''"<<o.getNombreClase()<<"'' (Salon "<<salon<<")"<<endl;
                cout<<"--------------------------"<<endl;
                break;
            case 2:
                op=2;
                break;
        }
        cout<<endl;
    } while(op!=2);
    return 0;
}
