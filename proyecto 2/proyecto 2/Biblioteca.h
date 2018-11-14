//  Helena Ruiz Ramirez (A01282531) , Gilberto Alejandro Castillo Perez (A00821306)
//  12/marzo/2018
//  Proyecto 2: Biblioteca header
#ifndef Biblioteca_h
#define Biblioteca_h
using namespace std;
class Biblioteca{
private:
    string clave;
    int piso;
    int estante;
    string claveBiblio;
public:
    //  Constructores
    Biblioteca();
    Biblioteca(string,int,int,string);
    //  Metodos de modificacion
    void setClaveBiblio(string);
    void setPiso(int);
    void setEstante(int);
    void setClave(string);
    //  Metodos de acceso
    string getClaveBiblio();
    int getPiso();
    int getEstante();
    string getClave();
    void muestra();
};
//  Constructores
Biblioteca::Biblioteca(){
    claveBiblio="";
    piso=0;
    estante=0;
    clave="";
}
Biblioteca::Biblioteca(string clave,int piso,int estante,string claveBiblio){
    this->claveBiblio=claveBiblio;
    this->piso=piso;
    this->estante=estante;
    this->clave=clave;
}
//  Metodos de Modificacion
void Biblioteca::setClaveBiblio(string claveBiblio){
    this->claveBiblio=claveBiblio;
}
void Biblioteca::setPiso(int piso){
    this->piso=piso;
}
void Biblioteca::setEstante(int estante){
    this->estante=estante;
}
void Biblioteca::setClave(string clave){
    this->clave=clave;
}
//  Metodos de Acceso
string Biblioteca::getClaveBiblio(){
    return claveBiblio;
}
int Biblioteca::getPiso(){
    return piso;
}
int Biblioteca::getEstante(){
    return estante;
}
string Biblioteca::getClave(){
    return clave;
}
//  Metodo de Muestra
void Biblioteca::muestra(){
    cout<<"Biblioteca: "<<claveBiblio<<endl;
    cout<<"Piso: "<<piso<<endl;
    cout<<"Estante: "<<estante<<endl;
    cout<<"ISBN: "<<clave<<endl;
}

#endif /* Biblioteca_h */
