//
// Created by Mauricio on 28-12-2018.
//

#ifndef UNTITLED1_VUELO_H
#define UNTITLED1_VUELO_H

#include "Avion.h"
#include <iostream>
#include <string.h>
#include "Fecha.h"
#include "Hora.h"
using namespace std;

class Vuelo {
public:
    Vuelo(string codigo,string origen,string destino,int tiempoVuelo,int horaSalida,int day, int month, int year,int prioridad,Avion* avion){
        this->codigo=codigo;
        this->origen=origen;
        this->destino=destino;
        this->horaSalida=new Hora(horaSalida);
        this->fecha=new Fecha(day,month,year);
        this->tiempoEspera=0;
        this->tiempoVuelo=tiempoVuelo;
        this->prioridad=prioridad;
        this->etapa=7;
        this->avion=avion;
        this->horaCarga=new Hora(this->horaSalida->getHora());
        this->horaCarga->Sum(this->getAvion()->getTiempoCargaDescarga());
        this->horaDespegue=new Hora(this->horaCarga->getHora());
        this->horaDespegue->Sum(this->getAvion()->getTiempoDespegueAterrizaje());
        this->horaVuelo=new Hora(this->horaDespegue->getHora());
        this->horaVuelo->Sum(this->tiempoVuelo);
        this->horaAterrizaje=new Hora(this->horaVuelo->getHora());
        this->horaAterrizaje->Sum(this->getAvion()->getTiempoDespegueAterrizaje());
        this->horaDescarga=new Hora(this->horaAterrizaje->getHora());
        this->horaDescarga->Sum(this->getAvion()->getTiempoCargaDescarga());
        this->horaFinalizar=new Hora(this->horaDescarga->getHora());
        this->horaFinalizar->Sum(this->getAvion()->getTiempoReabastecimiento());
        this->disponbilidadPista=false;
    }

private:
    string codigo;
    string origen;
    string destino;
    Fecha* fecha;
    Hora* horaSalida;
    Hora* horaCarga;
    Hora* horaDespegue;
    Hora* horaVuelo;
    Hora* horaAterrizaje;
    Hora* horaDescarga;
    Hora* horaFinalizar;
    int prioridad;
    bool disponbilidadPista;
    int tiempoVuelo;
    int tiempoEspera;
    int etapa;
    Avion* avion;
public:
    string getDestino(){return this->destino;}
    string getOrigen(){return origen;};
    Hora *getHoraSalida();
    Hora *getHoraCarga();
    Hora *getHoraDespegue();
    Hora *getHoraVuelo();
    Hora *getHoraAterrizaje();
    Hora *getHoraDescarga();
    Hora *getHoraFinalizar();
    int getPrioridad();
    Avion *getAvion();
    int getEtapa();
    int getTiempoVuelo();
    void setTiempoEspera(int tiempo){this->tiempoEspera=tiempo;}
    int getTiempoEspera(){return this->tiempoEspera;}
    bool isDisponbilidadPista();
    string getCodigo();

    void ChangeDisponibilidadPista();
    void NextEtapa();
    void InicioVuelo();
    void CargaRealizada();
    void DespegueRealizado();
    void VueloRealizado();
    void AterrizajeRealizado();
    void DescargaRealizada();
    void FinVuelo();
    void AddTiempoEspera();

    void ImprimirDatosVuelo();
};

#endif //UNTITLED1_VUELO_H
