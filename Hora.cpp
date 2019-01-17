//
// Created by Mauricio on 31-12-2018.
//

#include "Hora.h"
#include <iostream>
using namespace std;

void Hora::ImprimirHora() {
    cout << "Hora: ";
    if (int(this->hora / 100)<10)
        cout <<"0";
    cout << int(this->hora / 100) << ":";
    if (this->hora%100<10)
        cout << "0";
    cout << this->hora%100 << " ";
}

void Hora::ImprimirHoraArchivo() {

    ofstream archivo;
    archivo.open(R"(C:\Users\mauricio\CLionProjects\untitled1\Informe.txt)", ios::app);

    archivo << "Hora: ";
    if (int(this->hora / 100)<10)
        archivo <<"0";
    archivo << int(this->hora / 100) << ":";
    if (this->hora%100<10)
        archivo << "0";
    archivo << this->hora%100 << " ";

    archivo.close();
}

int Hora::AddTime() {
    hora++;
    if(hora%100==60){
        hora+=40;
        if (hora==2400){
            hora=0;
            return 1;
        }
    }
    return 0;
}

int Hora::Sum(int tiempo) {
    for(int i=0;i<tiempo;i++)
       this->AddTime();
     return 0;
}

