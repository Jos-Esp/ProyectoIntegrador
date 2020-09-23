#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <iostream>

using namespace std;

class Cliente {
    private:
        string nombre;
        string email;
        string password;
        float kilometraje;
        int puntatore;
        //in
    public:
        Cliente();
        ~Cliente();

        string getNombre();
        string getEmail();
        string getPassword();
        float getKilometraje();
        int getPuntatore();

        void setNombre(string);
        void setEmail(string);
        void setPassword(string);
        void setKilometraje(float);
        void setPuntatore(int);
        //in
    //in
};

#endif // CLIENTE_H_INCLUDED
