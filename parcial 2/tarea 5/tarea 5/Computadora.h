#ifndef Computadora_h
#define Computadora_h
using namespace std;

class Computadora{
    public:     // metodos
        Computadora();
        void setMarca(string);
        void setOS(string);
        void setRAM(int);
        string getMarca();
        string getOS();
        int getRAM();
    private:    // atributos
        string marca;
        string os;
        int ram;
};
/////////////////////////////////////////
//  constructor default
Computadora::Computadora(){
    marca="";
    os="";
    ram=0;
}
//  metodos de modificacion
void Computadora::setMarca(string marca){
    this->marca=marca;
}
void Computadora::setOS(string os){
    this->os=os;
}
void Computadora::setRAM(int ram){
    this->ram=ram;
}
//  metodos de acceso
string Computadora::getMarca(){
    return marca;
}
string Computadora::getOS(){
    return os;
}
int Computadora::getRAM(){
    return ram;
}

#endif /* Computadora_h */
