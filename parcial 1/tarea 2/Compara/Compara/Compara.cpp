//  Helena Ruiz Ramirez
//  A01282531
//  Enero 25, 2018

//  Tarea 2: Strings y Archivos
//  Ejercicio 1: Compara
//  Descripcion: Compara las diferencias de texto entre
//               dos archivos y luego imprime las lineas
//               completas donde se encuentran.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string texto1,texto2,linea1, linea2;
    ifstream entrada1,entrada2;
    entrada1.open("ArchUno.txt");
    entrada2.open("ArchDos.txt");
    while (!entrada1.eof() && !entrada2.eof()) {
        getline(entrada1, linea1);
        getline(entrada2, linea2);
        if (linea1!=linea2) {
            cout<<"Se encontraron lineas diferentes en el texto."<<endl;
            cout<<"Arch1: "<<linea1<<endl;
            cout<<"Arch2: "<<linea2<<endl;
        }
    }
    entrada1.close();
    entrada2.close();
    cout<<endl;
    return 0;
}
