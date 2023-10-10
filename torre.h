#include <string>
#include <cstdlib>
#include "Puerta.h"
#include "Aeronave.h"
#include <deque>
#include <stdexcept>
#include <utility>
#include <vector>
using namespace std;

#ifndef __TORRE_H
#define __TORRE_H



class Torre{

    string nombre;
    string localizacion;
private:
    deque<Aeronave> aeronaves;
    deque<Puerta> embarques;
    deque<pair<Aeronave , Puerta>>hist;

public:
    Torre(string name, string loc);
    void ubicarPuerta();
    void comunicarAvion();
    void agregarHist(pair <Aeronave, Puerta>p);
    void generarPuertas();

};

#endif
