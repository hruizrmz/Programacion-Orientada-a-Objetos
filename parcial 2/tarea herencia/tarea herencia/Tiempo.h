//  Helena Ruiz Ramirez
//  A01282531
//  22/marzo/2018
//  Tarea 7: Herencia
//  Descripcion: Header de la clase Tiempo.
#ifndef Tiempo_h
#define Tiempo_h
using namespace std;
class Tiempo{
public:
    Tiempo();
    Tiempo(int,int,int);
    void setHora(int);
    void setMin(int);
    void setSeg(int);
    int getHora();
    int getMin();
    int getSeg();
    void muestraTiempo();
    bool operator<(Tiempo);
private:
    int hora;
    int min;
    int seg;
};
//  Constructores Default
Tiempo::Tiempo(){
    hora=0;
    min=0;
    seg=0;
}
Tiempo::Tiempo(int hora,int min,int seg){
    this->hora=hora;
    this->min=min;
    this->seg=seg;
}
//  Metodo de Modificacion
void Tiempo::setHora(int hora){
    this->hora=hora;
}
void Tiempo::setMin(int min){
    this->min=min;
}
void Tiempo::setSeg(int seg){
    this->seg=seg;
}
//  Metodo de Acceso
int Tiempo::getHora(){
    return hora;
}
int Tiempo::getMin(){
    return min;
}
int Tiempo::getSeg(){
    return seg;
}
//  Metodo de Muestra
void Tiempo::muestraTiempo(){
    cout<<hora<<":"<<min<<":"<<seg<<endl;
}
//  Metodo de Sobrecarga ==
bool Tiempo::operator<(Tiempo t){
    if (hora<t.hora)
        return true;
    else if (hora==t.hora){
        if (min<t.min)
            return true;
        else if (min==t.min){
            if (seg<t.seg)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}
#endif /* Tiempo_h */
