//
// Created by Mauricio on 27-12-2018.
//

#include "Aeroporto.h"

void Aeroporto::CargarActividad() {

}

void Aeroporto::CierreActividad() {

}
void Aeroporto::DesocuparPista() {
    (this->pistasDisponibles)++;
}
void Aeroporto::OcuparPista() {
    (this->pistasDisponibles)--;
}

void Aeroporto::GenerarInforme() {

}

void Aeroporto::IniciarActividad() {

}
void Aeroporto::InterrumpirActividad() {

}
void Aeroporto::ImprimirInforme() {
    cout << "Aeropuerto: " << this->nombre << "\n\n";
    cout << "----------AEROLINEAS---------\n";
    for(Aerolinea* i=this->aerolineas;i!=NULL;i=i->getNext())
        i->ImprimirVuelos();
    cout << "\n";
    cout << "----------TERMINALES---------\n";
    for(Terminal* i=this->terminales;i!=NULL;i=i->getNext())
        i->ImprimirDatosTerminal();
    cout << "\n";
}

void Aeroporto::RegistrarTerminal(Terminal* terminal) {
    Terminal* i;
    if (this->terminales==NULL) {
        this->terminales = terminal;
        return;
    }
    for(i=this->terminales;i!=NULL;i=i->getNext())
        if(i->getNext()==NULL){
            i->setNext(terminal);
            return;
        }
}

void Aeroporto::RegistrarAerolinea(Aerolinea* aerolinea) {
    Aerolinea* i;
    if (this->aerolineas==NULL) {
        this->aerolineas = aerolinea;
        return;
    }
    for(i=this->aerolineas;i!=NULL;i=i->getNext())
        if(i->getNext()==NULL){
            i->setNext(aerolinea);
            return;
        }
}