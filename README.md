# PROYECTO POO #1

### *Integrantes: Ana Gabriela Argüello y Laura Isabel Olivero*

### Introducción
El presente proyecto tiene como objetivo el desarrollo de un sistema de gestión para el aeropuerto Alfonso Bonilla Aragón. Este sistema permitirá administrar y coordinar diversas operaciones dentro del aeropuerto.
##
### Gestión de Aeronaves:

1. Registro de aviones, helicópteros y jets privados.
   
##
### Programación de Vuelos:
1. Asignación de vuelos a aeronaves disponibles.
2. Restricción de un máximo de 3 vuelos al mismo tiempo por aeronave.
   
##
### Gestión de Pasajeros:

1. reservar vuelo
2. Registro de información de pasajeros, incluyendo datos médicos.
   
##
### Gestión de Tripulación:

1. Asignación de tripulación a vuelos con detalles de experiencia y horas máximas de trabajo.
2. Registro de información personal de la tripulación.

##
### Puertas de Embarque:

1. Asignación y control de puertas de embarque para vuelos.
2. Historial de asignaciones.

##
#

## Link del UML= [UML_Proyecto](https://drive.google.com/file/d/1gGzPHcVHrZBGxr4V1liCN0Aj2rsWrvsm/view?usp=sharing)

##
## ¿Como funcion nuestro programa?
El sistema funciona por medio de la clase principal aeropuerto la cual está asociada con la clase Torre, está contiene las clases puerta y aeronave, la clase Torre es la que se encarga de buscar el estado de los vuelos y conectarlos si están están aterrizando con las puertas que se encuentren disponibles, por otro lado si las aeronaves están despegándo se en carga de liberar las puertas. También podemos encontrar dentro de la clase aeropuerto las clases tripulantes, pasajeros y viajes.
Por otro lado tenemos a la clase usuario la cual se busca este en la capacidad de modificar los valores de objetos tales como Torre puertas y/o aeronave