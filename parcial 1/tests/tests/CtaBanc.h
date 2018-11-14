#ifndef CtaBanc_h
#define CtaBanc_h
using namespace std;
class CtaBanc {
    public:  //constructores
        CtaBanc();              //constructor por default
        CtaBanc(string,double); //establece cada parametro (no tipo) de la clase
    
        //metodos de acceso
        string getNombre();
        double getSaldo();
    
        //metodos de modificacion
        void setNombre(string);
        void setSaldo(double);
    
        //metodos de operacion
        void Deposita(double);
        bool Retira(double);
    
    
    private: //atributos
        string nombre;
        double saldo;
};
/////////////
//codificacion de valores iniciales

CtaBanc::CtaBanc(){
    nombre="helena";
    saldo=0;
}
string CtaBanc::getNombre() {
    return nombre;
}
double CtaBanc::getSaldo() {
    return saldo;
}

/////////////
//codificacion de valores declarados
CtaBanc::CtaBanc(string nombre, double saldo){
    this->nombre=nombre; //si el parametro y el atributo se llaman igual, se puede
                         //usar "this->" alado de tu atributo para diferenciarlos
                         //y especificar que quieres que el valor del parametro
                         //se guarde en el atributo de tu objeto
    this->saldo=saldo;
}
void CtaBanc::setNombre(string nombre) {
    this->nombre=nombre;
}
void CtaBanc::setSaldo(double saldo){
    this->saldo=saldo;
}

/////////////
//codificacion de funciones para la cuenta de banco
void CtaBanc::Deposita(double money) {
    saldo+=money;
}
bool CtaBanc::Retira(double money) {
    if (saldo>=money) {
        saldo-=money;
        cout<<"Retiro "<<money<<" pesos. Le queda un saldo de "<<saldo<<endl;
        return true;
    }
    else {
        cout<<"No tiene suficiente saldo"<<endl;
        return false;
    }
}

#endif /* CtaBanc_h */
