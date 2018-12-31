//
// Created by Mauricio on 28-12-2018.
//

#include "Vuelo.h"

void Vuelo::ImprimirDatosVuelo() {
    cout << "Codigo: "<< this->codigo<<"\n";
    cout << "Origen: " << this->origen << " - Destino: " << this->destino <<"\n";
    cout << "Hora de Salida: ";
    if (int(this->horaSalida / 100)<10)
        cout <<"0";
    cout << int(this->horaSalida / 100) << ":";
    if (this->horaSalida%100<10)
        cout << "0";
    cout << this->horaSalida%100 << "\n";

    cout << "Fecha: "<< this->fecha->getDay() << "-" << this->fecha->getMonth() << "-"<< this->fecha->getYear() << "\n";
    if(this->etapa==0)
        cout << "VUELO EN ESPERA\n";
    else
        if (this->etapa==1)
            cout << "VUELO EN PROCESO\n";
        else
            if (this->etapa==2){
                cout << "VUELO FINALIZADO\n";
                cout << "Tiempo de Vuelo: " << this->tiempoAtencion << "\n";
                cout << "Tiempo de Espera: " << this->tiempoEspera << "\n";
            }
    cout << "Avion:\n";
    (this->avion)->ImprimirDatosAvion();
}
