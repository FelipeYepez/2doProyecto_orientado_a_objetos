/*
Felipe Yepez A01658002
Crea la clase Programa como base de datos para guardar hoteles con todo
lo que estan compuestos, se hace composicion de clase Hotel
Si se elimina el Programa se eliminan consigo todos los hoteles, habitaciones y reservas
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

void Programa::agrega_hotel(string n, string u, int pis, bool d, bool parq, bool wf)
{
    Hotel hot(n, u, pis, d, parq, wf);
    hoteles[cont_hoteles] = hot;
    cont_hoteles += 1;
}
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
void Programa::muestra_nombres_hoteles()
{
    for (int i=0; i<cont_hoteles; i++)
    {
        cout << "--HOTEL #" << i+1 << ": ";
        cout << hoteles[i].get_nombre() << endl;
    }
}
bool Programa::comprobar_hotel(int hotel_n)
{
    if (hoteles[hotel_n].get_nombre() == "")
    {
        return false;
    }
    else
        {
            return true;
        }
}
void Programa::agrega_habitacion(int hotel_n, int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc)
{
    hotel_n = hotel_n - 1;
    hoteles[hotel_n].agrega_habitacion(num, cam, cn, tv, cf, micro, frigo, esc);
}
void Programa::agrega_habitacion(int hotel_n, string cam, int num, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal)
{
    hotel_n = hotel_n - 1;
    hoteles[hotel_n].agrega_habitacion(cam, num, cn, tv, cf, micro, frigo, esc, bal);
}
void Programa::agrega_habitacion(int hotel_n, int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal)
{
    hotel_n = hotel_n - 1;
    hoteles[hotel_n].agrega_habitacion(num, cam, cn, tv, cf, micro, frigo, esc, bal);
}
void Programa::agrega_habitacion(int hotel_n, int num, string cam, float cn, bool tv, bool cf, bool micro, bool frigo, bool esc, bool bal, bool sal, bool com)
{
    hotel_n = hotel_n - 1;
    hoteles[hotel_n].agrega_habitacion(num, cam, cn, tv, cf, micro, frigo, esc, bal, sal, com);
}
void Programa::muestra_habitacion(int hotel_n)
{
    hotel_n = hotel_n - 1;
    cout << "--HABITACIONES HOTEL:" << hoteles[hotel_n].get_nombre() << endl;
    hoteles[hotel_n].muestra_habitaciones();
}
void Programa::agrega_reserva(int hotel_n, string nom, int a, int n, string fi, string fs, string tipohabres)
{
    hotel_n = hotel_n - 1;
    hoteles[hotel_n].agrega_reserva(nom, a, n, fi, fs, tipohabres);
}
void Programa::muestra_reservas(int hotel_n)
{
    hotel_n = hotel_n - 1;
    cout << "--RESERVAS HOTEL:" << hoteles[hotel_n].get_nombre() << endl;
    hoteles[hotel_n].muestra_reservas();
}
#endif // PROGRAMA_H
