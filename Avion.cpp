//
// Created by Mauricio on 28-12-2018.
//

#include "Avion.h"

void Avion::ImprimirDatosAvion() {
    if(this->tipo==0) {
        cout << "   Avion Comercial\n";
        cout << "   Codigo: " << this->codigo << "\n";
        cout << "   Capacidad: " << this->capacidad << " pasajeros\n\n";
    }else{
        cout << "   Avion de Carga\n";
        cout << "   Codigo: " << this->codigo << "\n";
        cout << "   Capacidad: " << this->capacidad << " toneladas\n\n";
    }
    cout << "   Tiempo DespegueCargaDescarga: " << this->getTiempoCargaDescarga() << " minutos\n";
    cout << "   Tiempo DespegueAterrizaje: " << this->getTiempoDespegueAterrizaje() << " minutos\n";
    cout << "   Tiempo Reabastecimiento: " << this->getTiempoReabastecimiento() << " minutos\n\n";
}

int Avion::CalcularTiempoCargaDescarga() {
    return ((int)(sqrt(this->capacidad)*2));
}

int Avion::CalcularTiempoReabastecimiento() {
    return ((int)(sqrt(this->capacidad)));
}

int Avion::CalcularTiempoDespegueAterrizaje(){
    return ((int)(sqrt(sqrt(this->capacidad))));
}

int Avion::getTiempoCargaDescarga(){
    return tiempoCargaDescarga;
}
int Avion::getTiempoReabastecimiento(){
    return tiempoReabastecimiento;
}

int Avion::getTiempoDespegueAterrizaje(){
    return this->tiempoDespegueAterrizaje;
}

