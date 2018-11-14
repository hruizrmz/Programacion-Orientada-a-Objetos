#ifndef Pila_h
#define Pila_h
using namespace std;
template <class T>
class Pila{
private:
    T arr[15];
    int tope;
public:
    Pila();
    void meter(T num);
    void sacar();
    void observa();
};
template <class T>
Pila <T>::Pila(){
    tope=0;
}
template <class T>
void Pila <T>::meter(T nuevo){
    if (tope<15){
        arr[tope]=nuevo;
        tope++;
    }
    else
        cout<<"Pila llena"<<endl;
}
template <class T>
void Pila <T>::sacar(){
    if (tope>0){
        cout<<arr[tope-1]<<endl;
        tope--;
    }
    else
        cout<<"Pila vacia"<<endl;
}
template <class T>
void Pila <T>::observa(){
    if (tope>0)
        cout<<arr[tope-1]<<endl;
    else
        cout<<"Pila vacia"<<endl;
}
#endif /* Pila_h */
