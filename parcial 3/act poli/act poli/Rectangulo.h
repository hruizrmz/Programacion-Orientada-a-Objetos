#ifndef Rectangulo_h
#define Rectangulo_h
#include "Figura.h"
using namespace std;
class Rectangulo:public Figura{
private:
    double base,altura;
public:
    Rectangulo(double,double);
    void setBase(double);
    void setAltura(double);
    double getBase();
    double getAltura();
    double calcArea();
    double calcPerimetro();
    void muestraQueSoy();
};
Rectagulo::Rectangulo(double b,double h):Figura(){
    base=b;
    altura=h;
}
void Rectangulo::setBase(double b){
    base=b;
}
void Rectangulo::setAltura(double h){
    altura=h;
}
double Rectangulo::getBase(){
    return base;
}
double Rectangulo::getAltura(){
    return altura;
}
double Rectangulo::calcArea(){
    return base*altura;
}
///////////////////////////////////
double Rectangulo::calcPerimetro(){
    return (base*2)+(altura*2);
}
///////////////////////////////////
void Rectangulo::muestraQueSoy(){
    cout<<"Soy un rectangulo."<<endl;
}
#endif /* Rectangulo_h */
