#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include "Sistema.h"
#include <cstdio>

using namespace std;
Sistema s;
ifstream fileA;
ofstream fileC;
string linea;

void fillObj (string matrix[40][5])
{
    int countV = 0;
    for (int countAE = 0; countAE < 5; countAE++)
    {
        for (int ren = 0; ren < 40; ren = ren + 8)
        {
            //string
            s.listaAerolineas[countAE].listaVuelos[countV].setCodigoVuelo(matrix[ren][countAE]);
            //int
            int a = 0;
            stringstream b(matrix[ren+1][countAE]);
            b >> a;
            s.listaAerolineas[countAE].listaVuelos[countV].setNumeroAsientoDisponibles(a);
            //int
            int c = 0;
            stringstream d(matrix[ren+2][countAE]);
            d >> c;
            s.listaAerolineas[countAE].listaVuelos[countV].setTimeToDestination(c);
            //int
            int e = 0;
            stringstream f(matrix[ren+3][countAE]);
            f >> e;
            s.listaAerolineas[countAE].listaVuelos[countV].setHour(e);
            //string
            s.listaAerolineas[countAE].listaVuelos[countV].setDestination(matrix[ren+4][countAE]);
            //string
            s.listaAerolineas[countAE].listaVuelos[countV].setDate(matrix[ren+5][countAE]);
            //float
            float g = 0;
            stringstream h(matrix[ren+6][countAE]);
            h >> g;
            s.listaAerolineas[countAE].listaVuelos[countV].setDistance(g);
            //float
            float i = 0;
            stringstream l(matrix[ren+7][countAE]);
            l >> i;
            s.listaAerolineas[countAE].listaVuelos[countV].setPrice(i);
            countV++;
            if (countV > 4) countV = 0;
        }
    }
}

string fillMatrix(string matrix[40][5], string line)
{
    fileA.open("aerolinea.txt");
    int col = 0;
    if (fileA.fail())
    {
        cout << "El archivo no se pudo abrir <3>" << endl;
    }
    while (true)
    {
        if (fileA.eof()) break;
        for (int i = 0; i <= 39; i++)
        {
            getline(fileA, line);
            matrix[i][col] = line;
        }
        col ++;
        if (col > 4)
        {
            break;
        }
    }
    fillObj(matrix);
    fileA.close();
    return matrix[40][5];
}

void c_Client(string nome, string email, string password, float km)
{
    //string
    s.client.setNombre(nome);
    //string
    s.client.setEmail(email);
    //string
    s.client.setPassword(password);
    //float
    s.client.setKilometraje(km);

    cout << "Name: " << s.client.getNombre() << endl;
}

bool checkdate(int m, int d, int y)
{
  if (! (1<= m && m<=12) )
     return false;
  if (! (1<= d && d<=31) )
     return false;
  if ( (d==31) && (m==2 || m==4 || m==6 || m==9 || m==11) )
     return false;
  if ( (d==30) && (m==2) )
     return false;
  if ( (m==2) && (d==29) && (y%4!=0) )
     return false;
  if ( (m==2) && (d==29) && (y%400==0) )
     return true;
  if ( (m==2) && (d==29) && (y%100==0) )
     return false;
  if ( (m==2) && (d==29) && (y%4==0)  )
     return true;

  return true;
}

void writeDate(string dat, string ans)
{
    cout << "Porfavor elige una data" << endl;
    while (true)
    {
        cout << "Poner la data como DD/MM/AAAA: ";
        cin >> dat;
        if (dat.size() == 10)
        {
            string day = dat.substr(0,2);
            string month = dat.substr(3,2);
            string year = dat.substr(6,4);
            stringstream g(day);
            int d, m, y;
            g >> d;
            stringstream j(month);
            j >> m;
            stringstream k(year);
            k >> y;
            if (checkdate(d, m, y) == 1)
            {
                s.setDateSelected(dat);
                break;
            }
        }
    }
}

void printVuelo(int lista[5], int c, int counting)
{
    int conteggio = 0;
    conteggio = (lista[counting])/8;
    cout << counting <<"- \tFlight ID: " << s.listaAerolineas[c].getCodigoAerolinea();
    cout << s.listaAerolineas[c].listaVuelos[conteggio].getCodigoVuelo() << endl;
    cout << "\tDestination: " << s.listaAerolineas[c].listaVuelos[conteggio].getDestination();
    cout << "\t\tDepart: " << s.listaAerolineas[c].listaVuelos[conteggio].getHour();
    cout << "\n\tDistance in km: " << s.listaAerolineas[c].listaVuelos[conteggio].getDistance();
    cout << "\t\tPrice in Euro: " << s.listaAerolineas[c].listaVuelos[conteggio].getPrice() << endl << endl;
}

void printTicket(int lista[5], int c, int counting)
{
    cout << "\nNombre: " << s.client.getNombre() << endl;
    printVuelo(lista, c, counting);
}

