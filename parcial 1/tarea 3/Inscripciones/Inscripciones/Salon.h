#ifndef Salon_h
#define Salon_h
using namespace std;

class Salon{
    public: //constructores y metodos
        Salon(int,int,string);
        Salon();
    
        void setCapacidad(int);
        void setNombreClase(string);
    
        int getCapacidad();
        int getInscritos();
        string getNombreClase();
    
        void InscribirAlumnos(int);
    private: //atributos
        int capacidad, inscritos, numSalon;
        string nombreClase;
};

//metodos de declaracion
Salon::Salon(int cap,int salon,string clase){
    cap=capacidad;
    salon=numSalon;
    clase=nombreClase;
}
Salon::Salon(){
    inscritos=0;
}

//metodos de modificacion
void Salon::setCapacidad(int capacidad){
    this->capacidad=capacidad;
}
void Salon::setNombreClase(string nombreClase){
    this->nombreClase=nombreClase;
}

//metodos de acceso
int Salon::getCapacidad(){
    return capacidad;
}
int Salon::getInscritos(){
    return inscritos;
}
string Salon::getNombreClase(){
    return nombreClase;
}

//metodos para agregar un numero de alumnos a la variable
//'inscritos' para registrarlos en la clase
void Salon::InscribirAlumnos(int alumnos){
    inscritos+=alumnos;
}

#endif /* Salon_h */
