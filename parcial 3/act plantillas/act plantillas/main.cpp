#include <iostream>
#include <string>
using namespace std;

template <class T>
T llena (T n, T arr[n]){
    for (int i=0;i<n<i;i++){
        cout<<"Elemento "<<i+1<<": ";
        cin>>arr[i];
    }
}

template <class T>
T intercambio (T n, T arr[]){
    int j=0;
    T *menor = arr[j];
    T element;
    for (int i=0;i<n;i++){
        if (menor>arr[i]){
            element=arr[i];
            arr[i]=menor;
            menor=element;
        }
        i=j;
    }
}

template <class T>
T muestra (T n, T arr[n]){
    for (int i=0;i<n<i;i++)
        cout<<arr[i]<<" ";
}

int main() {
    int tam,op;
    string tipo;
    cout<<"¿Cuántos elementos tendrá el vector? ";
    cin>>tam;
    cout<<endl;
    
    cout<<"Tipo del vector..."<<endl;
    cout<<"1. int"<<endl;
    cout<<"2. char"<<endl;
    cout<<"3. double"<<endl;
    cin>>tipo;
    
    int arr1[tam];
    char arr2[tam];
    double arr3[tam];
    
    cout<<endl;
        
    do {
        cout<<endl;
        cout<<"¿Qué desea hacer con el vector?..."<<endl;
        cout<<"1. Dar de alta los "<<tam<<" elementos"<<endl;
        cout<<"2. Ordenar los elementos"<<endl;
        cout<<"3. Desplegar los elementos"<<endl;
        cout<<"4. Escoger otro tipo"<<endl;
        cout<<"( 5. Terminar )"<<endl;
        cin>>op;
        switch (op){
            case 1: {
                if (tipo=="int")
                    llena(tam,arr1);
                else if (tipo=="char")
                    llena(tam,arr2);
                else if (tipo=="double")
                    llena(tam,arr3);
                break;
            }
            case 2: {
                if (tipo=="int")
                    intercambio(tam,arr1;
                else if (tipo=="char")
                    intercambio(tam,arr2);
                else if (tipo=="double")
                    intercambio(tam,arr3);
                break;
            }
            case 3: {
                if (tipo=="int")
                    muestra(tam,arr1);
                else if (tipo=="char")
                    muestra(tam,arr2);
                else if (tipo=="double")
                    muestra(tam,arr3);
                break;
                break;
            }
            case 4: {
                cout<<endl;
                cout<<"Tipo del vector..."<<endl;
                cout<<"1. INTeger"<<endl;
                cout<<"2. CHARacter"<<endl;
                cout<<"3. DOUBLE"<<endl;
                cin>>tipo;
                break;
            }
            case 5: {
                break;
            }
        }
        cout<<endl;
    } while (op!=5);
    cout<<endl;
    return 0;
}
