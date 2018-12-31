//
// Created by Mauricio on 30-12-2018.
//
#include "Cronometro.h"

void Cronometro::Iniciar() {
    this->t0=clock();
}

void Cronometro::Detener() {
    this->t1 = clock();
    this->tiempo = ((double(t1 - t0)) / CLOCKS_PER_SEC);
}
void Cronometro::Reiniciar(){
    this->Iniciar();
}

int Cronometro::Chequear() {
    this->t1=clock();
    if (((double(t1-t0))/CLOCKS_PER_SEC)>this->tiempo)
        return 1;
    else
        return 0;
}
double Cronometro::getTime() {
    return this->tiempo;
}