//  Helena Ruiz Ramirez
//  A01282531
//  22/marzo/2018
//  Tarea 7: Herencia
//  Descripcion: Aplicacion para un sistema de empleados que los da de alta,
//               checa si llegaron tarde, checa su departamento y sus datos.
#include <iostream>
#include "Empleado.h"
using namespace std;
int main() {
    Empleado e[10];
    int op, empleados=0;
    do{
        string nom;
        int ident,depto,alta,h,m,s;
        Tiempo horaEnt,horaSal;
        cout<<"1) altaEmpleado"<<endl;
        cout<<"2) llegadaTarde"<<endl;
        cout<<"3) cantidadDepartamento"<<endl;
        cout<<"4) mostrarEmpleado"<<endl;
        cout<<"5) Terminar"<<endl;
        cin>>op;
        switch(op){
            case 1: {   //  opcion para dar de alta empleados. el usuario mete todos los datos
                        //  necesarios para el objeto Empleado dentro del arreglo de la misma clase.
                cout<<endl;
                cout<<"¿Cuantos empleados quiere dar de alta?: "; // declara la cantidad
                cin>>alta;
                while ((empleados+alta)>10){    // checa que haya suficiente espacio
                    cout<<"Nadamas queda espacio para "<<(10-empleados)<<" empleados o menos: "<<endl;
                    cin>>alta;
                }
                for (int i=0;i<alta;i++){   // ciclo para meter los datos
                    cout<<endl;
                    cout<<"Empleado "<<i+1<<"..."<<endl;
                    cout<<"Nombre: ";
                    cin>>nom;
                    e[i].setNombre(nom);
                    cout<<"Identidad: ";
                    cin>>ident;
                    e[i].setIdentidad(ident);
                    cout<<"Departamento: ";
                    cin>>depto;
                    e[i].setDepto(depto);
                    cout<<"Hora de entrada... "<<endl;
                    cout<<"Hora: ";
                    cin>>h;
                    cout<<"Minuto: ";
                    cin>>m;
                    cout<<"Segundo: ";
                    cin>>s;
                    Tiempo ent (h,m,s);
                    e[i].setHoraEnt(ent);
                    cout<<"Hora de salida... "<<endl;
                    cout<<"Hora: ";
                    cin>>h;
                    cout<<"Minuto: ";
                    cin>>m;
                    cout<<"Segundo: ";
                    cin>>s;
                    Tiempo sal (h,m,s);
                    e[i].setHoraSal(sal);
                    empleados++;
                }
                break;
            }
            case 2: {   // opcion que checa que los empleados hayan llegado a cierta hora.
                        // si la hora de entrada del empleado es mayor a la que puso el usuario,
                        // marca que llego tarde y muestra su nombre.
                cout<<endl;
                cout<<"Hora de llegada que se quiere checar... "<<endl;
                cout<<"Hora: ";
                cin>>h;
                cout<<"Minuto: ";
                cin>>m;
                cout<<"Segundo: ";
                cin>>s;
                Tiempo tarde (h,m,s);
                cout<<endl;
                bool late=false;
                cout<<"Lista de empleados que llegaron tarde..."<<endl;
                for (int i=0;i<empleados;i++){
                    if (tarde<e[i].getHoraEnt()){
                        cout<<e[i].getNombre()<<endl;
                        late=true;
                    }
                }
                if (!late)  // en caso de haber empleados que llegaron tarde, tambien lo avisa
                    cout<<"Todos los empleados llegaron a tiempo."<<endl;
                break;
            }
            case 3: {   // opcion para checar la cantidad de empleados que hay en cierto departamento
                        // especificado por el usuario. muestra el contador del ciclo.
                cout<<endl;
                cout<<"Departamento por el que se quiere buscar: "<<endl;
                cin>>depto;
                cout<<endl;
                int count=0;
                for (int i=0;i<empleados;i++){
                    if (depto==e[i].getDepto())
                        count++;
                }
                if (count==1)   // en caso de no haber empleados en ese departamento, tambien lo avisa
                    cout<<"Se encontro "<<count<<" empleado en el departamento "<<depto<<endl;
                else
                    cout<<"Se encontraron "<<count<<" empleados en el departamento "<<depto<<endl;
                break;
            }
            case 4: {   // opcion que muestra la informacion del empleado que desee el usuario
                cout<<endl;
                cout<<"Identidad del empleado que quiere mostrar: ";
                cin>>ident;
                cout<<endl;
                bool found=false;
                for (int i=0;i<empleados;i++){
                    if (ident==e[i].getIdentidad()){
                        e[i].muestraEmp();
                        found=true;
                    }
                }
                if (!false)     // en caso de que no exista la identidad, tambien lo avisa
                    cout<<"No se encontro un empleado con esa identidad, por favor intentelo de nuevo."<<endl;
                break;
            }
            case 5: {
                break;
            }
        }
        cout<<"------------------------------------"<<endl;
    } while(op!=5);
    return 0;
}
