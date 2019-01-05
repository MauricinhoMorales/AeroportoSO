//
// Created by Mauricio on 28-12-2018.
//

#include "Vuelo.h"

void Vuelo::ImprimirDatosVuelo() {
    cout << "Codigo: "<< this->codigo<<"\n";
    cout << "Origen: " << this->origen << " - Destino: " << this->destino <<"\n";
    this->horaSalida->ImprimirHora();
    this->fecha->ImprimirFecha();
    cout << "Hora Carga: ";
    this->horaCarga->ImprimirHora();
    cout <<"\n";
    cout << "Hora Despegue: ";
    this->horaDespegue->ImprimirHora();
    cout <<"\n";
    cout << "Hora Vuelo Finalizado: ";
    this->horaVuelo->ImprimirHora();
    cout <<"\n";
    cout << "Hora Aterrizaje: ";
    this->horaAterrizaje->ImprimirHora();
    cout <<"\n";
    cout << "Hora Descarga: ";
    this->horaDescarga->ImprimirHora();
    cout <<"\n";
    cout << "Hora Finalizar: ";
    this->horaFinalizar->ImprimirHora();
    cout <<"\n\n";
    cout << "Disponibiliad de pista: " <<this->disponbilidadPista << "\n";
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
void Vuelo::InicioVuelo(){
    cout<< "El Vuelo " << this->codigo << " esta listo para Cargar desde el Aeropuerto de "<< this->origen << "\n";
}

void Vuelo::AterrizajeRealizado() {
    cout<< "El Vuelo " << this->codigo << " ha Aterrizado en el Aeropuerto de "<< this->destino << "\n";
    this->NextEtapa();
}

void Vuelo::CargaRealizada() {
    cout<< "El Vuelo " << this->codigo << " ha Cargado en el Aeropuerto de "<< this->origen <<"\n";
    this->NextEtapa();
}

void Vuelo::DespegueRealizado() {
    cout<< "El Vuelo " << this->codigo << " ha Despegado del Aeropuerto de "<< this->origen << "\n";
    this->NextEtapa();
}

void Vuelo::VueloRealizado() {
    cout<< "El Vuelo " << this->codigo << " ha terminado su tiempo de Vuelo\n";
    this->NextEtapa();
}

void Vuelo::DescargaRealizada() {
    cout<< "El Vuelo " << this->codigo << " ha Descargado en el Aeropuerto de "<< this->destino <<"\n";
    this->NextEtapa();
}

void Vuelo::FinVuelo(){
    cout<< "El Vuelo " << this->codigo << " se ha reabastecido en el Aeropuerto de "<< this->destino <<"\n";
    this->NextEtapa();
}

int Vuelo::getEtapa() {
    return etapa;
}

void Vuelo::NextEtapa() {
    //this->etapa--;
}

Hora *Vuelo::getHoraSalida(){
    return horaSalida;
}

Avion *Vuelo::getAvion() {
    return this->avion;
}

int Vuelo::getTiempoVuelo() {
    return this->tiempoVuelo;
}

Hora *Vuelo::getHoraCarga() {
    return horaCarga;
}

Hora *Vuelo::getHoraDespegue() {
    return horaDespegue;
}

Hora *Vuelo::getHoraVuelo(){
    return horaVuelo;
}

Hora *Vuelo::getHoraAterrizaje() {
    return horaAterrizaje;
}

Hora *Vuelo::getHoraDescarga() {
    return horaDescarga;
}

Hora *Vuelo::getHoraFinalizar() {
    return horaFinalizar;
}

void Vuelo::ChangeDisponibilidadPista() {
    this->disponbilidadPista=!this->disponbilidadPista;
}

int Vuelo::getPrioridad(){
    return prioridad;
}

bool Vuelo::isDisponbilidadPista(){
    return disponbilidadPista;
}

void Vuelo::AddTiempoEspera() {
    this->tiempoEspera++;
    if(this->etapa==5) {
        this->horaDespegue->AddTime();
        this->horaVuelo->AddTime();
    }
    this->horaAterrizaje->AddTime();
    this->horaDescarga->AddTime();
    this->horaFinalizar->AddTime();
}


