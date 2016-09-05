//funciones de configuracion de Sansano
#include "Sansano.h"

void iniciarPrograma(char * NombreJugador, struct Sansano* Jugador, struct Sansano* PC){
    printf("Bienvenido a SansaStone, ¿Cual es su nombre? (Espacios no permitidos)\n");
    scanf("%s", NombreJugador);
    printf("Hola %s, tu prioridad inicial es de 3000\n", NombreJugador);

    Jugador->nombre = NombreJugador;
    Jugador->prioridad = 3000;
    PC->nombre = "Universidad";
    PC->prioridad = 3000;
}


void  giveCards(struct Sansano* Jugador, void* MazoOficial,pcg32_random_t rng){
    // Ordenar aleatoriamente las 20 cartas en el maso del jugador
    unsigned int i2;
    unsigned int chosen;
    i2 = 0;
    for (int i = CARDSNUMBER; i > 0; --i) {
        // Numero
        chosen = (unsigned int) pcg32_boundedrand_r(&rng,(uint32_t) i);
        printf("%d,", (int) chosen);
        // Lo metemos en el maso del jugador y lo sacamos del inicial;
        moveToPos(MazoOficial, chosen);
        CartaCurso* toInsert;
        toInsert = getValue(MazoOficial);
        insertL(Jugador->mazo, toInsert, i2);
        removeL(MazoOficial, chosen);
        i2++;
    }
}

void aprobar(void *carta, void *jugador){

}

void reprobar(void *carta, void *jugador){

}