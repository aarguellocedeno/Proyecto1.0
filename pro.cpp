#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <deque>
#include <stdexcept>
#include <cstdio>
#include "vuelo.h"
#include <limits>
using namespace std;

/*
 * PROYECTO 1
 * ANA GABRIELA ARGÜELLO
 * LAURA ISABEL OLIVERO
 * */
void eleccionUno(int& consulta);
void eleccionDos(int& consulta);
void eleccionTres(int& consulta);
void generarAvion(Vuelo& vu);
void generarHelicoptero(Vuelo& vu);
void generarJet(Vuelo& vu);

/*La clase personaFactory principalmente fue para implementar el factory method, sin embargo se llegó a la conclusión de
 * que el uso de este método no sería lo mejor puesto que para la información de cada tripulante y pasajero
 * se pide como parámetro uno de esos dos objetos, y aunque se pensó la posibilidad de una clase virtual ingresarInfo
 * que recibiera los objetos Pasajeros y Tripulación, no se optó por el uso de esta*/

class personaFactory{
    public:
        void crearPersona(int& cual,Pasajero& pas,Tripulante& tri){
            if(cual == 1){
                Pasajero p;
                p.ingresarInfoPasajero(pas);
                
            }else if(cual==2){
                Tripulante t;
                t.ingresarInfoTripulante(tri);
            }else if(cual==3){
                printf("Entrando a torre de control\n");
            }else{
                printf("Opcion no disponible\n");
            }
        }  
};


/*Esta es la función establecida para la reserva del vuelo, en esta función se hace una verificación
 * de la existencia de la aeronave, es decir verifica si en la lista respectiva de la aeronave, hay al
 * menos un objeto, seguido a esa verificación se pasa a la función reserva que se encarga de primero
 * mostrar los vuelos disponibles(Según la aeronave seleccionada), y según la elección del usuario, se
 * realiza la respectiva resta al número de asientos disponibles*/

void Pasajero::selVuelo(){
    int sel;
    Vuelo v;
    printf("Primero selecciona en que nave deseas ir=\n1) Avion\n2) Helicoptero\n3) Jet Privado\nselecciona = ");
    try{
        cin>>sel;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("Debes colocar un entero");
        }

    }catch(const exception& excep){
        std::cerr<<"Argumento invalido = "<<excep.what()<<endl;
    }
    if(sel==1){
        printf("si");
        if(v.a.size()!=0){

        }else{
            cout<<"Por el momento no hay vuelos disponibles\n";
        }
    }else if(sel==2){
        printf("si");
        if(v.h.size()!=0){

        }else{
            cout<<"Por el momento no hay vuelos disponibles\n";
        }
    }else if(sel==3){
        if(v.j.size()!=0){

        }else{
            cout<<"Por el momento no hay vuelos disponibles\n";
        }
        printf("si");
    }else{
        printf("Opcion no disponible");
    }
}

/*Las funciones auxiliares eleccionUno,eleccionDos,eleccionTres, están para brindarle mayor, orden
 * al código, y este sea lo más legible posible; en cada una de estas funciones lo que se hace
 * es mostrar las diferentes cosas que el usuario puede consultar en la aplicación, por ejemplo,
 * el pasajero puede hacer la reserva de su vuelo, ver la disponibilidad, y consultar la puerta de
 * embarque, ya con su vuelo asignado.*/

void eleccionUno(int& consulta,Vuelo& vu){
    cout<<"Que deseas consultar?\n";
    cout<<"1)Reservar vuelo\n2)Consultar disponibilidad\n3)Consultar puerta de embarque\n4)Ver servicios jet\n"<<endl;
    try{
        cin>>consulta;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("Debes colocar un entero");
        }

    }catch(const exception& excep){
        std::cerr<<"Argumento invalido = "<<excep.what()<<endl;
    }
    switch (consulta) {
        case 1:
            printf("don't know");
            break;
        case 2:
            printf("don't know");
            break;
        case 3:
            printf("don't know");
            break;
        case 4:
            if(vu.j.size()!=0){
                vu.j[0].first.verServicios(); //para acceder a esto primero se necesita crear un jet
            }else{
                printf("Por el momento no se puede acceder a los servicios\n");
            }

            break;
        default:
            printf("Opción no valida");
            break;
    }
}

