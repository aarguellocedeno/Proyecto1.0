#include "Torre.h"
#include "Puerta.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <utility>
using namespace std;

/*
Torre::Torre(string name, char loc){
    this-> nombre = name;
    this-> localizacion = loc;
    for(int i = 0; i < 10; i++){
        this -> aeronaves.push_back(Aeronave());
    }

    for(int i = 0; i < 10; i++){
        int hora = 24 - i;
        this -> embarques.push_back(Puerta(hora));
    }

    this->hist;
}

void Torre::ubicarPuerta(){
    pair <Aeronave,Puerta> asig();

    for(int i = 0; i < aeronaves.size(); i++){
        Aeronave act();
        Puerta dispo(0);

        if(aeronaves[i].reportarUbi() == 1){
            act = aeronaves[i];
            while(int flag = 0){
                for(int i = 0; i < embarques.size(); i++){
                    if(embarques[i].verEstado() == true){
                        embarques[i].cambiarEstado(false);
                        dispo = embarques [i];
                        flag = 1;
                    }
                }
            }
            asig.first = act;
            asig.second = dispo;
            agregarHist(asig);
        }
    }
}*/