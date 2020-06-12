/*
 *
 * Felipe Yepez A01658002
 *
 * Programa que permite crear hoteles con diferentes tipos de habitaciones
 * a traves de heredacion y composicion, se pueden generar reservas para
 * poder manejar adecuadamente el hotel.
 *
 */

#include <string.h>
#include <cstdlib>
#include <iostream>
#include "Programa.h"
#include "Hotel.h"
#include "Habitaciones.h"
#include "Reserva.h"

using namespace std;

bool comprueba_bool(string a);

/**
 * comprueba_bool verifica respuestas de usuario 
 *
 * @param
 * @return bool para saber si el usuario respondio si o no
 */
bool comprueba_bool(string a)
{
    if (a == "S" || a == "s")
    {
        return true;
    }
    else if (a == "N" || a == "n")
    {
        return false;
    }
    else
    {
        return false;
    }
}

int main()
{
    Programa principal(0);
    //Se crean casos prueba de un hotel, habitaciones con sus respectivos atributos de herencia y reserva
    principal.agrega_hotel("Hilton Garden Inn", "Prol. Av. Zaragoza 99", 2, true, true, true);
    //composiciones desde programa de hotel para crear habitaciones y reservas
    //si se elimina programa se eliminan composiciones
    //si se elimina hotel se eliminan composiciones

    principal.agrega_habitacion(1, 1, "Individual", 1950, true, false, false, false, false);   //sobrecarga
    principal.agrega_habitacion(1, 2, "Queen", 2350, true, true, false, false, true);
    principal.agrega_habitacion(1, "Queen + Queen", 3, 2900, false, true, true, false, true, false);
    principal.agrega_habitacion(1, "Individual + Individual", 4, 2600, false, false, true, false, false, false);
    principal.agrega_habitacion(1, "King + Individual", 5, 3000, true, false, true, false, false, true);
    principal.agrega_habitacion(1, 6, "King + Queen + Queen", 4800, true, true, true, true, false, true);
    principal.agrega_habitacion(1, 7, "King + Individual + Individual", 4000, true, true, true, true, true, false);
    principal.agrega_habitacion(1, 99, "Queen + Queen + Queen + Queen", 6000, true, true, true, true, true, true, true, false);
    principal.agrega_habitacion(1, 100, "King", 18000, true, true, true, true, true, true, true, false);  //sobrecarga
    principal.agrega_reserva(1, "Bad Bunny", 2, 0, "15/11/2019", "19/11/2019", "Suite");
    principal.agrega_reserva(1, "Pedro Capo", 1, 2, "22/05/2020", "28/05/2020", "Triple");

    int opcion, opcion1, opcion3, opcion3_1, opcion_hotel;

    //parametros hotel
    string nombre, ubicacion, b;
    int pisos;
    bool desayuno, parqueo, wifi;
    //parametros habitaciones
    int num;
    string cam;
    float cn;
    bool tv, cf, micro, frigo, esc, bal, sal, com;
    //parametros reservas
    int a, n;
    string nom, fi, fs, tipohabres;
    //inicia con pantalla limpia
    system("cls");

    do {
        cout << "\n\n----------------------------------" << endl;
        cout << "|        Programa Hoteles        |" << endl;
        cout << "----------------------------------" << endl;
        cout << "| Escoja una opcion:             |" << endl;
        cout << "| 1. Mostrar Hoteles existentes  |" << endl;
        cout << "| 2. Agregar Hotel               |" << endl;
        cout << "| 3. Administrar Hotel           |" << endl;
        cout << "| 4. SALIR                       |" << endl;
        cout << "----------------------------------" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        cout << "\n";

        switch (opcion) {
            case 1:
                system("cls");
                principal.muestra_hoteles();

                do{
                    cout << "\n\n Escoja una opcion:" << endl;
                    cout << "1. Mostrar Habitaciones de un Hotel" << endl;
                    cout << "2. Volver al menu principal" << endl;
                    cin >> opcion1;
                    cout << "\n";
                    switch(opcion1){
                        case 1:
                            system("cls");
                            principal.muestra_nombres_hoteles();
                            cout << "Ingrese el numero del Hotel para mostrar sus habitaciones" << endl;
                            cin >> opcion_hotel;
                            system("cls");
                            principal.muestra_habitacion(opcion_hotel);
                            break;
                        case 2:
                            system("cls");
                            break;
                    }
                    if (opcion1<1 || opcion1>2){
                        cout << "\n Por favor ingrese una opcion valida" << endl;
                    }
                }while (opcion1 != 2);
                break;

            case 2:
                system("cls");
                cout << "\nIngrese nombre del Hotel: " << endl;
                getline(cin >> ws, nombre);
                cout << "Ingrese ubicacion del Hotel: " << endl;
                getline(cin >> ws, ubicacion);
                cout << "Ingrese numero de pisos del Hotel: " << endl;
                cin >> pisos;
                cout << "El Hotel cuenta con desayuno?: S/N" << endl;
                cin >> b;
                desayuno = comprueba_bool(b);
                cout << "El Hotel cuenta con parqueo?: S/N" << endl;
                cin >> b;
                parqueo = comprueba_bool(b);
                cout << "El Hotel cuenta con wifi?: S/N" << endl;
                cin >> b;
                wifi = comprueba_bool(b);

                principal.agrega_hotel(nombre, ubicacion, pisos, desayuno, parqueo, wifi);
                system("cls");
                break;

            case 3:
                system("cls");
                do{
                    cout << "\n\n Escoja una opcion:" << endl;
                    cout << "1. Agregar habitacion de un Hotel" << endl;
                    cout << "2. Realizar reserva en un Hotel" << endl;
                    cout << "3. Mostrar Reservas de un Hotel" << endl;
                    cout << "4. Volver al menu principal" << endl;
                    cin >> opcion3;
                    cout << "\n";
                    switch(opcion3){
                        case 1:
                            system("cls");
                            do{
                                cout << "\n\n Escoja una opcion:" << endl;
                                cout << "1. Agregar habitacion Individual" << endl;
                                cout << "2. Agregar habitacion Doble" << endl;
                                cout << "3. Agregar habitacion Triple" << endl;
                                cout << "4. Agregar Suite" << endl;
                                cout << "5. Regresar" << endl;
                                cin >> opcion3_1;
                                cout << "\n";
                                switch(opcion3_1){
                                    case 1:
                                        system("cls");
                                        principal.muestra_nombres_hoteles();
                                        cout << "Ingrese el numero del Hotel para agregar una habitacion" << endl;
                                        cin >> opcion_hotel;
                                        system("cls");
                                        if (principal.comprobar_hotel(opcion_hotel) == false)
                                        {
                                            cout << "No existe dicho Hotel";
                                            break;
                                        }
                                        cout << "\nIngrese numero de habitacion: " << endl;
                                        cin >> num;
                                        cout << "Ingrese camas con las que cuenta: " << endl;
                                        cout << "         ej. Queen " << endl;
                                        getline(cin >> ws, cam);
                                        cout << "Ingrese costo por noche: " << endl;
                                        cin >> cn;
                                        cout << "Cuenta con TV?: S/N" << endl;
                                        cin >> b;
                                        tv = comprueba_bool(b);
                                        cout << "Cuenta con caja fuerte?: S/N" << endl;
                                        cin >> b;
                                        cf = comprueba_bool(b);
                                        cout << "Cuenta con microondas?: S/N" << endl;
                                        cin >> b;
                                        micro = comprueba_bool(b);
                                        cout << "Cuenta con refrigeradora?: S/N" << endl;
                                        cin >> b;
                                        frigo = comprueba_bool(b);
                                        cout << "Cuenta con escritorio?: S/N" << endl;
                                        cin >> b;
                                        esc = comprueba_bool(b);

                                        principal.agrega_habitacion(opcion_hotel, num, cam, cn, tv, cf, micro, frigo, esc);
                                        system("cls");
                                        break;
                                    case 2:
                                        system("cls");
                                        principal.muestra_nombres_hoteles();
                                        cout << "Ingrese el numero del Hotel para agregar una habitacion" << endl;
                                        cin >> opcion_hotel;
                                        system("cls");
                                        if (principal.comprobar_hotel(opcion_hotel) == false)
                                        {
                                            cout << "No existe dicho Hotel";
                                            break;
                                        }
                                        cout << "\nIngrese numero de habitacion: " << endl;
                                        cin >> num;
                                        cout << "Ingrese camas con las que cuenta: " << endl;
                                        cout << "         ej. Queen + King " << endl;
                                        getline(cin >> ws, cam);
                                        cout << "Ingrese costo por noche: " << endl;
                                        cin >> cn;
                                        cout << "Cuenta con TV?: S/N" << endl;
                                        cin >> b;
                                        tv = comprueba_bool(b);
                                        cout << "Cuenta con caja fuerte?: S/N" << endl;
                                        cin >> b;
                                        cf = comprueba_bool(b);
                                        cout << "Cuenta con microondas?: S/N" << endl;
                                        cin >> b;
                                        micro = comprueba_bool(b);
                                        cout << "Cuenta con refrigeradora?: S/N" << endl;
                                        cin >> b;
                                        frigo = comprueba_bool(b);
                                        cout << "Cuenta con escritorio?: S/N" << endl;
                                        cin >> b;
                                        esc = comprueba_bool(b);
                                        cout << "Cuenta con balcon?: S/N" << endl;
                                        cin >> b;
                                        bal = comprueba_bool(b);

                                        principal.agrega_habitacion(opcion_hotel, cam, num, cn, tv, cf, micro, frigo, esc, bal);
                                        system("cls");
                                        break;

                                    case 3:
                                        system("cls");
                                        principal.muestra_nombres_hoteles();
                                        cout << "Ingrese el numero del Hotel para agregar una habitacion" << endl;
                                        cin >> opcion_hotel;
                                        system("cls");
                                        if (principal.comprobar_hotel(opcion_hotel) == false)
                                        {
                                            cout << "No existe dicho Hotel";
                                            break;
                                        }
                                        cout << "\nIngrese numero de habitacion: " << endl;
                                        cin >> num;
                                        cout << "Ingrese camas con las que cuenta: " << endl;
                                        cout << "         ej. Queen + Queen + King " << endl;
                                        getline(cin >> ws, cam);
                                        cout << "Ingrese costo por noche: " << endl;
                                        cin >> cn;
                                        cout << "Cuenta con TV?: S/N" << endl;
                                        cin >> b;
                                        tv = comprueba_bool(b);
                                        cout << "Cuenta con caja fuerte?: S/N" << endl;
                                        cin >> b;
                                        cf = comprueba_bool(b);
                                        cout << "Cuenta con microondas?: S/N" << endl;
                                        cin >> b;
                                        micro = comprueba_bool(b);
                                        cout << "Cuenta con refrigeradora?: S/N" << endl;
                                        cin >> b;
                                        frigo = comprueba_bool(b);
                                        cout << "Cuenta con escritorio?: S/N" << endl;
                                        cin >> b;
                                        esc = comprueba_bool(b);
                                        cout << "Cuenta con balcon?: S/N" << endl;
                                        cin >> b;
                                        bal = comprueba_bool(b);

                                        principal.agrega_habitacion(opcion_hotel, num, cam, cn, tv, cf, micro, frigo, esc, bal);
                                        system("cls");
                                        break;

                                    case 4:
                                        system("cls");
                                        principal.muestra_nombres_hoteles();
                                        cout << "Ingrese el numero del Hotel para agregar una habitacion" << endl;
                                        cin >> opcion_hotel;
                                        system("cls");
                                        if (principal.comprobar_hotel(opcion_hotel) == false)
                                        {
                                            cout << "No existe dicho Hotel";
                                            break;
                                        }
                                        cout << "\nIngrese numero de habitacion: " << endl;
                                        cin >> num;
                                        cout << "Ingrese camas con las que cuenta: " << endl;
                                        cout << "         ej. Queen + Queen + King " << endl;
                                        getline(cin >> ws, cam);
                                        cout << "Ingrese costo por noche: " << endl;
                                        cin >> cn;
                                        cout << "Cuenta con TV?: S/N" << endl;
                                        cin >> b;
                                        tv = comprueba_bool(b);
                                        cout << "Cuenta con caja fuerte?: S/N" << endl;
                                        cin >> b;
                                        cf = comprueba_bool(b);
                                        cout << "Cuenta con microondas?: S/N" << endl;
                                        cin >> b;
                                        micro = comprueba_bool(b);
                                        cout << "Cuenta con refrigeradora?: S/N" << endl;
                                        cin >> b;
                                        frigo = comprueba_bool(b);
                                        cout << "Cuenta con escritorio?: S/N" << endl;
                                        cin >> b;
                                        esc = comprueba_bool(b);
                                        cout << "Cuenta con balcon?: S/N" << endl;
                                        cin >> b;
                                        bal = comprueba_bool(b);
                                        cout << "Cuenta con sala?: S/N" << endl;
                                        cin >> b;
                                        sal = comprueba_bool(b);
                                        cout << "Cuenta con comedor?: S/N" << endl;
                                        cin >> b;
                                        com = comprueba_bool(b);

                                        principal.agrega_habitacion(opcion_hotel, num, cam, cn, tv, cf, micro, frigo, esc, bal, sal, com);
                                        system("cls");
                                        break;

                                    case 5:
                                        system("cls");
                                        break;
                                }
                                if (opcion3_1<1 || opcion3_1>5){
                                    cout << "\n Por favor ingrese una opcion valida" << endl;
                                }
                            }while (opcion3_1 != 5);
                            break;

                        case 2:
                            system("cls");
                            principal.muestra_nombres_hoteles();
                            cout << "Ingrese el numero del Hotel para agregar una reserva" << endl;
                            cin >> opcion_hotel;
                            system("cls");
                            if (principal.comprobar_hotel(opcion_hotel) == false)
                            {
                                cout << "No existe dicho Hotel";
                                break;
                            }
                            cout << "\nReserva a nombre de: " << endl;
                            cin >> nom;
                            cout << "Cuantos adultos?: " << endl;
                            cin >> a;
                            cout << "Cuantos menores de edad? (-18): " << endl;
                            cin >> n;
                            cout << "Fecha de ingreso?: " << endl;
                            cout << "         ej. 06/08/2020 " << endl;
                            getline(cin >> ws, fi);
                            cout << "Fecha de salida?: " << endl;
                            cout << "         ej. 08/08/2020 " << endl;
                            getline(cin >> ws, fs);
                            cout << "Habitacion a reservar?: " << endl;
                            cout << "         ej. Suite " << endl;
                            cin >> tipohabres;

                            principal.agrega_reserva(opcion_hotel, nom, a, n, fi, fs, tipohabres);
                            system("cls");
                            break;

                        case 3:
                            system("cls");
                            principal.muestra_nombres_hoteles();
                            cout << "Ingrese el numero del Hotel para mostrar reservas" << endl;
                            cin >> opcion_hotel;
                            system("cls");
                            if (principal.comprobar_hotel(opcion_hotel) == false)
                            {
                                cout << "No existe dicho Hotel";
                                break;
                            }
                            principal.muestra_reservas(opcion_hotel);
                            break;

                        case 4:
                            system("cls");
                            break;
                    }
                    if (opcion3<1 || opcion3>4){
                        cout << "\n Por favor ingrese una opcion valida" << endl;
                    }
                }while (opcion3 != 4);
                break;
        }
        if (opcion<1 || opcion>4){
            cout << "\n Por favor ingrese una opcion valida" << endl;
        }
    } while (opcion != 4);

    return 0;
}
