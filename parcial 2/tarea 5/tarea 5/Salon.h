#ifndef Salon_h
#define Salon_h
#include "Computadora.h"
using namespace std;

class Salon {
    public:     // metodos
        Salon();
        void Set(int);
        void setCompu(Computadora);
        int getDatos();
        Computadora getCompu();
    private:    // atributos
        int datos;
        Computadora compu;  // se crea un objeto tipo Computadora
                            // dentro de la clase Salon
};
//////////////////////////////////////////
//  constructor default
Salon::Salon(){
    datos=0;
    Computadora compu;
}
//  metodos de modificacion
void Salon::Set(int datos){
    this->datos=datos;
}
void Salon::setCompu(Computadora compu){
    this->compu=compu;
}
//  metodos de acceso
int Salon::getDatos(){
    return datos;
}
Computadora Salon::getCompu(){
    return compu;
}

#endif /* Salon_h */
