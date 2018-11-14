///Ejercicio 3 de Herencia: Usa la clase figura la cual contiene un atributo Coordenada que es composición de la clase Punto
/// y contiene dos clases hijas Circulo y Rectangulo
/// Autor: Delia Castro R
///15 octubre del 2017
#include <iostream>
#include "Circulo.h"
#include "Figura.h"
#include "Rectangulo.h"
using namespace std;
int main(){
    Figura f1;
    Punto centro=Punto(3,4);
    cout << "Desplegano f1" << endl;
    f1.desplegar();
    cout << " Desplegando el circulo c1" << endl;
    Circulo c1(centro,"red",5);
    c1.desplegar();
    cout<<"El area del circulo es "<<c1.calcularArea()<<endl;
    Rectangulo r1(centro,"blue",3,4);
    cout << "Desplegando el rectangulo r1" << endl;
    r1.desplegar();
    cout<<"El area del rectangulo es "<<r1.calcularArea()<<endl;
    cout<<"El perimetro del rectangulo es "<<r1.calcularPerimetro()<<endl;
    return 0;
}
