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
// Colores
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_GRAY   "\x1b[37m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
// Colores claros
#define ANSI_COLOR_GREEN   "\x1b[1;32m"

void iniciarPrograma(char* NombreJugador, struct Sansano* Jugador, struct Sansano* PC);
void giveCards(struct Sansano* Jugador, void * MazoOficial);
void usarReprobar(void * carta, void * jugador);
void usarAprobar(void * carta, void * jugador);
void jugar(struct Sansano* Jugador, int tipo, struct Sansano* enemigo, unsigned int ronda);
void restantes(unsigned int ronda, int actual, short status);

#endif