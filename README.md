# 2doProyecto_orientado_a_objetos
Implementación Hotel con apuntadores y polimorfismo

LLevar manejo de un Hotel adecuadamente creando registro de reservas y habitaciones.

Clase Hotel crea Hoteles compuestos de habitaciones y reservas

Clase Reserva permite crear reservas que serán construidas dentro de clase Hotel

Clase Habitaciones es clase padre abstracta que hereda 4 clases: Individual, Doble, Triple y Suite cada una con sus propios atributos y métodos. 
Se construyen desde clase Hotel.

El proyecto dejaría de funcionar para habitaciones con parametros distintos a los creados. 
Interfaz de usuario permite desplegar información de los hoteles contando cada uno con su respectiva información completa, dar la posibilidad de crear un nuevo hotel, añadir habitaciones y crear reservas nuevas. Aún no se puede actualizar información del hotel, de sus habitaciones o de sus reservas desde el menu para el usuario. 

Dentro del main(), system("cls") funciona para windows, para linux deberia usarse system("clear")

compilar con: "g++ main.cpp && ./a.out"
