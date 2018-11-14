#ifndef Animal_h
#define Animal_h
using namespace std;
///Clase Animal que será la clase base para las clases Perro y Gato
/// Los métodos habla y muestra serán abstractos y serán redefinidos en a clase Perro y Gato
///Autor: Delia Castro
class Animal{
public:
    Animal(string,int);
    int calculaEdad();
    virtual void habla()=0;
    virtual void muestra()=0;
protected:
    string nombre;
    int anioNacim;
};
Animal::Animal(string sNom,int aNac){
    nombre=sNom;
    anioNacim=aNac;
}
int Animal::calculaEdad(){
    return 2018-anioNacim;
}
#endif /* Animal_h */
