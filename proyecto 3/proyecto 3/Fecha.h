#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
using namespace std;

class Fecha{
public:
    Fecha();
    Fecha(int,int,int);
    //Metodos de Acceso
    int getDia();
    int getMes();
    int getAnio();
    //Metodos de Modificacion
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    //Sobrecargas
    bool operator>=(Fecha f);
    bool operator<=(Fecha f);
    bool operator==(Fecha f);
    Fecha operator+(int d);
    friend istream& operator>>(istream &is, Fecha &f);
    friend ostream& operator<<(ostream &os, Fecha &f);
private:
    int dia, mes, anio;
};

///METODOS Y CONSTRUCTORES
//Constructores
Fecha::Fecha(){
    dia=0;
    mes=0;
    anio=0;
}
Fecha::Fecha(int m, int d, int a){
    dia=d;
    mes=m;
    anio=a;
}

//Metodos de Acceso
int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getAnio(){
    return anio;
}

//Metodos de Modificacion
void Fecha::setDia(int d){
    dia=d;
}
void Fecha::setMes(int m){
    mes=m;
}
void Fecha::setAnio(int a){
    anio=a;
}

//Sobrecargas
bool Fecha::operator>=(Fecha f){
    if(anio>=f.anio){
        if(anio==f.anio){
            if((mes==f.mes && dia>f.dia) || mes>f.mes)
                return true;
            else
                return false;
        }
        return true;
    }
    else
        return false;
}
bool Fecha::operator<=(Fecha f){
    if(anio<=f.anio){
        if(anio==f.anio){
            if((mes==f.mes && dia<f.dia) || mes<f.mes)
                return true;
            else
                return false;
        }
        return true;
    }
    else
        return false;
}
bool Fecha::operator==(Fecha f){
    if(anio==f.anio && mes==f.mes && dia==f.dia)
        return true;
    else
        return false;
}
Fecha Fecha::operator+(int d){
    int nDia=dia+d,nMes=mes,nAnio=anio;
    bool dias=false;
    while (!dias){
        if (nMes==1 || nMes==3 || nMes==5 || nMes==7 || nMes==8 || nMes==10 || nMes==12){
            if (nDia>31){
                nDia-=31;
                nMes++;
            }
        }
        else if (nMes == 4 || nMes==6 || nMes==9 || nMes==11){
            if (nDia>30){
                nDia-=30;
                nMes++;
            }
        }
        else if (nMes==2){
            if (anio%4==0){
                if (nDia>29){
                    nDia-=29;
                    nMes++;
                }
            }
            else {
                if (nDia>28){
                    nDia-=28;
                    nMes++;
                }
            }
        }
        while (nMes>12){
            nMes-=12;
            nAnio++;
        }
        if (nMes==1 || nMes==3 || nMes==5 || nMes==7 || nMes==8 || nMes==10 || nMes==12){
            if (nDia<31)
                dias=true;
        }
        else if (nMes==4 || nMes==6 || nMes==9 || nMes==11){
            if (nDia<30)
                dias=true;
        }
        else if (nMes==2){
            if (nAnio%4==0){
                if (nDia<29)
                    dias=true;
            }
            else {
                if (nDia<28)
                    dias=true;
            }
        }
    }
    Fecha f(nMes,nDia,nAnio);
    return f;
}
istream& operator>>(istream &is, Fecha &f){
    is >> f.mes;
    is >> f.dia;
    is >> f.anio;
    return is;
}
ostream& operator<<(ostream &os, Fecha &f){
    os << f.mes << " " << f.dia << " " << f.anio;
    return os;
}
#endif // FECHA_H_INCLUDED
