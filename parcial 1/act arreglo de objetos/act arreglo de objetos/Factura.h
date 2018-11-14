#ifndef Factura_h
#define Factura_h
using namespace std;

class Factura{
    public:
        Factura();
    
        int getNumArt();
        int getCant();
        string getNombre();
        double getPrecio();
    
        void setNumArt(int);
        void setCant(int);
        void setNombre(string);
        void setPrecio(int);
    
        double calculaTotal();

    private:
        int numArt;
        int cant;
        string nombre;
        double precio;
};
////////////////////////////////////////
Factura::Factura(){
    numArt=0;
    nombre="";
    cant=0;
    precio=0;
}
///////////////////
int Factura::getNumArt(){
    return numArt;
}
int Factura::getCant(){
    return cant;
}
string Factura::getNombre(){
    return nombre;
}
double Factura::getPrecio(){
    return precio;
}
///////////////////
void Factura::setNumArt(int numArt){
    this->numArt=numArt;
}
void Factura::setCant(int cant) {
    this->cant=cant;
}
void Factura::setNombre(string nombre) {
    this->nombre=nombre;
}
void Factura::setPrecio(int precio) {
    this->precio=precio;
}
///////////////////
double Factura::calculaTotal(){
    return cant*precio;
};

#endif /* Factura_h */
