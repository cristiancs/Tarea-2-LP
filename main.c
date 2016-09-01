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