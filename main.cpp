#include <iostream>
#include "Aeroporto.h"

int main() {
    Aeroporto* aeropuerto= new Aeroporto("SaoPaolo",2);
    Terminal* terminal1= new Terminal("CR20",10,10,0);
    Terminal* terminal2= new Terminal("TE12",5,4,0);
    Terminal* terminal3= new Terminal("QW01",7,5,1);
    Aerolinea* aerolinea1 = new Aerolinea("AmericanAirlines");
    Aerolinea* aerolinea2 = new Aerolinea("Rutaca");
    Vuelo* vuelo = new Vuelo("R2","Argentina","Brasil",700,0,new Avion("67",60,120,0));
    aeropuerto->RegistrarTerminal(terminal1);
    aeropuerto->RegistrarTerminal(terminal2);
    aeropuerto->RegistrarTerminal(terminal3);
    aerolinea1->RegistrarVuelo(vuelo);
    aeropuerto->RegistrarAerolinea(aerolinea1);
    aeropuerto->RegistrarAerolinea(aerolinea2);
    aeropuerto->ImprimirInforme();
}