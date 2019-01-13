#include <iostream>
#include "Aeroporto.h"
#include <windows.h>

int main() {
    string nombre;
    int numeroPistas;
    int hora;
    int day;
    int month;
    int year;

    int op=1;
    cout << "INTRODUZCA EL NOMBRE DEL AEROPUERTO: \n";
    getline(cin,nombre);
    cout << "INTRODUZCA EL NUMERO DE PISTAS DISPONIBLES: \n";
    cin >> numeroPistas;
    cout << "INTRODUZCA EL ANHO ACTUAL:  \n";
    cin >> year;
    cout << "INTRODUZCA EL MES ACTUAL:  \n";
    cin >> month;
    cout << "INTRODUZCA EL DIA ACTUAL:  \n";
    cin >> day;
    cout << "INTRODUZCA LA HORA ACTUAL:  \n";
    cin >> hora;
    Aeroporto *aeropuerto = new Aeroporto(nombre,numeroPistas,hora,day,month,year);
    while(op!=0){
        cout << "----------------------------------DATOS--------------------------------------------\n";
        cout << "* PARA INTERRUMPIR ACTIVIDAD MANTENER PRESIONADO LA TECLA <SHIFT>\n";
        cout << "* CARGAR LOS ARCHIVOS .txt QUE SE UTILIZARAN EN LA GESTION \n";
        cout << "----------------------------------MENU---------------------------------------------\n";
        cout << "INTRODUZCA LA OPCION QUE DESEA REALIZAR: \n 1)COMENZAR ACTIVIDAD DEL AEROPUERTO \n 2)RETOMAR ACTIVIDAD DEL AEROPUERTO \n 0)CIERRE ACTIVIDAD \n";
        cin >> op;
        cout << "-----------------------------------------------------------------------------------\n\n";

        switch(op){
            case 0:
                aeropuerto->CierreActividad();
                break;

            case 1:
                aeropuerto->ComenzarActividad();
                aeropuerto->InterrumpirActividad();
                break;

            case 2:
                aeropuerto->RetomarActividad();
                aeropuerto->InterrumpirActividad();
                break;
        }
        cout << "\n";
    }
}