void eleccionDos(int& consulta,Pasajero& pas,Tripulante& tri,Vuelo& vu){
    personaFactory per;
    cout<<"Que deseas consultar?\n";
    cout<<"1)Asignar a vuelo\n"<<endl;
    try{
        cin>>consulta;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("Debes colocar un entero");
        }

    }catch(const exception& excep){
        std::cerr<<"Argumento invalido = "<<excep.what()<<endl;
    }
    if(consulta==1){
        per.crearPersona(consulta,pas,tri);
        vu.tripulacion.push_back(tri);

    }else{
        printf("Opcion no disponible\n");
    }

}

void eleccionTres(int& consulta,Vuelo& vu){
    int num=0;
    Vuelo v;
    AeroFactory* aero;
    cout<<"Que deseas consultar?\n";
    cout<<"1)Informacion de la aeronave\n2)Asignar puerta de embarque\n3)Generar Naves\n4) Verificar si esta totalmente asignado\n5) verificar puertas de embarque disponibles\nSeleccionar = ";
    try{
        cin>>consulta;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("Debes colocar un entero");
        }

    }catch(const exception& excep){
        std::cerr<<"Argumento invalido = "<<excep.what()<<endl;
    }
    switch (consulta){
        case 1:
            printf("De que nave deseas informacion=\n1) Avion\n2) Helicoptero\n3) Jet Privado\nselecciona = ");
            try{
                cin>>num;
                if(cin.fail()) {
                throw invalid_argument("Debes colocar un entero");
            }
            }catch(const exception& excep){
                std::cerr<<"Argumento invalido = "<<excep.what()<<endl;
            }
  /*          if(num==1){
                Aeronave* avion = AeroFactory::crearNave(1);
                avion->info();
                delete avion;
            }else if(num==2){
                Aeronave* helicoptero = AeroFactory::crearNave(2);
                helicoptero->info();
                delete helicoptero;
            }else if(num==3){
                Aeronave* jet= AeroFactory::crearNave(3);
                jet->info();
                delete jet;
            }
*/
            aero->crearNave(num);
            break;
        case 2:
            printf("que paso");
            break;
        case 3:
            printf("Que nave deseas generar=\n1) Avion\n2) Helicoptero\n3) Jet Privado\nselecciona = ");

            try{
                cin>>num;
                if(cin.fail()) {
                    throw invalid_argument("Debes colocar un entero");
                }
            }catch(const exception& excep){
                std::cerr<<"Argumento invalido = "<<excep.what()<<endl;
            }
            v.generarVuelos(num,vu);
            break;
        case 4:
            printf("Que nave deseas verificar=\n1) Avion\n2) Helicoptero\n3) Jet Privado\nselecciona = ");

            try{
                cin>>num;
                if(cin.fail()) {
                    throw invalid_argument("Debes colocar un entero");
                }
            }catch(const exception& excep){
                std::cerr<<"Argumento invalido = "<<excep.what()<<endl;
            }
            v.verificarAsignacion(num,vu);
            break;
        default:
            printf("Opcion no disponible");
            break;
        }

}









int main() {
    int eleccion = 0, consulta;
    bool flag = true;
    Vuelo v;
    Tripulante tri;
    Pasajero pas;
    personaFactory per;
    printf("Bienvenido al sistema de gestion del aeropuerto Alfonso Bonilla Aragon\n");
    cout<< "Por favor selecciona una opcion:\n1) Pasajero\n2) Trabajador de aeropuerto\n3)Torre de Control\nSeleccionar= "; // coloco algo como trabajador...?

    try{
        cin>>eleccion;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("Debes colocar un entero");
        }

    }catch(const exception& excep){
        std::cerr<<"Argumento invalido = "<<excep.what()<<endl;
    }
    while(flag==true){

        if(eleccion==1){
            per.crearPersona(eleccion,pas,tri); //Se llama a esta función, para que el pasajero pueda diligenciar su información personal
            eleccionUno(consulta,v);
        }else if(eleccion==2){
            eleccionDos(consulta,pas,tri,v);
        }else if(eleccion==3){
            eleccionTres(consulta,v);
        }
        else if(eleccion==4){
            printf("Saliendo.... ... .... ... ... ... ");
            flag==false;
        }else{
            printf("Esa opcion no es valida\n");
        }
        cout<<"Por favor selecciona una opcion:\n1) Pasajero\n2) Trabajador de aeropuerto\n3)Torre de Control\n4)Salir;\nSeleccionar= "; // coloco algo como trabajador...?
        cin>>eleccion;
    }

    return 0;

}

