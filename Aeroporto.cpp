//
// Created by Mauricio on 27-12-2018.
//

#include "Aeroporto.h"

void Aeroporto::ComenzarActividad(){  // como se ordena el beta
    this->CargarArchivo();
    this->IniciarGestion();
}

void Aeroporto::RetomarActividad() {
    this->IniciarGestion();
}

void Aeroporto::InterrumpirActividad() {   //OPCION DE MENU PARA PARAR ACTIVIDAD
    this->GenerarInforme();
    this->ImprimirInforme();
}

void Aeroporto::CierreActividad() {    // OPCION DEL MENU CERRAR
    exit(1);
}

void Aeroporto::GenerarInforme(){ //ESCRIBIR UN ARCHIVO

}

void Aeroporto::CargarArchivo() {    //CARGAR ESTRUCTURAS LEER DEL ARCHIVO
    Terminal *terminal1 = new Terminal("CR20", 10, 10, 0);
    Terminal *terminal3 = new Terminal("QW01", 7, 1, 1);
    Aerolinea *aerolinea1 = new Aerolinea("AmericanAirlines");
    Aerolinea *aerolinea2 = new Aerolinea("Rutaca");
    Vuelo *vuelo1 = new Vuelo("SALIDA 1", "Brazil", "Chile",1,10,    10 ,4, 1, 2019, 1, new Avion("67", 60, 150, 1));
    Vuelo *vuelo2 = new Vuelo("SALIDA 2", "Brazil", "Colombia",1,10, 10, 4, 1, 2019, 1, new Avion("67", 60, 150, 1));
    Vuelo *vuelo3 = new Vuelo("SALIDA 3", "Brazil", "USA",1,10,      10, 4, 1, 2019, 1, new Avion("67", 60, 150, 1));
    Vuelo *vuelo4 = new Vuelo("LLEGADA 1", "Brazil",  "Chile",1,10,    10 ,4, 1, 2019, 1, new Avion("67", 60, 150, 1));
    Vuelo *vuelo5 = new Vuelo("LLEGADA 2", "Brazil", "Uruguay",1,10, 10, 4, 1, 2019, 1, new Avion("67", 60, 150, 1));
    Vuelo *vuelo6 = new Vuelo("LLEGADA 3", "Brazil", "Colombia",1,10,   10, 4, 1, 2019, 1, new Avion("67", 60, 150, 1));
    this->RegistrarTerminal(terminal1);
    this->RegistrarTerminal(terminal3);
    aerolinea1->RegistrarVuelo(vuelo1);
    aerolinea1->RegistrarVuelo(vuelo2);
    aerolinea2->RegistrarVuelo(vuelo3);
    aerolinea1->RegistrarVuelo(vuelo4);
    aerolinea1->RegistrarVuelo(vuelo5);
    aerolinea2->RegistrarVuelo(vuelo6);
    this->RegistrarVueloGeneral(vuelo1);
    this->RegistrarVueloGeneral(vuelo2);
    this->RegistrarVueloGeneral(vuelo3);
    this->RegistrarVueloGeneral(vuelo4);
    this->RegistrarVueloGeneral(vuelo5);
    this->RegistrarVueloGeneral(vuelo6);
    this->RegistrarAerolinea(aerolinea2);
    this->RegistrarAerolinea(aerolinea1);
}

