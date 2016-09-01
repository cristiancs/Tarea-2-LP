//funciones de configuracion de Sansano
#include "Sansano.h"

void iniciarPrograma(char * NombreJugador, struct Sansano* Jugador, struct Sansano* PC){
    printf("Bienvenido a SansaStone, ¿Cual es su nombre? (Espacios no permitidos)\n");
    scanf("%s", NombreJugador);
    printf("Hola %s, tu prioridad inicial es de 4500\n", NombreJugador);

    Jugador->nombre = NombreJugador;
    Jugador->prioridad = 3000;
    PC->nombre = "Universidad";
    PC->prioridad = 3000;
}


void  giveCards(struct Sansano* Jugador, void* MazoOficial){

    // Ordenar aleatoriamente las 20 cartas en el maso del jugador
    unsigned int i2;
    i2 = 0;
    for (int i = CARDSNUMBER; i > 1; --i) {
        // Numero
        unsigned int chosen;
        chosen = (unsigned int) pcg32_boundedrand((uint32_t) i);
        // Lo metemos en el maso del jugador y lo sacamos del inicial;
        moveToPos(MazoOficial, chosen);
        CartaCurso* toInsert = getValue(MazoOficial);
        insertL(Jugador->mazo, toInsert, i2);
        removeL(MazoOficial, chosen);
        i2++;
    }

}