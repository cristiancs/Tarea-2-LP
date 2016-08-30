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
        lista->size++;
    }
    else if (pos == 0){
    	tNodo * aux = (tNodo *)malloc(sizeof(tNodo));
    	aux->prev = NULL;
        aux->next = lista->head;
        aux->next->prev = aux;
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
    moveToPos(lista, posicion);
    if (posicion == 0){
        lista->head = lista->head->next;
        lista->head->prev = NULL;
        lista->size--;
        lista->pos_actual--;
    }
    else if (posicion == lista->size - 1){
        lista->current = lista->current->prev;
        lista->current->next = NULL;
        lista->size--;
        lista->pos_actual--;
    }
    else {
        tNodo * aux = lista->current->next;
        lista->current->next = aux->next;
        aux->next->prev = lista->current;
        lista->size--;
        lista->pos_actual--;
    }
}

void moveToPos(tLista *lista, unsigned int posicion){
    unsigned int i = 0;
    int absoluto = posicion - lista->pos_actual;
    if (absoluto > 0){
        tNodo * aux = lista->head;
        while (i < posicion){
            aux = aux->next;
            lista->pos_actual++;
        }
    }
    else if (absoluto < 0){
        tNodo * aux ;
    }
}

CartaCurso * getValue(tLista *lista){
}

void free_linked(tLista *base){
    unsigned int i = 0;
    tNodo * aux = base->head;
    while (i < base->size){
        aux = aux->next;
        i++;
    }
}

int main(){
    return 1;
}

