/*
*
* Felipe Yepez A01658002
* Crea la clase Hotel con sus respectivos getters para poder acceder
* a los atributos privados, crea funciones void para poder implementar la composicion
* de las clases habitaciones y reservas para posteriormente poder desplegarlas y ver el
* registro que se lleva dentro del hotel
* Si se elimina el hotel se eliminan consigo sus clases de composicion
*
*/

#ifndef HOTEL_H
#define HOTEL_H
#include <iostream>

using namespace std;

#include "Reserva.h"
#include "Individual.h"
#include "Doble.h"
#include "Triple.h"
#include "Suite.h"

class Hotel
{
    //atributos privados
private:
    Reserva reser[100];
    Habitaciones *habit_i[50];
    Habitaciones *habit_d[50];
    Habitaciones *habit_t[50];
    Habitaciones *habit_s[50];
    int cont_res = 0;
    int cont_hab_i = 0;
    int cont_hab_d = 0;
    int cont_hab_t = 0;
    int cont_hab_s = 0;
    string nombre;
    string ubicacion;
    int pisos;
    int cant_habitaciones = 0;
    bool desayuno;
    bool parqueo;
    bool wifi;

    //metodos publicos
    // no hay setters ya que no hay necesidad de cambiar la informacion del hotel
public:
    Hotel();

