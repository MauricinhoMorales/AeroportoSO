//
// Created by Mauricio on 27-12-2018.
//

#ifndef UNTITLED1_TERMINAL_H
#define UNTITLED1_TERMINAL_H
#include <iostream>
#include <string.h>
using namespace std;

class Terminal {
public:
    Terminal(string codigo,int numeroPistas,int disponibles,int tipo){
        this->codigo=codigo;
        this->numPlataformas=numeroPistas;
        this->disponibles=disponibles;
        this->tipo=tipo;
    }
private:
    string codigo;
    int numPlataformas;
    int disponibles;
    int tipo;// 0 para terminal pasajeros y 1 para terminal de carga
public:
    int getTipo(){return this->tipo;}

    void OcuparPlataforma();
    void DesocuparPlataforma();

    void ImprimirDatosTerminal();
};

#endif //UNTITLED1_TERMINAL_H
