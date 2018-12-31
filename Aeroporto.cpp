//
// Created by Mauricio on 27-12-2018.
//

#include "Aeroporto.h"

void Aeroporto::CargarActividad() {
    //Cargar en el archivo
}

void Aeroporto::CierreActividad() {
    //Final
}
void *Aeroporto::Reloj() {
    int horaActual=this->horaActual;
    while(true){
        for(long int i=0;i<segundo;i++);
        horaActual++;
        if(horaActual%100==60){
            horaActual+=40;
            if (horaActual==2400){
                horaActual=0;
                this->fecha->AddDay();
            }
        }
        this->horaActual=horaActual;
        cout << "Hora Actual: ";
        if (int(this->horaActual/ 100)<10)
            cout <<"0";
        cout << int(this->horaActual / 100) << ":";
        if (this->horaActual%100<10)
            cout << "0";
        cout << this->horaActual%100 << "\n";
    }
    return NULL;
}

void Aeroporto::GenerarInforme() {
    //Escribir en el archivo
}

void Aeroporto::IniciarActividad() {


}
void Aeroporto::InterrumpirActividad() {
    this->GenerarInforme();
    this->ImprimirInforme();
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

void Aeroporto::RegistrarVuelo(Vuelo* vuelo) {
    Vuelo *k,*previ;
    if (this->vuelos==NULL) {
        this->vuelos = vuelo;
        return;
    }
    for(k=this->vuelos,previ=NULL;(k!=NULL) && (vuelo->getHora()>k->getHora());previ=k,k=k->getNext());
    if(k==NULL){
        previ->setNext(vuelo);
        return;
    }
    if(previ==NULL){
        this->vuelos=vuelo;
        vuelo->setNext(k);
        return;
    }
    vuelo->setNext(k);
    previ->setNext(vuelo);
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
