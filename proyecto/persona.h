#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <deque>
#include <cstdio>
#include <stdexcept>
using namespace std;
#ifndef __PERSONA_H
#define __PERSONA_H

class Persona{
    public:
        Persona();
        int id;
        string nombre,apellido,fechaN,genero,direccion,correo,telefono;

};


class Pasajero: public Persona{
    public:
        Pasajero();
        string nacionalidad,infoMed;
        int maletas;
        void ingresarInfoPasajero(Pasajero& pas); //Para la info del pasajero

};



class Tripulante: public Persona{
    public:
        Tripulante();
        string puesto;
        int anosEx,horasDia;
        void ingresarInfoTripulante(Tripulante& tri); //Para la info del trabajador de aeropuerto y tripulación

};
#endif


