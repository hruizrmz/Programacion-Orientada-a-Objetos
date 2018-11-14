//  Helena Ruiz Ramirez
//  A01282531
//  Febrero 8, 2018
//  Proyecto 1:  Validacion de direcciones IP
//  Descripcion: Al leer un archivo conteniendo varias direcciones IP de tipo IPv4 e IPv6
//               el programa va a validar si estan escritas correctamente o no

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//  funcion que checa que la direccion de tipo IPv4 cumpla todas sus reglas de escritura,
//  dependiendo de su validez regresa falso o verdadero
bool ValidarIPv4(string v4) {
    string decimales=v4;
    int count=0;
    while (decimales.find('.')!=-1) { //  ciclo para checar que tenga cuatro numeros decimales
        long found=decimales.find('.');
        count++;
        decimales=decimales.substr(found+1);
    }
    if (count!=3) //  si hubieron mas de tres puntos, no se valida
        return false;
    string test=v4;
    while (test.find('.')!=-1) { //  ciclo para checar los numeros en si de la direccion
        string cantidad;
        int i=0;
        while (test[i]!='.') { // agarra los digitos entre los puntos
            cantidad+=test[i];
            i++;
        }
        long l=cantidad.length();
        if (l>3)  //  si tiene mas de tres digitos, no se valida
            return false;
        else if (l==2) {
            if (cantidad[0]=='0')  //  si tiene un 0 a la izquierda, no se valida
                return false;
        }
        else if (l==3) {
            if (cantidad[0]!='1'&&cantidad[0]!='2') //  si tiene un 0 a la izquierda, o es mayor a 200, no se valida
                return false;
            else if (cantidad[0]=='2') {   // si el primer digito es 2 y el segundo 5, el tercero debe estar entre 0 y 5 para validarse
                if (cantidad[1]=='5') {
                    if (cantidad[2]!='0'&&cantidad[2]!='1'&&cantidad[2]!='2'&&cantidad[2]!='3'&&cantidad[2]!='4'&&cantidad[2]!='5')
                        return false;
                }
                // si el segundo digito es mayor a 5 cuando el primero es 2, no se valida
                else if (cantidad[1]!='0'&&cantidad[1]!='1'&&cantidad[1]!='2'&&cantidad[1]!='3'&&cantidad[1]!='4'&&cantidad[1]!='5')
                    return false;
            }
        }
        test=test.erase(0,i+1);
    }
    // repite los mismos procedimientos de validacion ahora para el ultimo numero
    long l=test.length();
    if (l>3)
        return false;
    else if (l==2) {
        if (test[0]=='0')
            return false;
    }
    else if (l==3) {
        if (test[0]!='1'&&test[0]!='2')
            return false;
        else if (test[0]=='2') {
            if (test[1]=='5') {
                if (test[2]!='0'&&test[2]!='1'&&test[2]!='2'&&test[2]!='3'&&test[2]!='4'&&test[2]!='5')
                    return false;
            }
            else if (test[1]!='0'&&test[1]!='1'&&test[1]!='2'&&test[1]!='3'&&test[1]!='4'&&test[1]!='5')
                return false;
        }
    }
    return true;
}

//  funcion que checa que la direccion de tipo IPv6 cumpla todas sus reglas de escritura
//  dependiendo de su validez regresa falso o verdadero
bool ValidarIPv6(string v6) {
    string decimales=v6;
    int count=0;
    if (v6[0]=='0') // si la direccion empieza con 0, no se valida
        return false;
    while (decimales.find(':')!=-1) { //  ciclo para checar que tenga ocho numeros hexadecimales
        long found=decimales.find(':');
        count++;
        decimales=decimales.substr(found+1);
    }
    if (count!=7) //  si hubieron mas de siete puntos, no se valida
        return false;
    string test=v6;
    while (test.find(':')!=-1) { //  ciclo para checar los numeros en si de la direccion
        string cantidad;
        int i=0;
        while (test[i]!=':') { // agarra los digitos entre los puntos
            cantidad+=test[i];
            i++;
        }
        long l=cantidad.length();
        if (l>4)  //  si tiene mas de cuatro digitos, no se valida
            return false;
        
        for (int i=0;i<l;i++) {
            // utilizando el codigo ASCII, checa si el caracter es una letra de la f-z
            //  ya sea mayuscula o minuscula. en caso de que si, no se valida
            char c=cantidad[i];
            if (((c>69)&&(c<91))||((c>101)&&(c<123)))
                return false;
        }
        test=test.erase(0,i+1);

    }
    // repite los mismos procesos de validacion pero ahora con el ultimo numero
    long l=test.length();
    if (l>4)
        return false;
    for (int i=0;i<l;i++) {
        char c=test[i];
        if (((c>69)&&(c<91))||((c>101)&&(c<123)))
            return false;
    }
    return true;
}

// funcion que distingue que tipo de direccion IP esta leyendo
void Clasificacion(string ip,int&type){
    if ((ip.find(':'))==-1)
        type=4;
    else if ((ip.find('.'))==-1)
        type=6;
}

//  funcion para escribir en el nuevo archivo si las direcciones son validas o no
void EscribirArchivo(string file) {
    string linea,newFile;
    int tipo;
    ifstream entrada;
    ofstream salida;
    entrada.open(file);
    salida.open("DireccionesValidas.txt");
    while (!entrada.eof()) {
        bool valid;
        getline(entrada,linea);
        cout<<"";
        Clasificacion(linea,tipo);
        if (tipo==4){
            valid=ValidarIPv4(linea);
            if (valid)
                newFile+=linea+" = IP4 valida\n\n";
            else if (!valid)
                newFile+=linea+" = IP4 no valida\n\n";
        }
        else if (tipo==6){
            valid=ValidarIPv6(linea);
            if (valid)
                newFile+=linea+" = IP6 valida\n\n";
            else if (!valid)
                newFile+=linea+" = IP6 no valida\n\n";
        }
    }
    cout<<"Se ha generado el archivo con las validaciones bajo el nombre de DireccionesValidas.txt"<<endl;
    salida<<newFile;
    entrada.close();
    salida.close();
}

int main() {
    string archivo;
    cout<<"Archivo con las direcciones (abc.txt): ";
    cin>>archivo;
    cout<<endl;
    EscribirArchivo(archivo);
    cout<<endl;
    return 0;
}
