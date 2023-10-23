#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <deque>
#include <stdexcept>
#include "persona.h"
#include "aeronave.h"
#include <limits>
#include "vuelo.h"
using namespace std;



/*Esta funcion esta creada para dar una fecha a los vuelos; en esta funcion, pues se observa que se crea una lista de
 * strings y ya segun el numero que salga en ale, esa sera la fecha*/
string dimeFecha(){
    deque<string> date;
    date.push_back("Diciembre 13 2023");
    date.push_back("Diciembre 20 2023");
    date.push_back("Enero 9 2024");
    date.push_back("Enero 25 2024");
    date.push_back("Febrero 7 2024");
    date.push_back("Febrero 20 2024");
    date.push_back("Marzo 12 2024");
    date.push_back("Marzo 30 2024");
    date.push_back("Abril 10 2024");

    int ale = rand() % 8;
    string fecha= date[ale];
    return fecha;
}

/*Esta funcion al igual que las de generarHelicoptero y generarJet, estan encargadas de crear ese objeto
 * que se desee, y se le asignen todos los valores que se necesiten,luego ese objeto es agregado a la lista
 *que comparte con vuelo*/

void generarAvion(Vuelo& vu){
    int ele;
    Vuelo vuelo;
    Avion avion;
    int ale= rand() % 15 + 5; //me da un numero aleatorio entre 5 y 15;
    int ale2= rand() % 25 + 2000; // este es para el año de la aeronave
    int ale3= rand() % 4 + 1;
    int personas = rand() % 10 + 10;
    printf("Que uso tendra=\n1)Transporte\n2)Carga\nSeleccionar=  ");
    cin>>ele;
    if(ele==1){
        avion.categoria = "Transporte";
    }else if (ele==2){
        avion.categoria = "Carga";
    }else{
        printf("Opcion no dispinible, se asigna uso por defecto 'Transporte' ");
        avion.categoria = "Transporte";
    }
    avion.altMax = ale;
    avion.yearFab = ale2;
    avion.velocidad = ale;
    avion.cantPas=personas;
    avion.autonomia= ale;
    avion.estado= 1; //en uno esta en servivio, en dos esta completamente asignado, en tres esta en mantenimiento
    avion.cantMotor = ale3;
    avion.marca="GIAL Air";
    avion.modelo= "Top AirService";
    vu.a.push_back(make_pair(avion,vuelo));
    vu.sillasA += avion.cantPas;
}

void generarHelicoptero(Vuelo& vu){
    Vuelo vuelo;
    int sel=0;
    Helicoptero helicoptero;
    int ale= rand() % 30 + 10; //me da un numero aleatorio entre 5 y 15;
    int ale2= rand() % 25 + 2000; // este es para el año de la aeronave
    int ale3= rand() % 4 + 1;
    int personas = rand() % 5 + 5;
    helicoptero.rotores = ale3;
    helicoptero.capEle=ale;
    helicoptero.yearFab = ale2;
    helicoptero.velocidad = ale;
    helicoptero.cantPas=personas;
    helicoptero.autonomia= ale;
    helicoptero.estado= 1; //en uno esta en servivio, en dos esta completamente asignado, en tres esta en mantenimiento
    helicoptero.marca="GIAL Air";
    helicoptero.modelo= "Top AirService";
    printf("Que uso le daras al helicoptero\n1)Rescate\n2)Turismo\n3)Transporte\n4)Fuerza policial\n5)Ambulancia\nSelecciona una opcion= ");

    try{
        cin>>sel;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("Debes colocar un entero");
        }

    }catch(const exception& excep){
        std::cerr<<"Argumento invalido = "<<excep.what()<<endl;
        helicoptero.uso = "Transporte"; // Se le asigna un uso por defecto
    }
    switch (sel)
    {
        case 1:
            helicoptero.uso = "Rescate";
            break;
        case 2:
            helicoptero.uso = "Turismo";
            break;
        case 3:
            helicoptero.uso = "Transporte";
            break;
        case 4:
            helicoptero.uso = "Fuerza Policial";
            break;
        case 5:
            helicoptero.uso = "Ambulancia";
            break;
        default:
            printf("No disponible\n");
            break;
    }

    vu.h.push_back(make_pair(helicoptero, vuelo));
    vu.sillasH += helicoptero.cantPas;
}

void generarJet(Vuelo& vu){
    Vuelo vuelo;
    Jet jet;
    int ale= rand() % 15 + 5; //me da un numero aleatorio entre 5 y 15;
    int ale2= rand() % 25 + 2000; // este es para el año de la aeronave
    int persona= rand() % 6 + 9;
    jet.propietario = "";
    jet.yearFab = ale2;
    jet.velocidad = ale;
    jet.cantPas=persona;
    jet.autonomia= ale;
    jet.estado= 1; //en uno esta en servivio, en dos esta completamente asignado, en tres esta en mantenimiento
    jet.marca="GIAL Air";
    jet.modelo= "Top AirService";
    vu.j.push_back(make_pair(jet, vuelo));
    vu.sillasJ += jet.cantPas;
}

Vuelo::Vuelo(){
    int idAle= rand() % 18796 + 100;
    string date = dimeFecha();
    deque<Pasajero> pas;
    this -> sillasA = 0;
    this-> sillasH = 0;
    this-> sillasJ = 0;
    this-> idVuelo = idAle;
    this -> pasajeros = pas;
    this ->fecha = date;
    this -> origen = "Cali" ;
    this -> destino = "";

}


