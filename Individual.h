/*
Felipe Yepez A01658002
Crea la clase Individual que es una de las herencias de habitaciones con su respectivo constructor
que lleva valores default del constructor principal de habitacion
Este clase sera parte de la agregacion a hotel
*/

#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <Habitaciones.h>
#include <iostream>

using namespace std;

class Individual : public Habitaciones
{
public:
    Individual();
    //constructor de clase hija para poder construir en clase padre con datos predeterminados de la clase hija
    Individual(int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc):Habitaciones(num, cam, cn, tv, cf, micro, frigo, esc)
    {
    }
};

#endif // INDIVIDUAL_H
