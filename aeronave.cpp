#include "aeronave.h"
#include <string.h>
#include <stdio.h>
#include <deque>
#include <stdexcept>
using namespace std;



Aeronave::Aeronave(){
    velocidad=0;
    cantPas=0;
    autonomia=0;
    yearFab=0;
    estado=0;
    marca="";
    modelo="";
    ubi= rand() % 5;
}
int Aeronave::reportarUbi(){
    int ans = ubi;
    return ans;
}
Avion::Avion() {}

Avion::Avion(int num,string uno){
    num=0;
    this->altMax=num;
    this->cantMotor=num;
    this->categoria=uno;
}

void Avion::verCat() {
    cout<<"Este avion es de "<<categoria<<endl;
}

Helicoptero::Helicoptero(){
    this->rotores=0;
    this->capEle=0;
    this->uso="";
}

Jet::Jet(){
    propietario="";
    servicios = "\n1.Mayordomo a bordo\n2.Spa a bordo\n3.Tripulación profesional\n4.Wi-Fi a bordo\n5.Entretenimiento a bordo\n6.Bar y bebidas\n7.Catering gourmet\n8.Conserje personal\n\n";
}

void Jet::verServicios(){
    cout<<"Los servicios que proporciona el Jet son: \n"<<servicios;
}

AeroFactory::AeroFactory(){}

Aeronave::~Aeronave(){}
