#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED
#include <iostream>
#include "Cliente.h"
#include "Aerolinea.h"

using namespace std;

class Sistema {
    private:
        int numeroVuelosDisponibles;
        int numeroAsientosPren;
        float limiteKilometraje;
        int descuento;
        string dateSelected;

        //in
    public:
        Sistema();
        ~Sistema();

        Cliente client;
        Aerolinea listaAerolineas[40];

        int getNumeroVuelosDisponibles();
        int getNumeroAsientosPren();
        float getLimiteKilometraje();
        int getDescuento();
        string getDateSelected();
        float aplicaDescuento(int);

        void setNumeroVuelosDisponibles(int);
        void setNumeroAsientosPren(int);
        void setLimiteKilometraje(float);
        void setDescuento(float);
        void setDateSelected(string);

        //in
    //in
};

#endif // SISTEMA_H_INCLUDED
