//funciones de configuracion de CartaCurso

#include "CartaCurso.h"
void crearMazo(void * MazoOficial, CartaCurso * cartas[6]) {
    enum {MATE= 1, FISICA= 4, LP= 2, PROGRA= 6, ED= 3, EDD= 4};
    unsigned int i2;
    i2 = 0;
    for (int i = 0; i < MATE; ++i) {
        insertL(MazoOficial, cartas[0],i2);
        i2++;
    }
    for (int i = 0; i < FISICA; ++i) {
        insertL(MazoOficial, cartas[1],i2);
        i2++;
    }
    for (int i = 0; i < LP; ++i) {
        insertL(MazoOficial, cartas[2],i2);
        i2++;
    }
    for (int i = 0; i < PROGRA; ++i) {
        insertL(MazoOficial, cartas[3],i2);
        i2++;
    }
    for (int i = 0; i < ED; ++i) {
        insertL(MazoOficial, cartas[4],i2);
        i2++;
    }
    for (int i = 0; i < EDD; ++i) {
        insertL(MazoOficial, cartas[5],i2);
        i2++;
    }
}

void crearCartas(CartaCurso ** cartas){
    CartaCurso* mate = malloc(sizeof(CartaCurso));
    CartaCurso* fisica = malloc(sizeof(CartaCurso));
    CartaCurso* lp = malloc(sizeof(CartaCurso));
    CartaCurso* progra = malloc(sizeof(CartaCurso));
    CartaCurso* ed = malloc(sizeof(CartaCurso));
    CartaCurso* edd = malloc(sizeof(CartaCurso));
    cartas[0] = mate;
    cartas[1] = fisica;
    cartas[2] = lp;
    cartas[3] = progra;
    cartas[4] = ed;
    cartas[5] = edd;
    
    mate->nombre = "Matematicas";
    mate->descripcion = "";
    mate->ataque = 550;
    mate->defensa = 200;

    fisica->nombre = "Fisica";
    fisica->descripcion = "";
    fisica->ataque = 450;
    fisica->defensa = 150;

    lp->nombre = "Lenguajes de Programación";
    lp->descripcion = "";
    lp->ataque = 510;
    lp->defensa = 180;

    progra->nombre = "Programación";
    progra->descripcion = "";
    progra->ataque = 110;
    progra->defensa = 300;

    ed->nombre = "Estructura de Datos";
    ed->descripcion = "";
    ed->ataque = 470;
    ed->defensa = 160;

    edd->nombre = "Estructura Discretas";
    edd->descripcion = "";
    edd->ataque = 430;
    edd->defensa = 120;
}

void freeCards(CartaCurso ** cartas){
    for (unsigned int i=0; i<6; i++){
        free(cartas[i]);
    }
    free(cartas);
}