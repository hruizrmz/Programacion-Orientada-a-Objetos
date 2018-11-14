#ifndef Circulo_h
#define Circulo_h
#include "Figura.h"
using namespace std;
class Circulo:public Figura{
private:
    double radio;
public:
    Circulo(double);
    void setRadio(double);
    double getRadio();
    double calcArea();
    double calcPerimetro();
    void muestraQueSoy();
};
Circulo::Circulo(double r):Figura(){
    radio=r;
}
void Circulo::setRadio(double r){
    radio =r;
}
double Circulo::getRadio(){
    return radio;
}
double Circulo::calcArea(){
    return 3.1416*(radio)^2;
}
double Circulo::calcPerimetro(){
    return 2*radio*3.1416;
}
void Circulo::muestraQueSoy(){
    cout<<"Soy un circulo."<<endl;
}
#endif /* Circulo_h */
