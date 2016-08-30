//Archivo con estructuras y prototipos de funciones de Sansano
#ifndef _SANSANO_H_INCLUDED_
#define _SANSANO_H_INCLUDED_

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "libraries/pcg-c-basic-0.9/pcg_variants.h"

struct Sansano{
char * nombre;
int prioridad;
void * mazo;
};
#define LARGONOMBREMAXIMO 20

void iniciarPrograma(char*, struct Sansano*, struct Sansano*);
void giveCards(struct Sansano*);
#endif