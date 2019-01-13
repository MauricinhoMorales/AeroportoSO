//
// Created by Mauricio on 27-12-2018.
//
#include "Terminal.h"

void Terminal::ImprimirDatosTerminal() {
    if (this->tipo==0)
        cout << "Terminal de Pasajeros\n";
    else
        cout << "Terminal de Carga\n";
    cout << "Codigo: "<< this->codigo<<"\n";
    cout << "Numero de Plataformas : " << this->numPlataformas << "\n";
    cout << "Plataformas Disponibles : " << this->disponibles << "\n\n";

}

int Terminal::OcuparPlataforma() {
    if(this->disponibles!=0) {
        this->disponibles--;
        return 0;
    }else{
        return 1;
    }
}

int Terminal::DesocuparPlataforma() {
    if(this->disponibles!=numPlataformas) {
        this->disponibles++;
        return 0;
    }else{
        return 1;
    }
}