#include "main.h"

int main(){
    // Jugadores
    struct Sansano* Jugador = malloc(sizeof(struct Sansano));
    Jugador->mazo = malloc(sizeof(tLista));
    initialize(Jugador->mazo);
    struct Sansano* PC = malloc(sizeof(struct Sansano));
    PC->mazo = malloc(sizeof(tLista));
    initialize(PC->mazo);
    // Cartas
    CartaCurso* mate = malloc(sizeof(CartaCurso));
    CartaCurso* fisica = malloc(sizeof(CartaCurso));
    CartaCurso* lp = malloc(sizeof(CartaCurso));
    CartaCurso* progra = malloc(sizeof(CartaCurso));
    CartaCurso* ed = malloc(sizeof(CartaCurso));
    CartaCurso* edd = malloc(sizeof(CartaCurso));
    CartaCurso* cartas[6] = {mate,fisica,lp,progra,ed,edd};



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

    ed->nombre = "Matematicas";
    ed->descripcion = "";
    ed->ataque = 470;
    ed->defensa = 160;

    edd->nombre = "Matematicas";
    edd->descripcion = "";
    edd->ataque = 430;
    edd->defensa = 120;



    char *NombreJugador = malloc(sizeof(int) * LARGONOMBREMAXIMO);
    // Iniciar El programa y pedir el nombre
    iniciarPrograma(NombreJugador, Jugador, PC);
    void* MazoOficial;
    MazoOficial = (tLista *)malloc(sizeof(tLista));
    initialize(MazoOficial);
    crearMazo(MazoOficial,cartas);

    giveCards(Jugador, MazoOficial);
    crearMazo(MazoOficial,cartas);
    giveCards(PC, MazoOficial);

    for (int i = 0; i < 20; ++i) {
        moveToPos((tLista *) Jugador->mazo, (unsigned int) i);
        CartaCurso* nCarta= getValue((tLista *) Jugador->mazo);

        printf("%s\n", nCarta->nombre);
    }

    free(NombreJugador);
    free_linked(Jugador->mazo);
    free_linked(PC->mazo);
    free_linked(MazoOficial);
    free(Jugador);
    free(PC);
    free(mate);
    free(fisica);
    free(lp);
    free(progra);
    free(ed);
    free(edd);
}