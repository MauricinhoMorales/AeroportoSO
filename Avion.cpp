//
// Created by Mauricio on 28-12-2018.
//

#include "Avion.h"

void Avion::ImprimirDatosAvion() {
    if(this->tipo==0) {
        cout << " Avion Comercial\n";
        cout << " Codigo: " << this->codigo << "\n";
        cout << " Capacidad: " << this->capacidad << " pasajeros\n\n";
    }else{
        cout << " Avion de Carga\n";
        cout << " Codigo: " << this->codigo << "\n";
    }
}