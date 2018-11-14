#include <iostream>
using namespace std;

void Arreglo (int arr[], int orden) {
    for (int i=0;i<orden;i++) {
        cout<<"Num "<<(i+1)<<": ";
        cin>>arr[i];
    }
    cout<<endl;
}

void Mostrar (int arr[], int orden) {
    for (int j=0;j<orden;j++) {
        cout<<arr[j]<<" ";
    }
    cout<<endl;
}

void Buscar (int arr[], int orden, int n) {
    int stop=0;
    for (int i=0;i<orden;i++) {
        if (arr[i]==n) {
            if (stop==0){
                for (int j=i;j<(orden-1);j++) {
                    arr[j]=arr[j+1];
                }
                arr[orden-1]=0;
                stop++;
            }
        }
    }
    cout<<endl;
}

int main() {
    int num,tam;
    cout<<"Escriba un numero: ";
    cin>>num;
    cout<<"Tamaño del arreglo: ";
    cin>>tam;
    while (tam>15) {
        cout<<"Debe ser menor a 15: ";
        cin>>tam;
    }
    cout<<endl;
    int arrDatos[tam];
    
    Arreglo (arrDatos,tam);
    Mostrar (arrDatos,tam);
    cout<<"Eliminando el numero "<<num<<" del arreglo...";
    Buscar (arrDatos,tam,num);
    Mostrar (arrDatos,tam);
    
    cout<<endl;
    return 0;
}
