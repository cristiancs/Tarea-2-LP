//Archivo con estructuras y prototipos de funciones de lista enlazada
#ifndef _LISTA_H_INCLUDED_
#define _LISTA_H_INCLUDED_
#include "CartaCurso.h"

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

void initialize(tLista *lista);
void insertL(tLista *lista, CartaCurso * Carta, unsigned int pos);
void removeL(tLista *lista, unsigned int pos);
void moveToPos(tLista *lista, unsigned int posicion);
CartaCurso * getValue(tLista *lista);
void free_linked(tLista *base);

#endif