void Aeroporto::IniciarGestion() {    //REALIZAR LA GESTION
    while(this->VerificarEstadoVuelos()) {

        cout << "----------------------------------HORA Y FECHA -------------------------------------\n";
        if (this->horaActual->AddTime())
            this->fecha->AddDay();
        this->horaActual->ImprimirHora();
        this->fecha->ImprimirFecha();
        cout << "------------EVENTOS-------------\n";
        for (list<Vuelo *>::iterator it = this->vuelos.begin(); it != this->vuelos.end(); it++) {
            int tipo = (this->nombre == (*it)->getOrigen());
            if ((*it)->getFecha()->isIgual(this->fecha))
                if ((*it)->getHoraSalida()->getHora() == this->horaActual->getHora())
                    (*it)->InicioVuelo();
                else if ((*it)->getHoraCarga()->getHora() == this->horaActual->getHora()) {
                    (*it)->CargaRealizada();
                    if (tipo == 1) {
                        this->AgregarAColaVuelos(*it);
                    }
                } else if ((*it)->getHoraDespegue()->getHora() == this->horaActual->getHora()) {
                    (*it)->DespegueRealizado();
                    if (tipo == 1) {
                        this->SacarDeColaVuelos(*it);
                    }
                } else if ((*it)->getHoraVuelo()->getHora() == this->horaActual->getHora()) {
                    (*it)->VueloRealizado();
                    if (tipo == 0) {
                        this->AgregarAColaVuelos(*it);
                    }
                } else if ((*it)->getHoraAterrizaje()->getHora() == this->horaActual->getHora()) {
                    (*it)->AterrizajeRealizado();
                    if (tipo == 0) {
                        this->SacarDeColaVuelos(*it);
                    }
                } else if ((*it)->getHoraDescarga()->getHora() == this->horaActual->getHora())
                    (*it)->DescargaRealizada();
                else if ((*it)->getHoraFinalizar()->getHora() == this->horaActual->getHora())
                    (*it)->FinVuelo();
        }
        this->ActualizarColaVuelos();
        this->AddTimeEspera();
        this->ActualizarVuelosAtendidos();
        this->ActualizarTiempoOperacion();
        if (GetKeyState(VK_SHIFT) & 0x8000) {
            break;
        }
        for (long int i = 0; i < segundo; i++);
    }
}

void Aeroporto::ImprimirInforme() {
    cout << "-----------------------------------INFORME-----------------------------------------\n";
    cout << "NOMBRE DEL AEROPUERTO: "<< this->nombre << "\n";
    cout << "VUELOS ATENDIDOS: "<< this->vuelosAtendidos << " vuelos\n";
    cout << "VUELOS EN USO DE PISTA: "<< this->VuelosEnUso() << " vuelos \n";
    cout << "VUELOS EN ESPERA POR PISTA: "<< this->VuelosEnEspera() << " vuelos \n";
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
    cout << "-----------------------------VUELOS EN ESPERA POR PISTA-----------------------------\n";
    for(list<Vuelo*>::iterator it=this->colaVuelos.begin();it!=this->colaVuelos.end();it++)
        if (!(*it)->isDisponbilidadPista())
            (*it)->ImprimirDatosVuelo();
    cout << "------------------------------------------------------------------------------------\n";
}

int Aeroporto::VuelosEnEspera(){
    int cont=0;
    list<Vuelo*>::iterator it;
    for(it=this->colaVuelos.begin();it!=this->colaVuelos.end();it++)
        if (!(*it)->isDisponbilidadPista())
            cont++;
    return cont;
}

int Aeroporto::VuelosEnUso(){
    int cont=0;
    list<Vuelo*>::iterator it;
    for(it=this->colaVuelos.begin();it!=this->colaVuelos.end();it++)
        if ((*it)->isDisponbilidadPista())
            cont++;
    return cont;
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
    for (it = this->vuelos.begin();(it != this->vuelos.end()) && (vuelo->getFecha()->CompararFecha((*it)->getFecha())); it++);
    for (;(it != this->vuelos.end()) && (vuelo->getHoraSalida()->getHora() > (*it)->getHoraSalida()->getHora()); it++);
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
    cout << "----------USO DE PISTA----------\n";
    for(it=this->colaVuelos.begin();it!=this->colaVuelos.end() && (*it)->isDisponbilidadPista();it++){
        int tipo = (this->nombre==(*it)->getOrigen());
        if(tipo==1)
            (*it)->Despegando();
        if(tipo==0)
            (*it)->Aterrizando();
    }
    cout << "--------------------------------\n\n";

}
void Aeroporto::AddTimeEspera(){
    list<Vuelo*>::iterator it;
    for(it=this->colaVuelos.begin();it!=this->colaVuelos.end();it++){
        if(!(*it)->isDisponbilidadPista())
            (*it)->AddTiempoEspera();
    }
}

void Aeroporto::SacarDeColaVuelos(Vuelo *vuelo) {
    int tipo=vuelo->getAvion()->getTipo();
    int type=vuelo->getTipo();
    vuelo->ChangeDisponibilidadPista();
    this->colaVuelos.remove(vuelo);

    list<Terminal*>::iterator it;
    for(it=this->terminales.begin();it!=this->terminales.end();it++){
        if((*it)->getTipo()==tipo)
            if(type==1) {
                (*it)->DesocuparPlataforma();
                break;
            } else {
                (*it)->OcuparPlataforma();
                break;
            }
    }
    return;
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