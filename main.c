#include "main.h"

int main(){
    struct Sansano Jugador;
    struct Sansano PC;
    char *NombreJugador = malloc(sizeof(int) * LARGONOMBREMAXIMO);
    // Iniciar El programa y pedir el nombre
    iniciarPrograma(NombreJugador, Jugador, PC);

    //giveCards(Jugador);
    //giveCards(PC);
    free(NombreJugador);
}