# 2doProyecto_orientado_a_objetos
Implementación Hotel con apuntadores y polimorfismo

LLevar manejo de un Hotel adecuadamente creando registro de reservas y habitaciones.

Clase Hotel crea Hoteles compuestos de habitaciones y reservas

Clase Reserva permite crear reservas que serán construidas dentro de clase Hotel

Clase Habitaciones es clase padre abstracta que hereda 4 clases: Individual, Doble, Triple y Suite cada una con sus propios atributos y métodos. 
Se construyen desde clase Hotel.

El proyecto dejaría de funcionar para habitaciones distintas a las creadas o en el dado caso de que cuenten con más atributos de los especificados. Se esté trabajando en la interfaz de usuario para desplegar información de los hoteles contando cada uno con su respectiva información completa, dar la posibilidad de crear un nuevo hotel, añadir habitaciones y crear reservas nuevas, actualizar información del hotel, de sus habitaciones o de sus reservas. 

compilar con: "g++ main.cpp && ./a.out"
