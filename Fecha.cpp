//
// Created by Mauricio on 30-12-2018.
//

#include "Fecha.h"
#include <iostream>
using namespace std;

void Fecha::AddDay() {
    if(this->day==30){
        this->day=0;
        this->AddMonth();
    }
}

void Fecha::AddMonth() {
    if(this->month==12) {
        this->month = 0;
        this->AddYear();
    }
}

void Fecha::AddYear() {
    this->year++;
}

int Fecha::CompararFecha(Fecha * fecha) {
    if(this->year>fecha->getYear())
        return 1;
    else
        if(this->year<fecha->getYear())
            return 0;
        else
            if(this->month>fecha->getMonth())
                return 1;
            else
                if(this->month<fecha->getMonth())
                    return 0;
                else
                    if(this->day>fecha->getDay())
                        return 1;
                    else
                        if(this->day<fecha->getDay())
                            return 0;
                        else
                            return 0;
}

int Fecha::isIgual(Fecha *fecha) {
    if(this->year==fecha->getYear() && this->month==fecha->getMonth() && this->day==fecha->getDay())
        return 1;
    else
        return 0;
}

void Fecha::ImprimirFecha() {
    cout << "Fecha: ";
    if (this->day<10)
        cout << "0";
    cout << this->day << "-";
    if(this->month<10)
        cout << "0";
    cout << this->month << "-"<< this->year << "\n";
}