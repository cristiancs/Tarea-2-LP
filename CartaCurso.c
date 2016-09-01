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