#include "torre.h"
#include "Puerta.h"
#include "Aeronave.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <utility>
using namespace std;


Torre::Torre(string name, string loc){
    this-> nombre = name;
    this-> localizacion = loc;
    for(int i = 0; i < 10; i++){
        this -> aeronaves.push_back(Aeronave());
    }
    this -> embarques;
    /*for(int i = 0; i < 10; i++){
        embarques.push_back(Puerta());*/


    this->hist;
}

void Torre::generarPuertas(){
    for(int i = 0; i < 10; i++){
        Puerta p;
        embarques.push_back(p);
    }
}

void Torre::agregarHist(pair <Aeronave,Puerta> p){
    hist.push_back(p);
}
/*
void Torre::ubicarPuerta(){
    pair <Aeronave *,Puerta *> asig;
    int flag = 0;

    for(int i = 0; i < aeronaves.size(); i++){
        Aeronave act;
        Puerta dispo;

        if(aeronaves[i].reportarUbi() == 1){
            act = aeronaves[i];
            while(flag == 0){
                for(int i = 0; i < embarques.size(); i++){
                    if(embarques[i].verEstado() == true){
                        embarques[i].cambiarEstado(false);
                        dispo = embarques[i];
                        flag = 1;
                    }
                }
            }
            asig.first = &act;
            asig.second= &dispo;
            //agregarHist(asig);
            hist.push_back(make_pair(act,dispo));
        }

        else if(aeronaves[i].reportarUbi() == 2){
            for(int j = 0; j< hist.size(); j++){


                if(hist[j].first == aeronaves[i]){
                    hist[j].second.cambiarEstado(true);

                }
            }
        }
    }
}
*/
void Torre::cNombre(string n){
    nombre = n;
}
void Torre::cUbi(string n){
    localizacion = n;
}
/*
Puerta Torre::buscarPuerta(Puerta p){
    Puerta ans,aux;
    for(int i = 0; i<0;i++){
        aux= embarques[i];
        if(aux == p){
            ans = embarques[i];
        }
    }
    return ans;
}
 */