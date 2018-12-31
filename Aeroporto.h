//
// Created by Mauricio on 27-12-2018.
//

#ifndef UNTITLED1_AEROPORTO_H
#define UNTITLED1_AEROPORTO_H

#include "Terminal.h"
#include "Aerolinea.h"
#include <iostream>
#include <thread>

long int const segundo=320000000;

using namespace std;

class Aeroporto {
public:
    Aeroporto(char*nombre,int numeroPistas,int hora,int day, int month, int year){
        this->nombre=nombre;
        this->terminales=NULL;
        this->aerolineas=NULL;
        this->vuelos=NULL;
        this->horaActual= new Hora(hora);
        this->fecha= new Fecha(day,month,year);
        this->t1=thread(&Aeroporto::Reloj,this);
    }
private:
    Hora* horaActual;
    char* nombre;
    //mutex pista[2];
    int TiempOperante;
    Terminal* terminales;
    Aerolinea* aerolineas;
    Vuelo* vuelos;
    Fecha* fecha;
    thread t1;
public:
    char* getNombre(){return this->nombre;}
    Fecha* getFecha(){return this->fecha;}

    void RegistrarAerolinea(Aerolinea* aerolinea);
    void RegistrarTerminal(Terminal* Terminal);

    void IniciarGestion();
    void CargarArchivo();
    void GenerarInforme();

    void ComenzarActividad();
    void InterrumpirActividad();
    void RetomarActividad();
    void CierreActividad();

    void OcuparPista(int num);
    void DesocuparPista(int num);

    void Reloj();
    void AttachedThread();
    int VerificarEstadoVuelos();

    void ImprimirInforme();
};


#endif //UNTITLED1_AEROPORTO_H
