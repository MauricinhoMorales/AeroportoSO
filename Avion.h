//
// Created by Mauricio on 28-12-2018.
//

#ifndef UNTITLED1_AVION_H
#define UNTITLED1_AVION_H
#include <iostream>
#include<math.h>
#include <string.h>
#include<fstream>

using namespace std;

class Avion {
public:
    Avion(string codigo,float velocidad,int capacidad,int tipo){
      this->codigo=codigo;
      this->capacidad=capacidad;
      this->tiempoCargaDescarga=this->CalcularTiempoCargaDescarga();
      this->tiempoReabastecimiento=this->CalcularTiempoReabastecimiento();
      this->tiempoDespegueAterrizaje=this->CalcularTiempoDespegueAterrizaje();
      this->velocidadPromedio=velocidad;
      this->tipo=tipo;
    }
private:
    string codigo;
    int tiempoReabastecimiento;
    int tiempoCargaDescarga;
    int tiempoDespegueAterrizaje;
    float velocidadPromedio;
    int capacidad;
    int tipo;//0 para avion comercial y 1 para avion de carga

public:
    int getTiempoCargaDescarga();
    int getTiempoReabastecimiento();
    int getTiempoDespegueAterrizaje();
    int getTipo();

    int CalcularTiempoCargaDescarga();
    int CalcularTiempoReabastecimiento();
    int CalcularTiempoDespegueAterrizaje();

    void ImprimirDatosAvion();
    void ImprimirDatosAvionArchivo();
};



#endif //UNTITLED1_AVION_H
