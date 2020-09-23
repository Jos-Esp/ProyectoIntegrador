#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED
#include <iostream>

using namespace std;

class Vuelo {

    private:
        int numeroMaxAsiento;
        int numeroAsientoDisponibles;
        int timeToDestination;
        int hour;
        string destination;
        string codigoVuelo;
        string date;
        float distance;
        float price;
        //in
    public:
        Vuelo();
        ~Vuelo();

        int getNumeroMaxAsiento();
        int getNumeroAsientoDisponibles();
        int getTimeToDestination();
        int getHour();
        string getDestination();
        string getCodigoVuelo();
        string getDate();
        float getDistance();
        float getPrice();

        void setNumeroMaxAsiento(int);
        void setNumeroAsientoDisponibles(int);
        void setDestination(string);
        void setTimeToDestination(int);
        void setDistance(float);
        void setPrice(float);
        void setCodigoVuelo(string);
        void setDate(string);
        void setHour(int);
        //in

    //in
};

#endif // VUELO_H_INCLUDED
