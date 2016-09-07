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
void iniciarPrograma(char*, struct Sansano*, struct Sansano*);
void giveCards(struct Sansano*, void *, pcg32_random_t);
void usarAprobar(void *, void *);
void usarReprobar(void *, void *);
int jugar(struct Sansano*, int, struct Sansano*, int[20], unsigned int);
#endif