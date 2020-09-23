#include <iostream>
#include "Vuelo.h"

using namespace std;

Vuelo::Vuelo(){
    //cout << "Constructor Vuelo" << endl;
    numeroMaxAsiento = 50;
    numeroAsientoDisponibles = 50;
    timeToDestination = 1;
    hour = 10;
    destination = "Monterrey";
    codigoVuelo = "101";
    date = "26/01/2020";
    distance = 10.00;
    price = 10.00;
}

Vuelo::~Vuelo(){
    //cout << "Destructor Vuelo" << endl;
}

int Vuelo::getNumeroMaxAsiento(){
    return numeroMaxAsiento;
}

int Vuelo::getNumeroAsientoDisponibles(){
    return numeroAsientoDisponibles;
}

int Vuelo::getTimeToDestination(){
    return timeToDestination;
}

int Vuelo::getHour(){
    return hour;
}

string Vuelo::getDestination(){
    return destination;
}

string Vuelo::getCodigoVuelo(){
    return codigoVuelo;
}

string Vuelo::getDate(){
    return date;
}

float Vuelo::getDistance(){
    return distance;
}

float Vuelo::getPrice(){
    return price;
}

void Vuelo::setNumeroMaxAsiento(int numMA){
    numeroMaxAsiento = numMA;
}

void Vuelo::setNumeroAsientoDisponibles(int numAD){
    numeroAsientoDisponibles = numAD;
}

void Vuelo::setTimeToDestination(int tiempoADestinacion){
    timeToDestination = tiempoADestinacion;
}

void Vuelo::setHour(int hora){
    hour = hora;
}

void Vuelo::setDestination(string destinacion){
    destination = destinacion;
}

void Vuelo::setCodigoVuelo(string codeV){
    codigoVuelo = codeV;
}

void Vuelo::setDate(string data){
    date = data;
}

void Vuelo::setDistance(float distancia){
    distance = distancia;
}

void Vuelo::setPrice(float precio){
    price = precio;
}
