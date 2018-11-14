#include <iostream>
#include <cmath>
#include "Cuadratica.h"
using namespace std;

int main() {
    Cuadratica ec1(5,3,2), ec2, ecRes;
    cout << "Teclea los coeficientes para la segunda ecuación (ax^2+bx+c)" << endl;
    cin >> ec2;
    /*********************************/
    cout << endl;
    cout << "=== Suma de Ecuaciónes 1 y 2" << endl;
    cout << "Ecuación 1 :" ;
    ec1.muestra();
    cout << "Ecuación 2 :";
    ec2.muestra();
    ecRes=ec1+ec2;
    cout<<endl;
    cout << "Resultado :";
    ecRes.muestra();
    cout << endl;
    /*********************************/
    cout << endl;
    cout << "=== Resta de Ecuaciónes 1 y 2" << endl;
    cout << "Ecuación 1 :" ;
    ec1.muestra();
    cout << "Ecuación 2 :" ;
    ec2.muestra();
    ecRes=ec1-ec2;
    cout<<endl;
    cout << "Resultado :";
    ecRes.muestra();
    cout << endl;
    /*********************************/
    cout << endl;
    cout << "=== Multiplica Ecuación 1 por valor entero 2" << endl;
    cout << "Ecuación 1 :" ;
    ec1.muestra();
    ecRes=ec1*2;
    cout << "Resultado :";
    ecRes.muestra();
    cout << endl;
    /*********************************/
    cout << endl;
    cout << "=== Compara con == ecuación 1 y ecuación 2" << endl;
    cout << "Ecuación 1 :" ;
    ec1.muestra();
    cout << "Ecuación 2 :" ;
    ec2.muestra();
    if (ec1==ec2)
        cout<<"Son iguales"<<endl;
    else
        cout<<"Son diferentes"<<endl;
    /*********************************/
    cout << endl;
    double x;
    cout << "=== Escribe un valor para evaluar la ecuacion 2 en x: ";
    cin >> x;
    ec2.Evalua(x);
    /*********************************/
    cout << endl;
    cout << "=== Suma unitaria"<<endl;
    cout << "Ecuación 1 :" << ec1 << endl;
    ec1++;
    ecRes=ec1;
    cout << "Resultado :" << ecRes << endl;
    
    
    //  check notes for rest of code
    
    cout<<endl;
    return 0;
}
