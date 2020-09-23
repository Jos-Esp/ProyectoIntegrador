#include <iostream>
#include "Sistema.h"
#include "Cliente.h"
#include "FileOpener.h"

using namespace std;

Sistema::Sistema(){
    //cout << "Costructor Sistema" << endl;
    numeroVuelosDisponibles = 0;
    numeroAsientosPren = 1;
    limiteKilometraje = 50000.00;
    descuento = 40;
    dateSelected = "01/01/2020";
}

Sistema::~Sistema(){
    //cout << "Destructor Sistema" << endl;
}

int Sistema::getNumeroVuelosDisponibles(){
    return numeroVuelosDisponibles;
}

int Sistema::getNumeroAsientosPren(){
    return numeroAsientosPren;
}

float Sistema::getLimiteKilometraje(){
    return limiteKilometraje;
}

int Sistema::getDescuento(){
    return descuento;
}

string Sistema::getDateSelected(){
    return dateSelected;
}

float Sistema::aplicaDescuento(int descuento1){
    //convertire il numero a due o piu cifre in un numero float da *
    float multiply = 0.0;
    multiply = descuento1 / 100.00;
    return multiply;
}

void Sistema::setNumeroVuelosDisponibles(int numeroVD){
    numeroVuelosDisponibles = numeroVD;
}

void Sistema::setNumeroAsientosPren(int numAP){
    numeroAsientosPren = numAP;
}

void Sistema::setLimiteKilometraje(float limK){
    limiteKilometraje = limK;
}

void Sistema::setDescuento(float descu){
    descuento = descu;
}

void Sistema::setDateSelected(string dateS){
    dateSelected = dateS;
}
