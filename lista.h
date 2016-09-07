//Archivo con estructuras y prototipos de funciones de lista enlazada
#ifndef _LISTA_H_INCLUDED_
#define _LISTA_H_INCLUDED_
#include "CartaCurso.h"
#include <stdlib.h>


typedef struct node {               // Estructura nodo de lista enlazada
	CartaCurso *carta;
    struct node *prev;
    struct node *next;
} tNodo;

typedef struct lista {              // Estructura lista
    tNodo *head;                    // Almacena la cabeza de la lista enlazada
    tNodo *current;
    int size;
    unsigned int pos_actual;
} tLista;

/******** Funcion: initialize ********************
Descripcion: inicializa parametros de la lista enlazada a 0

Parametros:
lista a la que se desea inicializar

Retorno: void
************************************************/
void initialize(tLista *lista);

/******** Funcion: insertL ********************
Descripcion: inserta un elemento a la lista en la posicion indicada

Parametros:
lista sobre la cual trabajar
Carta a agregar en el nodo
pos posicion en la que agregar elemento

Retorno: void
************************************************/
void insertL(tLista *lista, CartaCurso * Carta, unsigned int pos);

/******** Funcion: removeL ********************
Descripcion: saca el elemento de la lisa en dicha posicion y
libera la memoria ocupada por su nodo

Parametros:
lista sobre la que se trabaja
posicion del nodo que se desea eliminar

Retorno: void
************************************************/
void removeL(tLista *lista, unsigned int pos);

/******** Funcion: moveToPos ********************
Descripcion: avanza a la posicion de la lista doble enlazada

Parametros:
lista sobre la cual trabajar
posicion a la que se desea mover

Retorno: void
************************************************/
void moveToPos(tLista *lista, unsigned int posicion);

/******** Funcion: getValue ********************
Descripcion: obtiene el elemento guardado en el nodo actual

Parametros:
lista de la cual se quiere obtener el elemento

Retorno: carta almacenada en nodo actual
************************************************/
CartaCurso * getValue(tLista *lista);

/******** Funcion: free_linked ********************
Descripcion: libera la memoria usada por la lista enlazada (mazo)

Parametros:
base direccion de la lista que se desea liberar memoria

Retorno: void
************************************************/
void free_linked(tLista *base);

#endif