void replaceData(float kms)
{
    int punt = s.client.getPuntatore();
    int a = 1;
    fileA.open("cliente.txt");
    fileC.open("tmp.txt", ios::app); //crea un archivo provisorio
    if (fileA.fail()) cout << "Error in opening the file <4>" << endl;
    while ( a < punt)
    {
        getline(fileA, linea);
        fileC << linea << endl;
        a++;
    }
    fileC << kms;
    getline(fileA, linea);
    while ( !fileA.eof())
    {
        getline(fileA, linea);
        fileC << endl << linea;
    }
    fileA.close();
    fileC.close();

    char oldname[] = "tmp.txt";
    char newname[] = "cliente.txt";
    if (remove(newname) == 0) //elimina el viejo archivo
    {
        if (rename(oldname, newname) != 0) cout << "Error: the file couldn't be renamed" << endl; //renombra el nuevo
    }
    else if (remove(newname) != 0) perror("File error");
}

int checkMatrix(string matri[40][5], int c, int lista[5], string ans)
{
    int counting = 0, numVnD = 0;
    lista[0] = 1;
    lista[1] = 1;
    lista[2] = 1;
    lista[3] = 1;
    lista[4] = 1;

    for (int h = 5; h < 40; h = h + 8)
    {
        ans = matri[h][c];
        if (ans == s.getDateSelected())
        {
            ans = matri[h-4][c];
            int result = 0;
            stringstream g(ans);
            g >> result;
            if (result >= 1 )
            {
                lista[counting] = h-5;
                counting ++;
            }
            else if (result == 0)
            {
                numVnD ++;
            }
        }
        else
        {
            numVnD ++;
        }
        if (numVnD >= 5)
        {
            cout << "No hay vuelos disponibles en la fecha seleccionada" << endl;
            break;
        }
    }
    if (numVnD < 5)
    {
        //mostra lista voli
        counting = 0;
        while (lista[counting] != 1)
        {
            printVuelo(lista, c, counting);
            counting++;
            if (counting > 5) break;
        }

        int respuesta = 7;
        while (respuesta > counting)
        {
            cout << "Porfavor elige un vuelo <0, ..., 4> or <9> to exit: ";
            cin >> respuesta;
            if (respuesta < counting)
            {
                printVuelo(lista, c, respuesta);
                cout << "Confirmar vuelo? <S N>: ";
                cin >> ans;
                if (ans == "S")
                {
                    int numAD = s.listaAerolineas[c].listaVuelos[(lista[respuesta])/8].getNumeroAsientoDisponibles();
                    numAD = numAD - 1;
                    s.listaAerolineas[c].listaVuelos[(lista[respuesta])/8].setNumeroAsientoDisponibles(numAD);
                    cout << "Print in <remove 1 seat from flight>: " << numAD << endl;
                    //adjunta kilometros al cliente
                    float kmToAdd = 0.0;
                    kmToAdd = s.listaAerolineas[c].listaVuelos[(lista[respuesta])/8].getDistance();
                    kmToAdd = kmToAdd + (s.client.getKilometraje());
                    s.client.setKilometraje(kmToAdd);
                    //aplica descuento
                    if (s.client.getKilometraje() >= s.getLimiteKilometraje())
                    {
                        float precio = 0.0;
                        precio = s.listaAerolineas[c].listaVuelos[(lista[respuesta])/8].getPrice();
                        int descuento = s.getDescuento();
                        precio = precio - (precio * s.aplicaDescuento(descuento));
                        s.listaAerolineas[c].listaVuelos[(lista[respuesta])/8].setPrice(precio);
                        //show ticket
                        counting --;
                        printTicket(lista, c, counting);
                        //replace old data with new data;
                        replaceData(kmToAdd);
                    }
                    else if (s.client.getKilometraje() < s.getLimiteKilometraje())
                    {
                        counting --;
                        printTicket(lista, c, counting);
                        replaceData(kmToAdd);
                    }
                }
                else if (ans == "N") break;
            }
            if (respuesta == 9) break;
        }
    }
    return lista[5];
}

