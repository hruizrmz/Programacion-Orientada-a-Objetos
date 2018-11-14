//  Helena Ruiz Ramirez
//  A01282531
//  Enero 11, 2018
//  Tarea 1: Arreglos y Matrices
//  Ejercicio 1: Shift

#include <iostream>
using namespace std;

void LlenarDatos (int arr[12]) {
    for (int i=0;i<12;i++) {
        cout<<"Espacio "<<(i+1)<<": ";
        cin>>arr[i];
    }
    cout<<endl;
}

void RecorreDerecha (int arr[12]) {
    int last=arr[11];
    for (int i=11;0<i;i--)
        arr[i]=arr[i-1];
    arr[0]=last;
    cout<<endl;
}

void MuestraDatos (int arr[12]) {
    for (int j=0;j<12;j++) {
        cout<<arr[j]<<" ";
    }
    cout<<endl;
}

int main() {
    int arreglo[12];
    LlenarDatos(arreglo);
    RecorreDerecha(arreglo);
    MuestraDatos(arreglo);
    cout<<endl;
    return 0;
}
