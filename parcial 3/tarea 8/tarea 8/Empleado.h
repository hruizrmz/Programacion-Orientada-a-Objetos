#ifndef Empleado_h
#define Empleado_h
using namespace std;
class Empleado{
protected:  // protected ya que es la clase base
    string nombre,apellidos;
    int nomina;
    double sueldoBase;
public:
    Empleado();
    Empleado(string,string,int,double);
    void setNombre(string);
    void setApellido(string);
    void setNomina(int);
    void setSueldoB(double);
    string getNombre();
    string getApellido();
    int getNomina();
    double getSueldoB();
    virtual double CalcularPago()=0;   // estos metodos son virtual pure
    virtual void mostrar()=0;          // para que sea una clase abstracta
};
//  Constructores
Empleado::Empleado(){
    nombre="";
    apellidos="";
    nomina=0;
    sueldoBase=0;
}
Empleado::Empleado(string nomb,string ape,int nomi,double sBase){
    nombre=nomb;
    apellidos=ape;
    nomina=nomi;
    sueldoBase=sBase;
}
//  Metodos set
void Empleado::setNombre(string nomb){
    nombre=nomb;
}
void Empleado::setApellido(string ape){
    apellidos=ape;
}
void Empleado::setNomina(int nomi){
    nomina=nomi;
}
void Empleado::setSueldoB(double sBase){
    sueldoBase=sBase;
}
//  Metodos get
string Empleado::getNombre(){
    return nombre;
}
string Empleado::getApellido(){
    return apellidos;
}
int Empleado::getNomina(){
    return nomina;
}
double Empleado::getSueldoB(){
    return sueldoBase;
}
#endif /* Empleado_h */
