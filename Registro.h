//
// Created by Mauricio on 31-12-2018.
//

#ifndef UNTITLED1_REGISTRO_H
#define UNTITLED1_REGISTRO_H

#include <iostream>
#include <string.h>
using namespace std;

class Registro {
public:
    Registro(string lugar, int distancia){
        this->distancia=distancia;
        this->lugar=lugar;

    }
private:
    string lugar;
    int distancia;
public:
    int CalcularTiempo(double velocidad);
};


#endif //UNTITLED1_REGISTRO_H
