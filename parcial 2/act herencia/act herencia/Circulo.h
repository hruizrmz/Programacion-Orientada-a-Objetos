#ifndef Circulo_h
#define Circulo_h
#include "Figura.h"
class Circulo: public Figura{
private:
    double dRadio;
public:
    Circulo();
    Circulo(double);
    Circulo(Punto,string,double);
    void setRadio(double);
    double getRadio();
    double calcularArea();
    double calcularPerimetro();
    void desplegar();
};
Circulo::Circulo(){
    dRadio=0;
}
Circulo::Circulo(double r){
    dRadio=r;
}
Circulo::Circulo(Punto centro,string sColor,double r):Figura(centro,sColor){
    dRadio=r;
}
void Circulo::setRadio(double r){
    dRadio=r;
}
double Circulo::getRadio(){
    return dRadio;
}
double Circulo::calcularArea(){
    double a = (3.1416)*(dRadio)*(dRadio);
    return a;
}
double Circulo::calcularPerimetro(){
    double a = 2*(3.1416)*(dRadio);
    return a;
}
void Circulo::desplegar(){
    Figura::desplegar();
    cout<<"Radio: "<<dRadio;
}
#endif /* Circulo_h */
