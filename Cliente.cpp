#include <iostream>
#include "Cliente.h"

using namespace std;

Cliente::Cliente(){
    //cout << "Constructor Cliente" << endl;
    nombre = "Your Name And Surname Here";
    email = " personalemail@email.com";
    password = "1234567890";
    kilometraje = 0.0;
    puntatore = 0;
}

Cliente::~Cliente(){
    //cout << "Destructor Cliente" << endl;
}

int Cliente::getPuntatore(){
    return puntatore;
}

string Cliente::getNombre(){
    return nombre;
}

string Cliente::getEmail(){
    return email;
}

string Cliente::getPassword(){
    return password;
}

float Cliente::getKilometraje(){
    return kilometraje;
}

void Cliente::setPuntatore(int punt){
    puntatore = punt;
}

void Cliente::setNombre(string name){
    nombre = name;
}

void Cliente::setEmail(string em){
    email = em;
}

void Cliente::setPassword(string pass){
    password = pass;
}

void Cliente::setKilometraje(float kilom){
    kilometraje = kilom;
}
