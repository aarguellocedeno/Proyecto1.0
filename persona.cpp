#include "persona.h"
#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <stdio.h>
#include <deque>
#include <stdexcept>
using namespace std;
#include <limits>

/*Estos son los constructores de las clases Persona,Pasajero,Tripulante*/
Persona::Persona(){
    id=0;
    nombre="";
    apellido="";
    fechaN="";
    genero="";
    direccion="";
    correo="";
    telefono="";
}

Pasajero::Pasajero(){
    maletas=0;
    nacionalidad="";
    infoMed="";

}

Tripulante::Tripulante(){
    anosEx=0;
    horasDia=0;
    puesto="";
}


/*
* La función ingresarInfoPasajero y la función ingresarInfoTripulante son las encargadas de pedir los datos para los pasajeros
* y para los tripulantes o los trabajadores del aeropuerto.
*/
void Pasajero::ingresarInfoPasajero(Pasajero& pas){
    cout<<"\n\nIngresa tu primer nombre, y primer apellido = ";
    cin>>pas.nombre>>pas.apellido;
    cin.ignore();
    cout<<"\n\nIngresa tu numero de ID y genero =  ";
    cin>>pas.id>>pas.genero;
    cin.ignore();
    cout<<"\n\nIngresa tu fecha de nacimiento= ";
    getline(cin,pas.fechaN);
    cout<<"\n\nIngresa tu nacionalidad =";
    cin>>pas.nacionalidad;
    cin.ignore();
    cout<<"\n\nIngresa direccion= ";
    getline(cin,pas.direccion);
    cout<<"\n\nIngresa tu telefono= ";
    cin>>pas.telefono;
    cin.ignore();
    cout<<"\n\nIngresa tu correo electronico= ";
    cin>>pas.correo;
    cin.ignore();
    cout<<"\n\nIngresa numero de maletas= ";
    try{
        cin>>pas.maletas;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("Debes colocar un entero");
        }
    }catch(const exception& excep){
        std::cerr<<"Argumento invalido = "<<excep.what()<<endl;
        printf("Tu numero de maletas sera 1\n");
        pas.maletas = 1;
    }
    cin.ignore();
    cout<<"\n\nIngrese su informacion medica (alergias, enfermedades, cirugias y medicamentos que se este tomando actualmente) = ";
    getline(cin,pas.infoMed);
    cout<<endl;
}

void Tripulante::ingresarInfoTripulante(Tripulante& tri) { //aca si nose como hacer lo del try catch
    cout << "\n\nIngresa tu primer nombre, y primer apellido = ";
    cin >> tri.nombre >> tri.apellido;
    cout<<"\n\nIngresa tu numero de ID y genero =  ";
    cin>>tri.id>>tri.genero;
    cin.ignore();
    cout<<"\n\nIngresa tu fecha de nacimiento= ";
    getline(cin,tri.fechaN);
    cin.ignore();
    cout<<"\n\nIngresa direccion= ";
    getline(cin,tri.direccion);
    cout<<"\n\nIngresa tu telefono= ";
    cin>>tri.telefono;
    cout<<"\n\nIngresa tu correo electronico= ";
    cin>>tri.correo;
    cin.ignore();
    cout<<"\n\nIngrese tu puesto= ";
    getline(cin,tri.puesto);
    cout<<"\n\nIngrese sus años de experiencia = "; 

    try{
        cin>>tri.anosEx;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("Debes colocar un entero");
        }
    }catch(const exception& excep){
        std::cerr<<"Argumento invalido = "<<excep.what()<<endl;
        printf("Tu numero de años de experiencia sera 1\n");
        tri.anosEx=1;
    }
    cout<<"\n\nCuantas horas de trabajo hace diariamente = ";
    cin>>tri.horasDia;
    try{
        cin>>tri.horasDia;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            throw invalid_argument("Debes colocar un entero");
        }
    }catch(const exception& excep){
        std::cerr<<"Argumento invalido = "<<excep.what()<<endl;
        printf("Tu numero de horas al dia sera 6 \n");
        tri.horasDia=6;
    }
    cout<<endl;
}


