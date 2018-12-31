//
// Created by Mauricio on 30-12-2018.
//

#ifndef UNTITLED1_CRONOMETRO_H
#define UNTITLED1_CRONOMETRO_H
#include <ctime>

class Cronometro {
public:
    Cronometro(){
        t0=clock();
        this->tiempo=0;
    }
    Cronometro(int tiempo){
        this->tiempo=tiempo;
        t0=clock();
    }
private:
    double tiempo;
    unsigned t0;
    unsigned t1;

public:
    void Iniciar();
    void Detener();
    void Reiniciar();
    int Chequear();
    double getTime();
};


#endif //UNTITLED1_CRONOMETRO_H
