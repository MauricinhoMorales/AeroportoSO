//
// Created by Mauricio on 27-12-2018.
//

#include <sstream>
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
}

void Aeroporto::CierreActividad() {    // OPCION DEL MENU CERRAR
    exit(1);
}

void Aeroporto::GenerarInforme(){ //ESCRIBIR UN ARCHIVO
    ofstream archivo;

    archivo.open(R"(C:\Users\mauricio\CLionProjects\untitled1\Informe.txt)");
    if (archivo.fail()) {
        cout << "ERROR: No se pudo abrir el archivo";
        exit(1);
    }

    archivo << "-----------------------------------INFORME-----------------------------------------\n";
    archivo << "NOMBRE DEL AEROPUERTO: "<< this->nombre << "\n";
    archivo << "HORA DE EMISION: ";

    archivo.close();

    this->horaActual->ImprimirHoraArchivo();

    archivo.open(R"(C:\Users\mauricio\CLionProjects\untitled1\Informe.txt)", ios::app);

    archivo << "\n";
    archivo << "VUELOS ATENDIDOS: "<< this->vuelosAtendidos << " vuelos\n";
    archivo << "VUELOS EN USO DE PISTA: "<< this->VuelosEnUso() << " vuelos \n";
    archivo << "VUELOS EN ESPERA POR PISTA: "<< this->VuelosEnEspera() << " vuelos \n";
    archivo << "TIEMPO OPERACION: "<< this->tiempOperante << " minutos \n";
    archivo << "-----------------------------------AEROLINEAS---------------------------------------\n";

    archivo.close();

    for(list<Aerolinea*>::iterator it=this->aerolineas.begin();it!=this->aerolineas.end();it++)
        (*it)->ImprimirVuelosArchivo();

    archivo.open(R"(C:\Users\mauricio\CLionProjects\untitled1\Informe.txt)", ios::app);

    archivo << "-----------------------------------TERMINALES---------------------------------------\n";

    archivo.close();

    for(list<Terminal*>::iterator it=this->terminales.begin();it!=this->terminales.end();it++)
        (*it)->ImprimirDatosTerminalArchivo();

    archivo.open(R"(C:\Users\mauricio\CLionProjects\untitled1\Informe.txt)", ios::app);

    archivo << "-----------------------------------VUELOS-------------------------------------------\n";

    archivo.close();

    for(list<Vuelo*>::iterator it=this->vuelos.begin();it!=this->vuelos.end();it++)
        (*it)->ImprimirDatosVueloArchivo();

    archivo.open(R"(C:\Users\mauricio\CLionProjects\untitled1\Informe.txt)", ios::app);

    archivo << "-----------------------------VUELOS EN ESPERA POR PISTA-----------------------------\n";

    archivo.close();

    for(list<Vuelo*>::iterator it=this->colaVuelos.begin();it!=this->colaVuelos.end();it++)
        if (!(*it)->isDisponbilidadPista())
            (*it)->ImprimirDatosVueloArchivo();

    archivo.open(R"(C:\Users\mauricio\CLionProjects\untitled1\Informe.txt)", ios::app);

    archivo << "------------------------------------------------------------------------------------\n";

   archivo.close();

}

void Aeroporto::CargarArchivo() {    //CARGAR ESTRUCTURAS LEER DEL ARCHIVO
    ifstream archivo;
    string texto , sLinea,nombre="new";
    string arrAux[15];


    // ASIGNACION DE LA AEROLINEA
    archivo.open(R"(C:\Users\mauricio\CLionProjects\untitled1\Aeropuerto.txt)", ios::in);
    if (archivo.fail()) {
        cout << "ERROR: No se pudo abrir el archivo";
        exit(1);
    }

    Aerolinea *aerolinea;

    while (!archivo.eof()) {
        getline(archivo, texto);
        int i = 0;
        stringstream ssTexto (texto);
        while (getline(ssTexto, sLinea, ' ')){
            arrAux[i] = sLinea;
            i++;
        }
        if (arrAux[0]!=nombre) {
            if(nombre!="new")
                this->RegistrarAerolinea(aerolinea);
            aerolinea = new Aerolinea(arrAux[0]);
            nombre=arrAux[0];
        }
        Avion *avion = new Avion(arrAux[1],stof(arrAux[2]),stoi(arrAux[3]),stoi(arrAux[4])) ;
        Vuelo *vuelo = new Vuelo(arrAux[5],arrAux[6],arrAux[7],stoi(arrAux[8]),stoi(arrAux[9]),stoi(arrAux[10]),stoi(arrAux[11]),stoi(arrAux[12]),stoi(arrAux[13]),stoi(arrAux[14]),avion);
        aerolinea->RegistrarVuelo(vuelo);
        this->RegistrarVueloGeneral(vuelo);
    }
    if(nombre!="new")
        this->RegistrarAerolinea(aerolinea);
    archivo.close();
    cout << "SE CARGO CORRECTAMENTE EL ARCHIVO: AEROPUERTO.txt \n";

    //Cerramos el archivo

    //ASIGNACION DEL TERMINAL

    archivo.open(R"(C:\Users\mauricio\CLionProjects\untitled1\Terminales.txt)", ios::in);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivo.eof()) {
        getline(archivo, texto);

        int i = 0;
        stringstream ssTexto (texto);
        while (getline(ssTexto, sLinea, ' ')) {
            arrAux[i] = sLinea;
            i++;
        }
        Terminal *terminal = new Terminal(arrAux[0],stoi(arrAux[1]),stoi(arrAux[2]),stoi(arrAux[3])) ;
        this->RegistrarTerminal(terminal);
    }
    archivo.close();
    cout << "SE CARGO CORRECTAMENTE EL ARCHIVO: TERMINALES.txt\n";

    //Cerramos el archivo
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
    cout << "HORA DE EMISION: ";
    this->horaActual->ImprimirHora();
    cout << "\n";
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
    for(it=this->aerolineas.begin();(it!=this->aerolineas.end()) && (aerolinea->getNombre()>=(*it)->getNombre());it++);
    this->aerolineas.insert(it, aerolinea);
}

void Aeroporto::RegistrarVuelosAerolinea(Aerolinea* origen, Aerolinea * destino){
    list<Vuelo*>::iterator it;
    for (it = origen->getVuelos().begin();it != origen->getVuelos().end(); it++);
        destino->RegistrarVuelo((*it));
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