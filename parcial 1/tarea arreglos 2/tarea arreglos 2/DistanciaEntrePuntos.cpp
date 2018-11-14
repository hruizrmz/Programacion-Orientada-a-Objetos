//  Helena Ruiz Ramirez
//  A01282531
//  Enero 11, 2018
//  Tarea 1: matrizeglos y Matrices
//  Ejercicio 2: Distancia Entre Puntos

#include <iostream>
#include <cmath>
using namespace std;

void LlenarDatos (double matriz[8][2]) {
    for (int i=0;i<8;i++) {
        cout<<"Coordenada "<<(i+1)<<endl;
        for (int j=0;j<2;j++) {
            if (j==0)
                cout<<"x: ";
            else if (j==1)
                cout<<"y: ";
            cin>>matriz[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void MuestraDatos (double matriz[8][2]) {
    for (int i=0;i<8;i++) {
        cout<<matriz[i][0]<<" "<<matriz[i][1];
        cout<<endl;
    }
    cout<<endl;
}

void CalculaDistancias (double matriz[8][2]) {
    double dist,x1,x2,y1,y2,check=1000000;
    for (int i=0;i<8;i++) {
        int one=0;
        for (int j=0;j<8;j++) {
            dist=sqrt(pow((matriz[i][0]-matriz[one][0]),2)+pow((matriz[i][1]-matriz[one][1]),2));
            if (dist!= 0) {
                if (dist<check) {
                    check=dist;
                    x1=matriz[i][0];
                    y1=matriz[i][1];
                    x2=matriz[one][0];
                    y2=matriz[one][1];
                }
            }
            one++;
        }
    }
    cout<<"El punto ("<<x1<<","<<y1<<") y el punto ("<<x2<<","<<y2<<") son los mas cercanos con una distancia de "<<check<<endl;
}

int main() {
    double plano[8][2];
    LlenarDatos(plano);
    MuestraDatos(plano);
    CalculaDistancias(plano);
    cout<<endl;
    return 0;
}
