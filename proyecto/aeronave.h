#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <deque>
#include <cstdio>
#include <stdexcept>
using namespace std;

#ifndef __AERONAVE_H
#define __AERONAVE_H


class Aeronave{
        public:
        Aeronave();
        int velocidad,cantPas,autonomia,yearFab,estado,ubi;
        string marca,modelo;
        virtual void info() { };
        virtual ~Aeronave();
        int reportarUbi();
  //      virtual void generarNave(Vuelo& vu) =0;

};

class Avion : public Aeronave{
public:
    Avion();
    Avion(int num,string uno);
    int altMax, cantMotor;
    string categoria;

    void info() override{

        cout<<"\n\nLa altura Maxima de este avion es de = "<<altMax<<" pies\n"<<endl;
        cout<<"\nEste Avion cuenta con "<<cantMotor<<" motores"<<endl<<endl;
        cout<<"El avion se encuentra "<<categoria<<endl<<endl;
    }

    void verCat();
};




class Helicoptero : public Aeronave{
public:
    Helicoptero();
    int rotores,capEle; //capEle = capacidad de elevacion
    string uso;
    void info() override{
        cout<<"\n\nLa capacidad de elevacion de este helicoptero es de = "<<capEle<<" kg"<<endl;
        cout<<"\nEste helicoptero cuenta con "<<rotores<<" rotores"<<endl;
        cout<<"\nUso del helicoptero= "<<uso<<endl<<endl;
    }
};


class Jet : public Aeronave{
public:
    Jet();
    string  propietario,servicios;
    //servicios = "1.\n2.\n3.\n4.\n5.\n6.\n7.\n8.";
    deque<string> desFre;
    // void printDestinos(deque<string> &desFre);
    void info() override{
        cout<<"El propietario de este jet es = "<<propietario<<endl;
        // printDestinos(desFre);
    }
    void verServicios();
};


class AeroFactory{
public:
    AeroFactory();
    Aeronave* nave;

    Aeronave* crearNave(int cual){
        Aeronave* nave;
        if(cual == 1){
            printf("entro");
            nave = new Avion ;
            nave->info();

            printf("2");
        }else if(cual==2){
            nave = new Helicoptero;
            nave->info();
        }else if(cual == 3){
            nave = new Jet;
            nave->info();
        }else{
            printf("Opcion no disponible\n");
        }
        return nave;
    }
};



#endif
