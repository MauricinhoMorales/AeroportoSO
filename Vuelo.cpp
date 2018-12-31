//
// Created by Mauricio on 28-12-2018.
//

#include "Vuelo.h"

void Vuelo::ImprimirDatosVuelo() {
    cout << "Codigo: "<< this->codigo<<"\n";
    cout << "Origen: " << this->origen << " - Destino: " << this->destino <<"\n";
    this->horaSalida->ImprimirHora();
    this->fecha->ImprimirFecha();
    if(this->etapa==2)
        cout << "VUELO EN ESPERA\n";
    else
        if (this->etapa==1)
            cout << "VUELO EN PROCESO\n";
        else
            if (this->etapa==0){
                cout << "VUELO FINALIZADO\n";
                cout << "Tiempo de Vuelo: " << this->tiempoAtencion << "\n";
                cout << "Tiempo de Espera: " << this->tiempoEspera << "\n";
            }
    cout << "Avion:\n";
    (this->avion)->ImprimirDatosAvion();
}

int Vuelo::getEtapa() {
    return etapa;
}

void Vuelo::NextEtapa() {
    this->etapa--;
}

Hora *Vuelo::getHoraSalida(){
    return horaSalida;
}
