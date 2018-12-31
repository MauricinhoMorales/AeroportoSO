//
// Created by Mauricio on 30-12-2018.
//

#include "Fecha.h"

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