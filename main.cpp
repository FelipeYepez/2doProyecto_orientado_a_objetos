/*
Felipe Yepez A01658002

Programa que permite crear hoteles con diferentes tipos de habitaciones
a traves de heredacion y composicion, se pueden generar reservas para
poder manejar adecuadamente el hotel.

*/

#include <iostream>
#include <Hotel.h>
#include <Habitaciones.h>
#include <Reserva.h>

using namespace std;

int main()
{
    //Se crean casos prueba de un hotel, dos habitaciones con sus respectivos atributos de herencia y una reserva
    Hotel hilton("Hilton Garden Inn", "Prol. Av. Zaragoza 99", 2, 9, true, true, true);

    //composiciones desde el hotel para crear habitaciones y reservas
    //si se elimina hotel se eliminan composiciones
    //se crea prueba para que se puedan desplegar strings de clase
    hilton.prueba();
    hilton.agrega_habitacion(1, "Individual", 1950, true, false, false, false, false);   //sobrecarga
    hilton.agrega_habitacion(2, "Queen", 2350, true, true, false, false, true);
    hilton.agrega_habitacion_dob(3, "Queen + Queen", 2900, false, true, true, false, true, false);
    hilton.agrega_habitacion_dob(4, "Individual + Individual", 2600, false, false, true, false, false, false);
    hilton.agrega_habitacion_dob(5, "King + Individual", 3000, true, false, true, false, false, true);
    hilton.agrega_habitacion_triple(6, "King + Queen + Queen", 4800, true, true, true, true, false, true);
    hilton.agrega_habitacion_triple(7, "King + Individual + Individual", 4000, true, true, true, true, true, false);
    hilton.agrega_habitacion(99, "Queen + Queen + Queen + Queen", 6000, true, true, true, true, true, true, true, false);
    hilton.agrega_habitacion(100, "King", 18000, true, true, true, true, true, true, true, false);  //sobrecarga
    hilton.agrega_reserva("Bad Bunny", 2, 0, "15/11/2019", "19/11/2019", "Suite");
    hilton.agrega_reserva("Pedro Capo", 1, 2, "22/05/2020", "28/05/2020", "Triple");
    //Al mostrar hotal se muestra su informacion completa incluyendo habitaciones y reservas
    hilton.muestra_hotel();


    return 0;
}
