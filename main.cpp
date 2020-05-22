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
    Hotel hilton("Hilton Garden Inn", "Prol. Av. Zaragoza 99", 8, 88, true, true, true);

    cout << hilton.get_nombre() << "\n Ubicacion: " << hilton.get_ubicacion() << "\n Numero de pisos: " << hilton.get_pisos()
         << "\n Numero de habitaciones: " << hilton.get_canthabitaciones() << "\n Cuenta con desayuno: " <<  hilton.get_desayuno()
         << "\n Cuenta con parqueo: " <<  hilton.get_parqueo() << "\n Cuenta con wi-fi: " <<  hilton.get_wifi() <<  "\n" <<  "\n";

    Doble dob(38, "Individual + Queen", 3200, false, true, false, false, false, false);
    cout << "Habitacion Doble #" << dob.get_numero() << "\n Tipo: " << dob.get_cama() << "\n Costo por noche: $" << dob.get_costonoche()
         << "\n Cuenta con television: " <<  dob.get_television() << "\n Cuenta con caja fuerte: "
         <<  dob.get_cajafuerte() << "\n Cuenta con microondas: " <<  dob.get_microondas() << "\n Cuenta con caja frigobar: "
         <<  dob.get_frigobar() << "\n Cuenta con caja escritorio: " <<  dob.get_escritorio() <<  "\n" <<  "\n";

    Suite presi(50, "King + Queen + Queen + Individual", 30000, true, true, true, true, true, true, true, true);
    cout << "Suite #" << presi.get_numero() << "\n Tipo: " << presi.get_cama() << "\n Costo por noche: $" << presi.get_costonoche()
         << "\n Cuenta con television: " <<  presi.get_television() << "\n Cuenta con caja fuerte: "
         <<  presi.get_cajafuerte() << "\n Cuenta con microondas: " <<  presi.get_microondas() << "\n Cuenta con caja frigobar: "
         <<  presi.get_frigobar() << "\n Cuenta con caja escritorio: " <<  presi.get_escritorio() << "\n Cuenta con balcon: "
         <<  presi.get_balcon() << "\n Cuenta con sala: " <<  presi.get_sala() << "\n Cuenta con comedor: "
         <<  presi.get_comedor()  <<  "\n" <<  "\n";

    Reserva juan(2, 0, "15/11/2019", "19/11/2019", "Doble");
    cout << "Reserva" << "\n Numero de adultos: " << juan.get_adultos() << "\n Numero de ninos: " << juan.get_ninos()
         << "\n Fecha de ingreso: " <<  juan.get_fechai() << "\n Fecha de salida: "
         <<  juan.get_fechas() << "\n Tipo de habitacion: " <<  juan.get_tipo_habitacion_r() <<  "\n" <<  "\n";

    cout <<  "\n" <<  "\n" <<  "\n" <<  "\n";

    //composiciones desde el hotel para crear habitaciones y reservas
    //si se elimina hotel se eliminan composiciones
    //se crea prueba para que se puedan desplegar strings de clase
    hilton.prueba();
    hilton.agrega_habitacion(1, "Individual", 1950, true, false, false, false, false);   //sobrecarga
    hilton.agrega_habitacion_dob(2, "Queen + Queen", 3200, false, true, true, false, false, true);
    hilton.agrega_habitacion_dob(3, "Individual + Individual", 2600, false, false, true, false, false, false);
    hilton.agrega_habitacion_triple(4, "King + Queen + Queen", 4800, true, true, true, true, false, true);
    hilton.agrega_habitacion(100, "King", 18000, true, true, true, true, true, true, true, false);  //sobrecarga
    hilton.agrega_reserva(2, 0, "15/11/2019", "19/11/2019", "Doble");
    hilton.agrega_reserva(1, 2, "22/05/2020", "28/05/2020", "Triple");
    //Al mostrar hotal se muestra su informacion completa incluyendo habitaciones y reservas
    hilton.muestra_hotel();

    return 0;
}
