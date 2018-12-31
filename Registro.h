//
// Created by Mauricio on 31-12-2018.
//

#ifndef UNTITLED1_REGISTRO_H
#define UNTITLED1_REGISTRO_H

#include <iostream>
using namespace std;

class Registro {
public:
    Registro(char* lugar, int distancia){
        this->distancia=distancia;
        this->lugar=lugar;
        this->next=NULL;

    }
private:
    char* lugar;
    int distancia;
    Registro *next;
public:
    int CalcularTiempo(double velocidad);
};


#endif //UNTITLED1_REGISTRO_H
