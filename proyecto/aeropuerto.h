#include <cstdlib>
#include "Torre.h"
#include <deque>
#include <string>
#include "Vuelo.h"
#include <deque>
#include <stdexcept>
#include <vector>
using namespace std;

#ifndef __AEROPUERTO_H
#define __AEROPUERTO_H


class Aeropuerto{
	public:
		string nombre;
		Aeropuerto(string name);
		vector <Vuelo> vuelos;
		Torre torreControl;

};

#endif