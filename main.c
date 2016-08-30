#include "main.h"

int main(){
    // Jugadores
    struct Sansano* Jugador = malloc(sizeof(struct Sansano));
    struct Sansano* PC = malloc(sizeof(struct Sansano));

    // Cartas
    CartaCurso* mate = malloc(sizeof(CartaCurso));
    CartaCurso* fisica = malloc(sizeof(CartaCurso));
    CartaCurso* lp = malloc(sizeof(CartaCurso));
    CartaCurso* progra = malloc(sizeof(CartaCurso));
    CartaCurso* ed = malloc(sizeof(CartaCurso));
    CartaCurso* edd = malloc(sizeof(CartaCurso));

    int* cartas = {mate,fisica,lp,progra,ed,edd};

    char *NombreJugador = malloc(sizeof(int) * LARGONOMBREMAXIMO);
    // Iniciar El programa y pedir el nombre
    iniciarPrograma(NombreJugador, Jugador, PC);
    void* MazoOficial;
    MazoOficial = malloc(sizeof(tLista));
    mazoOrdenado(MazoOficial,cartas);
    giveCards(Jugador);
    mazoOrdenado(MazoOficial,cartas);
    giveCards(PC);
    free(NombreJugador);
    free(Jugador);
    free(PC);
    free(mate);
    free(fisica);
    free(lp);
    free(progra);
    free(ed);
    free(edd);
}