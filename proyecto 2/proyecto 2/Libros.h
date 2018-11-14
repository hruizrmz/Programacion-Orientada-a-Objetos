//  Helena Ruiz Ramirez (A01282531) , Gilberto Alejandro Castillo Perez (A00821306)
//  12/marzo/2018
//  Proyecto 2: Libros header

#ifndef Libros_h
#define Libros_h
#include "Fecha.h"
#include "Alumno.h"
#include "Biblioteca.h"
#include <string>
class Libros{
private:
    Fecha Fecha_Prestamo;
    int diasPrestamo;
    string Titulo;
    string claveBiblio;
    string ISBN;
    int prestados;
    int listaAlumnos[10];
public:
    ///Constructores
    Libros();
    Libros(Fecha, int, string, string, string, int);
    ///Metodos de Modificacion
    void setFecha_Prestamo(Fecha);
    void setDiasPrestamo(int);
    void setTitulo(string);
    void setClaveBiblio(string);
    void setISBN(string);
    ///Metodos de Acceso
    Fecha getFecha_Prestamo();
    int getDiasPrestamo();
    string getTitulo();
    string getClaveBiblio();
    string getISBN();
    int getListaAlumnos(int);
    int getPrestados();
    ///Metodos de operacion
    void calculaFechaFinPrestamo(Fecha Fecha_Prestamo, int diasPrestamo);
    bool prestamos(string,int);
};
/////////////////////////////////////////////////////////////////////////////
//Constructores
Libros::Libros(){
    Fecha();
    diasPrestamo = 0;
    Titulo =" ";
    claveBiblio = " ";
    ISBN = " ";
    prestados = 0;
    int i=0;
    while (i<10) {
        listaAlumnos[i]=0;
        i++;
    }
}
//Metodos de Modificacion
void Libros::setFecha_Prestamo(Fecha Fecha_Prestamo){
    this ->Fecha_Prestamo = Fecha_Prestamo;
}
void Libros::setDiasPrestamo(int dp){
    diasPrestamo = dp;
}
void Libros::setTitulo(string t){
    Titulo = t;
}
void Libros::setClaveBiblio(string cb){
    claveBiblio = cb;
}
void Libros::setISBN(string i){
    ISBN = i;
}
//Metodos de Acceso
Fecha Libros::getFecha_Prestamo(){
    return Fecha_Prestamo;
}
int Libros::getDiasPrestamo(){
    return diasPrestamo;
}
string Libros::getTitulo(){
    return Titulo;
}
string Libros::getClaveBiblio(){
    return claveBiblio;
}
string Libros::getISBN(){
    return ISBN;
}
int Libros::getListaAlumnos(int indice){
    return listaAlumnos[indice];
}
int Libros::getPrestados(){
    return prestados;
}
/////////////////////////////////////////////////////////////////////////////
// Metodos de Operacion
void Libros::calculaFechaFinPrestamo(Fecha Fecha_Prestamo, int diasPrestamo){
    //  le suma a una fecha de prestamo dias para cambiar su valor
    //  a la fecha que se tiene que regresar un libro.
    Fecha_Prestamo+=diasPrestamo;
}

bool Libros::prestamos(string ISBN, int matricula){
    //  metodo para indicar si se pudo rentar un libro o no. checa que
    //  no haya rentado el alumno ya ese libro y que quede espacio
    //  suficiente en el sistema para registrar su prestamo.
    int space=0;
    for (int i=0;i<10;i++){
        if ((listaAlumnos[i]==matricula)&&(ISBN==ISBN)){
            cout<<"Ya tiene rentado ese libro."<<endl;
            return false;
        }
        else if (listaAlumnos[i]==0){
            listaAlumnos[i]=matricula;
            this->ISBN=ISBN;
            prestados++;
            return true;
        }
        space++;
    }
    if (space==10){
        cout<<"No quedan libros disponibles para rentar."<<endl;
        return false;
    }
    else
        return false;
}
#endif /* Libros_h */
