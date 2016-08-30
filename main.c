#include "main.h"

int main(){
    struct Sansano* Jugador = malloc(sizeof(struct Sansano));
    struct Sansano* PC = malloc(sizeof(struct Sansano));

    char *NombreJugador = malloc(sizeof(int) * LARGONOMBREMAXIMO);
    // Iniciar El programa y pedir el nombre
    iniciarPrograma(NombreJugador, Jugador, PC);

    giveCards(Jugador);
    giveCards(PC);
    free(NombreJugador);
    free(Jugador);
    free(PC);
}