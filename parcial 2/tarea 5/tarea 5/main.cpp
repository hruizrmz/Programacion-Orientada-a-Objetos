//  Helena Ruiz Ramirez
//  A01282531
//  Febrero 22, 2018
//  Tarea 5: Composicion
//  Descripcion: Programa que le muestra al usuario informacion
//               sobre las computadoras que se encuentran en
//               ciertos salones inscribio en el sistema.

#include <iostream>
#include <string>
#include "Computadora.h"
#include "Salon.h"
using namespace std;

int main() {
    Salon arr[10];  // se crea un arreglo de maximo 10 espacios para meter los datos de los salones
    Computadora o;
    int salones=0,datos=0,datosIn=0,piso,num,salon,ram,op;
    string marca,os;
    cout<<"Programa de Computadoras TEC"<<endl;
    cout<<"¿Cuantos salones hay? ";
    cin>>salones;
    while (salones>10){     // checa que sean menos de 10 salones para que quepan en el arreglo
        cout<<"Deben de ser 10 salones o menos: ";
        cin>>salones;
    }
    cout<<endl;
    cout<<"Datos de los Salones..."<<endl;
    for (int i=0;i<salones;i++){
        cout<<"Salon #"<<i+1<<endl;
        cout<<"Aula: ";
        cin>>datos;
        while (datos>9){    // ciclo para checar que el aula sea de una cifra
            cout<<"No existe esa aula. Intente otra vez: ";
            cin>>datos;
        }
        datos*=10;          // multiplica por 10 para poder sumar el proximo dato
        cout<<"Piso: ";     // y empezar a escribir el numero completo del salon
        cin>>datosIn;
        while (datosIn>9){  // ciclo para checar que el piso sea de una cifra
            cout<<"No existe ese piso. Intente otra vez: ";
            cin>>piso;
        }
        datos+=datosIn;     // se agrega el piso y se vuelve a multiplicar pero
        datos*=100;         // ahora por dos para que el salon tenga dos cifras
        cout<<"Numero: ";
        cin>>datosIn;
        while (datosIn>99){ // ciclo para checar que el salon sea de maximo dos cifras
            cout<<"No existe ese salon. Intente otra vez: ";
            cin>>num;
        }
        datos+=datosIn;     // se suma el salon a la variable datos para que quede como aula/piso/salon
        arr[i].Set(datos);  // se meten los valores al espacio i del arreglo de salones
        cout<<endl;
    }
    cout<<"Datos de las Computadoras..."<<endl;
    for (int i=0;i<salones;i++){
        cout<<"# de Salon: ";
        cin>>salon;
        if (salon>salones){ // si se escribe un numero mayor al numero de salones creados, el programa
                            // no continua para que no se pierda la informacion del usuario
            cout<<"No existe ese salon. Intente otra vez: ";
            cin>>salon;
        }
        cout<<"Marca: ";
        cin>>marca;
        o.setMarca(marca);
        cout<<"Sistema Operativo: ";
        cin.ignore();
        getline(cin,os);    // inclui un getline para sistemas operativos como 'mac os'
        o.setOS(os);
        cout<<"RAM: ";
        cin>>ram;
        o.setRAM(ram);
        arr[salon-1].setCompu(o);   // despues de meter los datos en variables del objeto o, el programa
        cout<<endl;                 // ahora los mete en el espacio del arreglo de salones indicado
    }
    cout<<"----------------------------"<<endl;
    do{
        int count=0;
        cout<<"1) Buscar salones por marca"<<endl;
        cout<<"2) Buscar salones por sistema operativo"<<endl;
        cout<<"3) Mostrar computadoras por salon"<<endl;
        cout<<"4) Terminar sesion"<<endl;
        cout<<"¿Que desea hacer?: ";
        cin>>op;
        switch(op){
            case 1:{
                cout<<endl;
                cout<<"¿Con cual marca quiere buscar?: ";
                cin>>marca;
                cout<<"Salones donde se encuentra: ";
                for (int i=0;i<salones;i++){
                    o=arr[i].getCompu();            // se agarran los valores de la variable compu del espacio i
                                                    // en el arreglo de salones, luego se guardan en el objeto o
                                                    // para poder usar las funciones 'get' de la clase Computadora
                    string check=o.getMarca();
                    datos=arr[i].getDatos();        // agarra los datos del salon dentro del espacio i
                    if (marca==check){              // si la marca que puso el usuario es igual a la que esta guardada
                        cout<<(datos%100)<<"  ";    // en el objeto o del espacio i, le muestra al usuario el salon
                        count++;
                    }
                }
                cout<<endl;
                if (count==0) {     // si no se encuentran salones, le avisa al usuario
                    cout<<"No se encontraron computadoras con ese sistema operativo."<<endl;
                }
                cout<<endl;
                break;
            }
            case 2:{    // son los mismos ciclos que el case 1, solo que en vez de variables de 'marca' son de 'os'
                cout<<endl;
                cout<<"¿Con cual sistema operativo quiere buscar?: ";
                cin.ignore();
                getline(cin,os);
                cout<<"Salones donde se encuentra: ";
                for (int i=0;i<salones;i++){
                    o=arr[i].getCompu();
                    string check=o.getOS();
                    datos=arr[i].getDatos();
                    if (os==check){
                        cout<<(datos%100)<<"  ";
                        count++;
                    }
                }
                cout<<endl;
                if (count==0) {
                    cout<<"No se encontraron computadoras con ese sistema operativo."<<endl;
                }
                cout<<endl;
                break;
            }
            case 3:{    // muestra en pantalla por numero de salon los datos de las computadoras.
                        // primero agarra todo en variables usando el mismo metodo de crear un objeto
                        // apartir del que esta guardado en el arreglo para luego usar las funciones de 'get'
                cout<<endl;
                for (int i=0;i<salones;i++){
                    cout<<"Salon #"<<i+1<<"..."<<endl;
                    datos=arr[i].getDatos();
                    o=arr[i].getCompu();
                    marca=o.getMarca();
                    os=o.getOS();
                    ram=o.getRAM();
                    cout<<"Numero de salon: "<<datos%100<<endl;
                    cout<<"Marca: "<<marca<<endl;
                    cout<<"Sistema Operativo: "<<os<<endl;
                    cout<<"RAM: "<<ram<<endl;
                    cout<<endl;
                }
                break;
            }
            case 4:{
                break;
            }
        }
        cout<<"----------------------------"<<endl;
    } while(op!=4);
    return 0;
}
