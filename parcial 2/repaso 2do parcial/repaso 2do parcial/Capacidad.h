#ifndef Capacidad_h
#define Capacidad_h
class Capacidad{
private:
    int ml,litros;
public:
    Capacidad();
    Capacidad(int,int);
    void setLitros(int);
    void setML(int);
    int getLitros();
    int getML();
};
Capacidad::Capacidad(){
    litros=0;
    ml=0;
}
Capacidad::Capacidad(int l,int ml){
    litros=l;
    this->ml=ml;
}
void Capacidad::setLitros(int l){
    litros=l;
}
void Capacidad::setML(int ml){
    this->ml=ml;
}
int Capacidad::getLitros(){
    return litros;
}
int Capacidad::getML(){
    return ml;
}
#endif /* Capacidad_h */
