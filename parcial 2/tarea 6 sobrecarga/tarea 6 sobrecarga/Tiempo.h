//  Helena Ruiz Ramirez
//  A01282531
//  08/marzo/2018
//  Tarea 6: Sobrecarga
//  Descripcion: Header para la clase "Tiempo"
//      que define todos los operadores de
//      sobrecarga que se dan en el main.

#ifndef Tiempo_h
#define Tiempo_h
using namespace std;
class Tiempo{
    public:
    //  declaracion de todos los operadores
        Tiempo();
        Tiempo(int,int,int);
        void muestra();
        friend Tiempo operator+(Tiempo,Tiempo);
        friend int operator!(Tiempo);
        Tiempo operator+(int);
        friend Tiempo operator-(Tiempo,int);
        friend bool operator>(Tiempo,Tiempo);
        bool operator<(Tiempo);
        void operator+=(Tiempo);
        Tiempo operator++();
    private:
        int hh,mm,ss;
};
/////////////////////////////////////////////////
Tiempo::Tiempo(){
    hh=0;
    mm=0;
    ss=0;
}
Tiempo::Tiempo(int hh, int mm, int ss){
    this->hh=hh;
    this->mm=mm;
    this->ss=ss;
}
void Tiempo::muestra() {
    cout << hh << ":";
    if (mm < 10)
        cout << "0";
    cout << mm << ":";
    if (ss < 10)
        cout << "0";
    cout << ss << endl;
}
/////////////////////////////////////////////////
Tiempo operator+(Tiempo t1, Tiempo t2){
    //  suma dos tiempos un parametro a la vez.
    //  si los segundos o minutos se pasan de 60,
    //  agrega un valor a "sobra" para añadirselo
    //  a el parametro siguiente.
    int sS,mM,hH,sobra=0;
    sS=t1.ss+t2.ss;
    while (sS>59){
        sS-=60;
        sobra++;
    }
    mM=t1.mm+t2.mm+sobra;
    sobra=0;
    while (mM>59){
        mM-=60;
        sobra++;
    }
    hH=t1.hh+t2.hh+sobra;
    Tiempo t3 (hH,mM,sS);
    return t3;
}
int operator!(Tiempo t){
    //  cambia el objeto de tiempo a segundos
    int s;
    s = (t.hh*3600) + (t.mm*60) + t.ss;
    return s;
}
Tiempo Tiempo::operator+(int s){
    //  suma la cantidad "s" de segundos a un
    //  objeto de Tiempo. se aplica la misma
    //  logica de la variable "sobra" que se
    //  utilizo en el operador de suma.
    int sobra=0;
    ss+=s;
    while (ss>59){
        ss-=60;
        sobra++;
    }
    mm+=sobra;
    sobra=0;
    while (mm>59){
        mm-=60;
        sobra++;
    }
    hh+=sobra;
    Tiempo t3 (hh,mm,ss);
    return t3;
}
Tiempo operator-(Tiempo t,int s){
    //  se restan "s" segundos del objeto "t"
    //  de tiempo. se aplica la misma
    //  logica de la variable "sobra" que se
    //  utilizo en el operador de suma. la
    //  diferencia es que aqui checa que no haya
    //  valores negativos, a diferencia de que
    //  sean mayores de 60.
    int sobra=0;
    while (s>59){
        s-=60;
        sobra++;
    }
    t.ss-=s;
    if (t.ss<0){
        t.ss=60+t.ss;
        sobra++;
    }
    t.mm-=sobra;
    sobra=0;
    if (t.mm<0){
        t.mm=60+s;
        sobra++;
    }
    t.hh+=sobra;
    return t;
}
bool operator>(Tiempo t1,Tiempo t2){
    //  compara dos objetos de tiempo parametro
    //  por parametro, regresando verdadero solo
    //  cuando el primer objeto sea mayor.
    if (t1.hh>t2.hh){
        return true;
    }
    else if (t1.hh<t2.hh){
        return false;
    }
    else{
        if (t1.mm>t2.mm){
            return true;
        }
        else if (t1.mm<t2.mm){
            return false;
        }
        else{
            if (t1.ss>t2.ss){
                return true;
            }
            else{
                return false;
            }
        }
    }
}
bool Tiempo::operator<(Tiempo t){
    //  compara dos objetos de tiempo parametro
    //  por parametro, regresando verdadero solo
    //  cuando el primer objeto sea menor.
    if (hh<t.hh){
        return true;
    }
    else if (hh>t.hh){
        return false;
    }
    else{
        if (mm<t.mm){
            return true;
        }
        else if (mm>t.mm){
            return false;
        }
        else{
            if (ss<t.ss){
                return true;
            }
            else{
                return false;
            }
        }
    }
}
Tiempo Tiempo::operator++(){
    //  le suma un segundo a un objeto Tiempo,
    //  aplicando la misma logica de la variable
    //  "sobra" que se utilizo en el operador de
    //  suma. luego crea un nuevo objeto Tiempo
    //  con el nuevo valor de los segundos.
    ss++;
    int sobra=0;
    while (ss>59){
        ss-=60;
        sobra++;
    }
    mm+=sobra;
    sobra=0;
    while (mm>59){
        mm-=60;
        sobra++;
    }
    hh+=sobra;
    Tiempo t(hh,mm,ss);
    return t;
}
void Tiempo::operator+=(Tiempo t){
    //  el objeto "t" se suma con los parametros
    //  de un objeto Tiempo para modificar
    //  solamente este ultimo.
    int sobra=0;
    ss+=t.ss;
    while (ss>59){
        ss-=60;
        sobra++;
    }
    mm+=t.mm+sobra;
    sobra=0;
    while (mm>59){
        mm-=60;
        sobra++;
    }
    hh+=t.hh+sobra;
}
/////////////////////////////////////////////////
#endif /* Tiempo_h */
