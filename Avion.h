//
// Created by Mauricio on 28-12-2018.
//

#ifndef UNTITLED1_AVION_H
#define UNTITLED1_AVION_H
#include <iostream>
using namespace std;

class Avion {
public:
    Avion(char* codigo,float velocidad,int capacidad,int tipo){
      this->codigo=codigo;
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
    void RealizarCarga();
    void RealizarDescarga();
    void ReaizarReabastecimiento();
    int CalcularTiempoCarga();
    int CalcularTiempoDescarga();
    int CalcularTiempoReabastecimiento();
    void ImprimirDatosAvion();
};



#endif //UNTITLED1_AVION_H
