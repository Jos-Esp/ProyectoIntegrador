#ifndef AEROLINEA_H_INCLUDED
#define AEROLINEA_H_INCLUDED
#include <iostream>
#include "Vuelo.h"

using namespace std;

class Aerolinea {
    private:
        int numeroMaxVuelos;
        string codigoAerolinea;
        //in
    public:
        Aerolinea();
        ~Aerolinea();

        Vuelo listaVuelos[40];

        int getNumeroMaxVuelos();
        string getCodigoAerolinea();

        void setNumeroMaxVuelos(int);
        void setCodigoAerolinea(string);
        //in
    //in

};


#endif // AEROLINEA_H_INCLUDED
