#ifndef Chequera_h
#define Chequera_h
#include "CtaBanc.h"
using namespace std;
class Chequera:public CtaBanc{
public:
    Chequera();
    Chequera(int);
    int getCom();
    void setCom(int);
    void muestra();
private:
    int comision;
};

Chequera():CtaBanc(){
    comision=0;
}
Chequera::Chequera(int n, int s,int c):CtaBanc(n,s){
    comision=c;
}
int Chequera::getCom(){
    return comision;
}
void Chequera::setCom(int c){
    comision=c;
}
void Chequera::muestra(){
    cout<<"Numero de Cuenta: "<<n<<endl;
    cout<<"Saldo: "<<s<<endl;
    cout<<"Comision: "<<c<<endl;
}

#endif /* Chequera_h */
