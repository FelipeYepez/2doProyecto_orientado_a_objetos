/*
 *
 * Felipe Yepez A01658002
 * Crea la clase Individual que es una de las herencias de habitaciones con su respectivo constructor
 * que lleva valores default del constructor principal de habitacion
 * Este clase sera parte de la agregacion a hotel
 *
 */

#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "Habitaciones.h"
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
    string arreglo();
};

/**
 * arreglo junta atributos con descripcion
 *
 * @param
 * @return string con la información concatenada
 */
string Individual::arreglo()
{
    stringstream hab;
    hab << "\n Habitacion # " << numero << "\n Tipo: " << cama << "\n Costo por noche: $" << costo_noche
         << "\n Cuenta con television " <<  get_television() << "\n Cuenta con caja fuerte: "
         <<  get_cajafuerte() << "\n Cuenta con microondas " <<  get_microondas() << "\n Cuenta con caja frigobar: "
         <<  get_frigobar() << "\n Cuenta con caja escritorio: " <<  get_escritorio()
         << "\n" <<  "\n";
    return hab.str();
}

#endif // INDIVIDUAL_H
