#ifndef RectName_h
#define RectName_h
#include "Rectangulo.h"
class RectName: public Rectangulo{
public:
    RectName();
    RectName(int,int,string);
    string getNom();
    void setNom(string);
    void dibuja();
private:
    string nombre;
};
RectName::RectName():Rectangulo(){
    nombre="";
}
RectName::RectName(int l,int h,string n):Rectangulo(l,h){
    nombre=n;
}
string RectName::getNom(){
    return nombre;
}
void RectName::setNom(string n){
    nombre=n;
}
void RectName::dibuja(){
    for (int r = 1; r <= alto; r++) {    // dibujo completo el primero y el ultimo renglon
        if (r == 1 || r == alto){
            for (int c = 1; c <= largo; c++)
                cout<<"*";
            cout<<endl;
        }
        else if (r==alto/2){
            cout<<"* "<<nombre<<" *"<<endl;
        }
        else {
            // dibujo solo los caracteres de los extremos en los renglones del medio
            cout<<"*";
            for (int c = 2; c < largo; c++)
                cout<<" ";
            cout<<"*"<<endl;
        }
    }
}
#endif /* RectName_h */
