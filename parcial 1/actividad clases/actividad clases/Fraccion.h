#ifndef Fraccion_h
#define Fraccion_h
using namespace std;

class Fraccion {
    public:
        Fraccion();
        Fraccion(double,double);
        double getNum();
        double getDen();
        void setNum(double);
        void setDen(double);
        void CalcValorReal(double,double);
    
    private:
        double numerador;
        double denominador;
};
////////////////////////////////////////////
Fraccion::Fraccion(){
    numerador=0;
    denominador=0;
}
double Fraccion::getNum(){
    return numerador;
}
double Fraccion::getDen(){
    return denominador;
}
////////////////////////////////////////////
Fraccion::Fraccion(double numerador, double denominador){
    this->numerador=numerador;
    this->denominador=denominador;
}
void Fraccion::setNum(double numerador){
    this->numerador=numerador;
}
void Fraccion::setDen(double denominador){
    this->denominador=denominador;
}
////////////////////////////////////////////
void Fraccion::CalcValorReal(double numerador, double denominador){
    double fraccion = numerador/denominador;
    cout<<"El valor de "<<numerador<<"/"<<denominador<<" es igual a "<<fraccion<<endl;
}

#endif /* Fraccion_h */