    Hotel(string n, string u, int pis, bool d, bool parq, bool wf); //Constructor
    ~Hotel()
    {
        for(int i=0; i<cont_hab_i; i++)
        {
            delete habit_i[i];
        }
        for(int i=0; i<cont_hab_d; i++)
        {
            delete habit_d[i];
        }
        for(int i=0; i<cont_hab_t; i++)
        {
            delete habit_t[i];
        }
        for(int i=0; i<cont_hab_s; i++)
        {
            delete habit_s[i];
        }

    }
    string get_nombre();
    string get_ubicacion();
    int get_pisos();
    int get_canthabitaciones();
    string get_desayuno();
    string get_parqueo();
    string get_wifi();
    string muestra_hotel();
    void muestra_reservas();
    void muestra_habitaciones();
    void agrega_habitacion(int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc);  //sobrecarga
    void agrega_habitacion(string cam, int num, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal);
    void agrega_habitacion(int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal);
    void agrega_habitacion(int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal, bool sal, bool com);  //sobrecarga
    void agrega_reserva(string nom, int a, int n, string fi, string fs, string tipohabres);
};
//constructor vacio
Hotel::Hotel()
{

}
//constructor hotel
Hotel::Hotel(string n, string u, int pis, bool d, bool parq, bool wf)
{
    nombre = n;
    ubicacion= u;
    pisos = pis;
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

/**
 * muestra_hotel junta atributos de hotel con descripcion
 *
 * @param
 * @return string con la información concatenada
 */
string Hotel::muestra_hotel()
{
    stringstream h;
    h    << "Nombre: " << nombre << "\n Ubicacion: " << ubicacion << "\n Numero de pisos: " << pisos
         << "\n Numero de habitaciones: " << cant_habitaciones << "\n Cuenta con desayuno: " <<  get_desayuno()
         << "\n Cuenta con parqueo: " <<  get_parqueo() << "\n Cuenta con wi-fi: " <<  get_wifi() <<  "\n" <<  "\n";
    return h.str();
}

/**
 * agrega_habitacion genera y guarda habitacion individual
 *
 * genera objeto de tipo Habitacion Individual y los
 * guarda en el arreglo habit_i[] (arreglo de habitaciones)
 * composicion que llama constructor de clase para crearla dentro de hotel
 *
 * @param todos los parametros para crear habitacion individual
 * @return
 */
void Hotel::agrega_habitacion(int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc)
{
    habit_i[cont_hab_i] = new Individual(num, cam, cn, tv, cf, micro, frigo, esc);
    cont_hab_i += 1;
    cant_habitaciones += 1;
}


/**
 * agrega_habitacion genera y guarda habitacion doble
 *
 * genera objeto de tipo Habitacion Doble y los
 * guarda en el arreglo habit_d[] (arreglo de habitaciones)
 * composicion que llama constructor de clase para crearla dentro de hotel
 *
 * @param todos los parametros para crear habitacion doble
 * @return
 */
void Hotel::agrega_habitacion(string cam, int num, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal)
{
    habit_d[cont_hab_d] = new Doble(num, cam, cn, tv, cf, micro, frigo, esc, bal);
    cont_hab_d += 1;
    cant_habitaciones += 1;
}

/**
 * agrega_habitacion genera y guarda habitacion triple
 *
 * genera objeto de tipo Habitacion Triple y los
 * guarda en el arreglo habit_t[] (arreglo de habitaciones)
 * composicion que llama constructor de clase para crearla dentro de hotel
 *
 * @param todos los parametros para crear habitacion triple
 * @return
 */
void Hotel::agrega_habitacion(int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal)
{
    habit_t[cont_hab_t] = new Triple(num, cam, cn, tv, cf, micro, frigo, esc, bal);
    cont_hab_t += 1;
    cant_habitaciones += 1;
}

/**
 * agrega_habitacion genera y guarda habitacion Suite
 *
 * genera objeto de tipo Habitacion Suite y los
 * guarda en el arreglo habit_s[] (arreglo de habitaciones)
 * composicion que llama constructor de clase para crearla dentro de hotel
 *
 * @param todos los parametros para crear habitacion suite
 * @return
 */
void Hotel::agrega_habitacion(int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal, bool sal, bool com)
{
    habit_s[cont_hab_s] = new Suite(num, cam, cn, tv, cf, micro, frigo, esc, bal, sal, com);
    cont_hab_s += 1;
    cant_habitaciones += 1;
}

/**
 * agrega_reserva genera y guarda reservas
 *
 * genera objeto de tipo Reserva y los
 * guarda en el arreglo reser (arreglo de reserva)
 * composicion que llama constructor de clase para crearla dentro de hotel
 *
 * @param todos los parametros para crear reserva
 * @return
 */
void Hotel::agrega_reserva(string nom, int a, int n, string fi, string fs, string tipohabres)
{
    Reserva reserv(nom, a, n, fi, fs, tipohabres);
    reser[cont_res] = reserv;
    cont_res += 1;
}


/**
 * muestra_reservas verifica si existen reservas para desplegarlas
 *
 * Ciclo que recorre el arreglo e imprime cada reserva con su informacion concatenada.
 * funcion que permite desplegar las reservas creadas a traves de composicion
 *
 * @param 
 * @return
 */
void Hotel::muestra_reservas()
{
    if (cont_res == 0){
        cout << "El Hotel no cuenta con reservas creadas hasta el momento";
    }
    for(int i=0; i<cont_res; i++)
    {
        cout << "\t\t" << reser[i].arreglo();
    }
}

/**
 * muestra_habitaciones verifica si existen habitaciones para desplegarlas
 *
 * Ciclo que recorre cada arreglo de habitaciones e imprime cada habitacion con su 
 * informacion concatenada mediante polimorfismo.
 * funcion que permite desplegar las habitaciones creadas a traves de composicion
 *
 * @param 
 * @return
 */
void Hotel::muestra_habitaciones()
{
    if (cant_habitaciones == 0){
        cout << "El Hotel no cuenta con habitaciones creadas hasta el momento";
    }
    if (cont_hab_i > 0)
    {
        cout << "\n \n" << "\t\t" << "HABITACIONES INDIVIDUALES: \n";
        for(int i=0; i<cont_hab_i; i++)
        {
            cout << "\t\t" << habit_i[i] -> arreglo(); //aplicacion de polimorfismo con apuntadores
        }
    }
    if (cont_hab_d > 0)
    {
        cout << "\n \n" << "\t\t" << "HABITACIONES DOBLES: \n";
        for(int i=0; i<cont_hab_d; i++)
        {
            cout << "\t\t" << habit_d[i] -> arreglo(); //aplicacion de polimorfismo con apuntadores
        }
    }
    if (cont_hab_t > 0)
    {
        cout << "\n \n" << "\t\t" << "HABITACIONES TRIPLES: \n";
        for(int i=0; i<cont_hab_t; i++)
        {
            cout << "\t\t" << habit_t[i] -> arreglo(); //aplicacion de polimorfismo con apuntadores
        }
    }
    if (cont_hab_s > 0)
    {
        cout << "\n \n" << "\t\t" << "SUITES: \n";
        for(int i=0; i<cont_hab_s; i++)
        {
            cout << "\t\t" << habit_s[i] -> arreglo(); //aplicacion de polimorfismo con apuntadores
        }
    }
}
#endif // HOTEL_H