int writeAerolinea(string ans, string date, string matrix[40][5], int listaVD[5])
{
    ans = "R";
    int c;
    cout << "Elegir una aerolinea: " << endl;
    while (ans != "AM" && ans != "AF" && ans != "IB" && ans != "LH" && ans != "AZ")
    {
        cout << "AeroMexico <AM>, AirFrance <AF>, Iberia <IB>, Lufthansa <LH>, Alitalia <AZ>";
        cout << "<E> si quiere salir" << endl;
        cin >> ans;

        if (ans == "AM")
        {
            //primera columna de la matriz
            c = 0;
            s.listaAerolineas[c].setCodigoAerolinea(ans);
            writeDate(date, ans);
            checkMatrix(matrix, c, listaVD, ans);
        }
        else if (ans == "AF")
        {
            //segunda columna de la matriz
            c = 1;
            s.listaAerolineas[1].setCodigoAerolinea(ans);
            writeDate(date, ans);
            checkMatrix(matrix, c, listaVD, ans);
        }
        else if (ans == "IB")
        {
            //tercera columna de la matriz
            c = 2;
            s.listaAerolineas[2].setCodigoAerolinea(ans);
            writeDate(date, ans);
            checkMatrix(matrix, c, listaVD, ans);
        }
        else if (ans == "LH")
        {
            //cuarta columna de la matriz
            c = 3;
            s.listaAerolineas[3].setCodigoAerolinea(ans);
            writeDate(date, ans);
            checkMatrix(matrix, c, listaVD, ans);
        }
        else if (ans == "AZ")
        {
            //quinta columna de la matriz
            c = 4;
            s.listaAerolineas[4].setCodigoAerolinea(ans);
            writeDate(date, ans);
            checkMatrix(matrix, c, listaVD, ans);
        }
        else if (ans == "E") break;
    }
    return listaVD[5];
}

int main()
{
    // Variables
    int varfind = 0, contador = 0;
    float kilom = 0.0;
    string dateS, name, em, pass, codeAe, destinacion, codeV, data, linea;

    string answer = "A";
    string m_AM[40][5];
    int listaVD[5];
    listaVD[0] = 1;
    listaVD[1] = 1;
    listaVD[2] = 1;
    listaVD[3] = 1;
    listaVD[4] = 1;

    //inicio programma
    cout << "--- Sistema de reservacion en linea ---\n" << endl;

    fillMatrix(m_AM, linea);
    fileA.open("cliente.txt");
    if (fileA.fail())
    {
        cout << "El file no se pudo abrir [0]" << endl;
        fileC.close();
        cout << "File creado" << endl;
    }
    fileA.close();
    while (true)
    {
        cout << "Nuevo cliente? <S N, E to exit>: ";
        cin >> answer;
        kilom = s.client.getKilometraje();
        if (answer == "S")
        {
            cout << "Poner solo el primer nombre: ";
            cin >> name;
            cout << "Correo electronico: ";
            cin >> em;
            cout << "Clave de acceso: ";
            cin >> pass;
            while (true)
            {
                fileA.open("cliente.txt");
                getline(fileA,linea);
                varfind = linea.find(name);
                if (varfind == 0) //if name is found
                {
                    getline(fileA,linea);
                    varfind = linea.find(em);
                    if (varfind == 0) //if email is found
                    {
                        cout << "Cliente ya registrado" << endl;
                        fileA.close();
                        break;
                    }
                    else //not found
                    {
                        fileC.open("cliente.txt", ios::app);
                        fileC << name << "\n" << em << "\n" << pass << "\n" << kilom << endl;
                        fileC.close();
                        cout << "Cliente registrado" << endl;
                        c_Client(name, em, pass, kilom);
                        fileA.close();
                        break;
                    }
                }
                else
                {
                    fileC.open("cliente.txt", ios::app);
                    fileC << name << "\n" << em << "\n" << pass << "\n" << kilom << endl;
                    fileC.close();
                    cout << "Cliente registrado" << endl;
                    fileA.close();
                    c_Client(name, em, pass, kilom);
                    break;
                }
            }
        }
        else if (answer == "N")
        {
            cout << "Correo electronico: ";
            cin >> em;
            cout << "Clave de acceso: ";
            cin >> pass;
            fileA.open("cliente.txt");
            if (fileA.fail())
            {
                cout << "El file no se pudo abrir <2>" << endl;
            }
            else
            {
                while (true)
                {
                    getline(fileA, linea);
                    contador ++;
                    name = linea;
                    getline(fileA, linea);
                    contador ++;
                    varfind = linea.find(em);
                    if (varfind == 0) //if email is found
                    {
                        getline(fileA, linea);
                        contador ++;
                        varfind = linea.find(pass);
                        if (varfind == 0) //if password is found
                        {
                            //Inicia reservacion
                            contador ++;
                            s.client.setPuntatore(contador);
                            s.client.setNombre(name);
                            s.client.setEmail(em);
                            s.client.setPassword(pass);
                            getline(fileA, linea);
                            stringstream intoKm(linea);
                            intoKm >> kilom;
                            fileA.close();
                            s.client.setKilometraje(kilom);
                            dateS = s.getDateSelected();
                            writeAerolinea(answer, dateS, m_AM, listaVD);
                            contador = 0;
                            break;
                        }
                    }

                    if (fileA.eof() || linea == "")
                    {
                        cout << "Cliente no registrato" << endl;
                        fileA.close();
                        break;
                    }
                }
            }
        }

        else if(answer == "E") break;
        else
        {
            cout << "Solo se aceptan <S> o <N> como respuesta" << endl;
        }
    }
    return 0;
}

//end
