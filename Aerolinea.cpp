//
// Created by Mauricio on 28-12-2018.
//

#include "Aerolinea.h"
#include <string.h>

void Aerolinea::ImprimirVuelos() {\
    cout << "Aerolinea: " << this->nombre << "\n\n";
    cout << "VUELOS\n\n";
    for(Vuelo* i=this->vuelos;i!=NULL;i=i->getNext())
        i->ImprimirDatosVuelo();
}

void Aerolinea::RegistrarVuelo(Vuelo* vuelo) {
    Vuelo *i,*prev;
    if (this->vuelos==NULL) {
        this->vuelos = vuelo;
        return;
    }
    for(i=this->vuelos,prev=NULL;(i!=NULL) && (vuelo->getHoraSalida()->getHora()>i->getHoraSalida()->getHora());prev=i,i=i->getNext());
        if(i==NULL){
            prev->setNext(vuelo);
            return;
        }
        if(prev==NULL){
            this->vuelos=vuelo;
            vuelo->setNext(i);
            return;
        }
        vuelo->setNext(prev->getNext());
        prev->setNext(vuelo);
        return;
}

int Aerolinea::EstadoVuelos() {
    int cont=0;
    for(Vuelo*i=this->vuelos;i!=NULL;i=i->getNext()){
        cont+=i->getEtapa();
    }
    return cont;
}