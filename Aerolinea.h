//
// Created by Mauricio on 28-12-2018.
//

#ifndef UNTITLED1_AEROLINEA_H
#define UNTITLED1_AEROLINEA_H

#include "Vuelo.h"
#include <iostream>
#include <string.h>
#include <list>
using namespace std;

class Aerolinea {
public:
    Aerolinea(string nombre){
         this->nombre=nombre;
    }
private:
    string nombre;
    list<Vuelo*> vuelos;

public:
    string getNombre(){return this->nombre;}
    list<Vuelo*> getVuelos(){return this->vuelos;}

    void RegistrarVuelo(Vuelo* vuelo);
    int EstadoVuelos();
    int VuelosAtendidos();

    void ImprimirVuelos();
};


#endif //UNTITLED1_AEROLINEA_H
