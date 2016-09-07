//Archivo con estructuras y prototipos de funciones de CartaCurso
#ifndef _CARTACURSO_H_INCLUDED_
#define _CARTACURSO_H_INCLUDED_

typedef struct CartaCurso{
	char * nombre, * descripcion;
	int ataque, defensa;
	void (*reprobar)(void *, void *); //Los parametros son la carta y el enemigo
	void (*aprobar)(void *, void *); //Los parametros son la carta y el jugador
} CartaCurso;

#include "lista.h"
#include "Sansano.h"

/******** Funcion: crearMazo ********************
Descripcion: crea mazo oficial con las cartas posibles,
de donde se "reparte" a cada jugador

Parametros:
MazoOficial mazo con cartas posibles
cartas lista de tipos de cartas

Retorno: void
************************************************/
void crearMazo(void * MazoOficial, CartaCurso *cartas[6]);

/******** Funcion: crearCartas ********************
Descripcion: crea en la memoria las cartas de cada tipo
con sus respectivos parametros

Parametros:
cartas lista de cada tipo de carta posible

Retorno: void
************************************************/
void crearCartas(CartaCurso ** cartas);

/******** Funcion: freeCards ********************
Descripcion: libera la memoria usada por la lista de tipos cartas

Parametros:
cartas lista de cartas posibles

Retorno: void
************************************************/
void freeCards(CartaCurso ** cartas);
#endif