#include <iostream>
using namespace std;

template <class T>
int funcion (T arr[], T num, int tam){
    for (int i;i<tam;i++){
        if (arr[i]==num)
            return i;
        else
            return -1;
    }
}

int main(){
    int entero[5];
    double doble[5];
    char caracter[5];
    
    for (int i=0,counter=0;i<5;i++,counter++){
        entero[i]=counter;
    }
    for (int i=0, double counter=0.0 ; i<5 ; i++, counter+=1.5){
        doble[i]=counter;
    }
    for (int i=0, char counter=097.0;i<5;i++,counter++){
        caracter[i]=counter;
    }
    int indiceE = funcion(entero,3,5);
    int indiceD = funcion(doble,4.5,5);
    int indiceC = funcion(caracter,'c',5);
}
