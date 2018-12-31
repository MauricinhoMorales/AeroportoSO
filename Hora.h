//
// Created by Mauricio on 31-12-2018.
//

#ifndef UNTITLED1_HORA_H
#define UNTITLED1_HORA_H


class Hora {
public:
    Hora(int hora){
        this->hora=hora;
    }
private:
    int hora;
public:
    int getHora(){return hora;}

    int AddTime();

    void ImprimirHora();
};


#endif //UNTITLED1_HORA_H
