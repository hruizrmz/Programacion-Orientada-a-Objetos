#ifndef Fecha_h
#define Fecha_h
using namespace std;
/////////////////
class Fecha{
    public:
        // constructor
        Fecha();
        // modificacion
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        // acceso
        int getDia();
        int getMes();
        int getAnio();
        // operaciones
        string nombreMes(int);
        //bool esBisiesto(int);
        void Muestra();
    private:
        int dia;
        int mes;
        int anio;
};
/////////////////
Fecha::Fecha(){
    dia=0;
    mes=0;
    anio=0;
}
/////////////////
void Fecha::setDia(int dia){
    this->dia=dia;
}
void Fecha::setMes(int mes){
    this->mes=mes;
}
void Fecha::setAnio(int anio){
    this->anio=anio;
}
/////////////////
int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getAnio(){
    return anio;
}
/////////////////
// usando el switch, la funcion regresa el
// nombre del mes de acuerdo a su numero
string Fecha::nombreMes(int mes){
    string nom;
    switch(mes){
        case 1:{
            nom="Enero";
            break;
        }
        case 2:{
            nom="Febrero";
            break;
        }
        case 3:{
            nom="Marzo";
            break;
        }
        case 4:{
            nom="Abril";
            break;
        }
        case 5:{
            nom="Mayo";
            break;
        }
        case 6:{
            nom="Junio";
            break;
        }
        case 7:{
            nom="Julio";
            break;
        }
        case 8:{
            nom="Agosto";
            break;
        }
        case 9:{
            nom="Septiembre";
            break;
        }
        case 10:{
            nom="Octubre";
            break;
        }
        case 11:{
            nom="Noviembre";
            break;
        }
        case 12:{
            nom="Diciembre";
            break;
        }
    }
    return nom;
}

// la funcion checa si el año es multiplo de 4,
// si si es, regresa un valor de verdadero para
// confirmar que es un año bisiesto
//bool Fecha::esBisiesto(int anio){
    //if (anio%4!=0)
        //return false;
    //else
        //return true;
//}

// utilizando las funciones de la clase, se
// imprime la fecha de acuerdo al formato deseado
void Fecha::Muestra(){
    string nom=nombreMes(mes);
    anio=anio%100;
    if (anio/10<1){
        if (dia/10<1){
            cout<<"0"<<dia<<"/"<<nom<<"/"<<"0"<<anio;
        }
        else if (dia/10>1){
            cout<<dia<<"/"<<nom<<"/"<<"0"<<anio;
        }
    }
    else if (anio/10>1){
        if (dia/10<1){
            cout<<"0"<<dia<<"/"<<nom<<"/"<<anio;
        }
        else if (dia/10>1){
            cout<<dia<<"/"<<nom<<"/"<<anio;
        }
    }
    //bool check=esBisiesto(anio);
    //if (check)
    //    cout<<" (Año bisiesto)"<<endl;
    //else if (!check)
    //    cout<<" (No es bisisesto)"<<endl;
}
#endif /* Fecha_h */
