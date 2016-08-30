//funciones de configuracion de CartaCurso

void crearMazo(void * MazoOficial, int* cartas) {


    enum {MATE: 1, FISICA: 4, LP: 2, PROGRA: 6, ED: 3, EDD: 4};

    for (int i = 0; i < MATE; ++i) {
        insertarL(MazoOficial, cartas[0]);
    }
    for (int i = 0; i < FISICA; ++i) {
        insertarL(MazoOficial, cartas[1]);
    }
    for (int i = 0; i < LP; ++i) {
        insertarL(MazoOficial, cartas[2]);
    }
    for (int i = 0; i < PROGRA; ++i) {
        insertarL(MazoOficial, cartas[3]);
    }
    for (int i = 0; i < ED; ++i) {
        insertarL(MazoOficial, cartas[4]);
    }
    for (int i = 0; i < EDD; ++i) {
        insertarL(MazoOficial, cartas[5]);
    }

}