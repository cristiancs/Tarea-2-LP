//funciones de configuracion de Sansano
#include "Sansano.h"

void iniciarPrograma(char * NombreJugador, struct Sansano* Jugador, struct Sansano* PC){
    printf("Bienvenido a SansaStone, ¿Cual es su nombre? (Espacios no permitidos)\n");
    scanf("%s", NombreJugador);
    system("clear");
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
        // Lo metemos en el mazo del jugador y lo sacamos del inicial;
        moveToPos(MazoOficial, chosen);
        CartaCurso* toInsert;
        toInsert = getValue(MazoOficial);
        insertL(Jugador->mazo, toInsert, i2);
        removeL(MazoOficial, chosen);
        i2++;
    }
}

void usarReprobar(void *carta, void *jugador){

}

void usarAprobar(void *carta, void *jugador){

}

int jugar(struct Sansano* Jugador, int tipo, struct Sansano* enemigo, pcg32_random_t rng){
    moveToPos(Jugador->mazo, 0);
    CartaCurso * carta = getValue(Jugador->mazo);
    int opcion = -1;
    printf("Turno del Jugador \"%s\" [Prioridad Actual: %d]\n", Jugador->nombre, Jugador->prioridad);
    printf("\"%s\" ha sacado la carta: \"%s\" [ATAQUE: %d, DEFENSA: %d]\n",Jugador->nombre, carta->nombre, carta->ataque, carta->defensa);
    if(tipo == 0){
        // Es el user
        printf("Presione 0 si desea jugar la carta en modo ATAQUE o 1 si desea jugar la carta en modo DEFENSA\n");
        scanf("%d", &opcion);
        while(opcion != 0 && opcion != 1){
            system("clear");
            printf("Turno del Jugador \"%s\" [Prioridad Actual: %d]\n", Jugador->nombre, Jugador->prioridad);
            printf("\"%s\" ha sacado la carta: \"%s\" [ATAQUE: %d, DEFENSA: %d]\n",Jugador->nombre, carta->nombre, carta->ataque, carta->defensa);
            printf("%d no es una opción valida\n",opcion);
            printf("Presione 0 si desea jugar la carta en modo ATAQUE o 1 si desea jugar la carta en modo DEFENSA\n");

            scanf("%d", &opcion);
        }
    }
    else{
        // Juego automatico
        opcion = pcg32_boundedrand_r(&rng,(uint32_t) 1);
    }
    if(tipo == 0){
        system("clear");
    }
    if(opcion == 0){
        carta->reprobar(carta, enemigo);
        printf("\"%s\" ataca %d puntos de Prioridad a \"%s\"\n",Jugador->nombre, carta->ataque, enemigo->nombre);
    }
    else if(opcion == 1){
        carta->aprobar(carta, Jugador);
        printf("\"%s\" recupera %d puntos de Prioridad\n",Jugador->nombre, carta->defensa);
    }
    printf("-------------------------------------------\n");
    return 0;
}