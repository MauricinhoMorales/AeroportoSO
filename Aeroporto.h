//
// Created by Mauricio on 27-12-2018.
//

#ifndef UNTITLED1_AEROPORTO_H
#define UNTITLED1_AEROPORTO_H

#include "Terminal.h"
#include "Aerolinea.h"
#include "Registro.h"
#include <list>
#include <iostream>
#include <thread>
#include <string.h>


long int const segundo=320000000;

using namespace std;

class Aeroporto {
public:
    Aeroporto(string nombre,int numeroPistas,int hora,int day, int month, int year){
        this->nombre=nombre;
        this->horaActual= new Hora(hora);
        this->fecha= new Fecha(day,month,year);
        this->pista=numeroPistas;
        this->tiempOperante=0;
        this->vuelosAtendidos=0;
    }
private:
    string nombre;
    Hora* horaActual;
    Fecha* fecha;
    int vuelosAtendidos;
    int tiempOperante;
    int pista;
    list<Terminal*> terminales;
    list<Aerolinea*> aerolineas;
    list<Vuelo*> vuelos;
    list<Vuelo*> colaVuelos;
    list<Registro*> registros;

public:
    string getNombre(){return this->nombre;}
    Fecha* getFecha(){return this->fecha;}
    Hora* getHora(){return this->horaActual;}

    void RegistrarAerolinea(Aerolinea* aerolinea);
    void RegistrarTerminal(Terminal* Terminal);
    void RegistrarVueloGeneral(Vuelo* vuelo);
    void AgregarAColaVuelos(Vuelo* vuelo);
    void SacarDeColaVuelos();

    void IniciarGestion();
    void CargarArchivo();
    void GenerarInforme();

    void ComenzarActividad();
    void InterrumpirActividad();
    void RetomarActividad();
    void CierreActividad();
    void ActualizarVuelosAtendidos();
    void ActualizarTiempoOperacion();
    void ActualizarAerolineas();

    int PistaDisponible();

    int VerificarEstadoVuelos();
    void ActualizarColaVuelos();
    void AddTimeEspera();
    void ImprimirInforme();
};


#endif //UNTITLED1_AEROPORTO_H
