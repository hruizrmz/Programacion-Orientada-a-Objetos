#ifndef Rectangulo_h
#define Rectangulo_h
#include "Figura.h"
class Rectangulo: public Figura{
private:
    double dBase;
    double dAltura;
public:
    Rectangulo();
    Rectangulo(Punto,string,double,double);
    void setBase(double);
    void setAltura(double);
    double getBase();
    double getAltura();
    double calcularArea();
    double calcularPerimetro();
    void desplegar();
};
Rectangulo::Rectangulo(){
    dBase=0;
    dAltura=0;
}
Rectangulo::Rectangulo(Punto centro,string sColor,double b,double h):Figura(centro,sColor){
    dBase=b;
    dAltura=h;
}
void Rectangulo::setBase(double b){
    dBase=b;
}
void Rectangulo::setAltura(double h){
    dAltura=h;
}
double Rectangulo::getBase(){
    return dBase;
}
double Rectangulo::getAltura(){
    return dAltura;
}
double Rectangulo::calcularArea(){
    double a = dBase * dAltura;
    return a;
}
double Rectangulo::calcularPerimetro(){
    double a = 2*(dBase + dAltura);
    return a;
}
void Rectangulo::desplegar(){
    Figura::desplegar();
    cout<<"Base: "<<dBase<<endl;
    cout<<"Altura: "<<dAltura;
}
#endif /* Rectangulo_h */
