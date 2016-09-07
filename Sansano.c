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

void  giveCards(struct Sansano* Jugador, void* MazoOficial){
    // Ordenar aleatoriamente las 20 cartas en el maso del jugador
    unsigned int i2;
    unsigned int chosen;
    i2 = 0;
    for (int i = CARDSNUMBER; i > 0; --i) {
        // Numero
        chosen = (unsigned int) pcg32_boundedrand((uint32_t) i);
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
    struct Sansano * player = (struct Sansano *)jugador;
    player->prioridad -= ((CartaCurso *)carta)->ataque;
    // Al ser menor a 0, mantener
    if (player->prioridad < 0) {
        player->prioridad = 0;
    }
}

void usarAprobar(void *carta, void *jugador){
    struct Sansano * player = (struct Sansano *)jugador;
    player->prioridad += ((CartaCurso *)carta)->defensa;
    // No pasar prioridad maxima
    if (player->prioridad > 3000){
        player->prioridad = 3000;
    }
}

void jugar(struct Sansano* Jugador, int tipo, struct Sansano* enemigo, unsigned int ronda){
    moveToPos(Jugador->mazo, ronda);
    CartaCurso * carta = getValue(Jugador->mazo);
    int opcion = -1;
    printf("Turno del Jugador \"%s\" [Prioridad Actual: %d]\n", Jugador->nombre, Jugador->prioridad);
    printf("\"%s\" ha sacado la carta: \"%s\". Descripción: %s\n",Jugador->nombre, carta->nombre, carta->descripcion);
    if(tipo == 0){
        // Es el user
        printf("Presione 0 si desea jugar la carta en modo ATAQUE o 1 si desea jugar la carta en modo DEFENSA\n");
        scanf("%d", &opcion);
        while(opcion != 0 && opcion != 1){
            system("clear");
            printf("Turno del Jugador \"%s\" [Prioridad Actual: %d]\n", Jugador->nombre, Jugador->prioridad);
            printf("\"%s\" ha sacado la carta: \"%s\". Descripción: %s\n",Jugador->nombre, carta->nombre, carta->descripcion);
            printf("%d no es una opción valida\n",opcion);
            printf("Presione 0 si desea jugar la carta en modo ATAQUE o 1 si desea jugar la carta en modo DEFENSA\n");
            scanf("%d", &opcion);
        }
    }
    else{
        // Juego automatico
        opcion = pcg32_boundedrand(2);
    }
    if(tipo == 0){
        system("clear");
    }
    if(opcion == 0){
        carta->reprobar(carta, enemigo);
        printf("\"%s\" ataca %d puntos de Prioridad a \"%s\"\n La nueva prioridad de %s es %d\n",Jugador->nombre, carta->ataque, enemigo->nombre, enemigo->nombre, enemigo->prioridad);
    }
    else if(opcion == 1){
        carta->aprobar(carta, Jugador);
        printf("\"%s\" recupera %d puntos de Prioridad\n La nueva prioridad de %s es %d\n",Jugador->nombre, carta->defensa, Jugador->nombre, Jugador->prioridad);
    }
    printf("-------------------------------------------\n");
}