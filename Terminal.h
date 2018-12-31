//
// Created by Mauricio on 27-12-2018.
//

#ifndef UNTITLED1_TERMINAL_H
#define UNTITLED1_TERMINAL_H
#include <iostream>
using namespace std;

class Terminal {
public:
    Terminal(char*codigo,int numeroPistas,int disponibles,int tipo){
        this->codigo=codigo;
        this->numPlataformas=numeroPistas;
        this->disponibles=disponibles;
        this->tipo=tipo;
        this->next=NULL;
    }
private:
    char* codigo;
    int numPlataformas;
    int disponibles;
    int tipo;// 0 para terminal pasajeros y 1 para terminal de carga
    Terminal* next;
public:
    Terminal* getNext(){return this->next;}
    int getTipo(){return this->tipo;}

    void setNext(Terminal* terminal){this->next=terminal;}

    void OcuparPlataforma();
    void DesocuparPlataforma();

    void ImprimirDatosTerminal();
};

#endif //UNTITLED1_TERMINAL_H
