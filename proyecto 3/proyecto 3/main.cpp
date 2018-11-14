/*
PROYECTO TRES, PROGRAMACION ORIENTADA A OBJETOS
###############################################

>>Creado por:
>Oscar Antonio Hinojosa Salum A00821930
>Ana Isabel Cruz Ramos A01138741
>Helena Ruiz Ramirez A01282531

>>Programa de tipo servicio Uber pero para gente rica que quiera
pedir servicios de autos,
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "Autos.h"
#include "Aviones.h"
using namespace std;

///SON 3 FUNCIONES EN TOTAL (POR AHORA), PARA QUE EL PROGRAMA SEA MODULAR Y MAS DINAMICO CON LA MEMORIA///
///MENU: RECIBE APUNTADORES NADA MAS, PARA LUEGO PASARSELOS A CASOS SI ES NECESARIO.
///CASOS: RECIBE OPCION DEL USUARIO "op" Y LOS APUNTADORES, AQUI SE HACEN LOS CASOS Y AL FINAL DE CADA UNO HAY QUE VOLVER AL MENU
///MAIN: AQUI SE CARGAN LOS ARCHIVOS DE TEXTO PARA LOS APUNTADORES, Y SOLAMENTE SE EJECUTA ESTO UNA VEZ POR EJECUCION DE PROGRAMA

int Casos(int &op, Servicio *s[], Reserva *r[], int &ind, Reserva &res){ ///RECIBIR A LOS APUNTADORES "s" y "r"
    //VARIABLES
    int id, dias=1, opcion=0, y, i=0;
    string cveSer, cveSer2;
    Fecha fecha, fechaFinCon;
    bool encontrado=false, stop=false;
    double costoFinal=0;
    //FIN DE VARIABLES
    
    switch(op){
        case 1: {
            //Un simple loop que hace la muestra de los 6 Servicios que hay
            cout << endl << "Lista de servicios" << endl;
            for (int x=0; x<6; x++) {
                s[x]->muestra();
            }
            break;
        }
        case 2: {
            //Mostrar todas las Reservaciones
            //Un loop para comparar Reservaciones
            for (int x=0; x<ind; x++) {
                cout << endl;
                cout << "---------------------------------" << endl;
                //Un loop para comparar los Servicios
                for (int y=0; y<6; y++) {
                    //Si son identicas las claves del Servicio, que imprima su informacion basica mas el Costo total
                    if (r[x]->getClaveServicio()==s[y]->getClave()){
                        s[y]->muestra();
                        cout << "ID Cliente: " << r[x]->getIDCliente() << endl;
                        double costo=s[y]->calculaCosto(r[x]->getDiasDuracion());
                        cout << "Costo total: " << costo << endl;
                    }
                }
                //Fechas de contrato y fin del contrato
                fecha=r[x]->getFechaContrato();
                cout << "Fecha de contrato: " << fecha << endl;
                fechaFinCon=r[x]->calcularFinContrato();
                cout << "Fecha de fin de contrato: " << fechaFinCon;
            }
            cout << endl;
            break;
        }
        case 3: {
            //Pedimos el servicio a buscar
            cout << "Clave del Servicio (ex. A-010): ";
            cin >> cveSer;
            
            encontrado=false;
            stop=false;
            for(int x=0; x<6 && !encontrado; x++){ //Este loop verifica que exista el servicio y lo muestre
                if(s[x]->getClave()==cveSer){
                    encontrado=true;
                    s[x]->muestra();
                }
            }
            if(encontrado==false)
                cout << "Servicio no existe." << endl;
            if(encontrado){
                encontrado=false;
                for(int x=0; x<ind; x++){
                    if(cveSer==r[x]->getClaveServicio()){ //Si existe el servicio se imprime ahora las reservas de ese servicio
                        cout << "----------------------" << endl;
                        cout << "ID Cliente: " << r[x]->getIDCliente() << endl;
                        fecha=r[x]->getFechaContrato();
                        cout << "Reservacion: " << fecha << endl;
                        fecha=r[x]->calcularFinContrato();
                        cout << "Terminacion: " << fecha << endl << endl;
                        encontrado=true;
                    }
                }
                if(!encontrado) //En caso de no encontrar reservaciones de ese servicio
                    cout << "Reservacion(es) no encontrada(s)." << endl;
            }
            break;
        }
        case 4: {
            cout << "Fecha a buscar (mm/dd/aaaa): "; //Pedimos la fecha a buscar
            cin >> fecha;
            cout << endl;
            encontrado=false;
            for(int x=0; x<ind; x++){ //Nested loop que primero verifica que la fecha de reserva coincida con la proporcionada
                if(fecha==r[x]->getFechaContrato()){
                    for(int y=0; y<6; y++){ //Y un loop que si al encontrarse coincidencia que ahora imprima el servicio que es y su informacion
                        if(r[x]->getClaveServicio()==s[y]->getClave()){
                            s[y]->muestra();
                            encontrado=true;
                        }
                    }
                }
            }
            if(!encontrado) //En caso de que no hubiera reservacion que coincida
                cout << "No hubo reservaciones en esta fecha." << endl;
            break;
        }
        case 5: {
            cout << "ID del cliente: "; //Pedimos el ID
            cin >> id;
            do{
                cout << "Clave del Servicio: ";
                cin >> cveSer;
                cveSer2=cveSer;
                if(cveSer!="-1"){ //Si la clave del servicio es -1 el caso se detiene
                    encontrado=false;
                    for(int x=0; x<6 && !encontrado; x++){ //Este loop verifica que el servicio exista
                        if(s[x]->getClave()==cveSer)
                            encontrado=true;
                    }
                    if(encontrado==false) //En caso de no existir el servicio, se le vuelve a pedir al usuario
                        cout << "Servicio no encontrado, vuelvalo a intentar." << endl;
                    else
                        cout << "Servicio aceptado." << endl;
                }
                if(encontrado){ //Solo entra si existe el servicio, continuamos con pedir la fecha ahora y los dias de duracion
                    encontrado=false;
                    cveSer="-1";
                    cout << "Fecha a rentar (mm/dd/aaaa): ";
                    cin >> fecha;
                    cout << "Dias requeridos: ";
                    cin >> dias;
                    do{
                        if(opcion==1){
                            cout << "Fecha a rentar (mm/dd/aaaa): ";
                            cin >> fecha;
                        }
                        if(opcion==2){
                            cout << "Dias requeridos: ";
                            cin >> dias;
                        }
                        if(!encontrado){
                            cout << "Fecha valida! ...registrando reserva." << endl;
                            res.setClaveServicio(cveSer2);
                            res.setIDCliente(id);
                            res.setFechaContrato(fecha);
                            res.setDiasDuracion(dias);
                            r[ind] = &res;
                            cout << "Registro hecho." << endl;
                            ind++;
                            opcion=3;
                        }
                        else if(encontrado){
                            cout << "Fecha de Contrato no disponible. Vuelvalo a intentar." << endl;
                            cout << "1. Cambiar Fecha." << endl;
                            cout << "2. Disminuir Dias." << endl;
                            cout << "3. Cancelar Registro." << endl;
                            cin >> opcion;
                        }
                    }while(opcion!=3);
                }
            }while(cveSer!="-1");
            
            if(encontrado)
                cout << "Registo sin exito." << endl;
            else{
                for(int x=0; x<6; x++){
                    if(cveSer2==s[x]->getClave()){
                        costoFinal=s[x]->calculaCosto(dias);
                    }
                }
                cout << "Costo: $" << costoFinal << endl;
            }
            break;
        }
    }
    cout << endl;
    return op;
}

int Menu(Servicio *s[], Reserva *r[], int &ind, Reserva &res){ ///DEBE RECIBIR A "s" y "r" COMO PARAMETROS, PERO SON APUNTADORES NO SUPE COMO HACERLO
    int op;
    do{
        cout << endl;
        cout << "######################################" << endl;
        cout << "Menu:" << endl;
        cout << "1. Consultar la lista de Servicios." << endl;
        cout << "2. Consultar la lista de reservaciones." << endl;
        cout << "3. Consultar las reservas de un servicio dado." << endl;
        cout << "4. Consultar las reservas de una fecha especifica." << endl;
        cout << "5. Hacer una reservacion." << endl;
        cout << "6. Guardar y Salir." << endl;
        cout << endl << "Opcion: ";
        cin >> op;
        if(op!=6)
            Casos(op,s,r,ind,res);
    }while(op!=6);
    return op;
}

int main(){
    cout << "Proyecto Tres: Servicio de Transporte." << endl;
    cout << "######################################" << endl;
    cout<<"Leyendo los archivos de Servicios y Reservas..."<<endl;
    ///DECLARACION DE VARIABLES
    Servicio *s[6]; //Maximo 6 elementos.
    Reserva *r[20]; //Maximo 20 elementos
    ifstream archEntSer; //Para el archivo de texo "Servicios.txt"
    ifstream archEntRes; //Para el archivo de texto "Reserva.txt" Se pudo haber hecho con un archEnt pero por seguridad y orden se agrego Ser y Res
    ofstream archSalRes;
    ///FIN DE DECLARACION
    
    /// LECTURA DEL ARCHIVO SERVICIOS
    archEntSer.open("Servicios.txt");
    int cycle=1,ind=0; // Variables para el # del ciclo y el indice
    while (!archEntSer.eof()){
        //  Variables del ciclo
        string linea,datoS,clave,desc;
        long length,space;
        char datoC,tipo;
        double datoD=0,costo;
        bool blind=true,chofer=true,carro=true;
        int personas=0, adicional=0,datoI=0;
        // ***
        //  El ciclo empieza agarrando toda la linea en el archivo
        getline(archEntSer,linea);
        //  Si va en el sexto ciclo, no borra el espacio extra al final de la linea
        if (cycle<6){
            length=linea.length();
            linea.erase(length-1);
        }
        //  Busca el espacio y agarra lo que hay antes, osea la clave.
        //  Luego se borra para agarrar el dato siguiente.
        space = linea.find(" ");
        clave = linea.substr(0,space);
        linea.erase(0,space+1);
        //  Hace lo mismo pero ahora guarda el tipo
        tipo = linea[0];
        space = linea.find(" ");
        linea.erase(0,space+1);
        //  Para el dato de costo, se hace un ciclo for para que cambie cada
        //  caracter del string linea a un int, se multiplique por 10^n, y
        //  se vaya sumando. Al final se guarda como la cantidad correcta y hace
        //  el mismo paso para borrarse de la linea.
        space = linea.find(" ");
        for (long j=space;j>0;j--){
            datoS = linea[0];
            datoI = atoi(datoS.c_str());
            datoD += datoI * pow(10,j-1);
            linea.erase(0,1);
        }
        space = linea.find(" ");
        linea.erase(0,space+1);
        costo = datoD;
        //  Aqui clasifica si la linea contiene datos de un carro y un avion
        //  al leer el tipo que se guardo. Cada uno tiene su ciclo individual
        //  para guardar sus datos especificos. Estos leen la linea al reves
        //  para no afectar la descripcion, la cual varia en tamaÒo.
        length = linea.length();
        if (tipo == 'S' || tipo == 'M' || tipo == 'T'){
            datoC = linea[length-1];
            if (datoC=='0')
                blind=false;
            length-=2;
            datoC = linea[length-1];
            if (datoC=='0')
                chofer=false;
            length-=2;
            linea.erase(length,4);
        }
        else if (tipo == 'H' || tipo == 'J' || tipo == 'A'){
            datoC = linea[length-1];
            adicional = datoC-48;
            linea.erase(length-2,2);
            length=linea.length()-1;
            int i=0;
            do {
                datoS = linea[length-i];
                datoI = atoi(datoS.c_str());
                personas += datoI*pow(10,i);
                i++;
            } while (linea[length-i]!=' ');
            space=linea.find(" ");
            linea.erase(space);
            carro=false;
        }
        //  Lo que queda no borrado en la linea se guarda como la
        //  descripcion del servicio.
        datoS = linea;
        desc = datoS;
        //  Ya que estan todos los datos, crea los objetos de carro
        //  o de avion, y se escribe que el espacio en el indice del
        //  arreglo de servicios apunte a ese objeto.
        if (carro) {
            Fecha fechaDefault;
            s[ind] = new Autos("",0,fechaDefault,0,clave,tipo,costo,desc,chofer,blind);
        }
        else {
            Fecha fechaDefault;
            s[ind] = new Aviones("",0,fechaDefault,0,clave,tipo,costo,desc,personas,adicional);
        }
        //  Suma uno a la variable de ciclo y vuelve a
        //  empezar hasta que se hayan leido todas las lineas del archivo
        cycle++;
        ind++;
    }
    archEntSer.close();
    /// ******** ///
    
    /// LECTURA DEL ARCHIVO RESERVA
    //  La primera vez que se abre para su lectura es para contar el numero de lineas
    //  dentro del archivo. Esto lo necesitamos para que al guardar sus datos en la
    //  segunda lectura, la ultima linea se guarde correctamente.
    archEntRes.open("Reserva.txt");
    string str;
    int lineas=0;
    while (!archEntRes.eof()){
        lineas++;
        getline(archEntRes,str);
    }
    archEntRes.close();
    //  Se redefinen las variables del ciclo e indice y volvemos a abrir el archivo.
    archEntRes.open("Reserva.txt");
    ind=0;
    while (!archEntRes.eof()){
        //  Variables del ciclo
        string linea,datoS,clave;
        long space,length;
        int datoI=0,id=0,dia=0,mes=0,anio=0,diasCont=0;
        // ***
        //  Aqui es donde incluimos el numero de lineas, ya que es necesario quitar
        //  el espacio extra de las demas excepto de la ultima. Para evitar que esto
        //  pase, creamos un if statement para que no borre nada cuando vaya en
        //  la ultima.
        getline(archEntRes,linea);
        if (lineas!=1) {
            length=linea.length();
            linea.erase(length-1);
        }
        //  Se va a repetir el mismo procedimiento de buscar el espacio,
        //  guardar la variable, y borrarlo de la linea. El primer dato
        //  que se cheque va a ser la clave.
        space = linea.find(" ");
        clave = linea.substr(0,space);
        linea.erase(0,space+1);
        //  Aparte de la clave, los datos en cada linea del archivo son enteros,
        //  por lo cual se va a repetir el ciclo. Sin embargo, cada ciclo va a
        //  guardar un dato diferente.
        //  El primero va a leer y guardar el ID del Cliente.
        space = linea.find(" ");
        for (long j=space;j>0;j--){
            datoS = linea[0];
            datoI = atoi(datoS.c_str());
            datoI *= pow(10,j-1);
            id+=datoI;
            linea.erase(0,1);
        }
        space = linea.find(" ");
        linea.erase(0,space+1);
        //  El siguiente dato es el mes de la Fecha del Contrato.
        space = linea.find(" ");
        for (long j=space;j>0;j--){
            datoS = linea[0];
            datoI = atoi(datoS.c_str());
            datoI *= pow(10,j-1);
            mes+=datoI;
            linea.erase(0,1);
        }
        space = linea.find(" ");
        linea.erase(0,space+1);
        //  El siguiente dato es el dia de la Fecha del Contrato.
        space = linea.find(" ");
        for (long j=space;j>0;j--){
            datoS = linea[0];
            datoI = atoi(datoS.c_str());
            datoI *= pow(10,j-1);
            dia+=datoI;
            linea.erase(0,1);
        }
        space = linea.find(" ");
        linea.erase(0,space+1);
        //  El siguiente dato es el aÒo de la Fecha del Contrato.
        space = linea.find(" ");
        for (long j=space;j>0;j--){
            datoS = linea[0];
            datoI = atoi(datoS.c_str());
            datoI *= pow(10,j-1);
            anio+=datoI;
            linea.erase(0,1);
        }
        space = linea.find(" ");
        linea.erase(0,space+1);
        //  Lo que resta de la linea se guarda en los dias del contrato.
        //  Se borra tambien para el proximo ciclo.
        diasCont = atoi(linea.c_str());
        linea.erase(0);
        //  Lo que sigue es crear un objeto Fecha para guardar la fecha del contrato.
        Fecha f(mes,dia,anio);
        //  Por ultimo, el arreglo tiene que apuntar a un objeto Reserva con todos
        //  los datos que se acaban de leer.
        r[ind] = new Reserva(clave,id,f,diasCont);
        //  Se le agrega uno a la variable del indice y se le resta uno a la variable
        //  de lineas para el siguiente ciclo.
        lineas--;
        ind++;
    }
    /// ******** ///
    archEntRes.close();
    
    Reserva res;
    Menu(s,r,ind,res);
    
    cout << endl << "Guardando y Saliendo...";
    archSalRes.open("Reserva.txt");
    for (int i=0; i<ind; i++){
        archSalRes << *r[i];
        if(i<ind-1)
            archSalRes << endl;
    }
    archSalRes.close();
    return 0;
}
