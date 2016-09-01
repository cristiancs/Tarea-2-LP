//Archivo con funciones de lista enlazada
#include <stdlib.h>
#include "lista.h"
#include "CartaCurso.h"

void initialize(tLista *lista){
    lista->size = 0;
    lista->pos_actual = 0;
}

void insertL(tLista *lista, CartaCurso * Carta, unsigned int pos) {
    if (lista->size == 0){
        lista->head = (tNodo *)malloc(sizeof(tNodo));
        lista->head->next = NULL;
        lista->head->prev = NULL;
        lista->head->carta = Carta;
        lista->current = lista->head;
        lista->pos_actual = 0;
        lista->size++;
    }
    else if (pos == 0){
        tNodo * aux = (tNodo *)malloc(sizeof(tNodo));
        aux->prev = NULL;
        aux->next = lista->head;
        aux->next->prev = aux;
        lista->head = aux;
        lista->head->carta = Carta;
        lista->current = lista->head;
        lista->pos_actual = 0;
        lista->size++;
    }
    else if (pos == lista->size){
        tNodo * aux = lista->head;
        while (aux->next != NULL){
            aux = aux->next;
        }
        aux->next = (tNodo *)malloc(sizeof(tNodo));
        aux->next->carta = Carta;
        aux->next->prev = aux;
        aux->next->next = NULL;
        lista->size++;
    }
    else {
        unsigned int i=0;
        tNodo * actual = lista->head;
        while (i < pos-1){
            actual = actual->next;
            i++;
        }
        tNodo * aux = (tNodo *)malloc(sizeof(tNodo));
        aux->carta = Carta;
        aux->prev = actual;
        aux->next = actual->next;
        actual->next->prev = aux;
        actual->next = aux;
        lista->size++;
    }
}

void removeL(tLista *lista, unsigned int posicion){
    if (posicion == 0){
        if (lista->size == 1) {
            lista->head = NULL;
            lista->size--;
            lista->current = NULL;
            return;
        }
        else {
            lista->head = lista->head->next;
            lista->head->prev = NULL;
            lista->size--;
            lista->current = lista->head;
            lista->pos_actual = 0;
            return;
        }
    }
    moveToPos(lista, posicion-1);
    if (posicion == lista->size - 1){
        lista->current->next = NULL;
        lista->size--;
    }
    else {
        tNodo * aux = lista->current->next;
        lista->current->next = aux->next;
        aux->next->prev = lista->current;
        lista->size--;
    }
}

void moveToPos(tLista *lista, unsigned int posicion){
    if (posicion == 0){
        lista->current = lista->head;
        lista->pos_actual = 0;
        return;
    }
    int relativo = posicion - lista->pos_actual;
    if (relativo > 0){
        while (relativo > 0){
            lista->current = lista->current->next;
            lista->pos_actual++;
            relativo--;
        }
    }
    else if (relativo < 0){
        if (posicion < -relativo){
            lista->current = lista->head;
            lista->pos_actual = 0;
            while (lista->pos_actual < posicion){
                lista->current = lista->current->next;
                lista->pos_actual++;
            }
        }
        else {
            while (relativo < 0) {
                lista->current = lista->current->prev;
                lista->pos_actual--;
                relativo++;
            }
        }
    }
}

CartaCurso * getValue(tLista *lista){
    return lista->current->carta;
}

void free_linked(tLista *base){
    unsigned int i = 0;
    tNodo * aux = base->head;
    while (i < base->size){
        base->head = base->head->next;
        free(aux);
        aux = base->head;
        i++;
    }
    free(base);
}

/*int main(){
    tLista lista;
    initialize(&lista);
    int i = 0;
    while (i<10){
        CartaCurso * prueba = (CartaCurso *)malloc(sizeof(CartaCurso));
        prueba->ataque = i;
        insertL(&lista, prueba, i);
        i++;
    }
    CartaCurso * prueba = (CartaCurso *)malloc(sizeof(CartaCurso));
    prueba->ataque = 100;
    insertL(&lista, prueba, 5);
    removeL(&lista, 4);
    removeL(&lista, 2);
    //printf("hola");
    free_linked(&lista);
    return 1;
} */

