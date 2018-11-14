#ifndef FIGURA_H_INCLUDED
#define FIGURA_H_INCLUDED
#include "Punto.h"
class Figura{
protected:
    Punto centro;
    string sColor;
public:
    Figura();
    Figura(Punto centro, string sColor);
    void SetsColor(string sColor);
    string GetsColor();
    void SetCentro(Punto centro);
    Punto GetCentro();
    double calcularArea();
    double clacularPerimetro();
    void desplegar();
    void desplazar(double dDeltaX, double dDeltaY);
};
//
Figura::Figura(){
    sColor = "Blanco";
    cout << "Figura()" << endl;
}
Figura::Figura(Punto centro, string sColor){
    this->centro = centro;
    this->sColor = sColor;
}
void Figura::SetsColor(string sColor){
    this->sColor = sColor;
}
string Figura::GetsColor(){
    return sColor;
}
void Figura::SetCentro(Punto centro){
    this->centro = centro;
}
Punto Figura::GetCentro(){
    return centro;
}
//
double Figura::calcularArea(){
    cout << "Calcular area" << endl;
    return 0;
}
double Figura::clacularPerimetro(){
    cout << "Calcular perimetro" << endl;
    return 0;
}
void Figura::desplegar(){
    cout << "****************************" << endl;
    cout << "Figura = " << endl;
    centro.desplegar();
    cout << "Color = "<< sColor << endl;
}
void Figura::desplazar(double dDeltaX, double dDeltaY ){
    centro.desplazar(dDeltaX,dDeltaY);
}
#endif // FIGURA_H_INCLUDED
