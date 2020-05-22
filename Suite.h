/*
Felipe Yepez A01658002
Crea la clase Suite que es una de las herencias de habitaciones con su respectivo constructor
que lleva valores default del constructor principal de habitacion
Este clase sera parte de la agregacion a hotel
*/

#ifndef SUITE_H
#define SUITE_H

#include <Habitaciones.h>
#include <iostream>

using namespace std;

class Suite : public Habitaciones
{
private:
    //posibles atributos propios de la clase hija
    bool balcon;
    bool sala;
    bool comedor;

public:
    //constructor de clase hija para poder construir en clase padre con datos predeterminados de la clase hija
    Suite(int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal, bool sal, bool com):Habitaciones(num, cam, cn, tv, cf, micro, frigo, esc)
    {
        balcon = bal;
        sala = sal;
        comedor = com;
    }
    //no se requieren setters para cambiar datos fisicos de suite
    string get_balcon();
    string get_sala();
    string get_comedor();
};
//metodos para saber si cuenta o no con distintos atributos
string Suite::get_balcon()
{
    string resp;

    if (balcon == true)
        return resp = "Si";

    else
        return resp = "No";
}

string Suite::get_sala()
{
    string resp;

    if (sala == true)
        return resp = "Si";

    else
        return resp = "No";
}

string Suite::get_comedor()
{
    string resp;

    if (comedor == true)
        return resp = "Si";

    else
        return resp = "No";
}

#endif // SUITE_H
