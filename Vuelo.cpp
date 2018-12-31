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

void Vuelo::RealizarAterrizaje() {
    cout<< "El Vuelo " << this->codigo << " ha Aterrizado en el Aeropuerto de "<< this->destino << "\n";
}

void Vuelo::RealizarCarga() {
    cout<< "El Vuelo " << this->codigo << " ha Cargado en el Aeropuerto de "<< this->origen << "\n";
}

void Vuelo::RealizarDespegue() {
    cout<< "El Vuelo " << this->codigo << " ha Despegado del Aeropuerto de "<< this->origen << "\n";
}

void Vuelo::RealizarVuelo() {
    cout<< "El Vuelo " << this->codigo << " ha terminado su tiempo de Vuelo\n";
}

void Vuelo::RealizarDescarga() {
    cout<< "El Vuelo " << this->codigo << " ha Descargado en el Aeropuerto de "<< this->destino << "\n";
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
