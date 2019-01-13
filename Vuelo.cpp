//
// Created by Mauricio on 28-12-2018.
//

#include "Vuelo.h"

void Vuelo::ImprimirDatosVuelo() {
    if(this->etapa==7)
        cout << "VUELO POR SALIR\n";
    else
        if (this->etapa==6)
            cout << "VUELO CARGANDO\n";
        else
            if (this->etapa==5)
                if((this->disponbilidadPista==1 && this->tipo==1) || (this->tipo==0))
                    cout << "VUELO DESPEGANDO\n";
                else
                    cout << "VUELO EN ESPERA\n";
            else
                if (this->etapa==4)
                    cout << "VUELO EN PROGRESO \n";
                else
                    if (this->etapa==3)
                        if ((this->disponbilidadPista && this->tipo==0) || (this->tipo==1))
                            cout << "VUELO ATERRIZANDO\n";
                        else
                            cout << "VUELO EN ESPERA\n";
                    else
                        if (this->etapa==2)
                            cout << "VUELO DESCARGANDO\n";
                        else
                            if (this->etapa==1)
                                cout << "VUELO REABASTECIENDOCE\n";
                            else
                                if (this->etapa==0){
                                    cout << "VUELO FINALIZADO\n";
                                    cout << "Tiempo de Vuelo: " << this->tiempoVuelo << " minutos\n";
                                    cout << "Tiempo de Uso Pista: " << this->avion->getTiempoDespegueAterrizaje() << " minutos\n";
                                    cout << "Tiempo de Espera: " << this->tiempoEspera << " minutos\n";
    }
    cout << " Codigo: "<< this->codigo<<"\n";
    cout << " Origen: " << this->origen << " - Destino: " << this->destino <<"\n";
    this->horaSalida->ImprimirHora();
    this->fecha->ImprimirFecha();
    cout << " Carga: ";
    this->horaCarga->ImprimirHora();
    cout <<" ";
    cout << "Despegue: ";
    this->horaDespegue->ImprimirHora();
    cout <<" ";
    cout << "Vuelo: ";
    this->horaVuelo->ImprimirHora();
    cout <<"\n";
    cout << " Aterrizaje: ";
    this->horaAterrizaje->ImprimirHora();
    cout <<" ";
    cout << "Descarga: ";
    this->horaDescarga->ImprimirHora();
    cout <<" ";
    cout << "Finalizado: ";
    this->horaFinalizar->ImprimirHora();
    cout <<"\n";
    cout << " Disponibiliad de pista: " <<this->disponbilidadPista << "\n";
    cout << " Avion:\n";
    (this->avion)->ImprimirDatosAvion();
}
void Vuelo::InicioVuelo(){
    cout<< "El Vuelo " << this->codigo << " esta listo para CARGAR desde el Aeropuerto de "<< this->origen << ". CARGANDO...\n";
    this->NextEtapa();
}

void Vuelo::AterrizajeRealizado() {
    cout<< "El Vuelo " << this->codigo << " ha ATERRIZADO en el Aeropuerto de "<< this->destino << ". DESCARGANDO...\n";
    this->NextEtapa();
}

void Vuelo::Despegando() {
    cout<< "El Vuelo " << this->codigo << " esta DESPEGANDO del Aeropuerto  de "<< this->origen << "\n";
}

void Vuelo::Aterrizando() {
    cout<< "El Vuelo " << this->codigo << " esta ATERRIZADO en el Aeropuerto de "<< this->destino << "\n";
}

void Vuelo::CargaRealizada() {
    if(this->tipo==0)
        cout<< "El Vuelo " << this->codigo << " ha CARGADO en el Aeropuerto de "<< this->origen <<". DESPEGANDO...\n";
    else
        cout<< "El Vuelo " << this->codigo << " ha CARGADO en el Aeropuerto de "<< this->origen <<"\n";
    this->NextEtapa();
}

void Vuelo::DespegueRealizado() {
    cout<< "El Vuelo " << this->codigo << " ha DESPEGADO del Aeropuerto de "<< this->origen << ". VOLANDO...\n";
    this->NextEtapa();
}

void Vuelo::VueloRealizado() {
    if(this->tipo==1)
        cout<< "El Vuelo " << this->codigo << " ha TERMINADO su tiempo de Vuelo. ATERRIZANDO...\n";
    else
        cout<< "El Vuelo " << this->codigo << " ha TERMINADO su tiempo de Vuelo\n";
    this->NextEtapa();
}

void Vuelo::DescargaRealizada() {
    cout<< "El Vuelo " << this->codigo << " ha DESCARGADO en el Aeropuerto de "<< this->destino <<". REABASTECIEDO LA AERONAVE...\n";
    this->NextEtapa();
}

void Vuelo::FinVuelo(){
    cout<< "El Vuelo " << this->codigo << " se ha REABASTECIDO en el Aeropuerto de "<< this->destino <<"\n";
    this->NextEtapa();
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

Avion *Vuelo::getAvion() {
    return this->avion;
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

Fecha * Vuelo::getFecha() {
    return this->fecha;
}

int Vuelo::getTipo() {
    return this->tipo;
}

