//funciones de configuracion de CartaCurso

void crearMazo(void * MazoOficial, int* cartas) {


    enum {MATE= 1, FISICA= 4, LP= 2, PROGRA= 6, ED= 3, EDD= 4};

    for (int i = 0; i < MATE; ++i) {
        insertL(MazoOficial, cartas[0]);
    }
    for (int i = 0; i < FISICA; ++i) {
        insertL(MazoOficial, cartas[1]);
    }
    for (int i = 0; i < LP; ++i) {
        insertL(MazoOficial, cartas[2]);
    }
    for (int i = 0; i < PROGRA; ++i) {
        insertL(MazoOficial, cartas[3]);
    }
    for (int i = 0; i < ED; ++i) {
        insertL(MazoOficial, cartas[4]);
    }
    for (int i = 0; i < EDD; ++i) {
        insertL(MazoOficial, cartas[5]);
    }

}