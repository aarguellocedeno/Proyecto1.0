#include<iostream>
#include <string>
#include<vector>
#include "Puerta.h"
#include <cstdlib>
#include <ctime>
#include <deque>
#include <stdexcept>
#include <utility>
using namespace std;


Puerta::Puerta(){
    int num = rand() % 65 + 1;
    this->numID = num;
    int al = (rand() % 15 + 0) - '0';
    this->ubi = "a";  //al + "A";
    this -> dispo = true;
    this ->horaE= 24- (rand() % 15 + 0);
}

bool Puerta::verEstado(){
    bool ans = dispo;
    return ans;
}
void Puerta::cambiarEstado(bool n){
    dispo = n;
}
