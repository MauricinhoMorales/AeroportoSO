#include <iostream>
#include "Aeroporto.h"
#include "Cronometro.h"
#include <windows.h>

int main() {
    Aeroporto* aeropuerto= new Aeroporto("SAO PAOLO",2,2,4,2010);
    Terminal* terminal1= new Terminal("CR20",10,10,0);
    Terminal* terminal2= new Terminal("TE12",5,4,0);
    Terminal* terminal3= new Terminal("QW01",7,5,1);
    Aerolinea* aerolinea1 = new Aerolinea("AmericanAirlines");
    Aerolinea* aerolinea2 = new Aerolinea("Rutaca");
    Vuelo* vuelo = new Vuelo("R2","Argentina","Brasil",700,7,8,1999,0,new Avion("67",60,120,0));
    Vuelo* vuelo1 = new Vuelo("R2","Dubai","Brasil",600,8,9,2010,0,new Avion("67",60,120,0));
    Vuelo* vuelo2 = new Vuelo("R2","Brasil","Colombia",800,7,8,2001,0,new Avion("67",60,120,0));
    Vuelo* vuelo3 = new Vuelo("R2","Brasil","USA",630,2,11,2017,0,new Avion("67",60,120,0));
    aeropuerto->RegistrarTerminal(terminal1);
    aeropuerto->RegistrarTerminal(terminal2);
    aeropuerto->RegistrarTerminal(terminal3);
    aerolinea1->RegistrarVuelo(vuelo);
    aerolinea1->RegistrarVuelo(vuelo1);
    aerolinea1->RegistrarVuelo(vuelo2);
    aerolinea1->RegistrarVuelo(vuelo3);
    aeropuerto->RegistrarAerolinea(aerolinea1);
    aeropuerto->RegistrarAerolinea(aerolinea2);
    aeropuerto->ImprimirInforme();
    aeropuerto->AttachedThread();

}