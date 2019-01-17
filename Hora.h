//
// Created by Mauricio on 31-12-2018.
//

#ifndef UNTITLED1_HORA_H
#define UNTITLED1_HORA_H
#include<fstream>
using namespace std;

class Hora {
public:
    Hora(int hora){
        this->hora=hora;
    }
    Hora(){
        this->hora=0;
    }
private:
    int hora;
public:
    int getHora(){return hora;}

    int AddTime();
    int Sum(int tiempo);
    void ImprimirHora();
    void ImprimirHoraArchivo();
};


#endif //UNTITLED1_HORA_H
