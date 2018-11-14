#include <iostream>
#include "Factura.h"
using namespace std;

int main() {
    Factura articulos[8];
    int op, indice=0, num, cant;
    string nom;
    double precio,total;
    bool found;
    
    do {
        cout<<"¿Que desea hacer?"<<endl;
        cout<<"1) Cobrar un articulo"<<endl;
        cout<<"2) Total a pagar por articulo"<<endl;
        cout<<"3) Total a pagar por la factura"<<endl;
        cout<<"4) Salir"<<endl;
        cin>>op;
        cout<<endl;
        switch (op) {
            case 1:
                if (indice<8) {
                    cout<<"Por favor escribe los datos del articulo..."<<endl;
                    cout<<"Numero: ";
                    cin>>num;
                    articulos[indice].setNumArt(num);
                    cout<<"Nombre: ";
                    cin>>nom;
                    articulos[indice].setNombre(nom);
                    cout<<"Cantidad: ";
                    cin>>cant;
                    articulos[indice].setCant(cant);
                    cout<<"Precio: ";
                    cin>>precio;
                    articulos[indice].setPrecio(precio);
                    indice++;
                }
                else
                    cout<<"No caben mas articulos."<<endl;
                break;
            case 2:
                found=false;
                cout<<"Numero del articulo: ";
                cin>>num;
                for (int i=0;i<indice && !found;i++){
                    if (num==articulos[i].getNumArt()){
                        cout<<"El total es "<<articulos[i].calculaTotal()<<"$"<<endl;
                        found=true;
                    }
                }
                if (found==false)
                    cout<<"No se encontro el articulo. Por favor delo de alta primero."<<endl;
                break;
            case 3:
                total=0;
                for (int i=0;i<indice;i++){
                    total+=articulos[i].calculaTotal();
                }
                cout<<"El total a pagar es "<<total<<"$"<<endl;
                break;
            case 4:
                break;
        }
        cout<<"----------------------"<<endl;
    } while(op!=4);
    return 0;
}
