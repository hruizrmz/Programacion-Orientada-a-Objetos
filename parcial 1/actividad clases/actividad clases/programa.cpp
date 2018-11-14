#include <iostream>
#include "Fraccion.h"
using namespace std;

int main() {
    Fraccion arr[5];
    int op, indice;
    double iNum,iDen,dNum,dDen;
    bool found;
    dNum=f.getNum();
    dDen=f.getDen();
    cout<<"Numerador: ";
    cin>>iNum;
    f.setNum(iNum);
    cout<<"Denominador: ";
    cin>>iDen;
    f.setDen(iDen);
    cout<<endl;
    f.CalcValorReal(dNum,dDen);
    f.CalcValorReal(iNum,iDen);
    cout<<endl;
    
    do {
        cout<<"¿Que desea hacer?"<<endl;
        cout<<"1) Dar de alta una fraccion"<<endl;
        cout<<"2) Sumar fracciones"<<endl;
        cout<<"3) Fraccion mayor"<<endl;
        cout<<"4) Fracciones mayores que uno"<<endl;
        cout<<"5) Terminar"<<endl;
        cin>>op;
        cout<<endl;
        switch (op) {
            case 1:
                if (indice<8) {
                    cout<<"Numerador: ";
                    cin>>iNum;
                    arr[indice].setNum(iNum);
                    indice++;
                }
                else
                    cout<<"No hay espacio en el arreglo."<<endl;
                break;
            case 2:
                found=false;
                cout<<"Numero de la fraccion: ";
                cin>>num-1;
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
            case 5:
                break;
        }
        cout<<"----------------------"<<endl;
    } while(op!=5);
    
    
    
    return 0;
}
