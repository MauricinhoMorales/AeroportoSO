//
// Created by Mauricio on 27-12-2018.
//

#include "Aeroporto.h"

void Aeroporto::ComenzarActividad(){  // como se ordena el beta
    this->CargarArchivo();
    this->IniciarGestion();
}

void Aeroporto::InterrumpirActividad() {   //OPCION DE MENU PARA PARAR ACTIVIDAD
    this->GenerarInforme();
    this->ImprimirInforme();
}

void Aeroporto::RetomarActividad() { // OPCION DE MENU PARA RETOMAR ACTIVIDAD
    this->ComenzarActividad();
}

void Aeroporto::CierreActividad() {    // OPCION DEL MENU CERRAR
    exit(1);
}

void Aeroporto::IniciarGestion() {    //REALIZAR LA GESTION (--------------)
    while(this->VerificarEstadoVuelos()){
        for (long int i = 0; i < segundo; i++);
        cout << "################################---HORA Y FECHA ACTUALES---#########################\n";
        if (this->horaActual->AddTime())
            this->fecha->AddDay();
        this->horaActual->ImprimirHora();
        this->fecha->ImprimirFecha();
        cout << "-----------------------------------EVENTOS------------------------------------------\n";
        for(list<Vuelo*>::iterator it=this->vuelos.begin();it!=this->vuelos.end();it++){
            int tipo = (this->nombre==(*it)->getOrigen());
            if((*it)->getHoraSalida()->getHora()==this->horaActual->getHora())
                (*it)->InicioVuelo();
            else
                if((*it)->getHoraCarga()->getHora()==this->horaActual->getHora()) {
                    (*it)->CargaRealizada();
                    if(tipo==1) {
                        this->AgregarAColaVuelos(*it);
                    }
                }
                else
                    if((*it)->getHoraDespegue()->getHora()==this->horaActual->getHora()) {
                        (*it)->DespegueRealizado();
                        if(tipo==1) {
                            this->SacarDeColaVuelos();
                        }
                    }
                    else
                        if((*it)->getHoraVuelo()->getHora()==this->horaActual->getHora()) {
                            (*it)->VueloRealizado();
                            if (tipo==0) {
                                this->AgregarAColaVuelos(*it);
                            }
                        }
                        else
                            if((*it)->getHoraAterrizaje()->getHora()==this->horaActual->getHora()) {
                                (*it)->AterrizajeRealizado();
                                if(tipo==0) {
                                    this->SacarDeColaVuelos();
                                }
                            }
                            else
                                if((*it)->getHoraDescarga()->getHora()==this->horaActual->getHora())
                                    (*it)->DescargaRealizada();
                                else
                                    if((*it)->getHoraFinalizar()->getHora()==this->horaActual->getHora())
                                        (*it)->FinVuelo();
        }
        this->ActualizarColaVuelos();
        this->AddTimeEspera();
        this->ActualizarVuelosAtendidos();
        this->ActualizarTiempoOperacion();
        this->ImprimirInforme();
    }
}

void Aeroporto::CargarArchivo() {    //CARGAR ESTRUCTURAS LEER DEL ARCHIVO

}

void Aeroporto::GenerarInforme() {      //ESCRIBIR EN EL ARCHIVO

}

void Aeroporto::ImprimirInforme() {
    cout << "-----------------------------------AEROPUERTO---------------------------------------\n";
    cout << "NOMBRE: "<< this->nombre << "\n";
    cout << "VUELOS ATENDIDOS: "<< this->vuelosAtendidos << " vuelos\n";
    cout << "TIEMPO OPERACION: "<< this->tiempOperante << " minutos \n";
    cout << "-----------------------------------AEROLINEAS---------------------------------------\n";
    for(list<Aerolinea*>::iterator it=this->aerolineas.begin();it!=this->aerolineas.end();it++)
        (*it)->ImprimirVuelos();
    cout << "-----------------------------------TERMINALES---------------------------------------\n";
    for(list<Terminal*>::iterator it=this->terminales.begin();it!=this->terminales.end();it++)
        (*it)->ImprimirDatosTerminal();
    cout << "-----------------------------------VUELOS-------------------------------------------\n";
    for(list<Vuelo*>::iterator it=this->vuelos.begin();it!=this->vuelos.end();it++)
        (*it)->ImprimirDatosVuelo();
    cout << "-----------------------------------COLAVUELOS---------------------------------------\n";
    for(list<Vuelo*>::iterator it=this->colaVuelos.begin();it!=this->colaVuelos.end();it++)
        (*it)->ImprimirDatosVuelo();
    cout << "\n";

}

