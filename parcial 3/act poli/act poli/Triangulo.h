#ifndef Triangulo_h
#define Triangulo_h
#include "Figura.h"
using namespace std;
class Triangulo:public Figura{
private:
    double base,altura;
public:
    Triangulo(double,double);
    void setBase(double);
    void setAltura(double);
    double getBase();
    double getAltura();
    double calcArea();
    double calcPerimetro();
    void muestraQueSoy();
};
Triangulo::Triangulo(double b,double h):Figura(){
    base=b;
    altura=h;
}
void Triangulo::setBase(double b){
    base=b;
}
void Triangulo::setAltura(double h){
    altura=h;
}
double Triangulo::getBase(){
    return base;
}
double Triangulo::getAltura(){
    return altura;
}
double Triangulo::calcArea(){
    return (base*altura)/2;
}
///////////////////////////////////
double Triangulo::calcPerimetro(){
    return
}
///////////////////////////////////
void Triangulo::muestraQueSoy(){
    cout<<"Soy un triangulo."<<endl;
}
#endif /* Triangulo_h */
