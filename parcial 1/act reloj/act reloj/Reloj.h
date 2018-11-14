#ifndef Reloj_h
#define Reloj_h
using namespace std;

class Reloj{
    public:
        void setHora(int);
        void setMinu(int);
        int getHora();
        int getMinu();
        void muestra(int,int);
    private:
        int hora,minu;
};
////////////////////////////////////////
void Reloj::setHora(int hora){
    this->hora=hora;
}
void Reloj::setMinu(int minu){
    this->minu=minu;
}
////////////////////////////////////////
int Reloj::getHora(){
    return hora;
}
int Reloj::getMinu(){
    return minu;
}
////////////////////////////////////////
void Reloj::muestra(int hora, int minu){
    if (hora/10<1) {
        if (minu/10<1)
            cout<<'0'<<hora<<":"<<'0'<<minu<<endl;
        else
            cout<<'0'<<hora<<":"<<minu<<endl;
    }
    else {
        if (minu/10<1)
            cout<<hora<<":"<<'0'<<minu<<endl;
        else
            cout<<hora<<":"<<minu<<endl;
    }
}

#endif /* Reloj_h */
