//  Helena Ruiz Ramirez (A01282531) , Gilberto Alejandro Castillo Perez (A00821306)
//  12/marzo/2018
//  Proyecto 2: Alumno header
#ifndef Alumno_h
#define Alumno_h
using namespace std;
class Alumno{
private:
    int matricula;
    string carrera;
    string nombre;
public:
    //  Constructores
    Alumno();
    Alumno(int,string,string);
    //  Metodos de modificacion
    void setMatricula(int);
    void setCarrera(string);
    void setNombre(string);
    //  Metodos de acceso
    int getMatricula();
    string getCarrera();
    string getNombre();
    void muestra();
};
//  Constructores
Alumno::Alumno(){
    matricula=0;
    carrera="";
    nombre="";
}
Alumno::Alumno(int matricula,string carrera,string nombre){
    this->matricula=matricula;
    this->carrera=carrera;
    this->nombre=nombre;
}
//  Metodos de Modificacion
void Alumno::setMatricula(int matricula){
    this->matricula=matricula;
}
void Alumno::setCarrera(string carrera){
    this->carrera=carrera;
}
void Alumno::setNombre(string nombre){
    this->nombre=nombre;
}
//  Metodos de Acceso
int Alumno::getMatricula(){
    return matricula;
}
string Alumno::getCarrera(){
    return carrera;
}
string Alumno::getNombre(){
    return nombre;
}
//  Metodo de Muestra
void Alumno::muestra(){
    cout<<"Matricula: "<<matricula<<endl;
    cout<<"Carrera: "<<carrera<<endl;
    cout<<"Nombre: "<<nombre<<endl;
}

#endif /* Alumno_h */
