//
// Created by Mauricio on 31-12-2018.
//

#include "Registro.h"

int Registro::CalcularTiempo(double velocidad) {
    return ((int)(this->distancia/velocidad));
}