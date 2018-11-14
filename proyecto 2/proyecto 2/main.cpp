//  Helena Ruiz Ramirez (A01282531) , Gilberto Alejandro Castillo Perez (A00821306)
//  12/marzo/2018
//  Proyecto 2: Prestamo de Libros 
//  Descripcion: Sistema para una red de bibliotecas donde se pueden checar las bibliotecas,
//               libros, alumnos, prestamos y demas.
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Libros.h"
#include "Fecha.h"
#include "Alumno.h"
#include "Biblioteca.h"
using namespace std;
int main() {
    string linea, titulo, clave, ISBN;
    long e;
    int i=0,libros=0,mat,d,m,a,op;
    char c;
    bool found;
    Biblioteca arrB[5];
    Alumno arrA[15];
    Libros arrL[10];
    ifstream ent;
    ent.open("Biblioteca.txt");
    while (!ent.eof() && i<5){
        //  ciclo para guardar los datos del archivo Biblioteca.txt dentro del arreglo arrB[].
        //  lee cada dato separado por espacios de una manera especializada para cada uno.
        int est=0;
        getline(ent,linea);
        e=linea.find(" ");
        clave=linea.substr(0,e);
        arrB[i].setClaveBiblio(clave);
        linea.erase(0,e+1);
        c=linea[0];
        arrB[i].setPiso(c-48);
        linea.erase(0,2);
        e=linea.find(" ");
        string estante=linea.substr(0,e+1);
        if (estante.length()==3){
            c=estante[0];
            est+=(c-48)*10;
            linea.erase(0,1);
        }
        c=linea[0];
        est+=(c-48);
        arrB[i].setEstante(est);
        linea.erase(0,2);
        arrB[i].setClave(linea);
        i++;
    }
    ent.close();
    ent.clear();
    ent.open("Alumno.txt");
    i=0;
    while (!ent.eof() && i<15){
        //  ciclo para guardar los datos del archivo Alumno dentro del arreglo arrA[].
        //  lee cada dato separado por espacios de una manera especializada para cada uno.
        mat=0;
        getline(ent,linea);
        c=linea[0];
        mat+=(c-48)*100;
        c=linea[1];
        mat+=(c-48)*10;
        c=linea[2];
        mat+=(c-48);
        arrA[i].setMatricula(mat);
        linea.erase(0,4);
        string car=linea.substr(0,4);
        arrA[i].setCarrera(car);
        linea.erase(0,4);
        arrA[i].setNombre(linea);
        i++;
    }
    ent.close();
    cout<<"¿Cuantos libros desea registar?: ";
    cin>>libros;
    while (libros>10){
        cout<<"Deben ser 10 o menos: ";
        cin>>libros;
    }
    for (int j=0;j<libros;j++){
        //  ciclo para guardar los datos del numero de libros especificados por el usuario
        cout<<endl;
        cout<<"Titulo del Libro "<<j+1<<": ";
        cin>>titulo;
        arrL[j].setTitulo(titulo);
        cout<<"Biblioteca (Clave): ";
        cin>>clave;
        arrL[j].setClaveBiblio(clave);
        cout<<"ISBN: ";
        cin>>ISBN;
        arrL[j].setISBN(ISBN);
        cout<<"Fecha de Prestamo (xx/xx/xx)"<<endl;
        cout<<"Dia: ";
        cin>>d;
        cout<<"Mes: ";
        cin>>m;
        cout<<"Año: ";
        cin>>a;
        Fecha f (d,m,a);
        arrL[j].setFecha_Prestamo(f);
        cout<<"Dias de Prestamo: ";
        cin>>d;
        arrL[j].setDiasPrestamo(d);
    }
    cout<<"-----------------------------"<<endl;
    do{
        //  menu de opciones para el sistema
        cout<<"1) Consultar todos los libros"<<endl;
        cout<<"2) Rentar un libro"<<endl;
        cout<<"3) Consultar entregas por fecha"<<endl;
        cout<<"4) Consultar por ISBN"<<endl;
        cout<<"5) Consultar por biblioteca"<<endl;
        cout<<"6) Consultar rentas activas"<<endl;
        cout<<"7) Terminar la sesion"<<endl;
        cout<<"¿Que desea hacer?: ";
        cin>>op;
        switch (op) {
            case 1: {
                //  muestra todos los libros en el sistema
                for (int j=0;j<libros;j++){
                    cout<<endl;
                    cout<<"Libro "<<j+1<<"..."<<endl;
                    cout<<"Titulo: "<<arrL[j].getTitulo()<<endl;
                    cout<<"Biblioteca (Clave): "<<arrL[j].getClaveBiblio()<<endl;
                    cout<<"ISBN: "<<arrL[j].getISBN()<<endl;
                    Fecha f=arrL[j].getFecha_Prestamo();
                    cout<<"Fecha de Prestamo: ";
                    f.muestra();
                }
                break;
            }
            case 2: {
                cout<<endl;
                found=false;
                cout<<"Escriba su matricula: ";
                cin>>mat;
                //  se confirma si existe la matricula dentro
                //  de los datos guardados del archivo "Alumno.txt"
                for (int j=0;j<15;j++){
                    if (mat==arrA[j].getMatricula())
                        found=true;
                }
                if (!found){
                    cout<<"No existe el alumno, por lo que no se realizo el prestamo."<<endl;
                    cout<<"Por favor intente de nuevo."<<endl;
                    break;
                }
                found=false;
                //  realiza el mismo ciclo para checar si se
                //  encuentran libros existentes con cierto ISBN
                cout<<"Escriba el ISBN del libro: ";
                cin>>ISBN;
                for (int j=0;j<libros;j++){
                    if (ISBN==arrL[j].getISBN())
                        found=true;
                }
                if (!found){
                    cout<<"No existe el libro, por lo que no se realizo el prestamo."<<endl;
                    cout<<"Por favor intente de nuevo."<<endl;
                    break;
                }
                bool exist = arrL[0].prestamos(ISBN,mat);
                cout<<endl;
                //  anuncia si el prestamo fue exitoso o no
                //  dependiendo del valor de la variable "exist"
                if (exist)
                    cout<<"Ha rentado el libro exitosamente."<<endl;
                else
                    cout<<"No se realizo el prestamo del libro. Por favor intente de nuevo."<<endl;
                break;
            }
            case 3: {
                //  busca libros que tengan que devolverse en la fecha que puso el usuario
                cout<<endl;
                found=false;
                cout<<"Escriba la fecha que quiere buscar (xx/xx/xx)... "<<endl;
                cout<<"Dia: ";
                cin>>d;
                cout<<"Mes: ";
                cin>>m;
                cout<<"Año: ";
                cin>>a;
                Fecha f (d,m,a);
                cout<<endl;
                for (int j=0;j<15;j++){
                    Fecha f2=arrL[j].getFecha_Prestamo();
                    if (f==f2){
                        //  si la fecha del usuario es igual a la de un libro rentado,
                        //  muestra los datos de ese libro
                        cout<<"Libro "<<j+1<<"..."<<endl;
                        cout<<"Titulo: "<<arrL[j].getTitulo()<<endl;
                        cout<<"Biblioteca (Clave): "<<arrL[j].getClaveBiblio()<<endl;
                        cout<<"ISBN: "<<arrL[j].getISBN()<<endl;
                        cout<<"Fecha de Prestamo: ";
                        f2.muestra();
                        cout<<endl;
                        found=true;
                    }
                }
                if (!found)
                    //  igualmente muestra si no se encontro nada
                    cout<<"No se encontraron libros con esa fecha."<<endl;
                break;
            }
            case 4: {
                //  otro metodo de busqueda, pero esta vez el usuario inscribe un ISBN
                cout<<endl;
                found=false;
                cout<<"Escriba el ISBN que quiere buscar: ";
                cin>>ISBN;
                for (int j=0;j<libros;j++){
                    if (ISBN==arrL[j].getISBN()){
                        //  muestra los datos del libro con el mismo ISBN
                        cout<<"Libro "<<j+1<<"..."<<endl;
                        cout<<"Titulo: "<<arrL[j].getTitulo()<<endl;
                        cout<<"Biblioteca (Clave): "<<arrL[j].getClaveBiblio()<<endl;
                        cout<<"ISBN: "<<arrL[j].getISBN()<<endl;
                        cout<<"Fecha de Prestamo: ";
                        Fecha f = arrL[j].getFecha_Prestamo();
                        f.muestra();
                        //  esta busqueda tambien muestra si el libro esta rentado y los
                        //  nombres de los alumnos que lo tienen
                        int a=arrL[j].getListaAlumnos(j);
                        if (a>0){
                            cout<<"Alumnos que han rentado el libro: "<<endl;
                            for (int b=0;b<10;b++){
                                mat=arrL[j].getListaAlumnos(b);
                                if (mat!=0){
                                    for (int c=0;c<15;c++){
                                        if (arrA[c].getMatricula()==mat)
                                            // imprime el nombre correspondiente de la
                                            //  matricula asignada al libro
                                            cout<<arrA[c].getNombre();
                                    }
                                }
                            }
                            cout<<endl;
                        }
                        else
                            cout<<"El libro no ha sido prestado por nadie."<<endl;
                        found=true;
                    }
                }
                if (!found)
                    cout<<"No se encontraron libros con ese ISBN."<<endl;
                break;
            }
            case 5: {
                //  hace una busqueda de todos los libros, mostrando los que estan bajo
                //  la clave de biblioteca que inscribio el usuario
                cout<<endl;
                found=false;
                cout<<"Escriba la clave de la biblioteca: ";
                cin>>clave;
                for (int j=0;j<5;j++){
                    if (clave==arrB[j].getClaveBiblio())
                        found=true;
                }
                if (!found){
                    cout<<"No existe esa biblioteca. Por favor intente otra busqueda."<<endl;
                    break;
                }
                found=false;
                for (int j=0;j<10;j++){
                    if (clave==arrL[j].getClaveBiblio()){
                        //  muestra los datos de todos los libros en la biblioteca
                        found=true;
                        cout<<"Libro "<<j+1<<"..."<<endl;
                        cout<<"Titulo: "<<arrL[j].getTitulo()<<endl;
                        cout<<"Biblioteca (Clave): "<<arrL[j].getClaveBiblio()<<endl;
                        cout<<"ISBN: "<<arrL[j].getISBN()<<endl;
                        cout<<"Fecha de Prestamo: ";
                        Fecha f = arrL[j].getFecha_Prestamo();
                        f.muestra();
                    }
                }
                if (!found){
                    cout<<"No se encontraron prestamos de esa biblioteca."<<endl;
                }
                break;
            }
            case 6: {
                cout<<endl;
                bool alum=false;
                found=false;
                cout<<"Escriba su matricula: ";
                cin>>mat;
                //  se confirma si existe la matricula
                for (int j=0;j<15;j++){
                    if (mat==arrA[j].getMatricula()){
                        found=true;
                        // imprime los datos del alumno
                        cout<<"Nombre: "<<arrA[j].getNombre()<<endl;
                        cout<<"Carrera: "<<arrA[j].getCarrera()<<endl;
                    }
                }
                cout<<endl;
                for (int b=0;b<10;b++){
                    //  checa si la matricula que puso el usuario queda con
                    //  alguna matricula guardada en el arreglo de algun libro,
                    //  es decir, si el libro fue rentado bajo esa matricula
                    if (mat==arrL[b].getListaAlumnos(b)){
                        found=true;
                        alum=true;
                        cout<<"Libro "<<b+1<<"..."<<endl;
                        cout<<"Titulo: "<<arrL[b].getTitulo()<<endl;
                        cout<<"Biblioteca (Clave): "<<arrL[b].getClaveBiblio()<<endl;
                        cout<<"ISBN: "<<arrL[b].getISBN()<<endl;
                        cout<<"Fecha de Prestamo: ";
                        Fecha f = arrL[b].getFecha_Prestamo();
                        f.muestra();
                    }
                }
                if (!found){
                    cout<<"No existe el alumno. Por favor intente de nuevo."<<endl;
                    break;
                }
                else if (!alum){
                    cout<<"El alumno no tiene rentas activas."<<endl;
                    break;
                }
            }
            case 7: {
                //  opcion para terminar el programa
                break;
            }
        }
        cout<<"-----------------------------"<<endl;
    } while(op!=7);
    return 0;
}
