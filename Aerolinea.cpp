//
// Created by Mauricio on 28-12-2018.
//

#include "Aerolinea.h"

void Aerolinea::ImprimirVuelos() {\
    cout << "Aerolinea: " << this->nombre << "\n\n";
    cout << "VUELOS\n\n";
    for(Vuelo* i=this->vuelos;i!=NULL;i=i->getNext())
        i->ImprimirDatosVuelo();
    cout << "\n";
}

void Aerolinea::RegistrarVuelo(Vuelo* vuelo) {
    Vuelo* i;
    if (this->vuelos==NULL) {
        this->vuelos = vuelo;
        return;
    }
    for(i=this->vuelos;i!=NULL;i=i->getNext())
        if(i->getNext()==NULL){
            i->setNext(vuelo);
            return;
        }
}