void Aeroporto::RegistrarTerminal(Terminal* terminal) {
    list<Terminal*>::iterator it;
    for(it=this->terminales.begin();(it!=this->terminales.end()) && (terminal->getTipo()>(*it)->getTipo());it++);
    this->terminales.insert(it,terminal);
}

void Aeroporto::RegistrarAerolinea(Aerolinea* aerolinea) {
    list<Aerolinea*>::iterator it;
    for(it=this->aerolineas.begin();(it!=this->aerolineas.end()) && (aerolinea->getNombre()>(*it)->getNombre());it++);
    this->aerolineas.insert(it,aerolinea);
}

void Aeroporto::RegistrarVueloGeneral(Vuelo* vuelo) {
    list<Vuelo*>::iterator it;
    for (it = this->vuelos.begin();
         (it != this->vuelos.end()) && (vuelo->getHoraSalida()->getHora() > (*it)->getHoraSalida()->getHora()); it++);
    this->vuelos.insert(it, vuelo);
}

void Aeroporto::AgregarAColaVuelos(Vuelo* vuelo) {
    list<Vuelo*>::iterator it;
    for(it=this->colaVuelos.begin();(it!=this->colaVuelos.end()) && (vuelo->getPrioridad()>=(*it)->getPrioridad());it++);
    this->colaVuelos.insert(it,vuelo);
}

void Aeroporto::ActualizarColaVuelos() {
    list<Vuelo*>::iterator it;
    int contmax=this->pista,cont=0;
    for(it=this->colaVuelos.begin(),cont=0;it!=this->colaVuelos.end() && cont<2;it++,cont++){
        int tipo = (this->nombre==(*it)->getOrigen());
        if(tipo==1 && ((*it)->getHoraDespegue()->getHora()==this->horaActual->getHora()))
            contmax++;
        if(tipo==0 && ((*it)->getHoraAterrizaje()->getHora()==this->horaActual->getHora()))
            contmax++;
    }
    for(it=this->colaVuelos.begin(),cont=0;it!=this->colaVuelos.end() && cont<contmax;it++,cont++){
    if(!(*it)->isDisponbilidadPista())
                (*it)->ChangeDisponibilidadPista();
    }
}
void Aeroporto::AddTimeEspera(){
    list<Vuelo*>::iterator it;
    for(it=this->colaVuelos.begin();it!=this->colaVuelos.end();it++){
        if(!(*it)->isDisponbilidadPista())
            (*it)->AddTiempoEspera();
    }
}
void Aeroporto::SacarDeColaVuelos() {
    Vuelo* vuelo=this->colaVuelos.front();
    vuelo->ChangeDisponibilidadPista();
    this->colaVuelos.pop_front();
}

int Aeroporto::VerificarEstadoVuelos() {
    int cont=0;
    for(list<Vuelo*>::iterator it=this->vuelos.begin();it!=this->vuelos.end();it++){
        cont+=(*it)->getEtapa();
    }
    return cont;
}

void Aeroporto::ActualizarVuelosAtendidos() {
    int cont=0;
    for(list<Vuelo*>::iterator it=this->vuelos.begin();it!=this->vuelos.end();it++){
        int tipo = (this->nombre==(*it)->getOrigen());
        if(tipo==0 && (*it)->getEtapa()<=2)
            cont++;
        if(tipo==1 && (*it)->getEtapa()<=4)
            cont++;
    }
    this->vuelosAtendidos=cont;
}

void Aeroporto::ActualizarTiempoOperacion() {
    int cont=0;
    for(list<Vuelo*>::iterator it=this->vuelos.begin();it!=this->vuelos.end();it++){
        int tipo = (this->nombre==(*it)->getOrigen());
        if(tipo==0 && (*it)->getEtapa()<=2)
            cont+=(*it)->getAvion()->getTiempoDespegueAterrizaje();
        if(tipo==1 && (*it)->getEtapa()<=4)
            cont+=(*it)->getAvion()->getTiempoDespegueAterrizaje();
    }
    this->tiempOperante=cont;
}