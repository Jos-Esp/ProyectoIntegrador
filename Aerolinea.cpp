#include <iostream>
#include "Aerolinea.h"

using namespace std;

Aerolinea::Aerolinea(){
    //cout << "Constructor Aerolinea" << endl;
    numeroMaxVuelos = 50;
    codigoAerolinea = "IB";
}

Aerolinea::~Aerolinea(){
    //cout << "Destructor Aerolinea" << endl;
}

int Aerolinea::getNumeroMaxVuelos(){
    return numeroMaxVuelos;
}

string Aerolinea::getCodigoAerolinea(){
    return codigoAerolinea;
}

void Aerolinea::setNumeroMaxVuelos(int numMV){
    numeroMaxVuelos = numMV;
}

void Aerolinea::setCodigoAerolinea(string codeAe){
    codigoAerolinea = codeAe;
}
