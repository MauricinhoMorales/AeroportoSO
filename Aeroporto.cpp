//
// Created by Mauricio on 27-12-2018.
//

#include "Aeroporto.h"

void Aeroporto::ComenzarActividad(){  // como se ordena el beta
    this->CargarArchivo();
    this->IniciarGestion();
}

void Aeroporto::InterrumpirActividad() {   //OPCION DE MENU PARA PARAR ACTIVIDAD
    this->GenerarInforme();
    this->ImprimirInforme();
}

void Aeroporto::RetomarActividad() { // OPCION DE MENU PARA RETOMAR ACTIVIDAD
    this->ComenzarActividad();
}

void Aeroporto::CierreActividad() {    // OPCION DEL MENU CERRAR
    exit(1);
}

void Aeroporto::IniciarGestion() {    //REALIZAR LA GESTION

}

void Aeroporto::CargarArchivo() {    //CARGAR ESTRUCTURAS LEER DEL ARCHIVO

}

void Aeroporto::GenerarInforme() {      //ESCRIBIR EN EL ARCHIVO

}

void Aeroporto::Reloj() {
    while(this->VerificarEstadoVuelos()){
        for(long int i=0;i<segundo;i++);
        if(this->horaActual->AddTime())
            this->fecha->AddDay();
        this->horaActual->ImprimirHora();
        this->fecha->ImprimirFecha();
    }
}

void Aeroporto::ImprimirInforme() {
    cout << "----------AEROPUERTO---------\n";
    cout << this->nombre << "\n";
    cout << "----------AEROLINEAS---------\n";
    for(Aerolinea* i=this->aerolineas;i!=NULL;i=i->getNext())
        i->ImprimirVuelos();
    cout << "\n";
    cout << "----------TERMINALES---------\n";
    for(Terminal* i=this->terminales;i!=NULL;i=i->getNext())
        i->ImprimirDatosTerminal();
    cout << "\n";
    cout << "----------VUELOS---------\n";
    for(Vuelo* i=this->vuelos;i!=NULL;i=i->getNext())
        i->ImprimirDatosVuelo();
    cout << "\n";
}

void Aeroporto::RegistrarTerminal(Terminal* terminal) {
    Terminal* i,*prev;
    if (this->terminales==NULL) {
        this->terminales = terminal;
        return;
    }
    for(i=this->terminales,prev=NULL;(i!=NULL) && (terminal->getTipo()>i->getTipo());prev=i,i=i->getNext());
        if(i==NULL){
            prev->setNext(terminal);
            return;
        }
        if(prev==NULL){
            this->terminales=terminal;
            terminal->setNext(i);
            return;
        }
        terminal->setNext(i);
        prev->setNext(terminal);
        return;
}

void Aeroporto::RegistrarAerolinea(Aerolinea* aerolinea) {
    Aerolinea* i,*prev;

    if (this->aerolineas==NULL) {
        this->aerolineas = aerolinea;
        return;
    }
    for(i=this->aerolineas,prev=NULL;(i!=NULL) && (strcmp(aerolinea->getNombre(),i->getNombre())>0);prev=i,i=i->getNext());
    if(i==NULL){
        prev->setNext(aerolinea);
        return;
    }
    if(prev==NULL){
        this->aerolineas=aerolinea;
        aerolinea->setNext(i);
        return;
    }
    aerolinea->setNext(i);
    prev->setNext(aerolinea);
    return;
}

int Aeroporto::VerificarEstadoVuelos() {
    int conta=0;
    Aerolinea *i;
    for(i=this->aerolineas;i!=NULL;i=i->getNext()){
        conta+=i->EstadoVuelos();
    }
    return conta;
}
