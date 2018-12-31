//
// Created by Mauricio on 28-12-2018.
//

#ifndef UNTITLED1_VUELO_H
#define UNTITLED1_VUELO_H

#include "Avion.h"
#include <iostream>
#include "Fecha.h"
#include "Hora.h"
using namespace std;

class Vuelo {
public:
    Vuelo(char* codigo,char*origen,char* destino,int horaSalida,int day, int month, int year,int prioridad,Avion* avion){
        this->codigo=codigo;
        this->origen=origen;
        this->destino=destino;
        this->horaSalida=new Hora(horaSalida);
        this->fecha=new Fecha(day,month,year);
        this->prioridad=prioridad;
        this->etapa=2;
        this->avion=avion;
        this->next=NULL;
    }
private:
    char* codigo;
    char* origen;
    char* destino;
    Fecha* fecha;
    Hora* horaSalida;
    int prioridad;
    float tiempoVuelo;
    float tiempoAtencion;
    float tiempoEspera;
    int etapa; //2 para en espera, 1 para vuelo, 0 para terminado
    Avion* avion;
    Vuelo* next;
public:
    Vuelo* getNext(){return this->next;}
    char* getDestino(){return this->destino;}
    char *getOrigen(){return origen;};
    Hora *getHoraSalida();
    int getEtapa();

    void setNext(Vuelo* vuelo){this->next=vuelo;}
    void NextEtapa();

    void RealizarCarga();
    void RealizarDespegue();
    void RealizarVuelo();
    void RealizarAterrizaje();
    void RealizarDescarga();

    void ImprimirDatosVuelo();
};

#endif //UNTITLED1_VUELO_H
