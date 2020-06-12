/*
 *
 * Felipe Yepez A01658002
 * Crea la clase Programa como base de datos para guardar hoteles con todo
 * lo que estan compuestos, se hace composicion de clase Hotel
 * Si se elimina el Programa se eliminan consigo todos los hoteles, habitaciones y reservas
 *
 */

#ifndef PROGRAMA_H
#define PROGRAMA_H
#include <iostream>

using namespace std;

#include "Hotel.h"

class Programa
{
    private:
        Hotel hoteles[100];
        int cont_hoteles = 0;

    public:
        Programa(); //Constructor
        Programa(int c){cont_hoteles=c;};
        void agrega_hotel(string n, string u, int pis, bool d, bool parq, bool wf);
        void muestra_hoteles();
        void muestra_nombres_hoteles();
        bool comprobar_hotel(int hotel_n);
        void agrega_habitacion(int hotel_n, int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc);  //sobrecarga
        void agrega_habitacion(int hotel_n, string cam, int num, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal);
        void agrega_habitacion(int hotel_n, int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal);
        void agrega_habitacion(int hotel_n, int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal, bool sal, bool com);
        void muestra_habitacion(int hotel_n);
        void agrega_reserva(int hotel_n, string nom, int a, int n, string fi, string fs, string tipohabres);
        void muestra_reservas(int hotel_n);
};

/**
 * agrega_hotel genera y guarda hotel
 *
 * genera objeto de tipo Hotel y lo guarda en el arreglo hoteles[] (arreglo de hotel)
 *
 * @param todos los parametros para crear hotel
 * @return
 */
void Programa::agrega_hotel(string n, string u, int pis, bool d, bool parq, bool wf)
{
    Hotel hot(n, u, pis, d, parq, wf);
    hoteles[cont_hoteles] = hot;
    cont_hoteles += 1;
}

/**
 * muestra_hoteles despliega hoteles creados
 *
 * Ciclo que recorre el arreglo hoteles[] e imprime cada hotel con su informacion concatenada.
 *
 * @param 
 * @return
 */
void Programa::muestra_hoteles()
{
    for (int i=0; i<cont_hoteles; i++)
    {
        cout << "--HOTEL #" << i+1 << endl;
        string info_hotel;
        info_hotel = hoteles[i].muestra_hotel();
        cout << info_hotel;
    }
}

/**
 * muestra_nombres_hoteles despliega tan solo nombres de hoteles creados para facilitar
 * informaci[on al usuario cuando desee administrar hoteles
 *
 * Ciclo que recorre el arreglo hoteles[] e imprime cada hotel con su informacion concatenada.
 *
 * @param
 * @return
 */
void Programa::muestra_nombres_hoteles()
{
    for (int i=0; i<cont_hoteles; i++)
    {
        cout << "--HOTEL #" << i+1 << ": ";
        cout << hoteles[i].get_nombre() << endl;
    }
}

/**
 * comprobar_hotel verifica si existe hotel que se desea elegir para realizar operaciones 
 * Busca en el arreglo que almacena a cada Hotel
 *
 * @param int hotel_n es el numero que toma cada hotel, su numero es el indice del arreglo
 * en el que se encuentra sumado uno
 * @return bool para saber si existe o no
 */
bool Programa::comprobar_hotel(int hotel_n)
{
    hotel_n = hotel_n - 1;
    if (hoteles[hotel_n].get_nombre() == "")
    {
        return false;
    }
    else
        {
            return true;
        }
}

/**
 * agrega_habitacion genera y guarda habitacion individual
 *
 * composicion que llama constructor de clase hotel para crearla desde programa
 *
 * @param todos los parametros para crear habitacion individual
 * @return
 */
void Programa::agrega_habitacion(int hotel_n, int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc)
{
    hotel_n = hotel_n - 1;
    hoteles[hotel_n].agrega_habitacion(num, cam, cn, tv, cf, micro, frigo, esc);
}

/**
 * agrega_habitacion genera y guarda habitacion doble
 *
 * composicion que llama constructor de clase hotel para crearla desde programa
 *
 * @param todos los parametros para crear habitacion doble
 * @return
 */
void Programa::agrega_habitacion(int hotel_n, string cam, int num, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal)
{
    hotel_n = hotel_n - 1;
    hoteles[hotel_n].agrega_habitacion(cam, num, cn, tv, cf, micro, frigo, esc, bal);
}

/**
 * agrega_habitacion genera y guarda habitacion triple
 *
 * composicion que llama constructor de clase hotel para crearla desde programa
 *
 * @param todos los parametros para crear habitacion triple
 * @return
 */
void Programa::agrega_habitacion(int hotel_n, int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal)
{
    hotel_n = hotel_n - 1;
    hoteles[hotel_n].agrega_habitacion(num, cam, cn, tv, cf, micro, frigo, esc, bal);
}

/**
 * agrega_habitacion genera y guarda habitacion suite
 *
 * composicion que llama constructor de clase hotel para crearla desde programa
 *
 * @param todos los parametros para crear habitacion suite
 * @return
 */
void Programa::agrega_habitacion(int hotel_n, int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal, bool sal, bool com)
{
    hotel_n = hotel_n - 1;
    hoteles[hotel_n].agrega_habitacion(num, cam, cn, tv, cf, micro, frigo, esc, bal, sal, com);
}

/**
 * muestra_habitaciones llama a funcion de hotel para mostrar las habitaciones del 
 * hotel seleccionado
 *
 * Ciclo que recorre el arreglo de hoteles para desplegar sus habitaciones concatenadas.
 *
 * @param 
 * @return
 */
void Programa::muestra_habitacion(int hotel_n)
{
    hotel_n = hotel_n - 1;
    cout << "--HABITACIONES HOTEL:" << hoteles[hotel_n].get_nombre() << endl;
    hoteles[hotel_n].muestra_habitaciones();
}

/**
 * agrega_reserva guarda reservas
 *
 * composicion que llama constructor de clase hotel para crear la reserva
 *
 * @param todos los parametros para crear reserva
 * @return
 */
void Programa::agrega_reserva(int hotel_n, string nom, int a, int n, string fi, string fs, string tipohabres)
{
    hotel_n = hotel_n - 1;
    hoteles[hotel_n].agrega_reserva(nom, a, n, fi, fs, tipohabres);
}

/**
 * muestra_reservas llama a funcion de hotel para mostrar las reservas del 
 * hotel seleccionado
 *
 * Ciclo que recorre el arreglo de hoteles para desplegar sus reservas concatenadas.
 *
 * @param int hotel_n es el numero que toma cada hotel, su numero es el indice del arreglo
 * en el que se encuentra sumado uno
 * @return
 */
void Programa::muestra_reservas(int hotel_n)
{
    hotel_n = hotel_n - 1;
    cout << "--RESERVAS HOTEL:" << hoteles[hotel_n].get_nombre() << endl;
    hoteles[hotel_n].muestra_reservas();
}
#endif // PROGRAMA_H
