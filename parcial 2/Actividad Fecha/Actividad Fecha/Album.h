#ifndef Album_h
#define Album_h
#include "Fecha.h"
using namespace std;
class Album {
    public:
        // default
        Album();
        void Set(string,string,string,Fecha);
        // modificacion
        void setNom(string);
        void setGenero(string);
        void setArtista(string);
        void setLanz(Fecha);
        // acceso
        string getNom();
        string getGenero();
        string getArtista();
        Fecha getLanz();
        // operaciones
        void Muestra();
    
    private:
        // atributos
        string nomAlbum;
        string genero;
        string artista;
        Fecha lanz;
};
///////////////////////////////////////////////////
Album::Album(){
    nomAlbum="";
    genero="";
    artista="";
    Fecha lanz;
}
void Album::Set(string nomAlbum,string genero,string artista,Fecha lanz){
    this->nomAlbum=nomAlbum;
    this->genero=genero;
    this->artista=artista;
    this->lanz=lanz;
}
///////////////////////////////////////////////////
void Album::setNom(string nomAlbum){
    this->nomAlbum=nomAlbum;
}
void Album::setGenero(string genero){
    this->genero=genero;
}
void Album::setArtista(string artista){
    this->artista=artista;
}
void Album::setLanz(Fecha lanz){
    this->lanz=lanz;
}
///////////////////////////////////////////////////
string Album::getNom(){
    return nomAlbum;
}
string Album::getGenero(){
    return genero;
}
string Album::getArtista(){
    return artista;
}
Fecha Album::getLanz(){
    return lanz;
}
///////////////////////////////////////////////////
void Album::Muestra(){
    cout<<"Nombre del album: "<<nomAlbum<<endl;
    cout<<"Fecha de lanzamiento: ";
    lanz.Muestra();
    cout<<endl;
}

#endif /* Album_h */
