//
// Created by Mauricio on 28-12-2018.
//

#ifndef UNTITLED1_VUELO_H
#define UNTITLED1_VUELO_H

#include "Avion.h"
#include <iostream>
#include "Fecha.h"
using namespace std;

class Vuelo {
public:
    Vuelo(char* codigo,char*origen,char* destino,int horaSalida,int day, int month, int year,int prioridad,Avion* avion){
        this->codigo=codigo;
        this->origen=origen;
        this->destino=destino;
        this->horaSalida=horaSalida;
        this->fecha=new Fecha(day,month,year);
        this->prioridad=prioridad;
        this->etapa=0;
        this->avion=avion;
        this->next=NULL;
    }
private:
    char* codigo;
    char* origen;
    char* destino;
    Fecha* fecha;
    int horaSalida;
    int prioridad;
    float tiempoAtencion;
    float tiempoEspera;
    int etapa; //2 para terminado, 1 para vuelo, 0 para en espera
    Avion* avion;
    Vuelo* next;
public:
    Vuelo* getNext(){return this->next;}
    int getHora(){return this->horaSalida;}
    void setNext(Vuelo* vuelo){this->next=vuelo;}
    void RealizarCarga();
    void RealizarDespegue();
    void RealizarVuelo();
    void RealizarAterrizaje();
    void RealizarDescarga();
    void ImprimirDatosVuelo();
};

#endif //UNTITLED1_VUELO_H
