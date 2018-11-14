#ifndef PUNTO_H_INCLUDED
#define PUNTO_H_INCLUDED
#include <math.h>
using namespace std;
class Punto {
protected:
    double dX;
    double dY;
public:
    // Constructores
    Punto();
    Punto (double dX, double dY);
    //setters and getters
    void SetdX(double dX);
    double GetdX();
    void SetdY(double dY);
    double GetdY();
    // Calcula la distancia entre dos puntos- actual y p2
    double distancia(Punto p2);
    // desplaza a dX en dDespX y dY
    void desplazar(double dDespX, double dDespY);
    //Despliega el punto en el formato (x,y)
    void desplegar();
};
Punto::Punto(){
    dX = 0;
    dY = 0;
}
Punto::Punto (double dX, double dY){
    this -> dX = dX;
    this -> dY = dY;
}
//setters and getters
void Punto::SetdX(double dX){
    this->dX = dX;
}
double Punto::GetdX(){
    return dX;
}
void Punto::SetdY(double dY){
    this->dY = dY;
}
double Punto::GetdY(){
    return dY;
}
// Calcula la distancia entre dos puntos- actual y p2
double Punto::distancia(Punto p2){
    return sqrt(pow(p2.dX - dX,2) + pow(p2.dY - dY,2));
}
// desplaza a dX en dDespX y dY
void Punto::desplazar(double dDespX, double dDespY){
    dX += dDespX;
    dY += dDespY;
}
//Despliega el punto en el formato (x,y)
void Punto::desplegar(){
    cout << "(" << dX << "," << dY << ")"<< endl;
}
#endif // PUNTO_H_INCLUDED
