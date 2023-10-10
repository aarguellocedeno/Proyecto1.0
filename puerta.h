#include <string.h>
#include <cstdlib>
#include "Vuelo.h"
#include <deque>
#include <string.h>
#include <stdio.h>
#include <deque>
#include <stdexcept>
#include <utility>
using namespace std;

#ifndef __PUERTA_H
#define __PUERTA_H

class Puerta{
private:
    int numID;
    string ubi;
    bool dispo;
    int horaE;
    deque<Vuelo>historial;
public:
    Puerta();
    bool verEstado();
    void cambiarEstado(bool n);
    void agregarVuelo(Vuelo n);
};

#endif
