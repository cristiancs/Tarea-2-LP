//funciones de configuracion de Sansano
#include "Sansano.h"

void iniciarPrograma(char * NombreJugador, struct Sansano* Jugador, struct Sansano* PC){
    printf("Bienvenido a SansaStone, ¿Cual es su nombre? (Espacios no permitidos)\n");
    scanf("%s", NombreJugador);
    printf("Hola %s, tu prioridad inicial es de 4500\n", NombreJugador);

    Jugador->nombre = NombreJugador;
    Jugador->prioridad = 4500;
    PC->nombre = "Universidad";
    PC->prioridad = 4500;
}


void  giveCards(struct Sansano* Jugador, void* MazoOficial){

    // Ordenar aleatoriamente las 20 cartas en el maso del jugador
    for (int i = CARDSNUMBER; i > 1; --i) {
        // Numero
        int chosen = pcg32_boundedrand(i);
        // Lo metemos en el maso del jugador y lo sacamos del inicial;
        moveToPos(MazoOficial, (unsigned int) chosen);
        insertL(Jugador->mazo, getValue(MazoOficial);
        removeL(MazoOficial, chosen);
    }

}