//
// Created by Mauricio on 28-12-2018.
//

#ifndef UNTITLED1_AEROLINEA_H
#define UNTITLED1_AEROLINEA_H

#include "Vuelo.h"

class Aerolinea {
public:
    Aerolinea(char* nombre){
         this->nombre=nombre;
         this->vuelos=NULL;
         this->next=NULL;
    }
private:
    char* nombre;
    Vuelo* vuelos;
    Aerolinea* next;
public:
    Aerolinea* getNext(){return this->next;}
    void setNext (Aerolinea* aerolinea){this->next=aerolinea;}
    void RegistrarVuelo(Vuelo* vuelo);
    void ImprimirVuelos();
};


#endif //UNTITLED1_AEROLINEA_H
