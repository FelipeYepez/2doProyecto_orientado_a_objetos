/*
Felipe Yepez A01658002
Crea la clase Triple que es una de las herencias de habitaciones con su respectivo constructor
que lleva valores default del constructor principal de habitacion
Este clase sera parte de la agregacion a hotel
*/

#ifndef TRIPLE_H
#define TRIPLE_H

#include <Habitaciones.h>
#include <iostream>

using namespace std;

class Triple : public Habitaciones
{
private:
    //posible atributo propio de la clase hija
    bool balcon;

public:
    Triple();
    //constructor de clase hija para poder construir en clase padre con datos predeterminados de la clase hija
    Triple(int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal):Habitaciones(num, cam, cn, tv, cf, micro, frigo, esc)
    {
        balcon = bal;
    }
    string get_balcon();
    string arreglo();
};
//metodo para saber si cuenta o no con balcon
string Triple::get_balcon()
{
    string resp;

    if (balcon == true)
        return resp = "Si";

    else
        return resp = "No";
}
string Triple::arreglo()
{
    stringstream hab;
    hab << "\n Habitacion # " << get_numero() << "\n Tipo: " << get_cama() << "\n Costo por noche: $" << get_costonoche()
         << "\n Cuenta con television " <<  get_television() << "\n Cuenta con caja fuerte: "
         <<  get_cajafuerte() << "\n Cuenta con microondas " <<  get_microondas() << "\n Cuenta con caja frigobar: "
         <<  get_frigobar() << "\n Cuenta con caja escritorio: " <<  get_escritorio() << "\n Cuenta con balcon: "
         <<  get_balcon()
         << "\n" <<  "\n";
    return hab.str();
}
#endif // TRIPLE_H
