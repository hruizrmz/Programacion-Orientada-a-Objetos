//  Helena Ruiz Ramirez (A01282531) , Gilberto Alejandro Castillo Perez (A00821306)
//  12/marzo/2018
//  Proyecto 2: Fecha header
#ifndef Fecha_h
#define Fecha_h
using namespace std;
class Fecha{
private:
    int dia;
    int mes;
    int anio;
public:
    //  Constructores
    Fecha();
    Fecha(int,int,int);
    //  Metodos de Modificacion
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    //  Metodos de Acceso
    int getDia();
    int getMes();
    int getAnio();
    void muestra();
    //  Metodos de sobrecarga
    void operator+=(int);
    bool operator==(Fecha);
    //  Metodos de operacion
    bool esBisiesto (int);
    //////////////////////////////////
    
};
//  Constructores
Fecha::Fecha(){
    dia=0;
    mes=0;
    anio=0;
}
Fecha::Fecha(int dia,int mes,int anio){
    this->dia=dia;
    this->mes=mes;
    this->anio=anio;
}
//  Metodos de Modificacion
void Fecha::setDia(int dia){
    this->dia=dia;
}
void Fecha::setMes(int mes){
    this->mes=mes;
}
void Fecha::setAnio(int anio){
    this->anio=anio;
}
//  Metodos de Acceso
int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getAnio(){
    return anio;
}
//  Metodo de Muestra
void Fecha::muestra(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
/////////////////////////////////////////////////////////////////////////////
//  Metodos de sobrecarga
void Fecha::operator+=(int d){
    //  le suma una cantidad de dias "int d" a una fecha, checando que la
    //  suma restante sea una fecha valida en cuanto al numero de dias del
    //  mes y el año
    dia+=d;
    if (mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12){
        while (dia>31){
            dia-=31;
            mes++;
            if (mes>12){
                mes-=12;
                anio++;
            }
        }
    }
    else if (mes==4||mes==6||mes==9||mes==11){
        while (dia>30){
            dia-=30;
            mes++;
            if (mes>12){
                mes-=12;
                anio++;
            }
        }
    }
    else if (mes==2){
        if (esBisiesto(anio)){
            while (dia>29){
                dia-=29;
                mes++;
                if (mes>12){
                    mes-=12;
                    anio++;
                }
            }
        }
        else {
            while (dia>28){
                dia-=28;
                mes++;
                if (mes>12){
                    mes-=12;
                    anio++;
                }
            }
        }
    }
}
bool Fecha::operator== (Fecha f2){
    //  operador de igualdad para confirmar que dos
    //  objetos tipo fecha son iguales
    if ( (dia==f2.dia) && (mes==f2.mes) && (anio==f2.anio) )
        return true;
    else
        return false;
}
//  Metodos de operacion
bool Fecha::esBisiesto(int anio){
    //  confirma si un año es bisiesto
    if (anio%4!=0)
        return false;
    else
        return true;
}

#endif /* Fecha_h */
