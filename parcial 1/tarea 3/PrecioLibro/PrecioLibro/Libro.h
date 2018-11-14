#ifndef Libro_h
#define Libro_h
using namespace std;

class Libro {
    public: //constructores y metodos
        Libro();
    
        void setTitulo(string);
        void setAutor(string);
        void setPrecio(double);
    
        string getTitulo();
        string getAutor();
        double getPrecio();
    
        void SubePrecio(string,string);
        void Muestra();
    
    private: //atributos
        string titulo, autor;
        double precio;
};

//metodo de declaracion
Libro::Libro(){
    titulo="";
    autor="";
    precio=0;
}

// metodos de modificacion
void Libro::setTitulo(string titulo) {
    this->titulo=titulo;
}
void Libro::setAutor(string autor) {
    this->autor=autor;
}
void Libro::setPrecio(double precio) {
    this->precio=precio;
}

// metodos de acceso
string Libro::getTitulo() {
    return titulo;
}
string Libro::getAutor() {
    return autor;
}
double Libro::getPrecio() {
    return precio;
}

// metodo para aumentar el precio por un porcentaje
// que pide el usuario. cambia el valor de 'precio'
void Libro::SubePrecio(string titulo, string autor) {
    double per;
    cout<<"Porcentaje del precio que desea aumentar: ";
    cin>>per;
    cout<<endl;
    precio+=(precio*(per*0.01));
}
// metodo para mostrar los datos ingresados/modificados del libro
void Libro::Muestra() {
    cout<<"Datos Finales del Libro"<<endl;
    cout<<"Titulo: "<<titulo<<endl;
    cout<<"Autor: "<<autor<<endl;
    cout<<"Precio incrementado: "<<precio<<endl;
    cout<<endl;
}

#endif /* Libro_h */
