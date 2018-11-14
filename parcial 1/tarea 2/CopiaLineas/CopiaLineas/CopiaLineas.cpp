//  Helena Ruiz Ramirez
//  A01282531
//  Enero 25, 2018

//  Tarea 2: Strings y Archivos
//  Ejercicio 2: CopiaLineas
//  Descripcion: Copia las ultimas lineas indicadas
//               de un archivo ya existente a uno nuevo

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void CopiaFichero (int iNum, string arch) {
    string i,edit;
    int lineas=0;
    ifstream archEnt;
    ofstream archSal;
    archSal<<" ";
    archEnt.open(arch);
    archSal.open("Edit.txt");
    while (!archEnt.eof()) {
        getline(archEnt,i);
        lineas++;
    }
    while (iNum>lineas) {
        cout<<"No se puede realizar la copia. Intente con menos lineas: ";
        cin>>iNum;
        cin.ignore();
    }
    cout<<endl;
    archEnt.close();
    archEnt.open(arch);
    while (!archEnt.eof()) {
        getline(archEnt,i);
        --lineas;
        if (lineas<iNum) {
            archSal<<i<<endl;
            cout<<i<<endl;
        }
    }
    archEnt.close();
    archSal.close();
}

int main() {
    string archivo;
    int num;
    cout<<"Nombre del archivo exacto (ABC.txt): ";
    cin>>archivo;
    cout<<endl;
    cout<<"Cantidad de lineas que desea imprimir: ";
    cin>>num;
    CopiaFichero(num,archivo);
    cout<<endl;
    return 0;
}
