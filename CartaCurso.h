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


void crearMazo(void *, CartaCurso *[6]);
void crearCartas(CartaCurso **);
void freeCards(CartaCurso **);
#endif