#include <iostream>
#include <string>
#include "CtaBanc.h"
using namespace std;

int main() {
    CtaBanc c;
    string nom;
    int sal,op;
    
    cout<<"Nombre: ";
    cin>>nom;
    c.setNombre(nom);
    cout<<"Saldo: ";
    cin>>sal;
    c.setSaldo(sal);
    cout<<endl;
    
    do {
        double din;
        cout<<"¿Que desea hacer?"<<endl;
        cout<<"1) Checar saldo"<<endl;
        cout<<"2) Depositar"<<endl;
        cout<<"3) Retirar"<<endl;
        cout<<"4) Salir"<<endl;
        cin>>op;
        switch(op) {
            case 1:
                cout<<c.getNombre()<<", su saldo es de "<<c.getSaldo()<<"$"<<endl;
                break;
            case 2:
                cout<<"Cantidad a depositar: ";
                cin>>din;
                c.Deposita(din);
                cout<<"Saldo total: "<<c.getSaldo()<<"$"<<endl;
                break;
            case 3:
                cout<<"Cantidad a retirar: ";
                cin>>din;
                c.Retira(din);
                cout<<"Saldo restante: "<<c.getSaldo()<<"$"<<endl;
                break;
            case 4:
                op=4;
                break;
        }
        cout<<endl;
    } while(op!=4);
    
    return 0;
}
