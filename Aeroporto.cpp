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

void Aeroporto::IniciarGestion() {    //REALIZAR LA GESTION
    while(this->VerificarEstadoVuelos()){
        for(long int i=0;i<segundo;i++);
        if(this->horaActual->AddTime())
            this->fecha->AddDay();
        this->horaActual->ImprimirHora();
        this->fecha->ImprimirFecha();

        for(list<Vuelo>::iterator it=this->vuelos.begin();it!=this->vuelos.end();it++){
            int tipo = (this->nombre==(*it).getOrigen());
            if((*it).getHoraSalida()->getHora()==this->horaActual->getHora())
                (*it).InicioVuelo();
            else
                if((*it).getHoraCarga()->getHora()==this->horaActual->getHora())
                    (*it).CargaRealizada();
                else
                    if((*it).getHoraDespegue()->getHora()==this->horaActual->getHora())
                        (*it).DespegueRealizado();
                    else
                        if((*it).getHoraVuelo()->getHora()==this->horaActual->getHora())
                            (*it).VueloRealizado();
                        else
                            if((*it).getHoraAterrizaje()->getHora()==this->horaActual->getHora())
                                (*it).AterrizajeRealizado();
                            else
                                if((*it).getHoraDescarga()->getHora()==this->horaActual->getHora())
                                    (*it).DescargaRealizada();
                                else
                                    if((*it).getHoraFinalizar()->getHora()==this->horaActual->getHora())
                                        (*it).FinVuelo();
        }
        this->ActualizarColaVuelos();
        this->ImprimirInforme();

    }
}

void Aeroporto::CargarArchivo() {    //CARGAR ESTRUCTURAS LEER DEL ARCHIVO

}

void Aeroporto::GenerarInforme() {      //ESCRIBIR EN EL ARCHIVO

}

void Aeroporto::ImprimirInforme() {
//    cout << "----------AEROPUERTO---------\n";
//    cout << this->nombre << "\n";
//    cout << "----------AEROLINEAS---------\n";
//    for(list<Aerolinea>::iterator it=this->aerolineas.begin();it!=this->aerolineas.end();it++)
//        (*it).ImprimirVuelos();
//    cout << "\n";
//    cout << "----------TERMINALES---------\n";
//    for(list<Terminal>::iterator it=this->terminales.begin();it!=this->terminales.end();it++)
//        (*it).ImprimirDatosTerminal();
//    cout << "\n";
//    cout << "----------VUELOS---------\n";
//    for(list<Vuelo>::iterator it=this->vuelos.begin();it!=this->vuelos.end();it++)
//        (*it).ImprimirDatosVuelo();
//    cout << "\n";
    cout << "----------COLAVUELOS---------\n";
    for(list<Vuelo>::iterator it=this->colaVuelos.begin();it!=this->colaVuelos.end();it++)
        (*it).ImprimirDatosVuelo();
    cout << "\n";

}

void Aeroporto::RegistrarTerminal(Terminal* terminal) {
    list<Terminal>::iterator it;
    for(it=this->terminales.begin();(it!=this->terminales.end()) && (terminal->getTipo()>(*it).getTipo());it++);
    this->terminales.insert(it,*terminal);
}

void Aeroporto::RegistrarAerolinea(Aerolinea* aerolinea) {
    list<Aerolinea>::iterator it;
    for(it=this->aerolineas.begin();(it!=this->aerolineas.end()) && (aerolinea->getNombre()>(*it).getNombre());it++);
    this->aerolineas.insert(it,*aerolinea);
}

void Aeroporto::RegistrarVuelo(Vuelo* vuelo) {
    list<Vuelo>::iterator it;
    for (it = this->vuelos.begin();
         (it != this->vuelos.end()) && (vuelo->getHoraSalida()->getHora() > (*it).getHoraSalida()->getHora()); it++);
    this->vuelos.insert(it, *vuelo);
}

void Aeroporto::AgregarAColaVuelos(Vuelo* vuelo) {
    list<Vuelo>::iterator it;
    for(it=this->colaVuelos.begin();(it!=this->colaVuelos.end()) && (vuelo->getPrioridad()>=(*it).getPrioridad());it++);
    this->colaVuelos.insert(it,*vuelo);
}

void Aeroporto::ActualizarColaVuelos() {
    list<Vuelo>::iterator it;
    int cont=0;
    for(it=this->colaVuelos.begin();it!=this->colaVuelos.end();it++,cont++){
        if(cont<2)
            if(!(*it).isDisponbilidadPista())
                (*it).ChangeDisponibilidadPista();
    }
    for(it=this->colaVuelos.begin();it!=this->colaVuelos.end();it++){
        if(!(*it).isDisponbilidadPista())
            (*it).AddTiempoEspera();
    }
}
void Aeroporto::SacarDeColaVuelos() {
  this->colaVuelos.pop_front();
}

int Aeroporto::PistaDisponible() {
    return this->pista;
}

int Aeroporto::VerificarEstadoVuelos() {
    int cont=0;
    for(list<Aerolinea>::iterator it=this->aerolineas.begin();it!=this->aerolineas.end();it++)
        cont+=(*it).EstadoVuelos();
    return cont;
}

void Aeroporto::ActualizarVuelosAtendidos() {
    int cont=0;
    for(list<Aerolinea>::iterator it=this->aerolineas.begin();it!=this->aerolineas.end();it++)
        cont+=(*it).VuelosAtendidos();
    this->vuelosAtendidos=cont;
}
