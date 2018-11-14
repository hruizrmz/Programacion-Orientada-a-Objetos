//  Helena Ruiz Ramirez
//  A01282531
//  Febrero 1, 2018

//  Tarea 4: Arreglos de Objetos
//  Descripcion: Aplicacion que permite modificar datos sobre los equipos
//               de futbol dentro de la liga mexicana.

#include <iostream>
#include <iomanip>
#include "Equipo.h"
using namespace std;

int main() {
    int op,espacio=0;
    Equipo lista[15];
    
    cout<<"Bienvenido al sistema de equipos de la Liga Mexicana."<<endl;
    do {
        int equipos,game,tie,win;
        string nom;
        cout<<"1. Dar de alta equipos"<<endl;
        cout<<"2. Modificar partidos jugados"<<endl;
        cout<<"3. Modificar partidos empatados"<<endl;
        cout<<"4. Registrar partidos ganados"<<endl;
        cout<<"5. Ver lista de equipos"<<endl;
        cout<<"6. Terminar la sesion"<<endl;
        cout<<"Opcion: ";
        cin>>op;
        switch(op){
            case 1: {
                cout<<endl;
                cout<<"¿Cuantos equipos desea registrar?: ";
                cin>>equipos;
                while (equipos>(15-espacio)){
                    cout<<"Deben ser "<<(15-espacio)<<" o menos equipos: ";
                    cin>>equipos;
                }
                cout<<endl;
                for(int i=0;i<equipos;i++){
                    cout<<"Equipo "<<(i+1)<<": ";
                    cin>>nom;
                    lista[i+espacio].setNom(nom);
                }
                espacio+=equipos;
                cout<<endl;
                cout<<"Se registraron los equipos."<<endl;
                break;
            }
            case 2: {
                bool found=false;
                cout<<endl;
                cout<<"Nombre del equipo que desea modificar: ";
                cin>>nom;
                cout<<endl;
                for (int i=0;i<espacio && !found;i++){
                    if (nom==lista[i].getNom()){
                        cout<<"Numero de partidos que ha jugado: ";
                        cin>>game;
                        cout<<endl;
                        while (game<0){
                            cout<<"Deben de ser 0 o mas: ";
                            cin>>game;
                        }
                        lista[i].setGame(game);
                        cout<<"Se registraron los partidos."<<endl;
                        found=true;
                    }
                }
                if (found==false){
                    cout<<"No se encontro el equipo. Por favor delo de alta primero."<<endl;
                }
                break;
            }
            case 3: {
                bool found=false;
                cout<<endl;
                cout<<"Nombre del equipo que desea modificar: ";
                cin>>nom;
                cout<<endl;
                for (int i=0;i<espacio && !found;i++){
                    if (nom==lista[i].getNom()){
                        game=lista[i].getGame();
                        win=lista[i].getWin();
                        if (game==0){
                            cout<<"Este equipo no tiene partidos registrados. Por favor haga la opcion 2 primero."<<endl;
                            found=true;
                            break;
                        }
                        cout<<"Cantidad de partidos que ha empatado: ";
                        cin>>tie;
                        while (tie<0){
                            cout<<"Deben de ser 0 o mas: ";
                            cin>>tie;
                        }
                        cout<<endl;
                        while (tie>(game-win)){
                            cout<<"Deben ser "<<(game-win)<<" o menos partidos: ";
                            cin>>tie;
                        }
                        lista[i].setTie(tie);
                        cout<<"Se registraron los empates."<<endl;
                        found=true;
                    }
                }
                if (found==false){
                    cout<<"No se encontro el equipo. Por favor delo de alta primero."<<endl;
                }
                break;
            }
            case 4: {
                bool found=false;
                cout<<endl;
                cout<<"Nombre del equipo que desea modificar: ";
                cin>>nom;
                cout<<endl;
                for (int i=0;i<espacio && !found;i++){
                    if (nom==lista[i].getNom()){
                        game=lista[i].getGame();
                        tie=lista[i].getTie();
                        if (game==0){
                            cout<<"Este equipo no tiene partidos registrados. Por favor haga la opcion 2 primero."<<endl;
                            found=true;
                            break;
                        }
                        cout<<"Cantidad de partidos que ha ganado: ";
                        cin>>win;
                        while (win<0){
                            cout<<"Deben de ser 0 o mas: ";
                            cin>>win;
                        }
                        cout<<endl;
                        while (win>(game-tie)){
                            cout<<"Deben ser "<<(game-tie)<<" o menos partidos: ";
                            cin>>win;
                        }
                        lista[i].newWin(win);
                        cout<<"Se registraron los partidos ganados."<<endl;
                        found=true;
                    }
                }
                if (found==false){
                    cout<<"No se encontro el equipo. Por favor delo de alta primero."<<endl;
                }
                break;
            }
            case 5: {
                cout<<endl;
                cout<<"Nombre"<<setw(10)<<"Partidos"<<setw(10)<<"Empates"<<setw(10)<<"Ganados"<<setw(10)<<"Puntaje"<<endl;
                for(int i=0;i<espacio;i++){
                    lista[i].calcScore();
                    lista[i].printList();
                }
                break;
            }
            case 6: {
                break;
            }
        }
        cout<<"-----------------------------------"<<endl;
    } while(op!=6);
    return 0;
}
