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

void Terminal::ImprimirDatosTerminalArchivo() {
    ofstream archivo;
    archivo.open(R"(C:\Users\mauricio\CLionProjects\untitled1\Informe.txt)", ios::app);

    if (this->tipo==0)
        archivo << "Terminal de Pasajeros\n";
    else
        archivo << "Terminal de Carga\n";
    archivo << "Codigo: "<< this->codigo<<"\n";
    archivo << "Numero de Plataformas : " << this->numPlataformas << "\n";
    archivo << "Plataformas Disponibles : " << this->disponibles << "\n\n";

    archivo.close();
}


int Terminal::OcuparPlataforma() {
    if(this->disponibles!=0) {
        this->disponibles--;
        return 1;
    }else{
        return 0;
    }
}

int Terminal::DesocuparPlataforma() {
    if(this->disponibles!=numPlataformas) {
        this->disponibles++;
        return 1;
    }else{
        return 0;
    }
}