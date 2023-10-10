//
// Created by Ana Gabriela on 8/10/2023.
//
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <deque>
#include <stdexcept>
#include "persona.h"
#include "aeronave.h"
using namespace std;

#ifndef __VUELO_H
#define __VUELO_H


class Vuelo{
private:

    deque<Pasajero> pasajeros;

public:
    int idVuelo;
    string fecha;
    string origen ;
    string destino;

    int sillasA;
    int sillasH;
    int sillasJ;
    Vuelo();
    deque<Tripulante> tripulacion;
    deque<pair<Avion,Vuelo>> a;
    deque<pair<Helicoptero,Vuelo>> h;
    deque<pair<Jet,Vuelo>> j;
    void reservar(Pasajero p,int num);
    void verTodosLosPasajeros();
    //void puertoEmbarque();
    void generarVuelos(int& num,Vuelo& v);
    void verificarAsignacion(int&num,Vuelo& v);

};



#endif
