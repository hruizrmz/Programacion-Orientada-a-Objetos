//  Actividad 08/marzo/2018
//  Helena Ruiz Ramirez
//  A01282531

// Nombre: Clase Bulto
//Descipción: clase que contiene los atributos kilos y gramos, que representan el peso de un bulto
//Autor: Maestras
//Fecha: 5 octubre

#ifndef Bulto_h
#define Bulto_h
#include <math.h>
using namespace std;
class Bulto{
private:
    int kilos;
    int gramos;
public:
    //Constructores
    Bulto();
    Bulto(int k);
    Bulto(int k, int g);
    //Métodos de acceso
    void setKilo(int k);
    void setGramo(int g);
    //Métodos de modificación
    int getKilo();
    int getGramo();
    //Métodos de operación
    void muestra();
    void operator++(int);  // incrementa un gramo al bulto
    friend void operator--(Bulto &b,int);  // decrementa un gramo al bulto
    Bulto operator+(int m);  // suma la cantidad de gramos recibidos en m a bulto y regresa el bulto modificado
    friend Bulto operator+(Bulto b1, Bulto b2);  // suma dos bultos y regresa un nuevo Bulto
    Bulto operator-(int m);  // a un Bulto le resta una cantidad de gramos y regresa el  Bulto modificado
    friend Bulto operator-(Bulto b1, Bulto b2); // a un Bulto le resta otro Bulto y regresa el nuevo Bulto
    bool operator>(Bulto b);  // regresa true/false si el primer Bulto es > que el segundo
    bool operator<(Bulto b); // regresa true/false si el primer Bulto es < que el segundo
    bool operator==(Bulto b); // regresa true/false si ambos Bultos son iguales
    
};
//Constructores
Bulto::Bulto(){
    kilos=0;
    gramos=0;
}
Bulto::Bulto(int k){
    kilos = k;
    gramos = 0;
}
Bulto::Bulto(int k, int g){
    kilos = k;
    gramos = g;
}
//Métodos de modificación
void Bulto::setKilo(int k){
    kilos=k;
}
void Bulto::setGramo(int g){
    gramos=g;
}
//Métodos de acceso
int Bulto::getKilo(){
    return kilos;
}
int Bulto::getGramo(){
    return gramos;
}
//Métodos de operación
void Bulto::muestra(){
    cout<<kilos<<" kg con "<<gramos<< " gramos"<<endl;
}
//////////////////////////////////////////
//COMPLETA EL CÓDIGO QUE FALTA
//////////////////////////////////////////
// incrementa un gramo al bulto opcion uno
void Bulto::operator++(int){
    gramos++;
    if (gramos>999){
        gramos-=1000;
        kilos++;
    }
}

// decrementa un gramo al bulto opcion 2
void operator--(Bulto &b,int){
    b.gramos--;
    if (b.gramos<0){
        b.gramos+=1000;
        b.kilos--;
    }
}

// suma la cantidad de gramos recibidos en m al bulto y regresa el bulto modificado opcion 3
Bulto Bulto::operator+(int m){
    gramos+=m;
    if (gramos>999){
        gramos-=1000;
        kilos++;
    }
    Bulto b(kilos,gramos);
    return b;
}

// suma dos bultos y regresa un nuevo Bulto opcion 4
Bulto operator+(Bulto b1, Bulto b2){
    int g=b1.gramos+b2.gramos;
    int k=b1.kilos+b2.kilos;
    if (g>999){
        g-=1000;
        k++;
    }
    Bulto b(k,g);
    return b;
}

// a un Bulto le resta una cantidad de gramos y regresa el  Bulto modificado opcion 5
Bulto Bulto::operator-(int m){
    gramos-=m;
    if (gramos<0){
        gramos+=1000;
        kilos--;
    }
    Bulto b(kilos,gramos);
    return b;
}

// resta dos Bultos y regresa el nuevo Bulto opcion 6
Bulto operator-(Bulto b1, Bulto b2){
    int g=b1.gramos-b2.gramos;
    int k=b1.kilos-b2.kilos;
    if (g<0){
        g+=1000;
        k--;
    }
    Bulto b(k,g);
    return b;
}

// regresa true/false si el primer Bulto es > que el segundo opcion 7
bool Bulto::operator>(Bulto b){
    if (kilos>b.kilos){
        return true;
    }
    else if (kilos<b.kilos){
        return false;
    }
    else{
        if (gramos>b.gramos){
            return true;
        }
        else if (gramos<b.gramos){
            return false;
        }
        else {
            return false;
        }
    }
}

// regresa true/false si el primer Bulto es < que el segundo opcion 8
bool Bulto::operator<(Bulto b){
    if (kilos<b.kilos){
        return true;
    }
    else if (kilos>b.kilos){
        return false;
    }
    else{
        if (gramos<b.gramos){
            return true;
        }
        else if (gramos>b.gramos){
            return false;
        }
        else {
            return false;
        }
    }
}

// regresa true/false si ambos Bultos son iguales opcion 9
bool Bulto::operator==(Bulto b){
    if ( (kilos==b.kilos)&&(gramos==b.gramos) )
        return true;
    else
        return false;
}

#endif /* Bulto_h */
