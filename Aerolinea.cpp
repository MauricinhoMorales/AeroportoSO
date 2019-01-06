//
// Created by Mauricio on 28-12-2018.
//

#include "Aerolinea.h"
#include <string.h>

void Aerolinea::ImprimirVuelos() {
    cout << "AEROLINEA: " << this->nombre << "\n\n";
    cout << "***** VUELOS *****\n\n";
    for(list<Vuelo*>::iterator it=this->vuelos.begin();it!=this->vuelos.end();it++)
        (*it)->ImprimirDatosVuelo();
}

void Aerolinea::RegistrarVuelo(Vuelo* vuelo) {
    list<Vuelo*>::iterator it;
    for(it=this->vuelos.begin();(it!=this->vuelos.end()) && (vuelo->getHoraSalida()->getHora()>(*it)->getHoraSalida()->getHora());it++);
    this->vuelos.insert(it,vuelo);
}