//
// Created by Mauricio on 27-12-2018.
//

#ifndef UNTITLED1_AEROPORTO_H
#define UNTITLED1_AEROPORTO_H

#include "Terminal.h"
#include "Aerolinea.h"

class Aeroporto {
public:
    Aeroporto(char*nombre,int numeroPistas){
        this->nombre=nombre;
        this->pistasDisponibles=numeroPistas;
        this->terminales=NULL;
        this->aerolineas=NULL;
    }
private:
    char* nombre;
    int pistasDisponibles;
    int operante;
    Terminal* terminales;
    Aerolinea* aerolineas;
public:
    void RegistrarAerolinea(Aerolinea* aerolinea);
    void RegistrarTerminal(Terminal* Terminal);
    void IniciarActividad();
    void CargarActividad();
    void InterrumpirActividad();
    void GenerarInforme();
    void CierreActividad();
    void OcuparPista();
    void DesocuparPista();
    void ImprimirInforme();
};


#endif //UNTITLED1_AEROPORTO_H
