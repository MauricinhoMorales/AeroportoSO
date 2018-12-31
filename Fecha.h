//
// Created by Mauricio on 30-12-2018.
//

#ifndef UNTITLED1_FECHA_H
#define UNTITLED1_FECHA_H


class Fecha {
public:
    Fecha(int day, int month, int year){
        this->day=day;
        this->month=month;
        this->year=year;
    }
private:
    int day;
    int month;
    int year;
public:
    int getDay(){return this->day;}
    int getMonth(){return this->month;}
    int getYear(){return this->year;}

    void AddDay();
    void AddMonth();
    void AddYear();

    void ImprimirFecha();

};


#endif //UNTITLED1_FECHA_H
