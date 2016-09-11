//funciones de configuracion de Sansano
#include "Sansano.h"

/******** Funcion: iniciarPrograma ********************
Descripcion: inicializa el programa con los parametros de
cada jugador

Parametros:
NombreJugador string que almacena el nombre del jugador
Jugador struct Sansano del jugador
PC struct Sansano de la computadora

Retorno: void
************************************************/
void iniciarPrograma(char * NombreJugador, struct Sansano* Jugador, struct Sansano* PC){
    printf("Bienvenido a SansaStone, ¿Cual es su nombre? \n");
    fgets(NombreJugador, LARGONOMBREMAXIMO, stdin);
    size_t len = strlen(NombreJugador);
    if( NombreJugador[len-1] == '\n' ){
        NombreJugador[len-1] = '\0';
    }
    system("clear");
    printf("Hola %s, tu prioridad inicial es de 3000\n", NombreJugador);
    Jugador->nombre = NombreJugador;
    Jugador->prioridad = 3000;
    PC->nombre = "Universidad";
    PC->prioridad = 3000;
}

/******** Funcion: giveCards ********************
Descripcion: "reparte" las cartas del mazo oficial a el jugador
actual de forma aleatoria

Parametros:
Jugador struct Sansano sobre el que se desea "repartir" cartas
MazoOficial mazo con todas las cartas posibles

Retorno: void
************************************************/
void  giveCards(struct Sansano* Jugador, void* MazoOficial){
    // Ordenar aleatoriamente las 20 cartas en el maso del jugador
    unsigned int i2;
    unsigned int chosen;
    i2 = 0;
    int i;
    for (i = CARDSNUMBER; i > 0; --i) {
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

/******** Funcion: usarReprobar ********************
Descripcion: Actualiza prioridad del jugador segun el ataque recibido
del contrincante

Parametros:
carta con la cual se esta atacando
jugador el cual recibe el ataque correspondiente

Retorno: void
************************************************/
void usarReprobar(void *carta, void *jugador){
    struct Sansano * player = (struct Sansano *)jugador;
    player->prioridad -= ((CartaCurso *)carta)->ataque;
    // Al ser menor a 0, mantener
    if (player->prioridad < 0) {
        player->prioridad = 0;
    }
}

/******** Funcion: usarAprobar ********************
Descripcion: Actualiza prioridad del jugador segun la defensa
de la carta utilizada

Parametros:
carta con la cual se esta defendiendo
jugador el cual se esta defendiendo

Retorno: void
************************************************/
void usarAprobar(void *carta, void *jugador){
    struct Sansano * player = (struct Sansano *)jugador;
    player->prioridad += ((CartaCurso *)carta)->defensa;
    // No pasar prioridad maxima
    if (player->prioridad > 3000){
        player->prioridad = 3000;
    }
}

/******** Funcion: jugar ********************
Descripcion: realiza turno de cada jugador

Parametros:
Jugador cuyo turno esta en curso
tipo representa la jugada manual (usuario) o automatica (PC) segun corresponda
enemigo del Jugador actual
ronda numero de ronda que se esta llevando a cabo

Retorno: void
************************************************/
void jugar(struct Sansano* Jugador, int tipo, struct Sansano* enemigo, unsigned int ronda){
    moveToPos(Jugador->mazo, ronda);
    CartaCurso * carta = getValue(Jugador->mazo);
    char white;
    int opcion = -1;
    short estado = 0;
    printf("Turno del Jugador \"%s\" [Prioridad Actual: %d]\n", Jugador->nombre, Jugador->prioridad);
    printf("\"%s\" ha sacado la carta: \"%s\". \nDescripción: %s\n",Jugador->nombre, carta->nombre, carta->descripcion);
    if(tipo == 0){
        // Es el user
        printf("Presione 0 si desea jugar la carta en modo ATAQUE o 1 si desea jugar la carta en modo DEFENSA\n");
        scanf("%d", &opcion);
        while(opcion != 0 && opcion != 1){
            printf(ANSI_COLOR_RED "Esa no es una opción valida\n" ANSI_COLOR_RESET);
            printf("Presione 0 si desea jugar la carta en modo ATAQUE o 1 si desea jugar la carta en modo DEFENSA\n");
            while ((white = getchar()) != '\n');
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
        if (enemigo -> prioridad <= 0){
            estado = 1;
        }
        printf(ANSI_COLOR_YELLOW "\"%s\" ataca %d puntos de Prioridad a \"%s\"\n La nueva prioridad de %s es %d\n" ANSI_COLOR_RESET,Jugador->nombre, carta->ataque, enemigo->nombre, enemigo->nombre, enemigo->prioridad);
    }
    else if(opcion == 1){
        carta->aprobar(carta, Jugador);
        printf(ANSI_COLOR_CYAN "\"%s\" recupera %d puntos de Prioridad\n La nueva prioridad de %s es %d\n" ANSI_COLOR_RESET,Jugador->nombre, carta->defensa, Jugador->nombre, Jugador->prioridad);
    }
    restantes(ronda, 0, estado);
}

/******** Funcion: restantes ********************
Descripcion: imprime la cantidad de cartas restantes en cada mazo

Parametros:
ronda numero actual de rondas jugadas
actual numero de guiones ya impresos
status si ya hay ganador o no

Retorno: void
************************************************/
void restantes(unsigned int ronda, int actual, short status){
    //Casos base
        //Ya termino juego
    if (status == 1){
        return;
    }
        // Final de linea
    if (actual == 20){
        printf(ANSI_COLOR_RESET   "\x1b[0m""\n");
        return;
    }
    // Ronda actual
    if (actual == ronda){
        printf(ANSI_COLOR_GREEN "[%u] ", 20-ronda);
    }
    else {
        printf(ANSI_COLOR_GREEN "- ");
    }
    return restantes(ronda, ++actual, status);
}