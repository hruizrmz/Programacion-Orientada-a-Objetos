//  Helena Ruiz Ramirez
//  A01282531
//  22/marzo/2018
//  Tarea 7: Herencia
//  Descripcion: Header de la clase Persona.
#ifndef Persona_h
#define Persona_h
using namespace std;
class Persona{
public:
    Persona();
    Persona(int, string);
    void setIdentidad(int);
    void setNombre(string);
    int getIdentidad();
    string getNombre();
    void muestraPer();
protected:
    int identidad;
    string nombre;
};
//  Constructores Default
Persona::Persona(){
    identidad=0;
    nombre="";
}
Persona::Persona(int ident, string nom){
    identidad=ident;
    nombre=nom;
}
//  Metodos de Modificacion
void Persona::setIdentidad(int ident){
    identidad=ident;
}
void Persona::setNombre(string nom){
    nombre=nom;
}
//  Metodos de Acceso
int Persona::getIdentidad(){
    return identidad;
}
string Persona::getNombre(){
    return nombre;
}
//  Metodo de Muestra
void Persona::muestraPer(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Identidad: "<<identidad<<endl;
}
#endif /* Persona_h */
