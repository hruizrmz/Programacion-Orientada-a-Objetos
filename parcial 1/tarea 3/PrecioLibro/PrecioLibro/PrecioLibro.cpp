//  Helena Ruiz Ramirez
//  A01282531
//  Febrero 1, 2018

//  Tarea 3: Clases y Objetos
//  Ejercicio 1: Precio de un libro
//  Descripcion: El programa sube por un percentaje el precio de
//               un libro basandose en su titulo y autor.

#include <iostream>
#include "Libro.h"
using namespace std;

int main() {
    string t,a;
    double p;
    Libro precio;
    //  el usuario mete al programa los datos de su libro y se guardan
    //  como atributos de un objeto clase Libro.
    cout<<"Por favor ingrese los datos de su libro."<<endl;
    cout<<"Titulo: ";
    cin>>t;
    precio.setTitulo(t);
    cout<<"Autor: ";
    cin>>a;
    precio.setAutor(a);
    cout<<"Precio: ";
    cin>>p;
    precio.setPrecio(p);
    cout<<endl;
    //  el programa muestra al usuario la informacion que acaba de escribir
    //  como metodo de confirmacion antes de cambiar el precio.
    cout<<"Su libro es ''"<<precio.getTitulo()<<"'' escrito por "<<precio.getAutor()<<" con un precio actual de "<<precio.getPrecio()<<" pesos."<<endl;
    cout<<endl;
    //  se manda a llamar la funcion para cambiar el precio localizada
    //  en el header de la clase
    precio.SubePrecio(t,a);
    precio.Muestra();
    return 0;
}
