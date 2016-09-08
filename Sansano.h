//Archivo con estructuras y prototipos de funciones de Sansano
#ifndef _SANSANO_H_INCLUDED_
#define _SANSANO_H_INCLUDED_

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>


#include "libraries/pcg-c-basic-0.9/pcg_basic.h"
#include "lista.h"
struct Sansano{
char * nombre;
int prioridad;
void * mazo;
};
#define LARGONOMBREMAXIMO 256
#define CARDSNUMBER 20
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_GRAY   "\x1b[37m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/******** Funcion: iniciarPrograma ********************
Descripcion: inicializa el programa con los parametros de
cada jugador

Parametros:
NombreJugador string que almacena el nombre del jugador
Jugador struct Sansano del jugador
PC struct Sansano de la computadora

Retorno: void
************************************************/
void iniciarPrograma(char* NombreJugador, struct Sansano* Jugador, struct Sansano* PC);

/******** Funcion: giveCards ********************
Descripcion: "reparte" las cartas del mazo oficial a el jugador
actual de forma aleatoria

Parametros:
Jugador struct Sansano sobre el que se desea "repartir" cartas
MazoOficial mazo con todas las cartas posibles

Retorno: void
************************************************/
void giveCards(struct Sansano* Jugador, void * MazoOficial);

/******** Funcion: usarReprobar ********************
Descripcion: Actualiza prioridad del jugador segun el ataque recibido
del contrincante

Parametros:
carta con la cual se esta atacando
jugador el cual recibe el ataque correspondiente

Retorno: void
************************************************/
void usarReprobar(void * carta, void * jugador);

/******** Funcion: usarAprobar ********************
Descripcion: Actualiza prioridad del jugador segun la defensa
de la carta utilizada

Parametros:
carta con la cual se esta defendiendo
jugador el cual se esta defendiendo

Retorno: void
************************************************/
void usarAprobar(void * carta, void * jugador);

/******** Funcion: jugar ********************
Descripcion: realiza turno de cada jugador

Parametros:
Jugador cuyo turno esta en curso
tipo representa la jugada manual (usuario) o automatica (PC) segun corresponda
enemigo del Jugador actual
ronda numero de ronda que se esta llevando a cabo

Retorno: void
************************************************/
void jugar(struct Sansano* Jugador, int tipo, struct Sansano* enemigo, unsigned int ronda);

/******** Funcion: restantes ********************
Descripcion: imprime la cantidad de cartas restantes en cada mazo

Parametros:
ronda numero actual de rondas jugadas
actual numero de guiones ya impresos
status si ya hay ganador o no

Retorno: void
************************************************/
void restantes(unsigned int ronda, int actual, short status);
#endif