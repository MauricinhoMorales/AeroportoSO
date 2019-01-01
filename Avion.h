//
// Created by Mauricio on 28-12-2018.
//

#ifndef UNTITLED1_AVION_H
#define UNTITLED1_AVION_H
#include <iostream>
#include<math.h>
using namespace std;

class Avion {
public:
    Avion(char* codigo,float velocidad,int capacidad,int tipo){
      this->codigo=codigo;
      this->tiempoCarga=this->CalcularTiempoCargaDescarga();
      this->tiempoDescarga=this->CalcularTiempoCargaDescarga();
      this->tiempoRestablecimiento=this->CalcularTiempoReabastecimiento();
      this->velocidadPromedio=velocidad;
      this->capacidad=capacidad;
      this->tipo=tipo;
    }
private:
    char* codigo;
    int tiempoRestablecimiento;
    int tiempoCarga;
    int tiempoDescarga;
    float velocidadPromedio;
    int capacidad;
    int tipo;//0 para avion comercial y 1 para avion de carga

public:
    int CalcularTiempoCargaDescarga();
    int CalcularTiempoReabastecimiento();

    void ImprimirDatosAvion();
};



#endif //UNTITLED1_AVION_H