void Vuelo::verificarAsignacion(int &num, Vuelo &vu) {
    if(num==1){
        if(vu.sillasA==0){
            printf("No hay mas vuelos disponibles en avion\n");
        }else{
            printf("Todavia no esta totalmente asignado\n");
        }
    }else if(num==2){
        if(vu.sillasH==0){
            printf("No hay mas vuelos disponibles en helicoptero\n");
        }else{
            printf("Todavia no esta totalmente asignado\n");
        }
    }else if(num==3){
        if(vu.sillasJ==0){
            printf("No hay mas vuelos disponibles en jet\n");
        }else{
            printf("Todavia no esta totalmente asignado\n");
        }
    }else{
        printf("Opcion no disponible\n");
    }
}

void Vuelo::generarVuelos(int& num, Vuelo &vu){


    if(num==1){
        if(vu.a.size()<3){
            generarAvion(vu);
            printf("Generando Avion... ... ...\n\nAvion Generado.\n");
        }else{
            printf("Lo siento pero no es posible generar más aviones\n");
        }

    }else if(num==2){
        if(vu.h.size()<3){
            generarHelicoptero(vu);
            printf("Generando Helicoptero... ... ...\n\nHelicoptero Generado.\n");
        }else{
            printf("Lo siento pero no es posible generar más helicopteros\n");
        }

    }else if(num==3){
        if(vu.j.size()<3){
            generarJet(vu);
            printf("Generando Jet... ... ...\n\nJet Generado.\n");

        }else{
            printf("Lo siento pero no es posible generar más jets\n");
        }

    }

}

void Vuelo::verTodosLosPasajeros() {
    int i;
    if(pasajeros.size()!=0){
        for(i=0;i<pasajeros.size();i++){
            cout<<"Nombre= "<<pasajeros[i].nombre<<"\nApellido= "<<pasajeros[i].apellido<<"\nID= "<<pasajeros[i].id<<"Alergias= "<<pasajeros[i].infoMed<<endl;
            cout<<"Cantidad de Maletas= "<<pasajeros[i].maletas<<"\nNacionalidad= "<<pasajeros[i].nacionalidad<<"\n\n";
        }
    }else{
        printf("Por el momento las naves no tienen pasajeros");
    }
}

void Vuelo::reservar(Pasajero p,int num){
    int u=0,i=0,sel;
    if(num==1){
        if( sillasA > 0){
            for(i=0;i<a.size();i++){
                u=i+1;
                cout<<endl<<u<<") "<<a[i].second.fecha<<endl;
                cout<<"Asientos disponibles en ese vuelo= "<<a[i].first.cantPas<<endl;
            }
            printf("Selecciona una de las fechas= ");
            try{
                cin>>sel;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    throw invalid_argument("Debes colocar un entero");
                }

            }catch(const exception& excep){
                std::cerr<<"Argumento invalido = "<<excep.what()<<endl;
                cerr<<"Tu reserva no fue exitosa\n";
            }
            if(a[sel-1].first.cantPas==0){
                printf("Lo sentimos ese vuelo ya no se encuentra disponible\n");
            }else{
                a[sel-1].first.cantPas-=1;
                sillasA -= 1;
                pasajeros.push_back(p);
                cout<<"Tu reserva ha sido exitosa\n";
            }

        }else{
            printf("No es posible reservar");
        }
    }else if(num==2){
        if( sillasH > 0){
                for(i=0;i<h.size();i++){
                    u=i+1;
                    cout<<endl<<u<<") "<<h[i].second.fecha<<endl;
                    cout<<"Asientos disponibles en ese vuelo= "<<h[i].first.cantPas<<endl;
                }
                printf("Selecciona una de las fechas= ");
                try{
                    cin>>sel;
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                        throw invalid_argument("Debes colocar un entero");
                    }

                }catch(const exception& excep){
                    std::cerr<<"Argumento invalido = "<<excep.what()<<endl;
                    cerr<<"Tu reserva no fue exitosa\n";
                    cerr<<"Tu reserva no fue exitosa\n";
                }
                if(h[sel-1].first.cantPas==0){
                    printf("Lo sentimos ese vuelo ya no se encuentra disponible\n");
                }else {
                    h[sel - 1].first.cantPas -= 1;
                    sillasH -= 1;
                    pasajeros.push_back(p);
                    cout<<"Tu reserva ha sido exitosa\n";
                }
        }else{
            printf("No es posible reservar");
        }
    }else if(num==3){
        if( sillasJ > 0){
                for(i=0;i<j.size();i++){
                    u=i+1;
                    cout<<endl<<u<<") "<<j[i].second.fecha<<endl;
                    cout<<"Asientos disponibles en ese vuelo= "<<j[i].first.cantPas<<endl;
                }
                printf("Selecciona una de las fechas= ");
                try{
                    cin>>sel;
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                        throw invalid_argument("Debes colocar un entero");
                    }

                }catch(const exception& excep){
                    std::cerr<<"Argumento invalido = "<<excep.what()<<endl;
                    cerr<<"Tu reserva no fue exitosa\n";
                }
                if(j[sel-1].first.cantPas==0){
                    printf("Lo sentimos ese vuelo ya no se encuentra disponible\n");
                }else{
                    j[sel-1].first.cantPas-=1;
                    sillasJ -= 1;
                    pasajeros.push_back(p);
                    cout<<"Tu reserva ha sido exitosa\n";
                }


        }else{
            printf("No es posible reservar");
        }
    }


};