//Archivo con funciones de lista enlazada
#include "lista.h"

void initialize(tLista *lista){
    lista->size = 0;
    lista->pos_actual = 0;
}

void insertL(tLista *lista, CartaCurso * Carta, unsigned int pos) {
    // Caso primer elemento
    if (lista->size == 0){
        lista->head = (tNodo *)malloc(sizeof(tNodo));
        lista->head->next = NULL;
        lista->head->prev = NULL;
        lista->head->carta = Carta;
        lista->current = lista->head;
        lista->pos_actual = 0;
        lista->size++;
    }

    // Agregar en la cabeza
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

    // Agregar en la cola
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

    // Agregar entremedio
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
    // Sacar de la cabeza
    if (posicion == 0){
        // Caso ultimo elemento
        if (lista->size == 1) {
            free(lista->head);
            lista->head = NULL;
            lista->size--;
            lista->current = NULL;
            return;
        }
        // Mas de un elemento - actualizar cabeza
        else {
            tNodo * aux = lista->head;
            lista->head = lista->head->next;
            free(aux);
            lista->head->prev = NULL;
            lista->size--;
            lista->current = lista->head;
            lista->pos_actual = 0;
            return;
        }
    }
    moveToPos(lista, posicion-1);   // Avanzar al anterior
    // Actualizar ultimo
    if (posicion == lista->size - 1){
        free(lista->current->next);
        lista->current->next = NULL;
        lista->size--;
    }
    // Actualizar medio
    else {
        tNodo * aux = lista->current->next;
        lista->current->next = aux->next;
        aux->next->prev = lista->current;
        free(aux);
        lista->size--;
    }
}

void moveToPos(tLista *lista, unsigned int posicion){
    // Actualizar current a cabeza
    if (posicion == 0){
        lista->current = lista->head;
        lista->pos_actual = 0;
        return;
    }
    // Verificar distancia segun posicion actual
    int relativo = posicion - lista->pos_actual;
    // Avanzar o retroceder segun corresponda
    if (relativo > 0){
        while (relativo > 0){
            lista->current = lista->current->next;
            lista->pos_actual++;
            relativo--;
        }
    }
    else if (relativo < 0){
        // Preferir retroceder o empezar desde el inicio segun eficiencia
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

CartaCurso * getValue(tLista *lista){   // Valor del nodo actual
    return lista->current->carta;
}

void free_linked(tLista *base){
    unsigned int i = 0;
    tNodo * aux = base->head;
    // Avanzar cabeza, liberar auxiliar
    while (i < base->size){
        base->head = base->head->next;
        free(aux);
        aux = base->head;
        i++;
    }
    free(base);
}