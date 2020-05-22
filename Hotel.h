/*
Felipe Yepez A01658002
Crea la clase Hotel con sus respectivos getters para poder acceder
a los atributos privados, crea funciones void para poder implementar la composicion
de las clases habitaciones y reservas para posteriormente poder desplegarlas y ver el
registro que se lleva dentro del hotel
Si se elimina el hotel se eliminan consigo sus clases de composicion
*/

#ifndef HOTEL_H
#define HOTEL_H
#include <iostream>

using namespace std;

#include "reserva.h"
#include <Individual.h>
#include <Doble.h>
#include <Triple.h>
#include <Suite.h>

class Hotel
{
    //atributos privados
private:
    Reserva reser[100];
    Habitaciones habit_i[50];
    Habitaciones habit_d[50];
    Habitaciones habit_t[50];
    Habitaciones habit_s[50];
    int cont_res = 0;
    int cont_hab_i = 0;
    int cont_hab_d = 0;
    int cont_hab_t = 0;
    int cont_hab_s = 0;
    string nombre;
    string ubicacion;
    int pisos;
    int cant_habitaciones;
    bool desayuno;
    bool parqueo;
    bool wifi;

    //metodos publicos
    // no hay setters ya que no hay necesidad de cambiar la informacion del hotel
public:
    Hotel();

    Hotel(string n, string u, int pis, int h, bool d, bool parq, bool wf); //Constructor
    string prueba();
    string get_nombre();
    string get_ubicacion();
    int get_pisos();
    int get_canthabitaciones();
    string get_desayuno();
    string get_parqueo();
    string get_wifi();
    void muestra_hotel();
    void muestra_reservas();
    void muestra_habitaciones();
    void agrega_habitacion(int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc);  //sobrecarga
    void agrega_habitacion_dob(int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal);
    void agrega_habitacion_triple(int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal);
    void agrega_habitacion(int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal, bool sal, bool com);  //sobrecarga
    void agrega_reserva(int a, int n, string fi, string fs, string tipohabres);
};
//constructor vacio
Hotel::Hotel()
{

}
//constructor hotel
Hotel::Hotel(string n, string u, int pis, int h, bool d, bool parq, bool wf)
{

    nombre = n;
    ubicacion= u;
    pisos = pis;
    cant_habitaciones = h;
    desayuno = d;//metodo para saber si cuenta o no con balcon
    parqueo = parq;
    wifi = wf;
}

//metodos de las clases para poder obtener, modificar o ver el estado de la informacion que tienen sus atributos privados
string Hotel::get_nombre()
{
    return nombre;
}

string Hotel::get_ubicacion()
{
    return ubicacion;
}

int Hotel::get_pisos()
{
    return pisos;
}

int Hotel::get_canthabitaciones()
{
    return cant_habitaciones;
}

string Hotel::get_desayuno()
{
    string resp;
    if (desayuno == true)
        return resp = "Si";
    else
        return resp = "No";
}

string Hotel::get_parqueo()
{
    string resp;
    if (parqueo == true)
        return resp = "Si";
    else
        return resp = "No";
}

string Hotel::get_wifi()
{
    string resp;
    if (wifi == true)
        return resp = "Si";
    else
        return resp = "No";
}
string Hotel::prueba()
{
    string a = "Hola";
    return a;
}

//Funcion para imprimir Hotel creado
void Hotel::muestra_hotel()
{
    stringstream h;
    h    << nombre << "\n Ubicacion: " << ubicacion << "\n Numero de pisos: " << pisos
         << "\n Numero de habitaciones: " << cant_habitaciones << "\n Cuenta con desayuno: " <<  get_desayuno()
         << "\n Cuenta con parqueo: " <<  get_parqueo() << "\n Cuenta con wi-fi: " <<  get_wifi() <<  "\n" <<  "\n";
    cout << h.str();
    muestra_habitaciones();
    muestra_reservas();
}

// composicion que llama constructor de clase para crearla dentro de hotel
void Hotel::agrega_habitacion(int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc)
{
    Individual indiv(num, cam, cn, tv, cf, micro, frigo, esc);
    habit_i[cont_hab_i] = indiv;
    cont_hab_i += 1;
}
// composicion que llama constructor de clase para crearla dentro de hotel
void Hotel::agrega_habitacion_dob(int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal)
{
    Doble dob(num, cam, cn, tv, cf, micro, frigo, esc, bal);
    habit_d[cont_hab_d] = dob;
    cont_hab_d += 1;
}
// composicion que llama constructor de clase para crearla dentro de hotel
void Hotel::agrega_habitacion_triple(int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal)
{
    Triple trip(num, cam, cn, tv, cf, micro, frigo, esc, bal);
    habit_t[cont_hab_t] = trip;
    cont_hab_t += 1;
}
// composicion que llama constructor de clase para crearla dentro de hotel
void Hotel::agrega_habitacion(int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal, bool sal, bool com)
{
    Suite sui(num, cam, cn, tv, cf, micro, frigo, esc, bal, sal, com);
    habit_s[cont_hab_s] = sui;
    cont_hab_s += 1;
}
// composicion que llama constructor de clase para crearla dentro de hotel
void Hotel::agrega_reserva(int a, int n, string fi, string fs, string tipohabres)
{
    Reserva reserv(a, n, fi, fs, tipohabres);
    reser[cont_res] = reserv;
    cont_res += 1;
}
//funcion que permite desplegar las reservas creadas a traves de composicion
void Hotel::muestra_reservas()
{
    cout << "RESERVAS: \n";
    for(int i=0; i<cont_res; i++)
    {
        cout << "\t\t" << reser[i].arreglo();
    }
}
//funcion que permite desplegar las habitaciones creadas a traves de composicion
void Hotel::muestra_habitaciones()
{
    if (cont_hab_i > 0)
    {
        cout << "HABITACIONES INDIVIDUALES: \n";
        for(int i=0; i<cont_hab_i; i++)
        {
            cout << "\t\t" << habit_i[i].arreglo();
        }
    }
    if (cont_hab_d > 0)
    {
        cout << "HABITACIONES DOBLES: \n";
        for(int i=0; i<cont_hab_d; i++)
        {
            cout << "\t\t" << habit_d[i].arreglo();
        }
    }
    if (cont_hab_t > 0)
    {
        cout << "HABITACIONES TRIPLES: \n";
        for(int i=0; i<cont_hab_t; i++)
        {
            cout << "\t\t" << habit_t[i].arreglo();
        }
    }
    if (cont_hab_s > 0)
    {
        cout << "SUITES: \n";
        for(int i=0; i<cont_hab_s; i++)
        {
            cout << "\t\t" << habit_s[i].arreglo();
        }
    }
}
#endif // HOTEL_H
