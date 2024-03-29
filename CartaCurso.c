//funciones de configuracion de CartaCurso

#include "CartaCurso.h"

/******** Funcion: crearMazo ********************
Descripcion: crea mazo oficial con las cartas posibles,
de donde se "reparte" a cada jugador

Parametros:
MazoOficial mazo con cartas posibles
cartas lista de tipos de cartas

Retorno: void
************************************************/
void crearMazo(void * MazoOficial, CartaCurso * cartas[6]) {
    enum {MATE= 1, FISICA= 4, LP= 2, PROGRA= 6, ED= 3, EDD= 4};
    unsigned int i2;
    i2 = 0;
    int i;
    // Insertar a MazoOficial segun la cantidad de veces que aparecen
    for (i = 0; i < MATE; ++i) {
        insertL(MazoOficial, cartas[0],i2);
        i2++;
    }
    for (i = 0; i < FISICA; ++i) {
        insertL(MazoOficial, cartas[1],i2);
        i2++;
    }
    for (i = 0; i < LP; ++i) {
        insertL(MazoOficial, cartas[2],i2);
        i2++;
    }
    for (i = 0; i < PROGRA; ++i) {
        insertL(MazoOficial, cartas[3],i2);
        i2++;
    }
    for (i = 0; i < ED; ++i) {
        insertL(MazoOficial, cartas[4],i2);
        i2++;
    }
    for (i = 0; i < EDD; ++i) {
        insertL(MazoOficial, cartas[5],i2);
        i2++;
    }
}

/******** Funcion: crearCartas ********************
Descripcion: crea en la memoria las cartas de cada tipo
con sus respectivos parametros

Parametros:
cartas lista de cada tipo de carta posible

Retorno: void
************************************************/
void crearCartas(CartaCurso ** cartas){
    // Asignar en heap
    CartaCurso* mate = malloc(sizeof(CartaCurso));
    CartaCurso* fisica = malloc(sizeof(CartaCurso));
    CartaCurso* lp = malloc(sizeof(CartaCurso));
    CartaCurso* progra = malloc(sizeof(CartaCurso));
    CartaCurso* ed = malloc(sizeof(CartaCurso));
    CartaCurso* edd = malloc(sizeof(CartaCurso));

    // Agregar a la lista
    cartas[0] = mate;
    cartas[1] = fisica;
    cartas[2] = lp;
    cartas[3] = progra;
    cartas[4] = ed;
    cartas[5] = edd;
    
    // Agregar parametros de cada una
    mate->nombre = "Matematicas";
    mate->descripcion = "Ataca 550/Cura 200 puntos de prioridad.";
    mate->ataque = 550;
    mate->defensa = 200;

    fisica->nombre = "Fisica";
    fisica->descripcion = "Ataca 450/Cura 150 puntos de prioridad.";
    fisica->ataque = 450;
    fisica->defensa = 150;

    lp->nombre = "Lenguajes de Programación";
    lp->descripcion = "Ataca 510/Cura 180 puntos de prioridad.";
    lp->ataque = 510;
    lp->defensa = 180;

    progra->nombre = "Programación";
    progra->descripcion = "Ataca 110/Cura 300 puntos de prioridad.";
    progra->ataque = 110;
    progra->defensa = 300;

    ed->nombre = "Estructura Discretas";
    ed->descripcion = "Ataca 470/Cura 160 puntos de prioridad.";
    ed->ataque = 470;
    ed->defensa = 160;

    edd->nombre = "Estructura de Datos";
    edd->descripcion = "Ataca 430/Cura 120 puntos de prioridad.";
    edd->ataque = 430;
    edd->defensa = 120;
}

/******** Funcion: freeCards ********************
Descripcion: libera la memoria usada por la lista de tipos cartas

Parametros:
cartas lista de cartas posibles

Retorno: void
************************************************/
void freeCards(CartaCurso ** cartas){
    unsigned int i;
    for (i=0; i<6; i++){
        free(cartas[i]);
    }
    free(cartas);
}