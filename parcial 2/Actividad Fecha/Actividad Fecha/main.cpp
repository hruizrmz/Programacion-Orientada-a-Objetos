//  Helena Ruiz Ramirez
//  A01282531
//  Febrero 15, 2018

//  Actividad Fecha
//  Descripcion: Programa para mostrar fechas de acuerdo a
//               un formato de estilo dd/nombre del mes/aa

#include <iostream>
#include <string>
#include "Fecha.h"
#include "Album.h"
using namespace std;

int main() {
    int op=0,albumes=0;
    Album arr[10];
    Fecha f;
    cout<<"Biblioteca de musica digital"<<endl;
    do {
        int dia,mes,anio,count=0;
        string nom,artista,genero;
        cout<<"1) Dar de alta albumes"<<endl;
        cout<<"2) Mostrar la lista completa"<<endl;
        cout<<"3) Buscar por artista"<<endl;
        cout<<"4) Buscar por genero"<<endl;
        cout<<"5) Salir"<<endl;
        cout<<"¿Que desea hacer?: ";
        cin>>op;
        cout<<endl;
        switch (op){
            case 1:{
                cout<<"¿Cuantos albumes quiere dar de alta?: ";
                cin>>albumes;
                while (albumes>5){
                    cout<<"Deben ser 10 o menos: ";
                    cin>>albumes;
                }
                cout<<endl;
                for (int i=0;i<albumes;i++){
                    cout<<"Album "<<i+1<<"..."<<endl;
                    cout<<"Nombre: ";
                    cin.ignore();
                    getline(cin,nom);
                    arr[i].setNom(nom);
                    cout<<"Artista: ";
                    getline(cin,artista);
                    arr[i].setArtista(artista);
                    cout<<"Genero: ";
                    getline(cin,genero);
                    arr[i].setGenero(genero);
                    cout<<"Fecha de lanzamiento (dd/mm/aa):"<<endl;
                    cout<<"Dia: ";
                    cin>>dia;
                    f.setDia(dia);
                    cout<<"Mes: ";
                    cin>>mes;
                    f.setMes(mes);
                    cout<<"Año: ";
                    cin>>anio;
                    f.setAnio(anio);
                    arr[i].setLanz(f);
                    cout<<endl;
                }
                break;
            }
            case 2:{
                for(int i=0;i<albumes;i++){
                    arr[i].Muestra();
                    cout<<endl;
                }
                break;
            }
            case 3:{
                cout<<"¿Por cual artista quieres buscar?: ";
                cin.ignore();
                getline(cin,artista);
                cout<<endl;
                for (int i=0;i<albumes;i++){
                    string check=arr[i].getArtista();
                    if (artista==check){
                        count++;
                        arr[i].Muestra();
                        cout<<endl;
                    }
                }
                if (count==1){
                    cout<<"Se encontro "<<count<<" album del artista "<<artista<<endl;
                }
                else {
                    cout<<"Se encontraron "<<count<<" albumes del artista "<<artista<<endl;
                }
                break;
            }
            case 4:{
                cout<<"¿Por cual genero quieres buscar?: ";
                cin.ignore();
                getline(cin,genero);
                cout<<endl;
                for (int i=0;i<albumes;i++){
                    string check=arr[i].getGenero();
                    if (genero==check){
                        count++;
                        arr[i].Muestra();
                        cout<<endl;
                    }
                }
                if (count==1){
                    cout<<"Se encontro "<<count<<" album del genero "<<artista<<endl;
                }
                else {
                    cout<<"Se encontraron "<<count<<" albumes del genero "<<artista<<endl;
                }
                break;
            }
            case 5:{
                break;
            }
        }
        cout<<"----------------------------"<<endl;
    } while(op!=5);
    cout<<endl;
    return 0;
}
