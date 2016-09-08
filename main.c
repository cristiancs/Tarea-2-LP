#include "main.h"

int main(int argc, char** argv){
    int rounds = 5;
    bool nondeterministic_seed = false;

    ++argv;
    --argc;
    if (argc > 0 && strcmp(argv[0], "-r") == 0) {
        nondeterministic_seed = true;
        ++argv;
        --argc;
    }
    if (argc > 0) {
        rounds = atoi(argv[0]);
    }
    if (nondeterministic_seed) {
        // Seed with external entropy -- the time and some program addresses
        // (which will actually be somewhat random on most modern systems).
        // A better solution, entropy_getbytes, using /dev/random, is provided
        // in the full library.

        pcg32_srandom((uint64_t) (time(NULL) ^ (intptr_t)&printf), (uint64_t) (intptr_t)&rounds);
    } else {
        // Seed with a fixed constant

        pcg32_srandom(42u, 54u);
    }

    // Jugadores
    struct Sansano* Jugador = malloc(sizeof(struct Sansano));
    Jugador->mazo = malloc(sizeof(tLista));
    initialize(Jugador->mazo);
    struct Sansano* PC = malloc(sizeof(struct Sansano));
    PC->mazo = malloc(sizeof(tLista));
    initialize(PC->mazo);
    // Cartas
    CartaCurso ** cartas = malloc(sizeof(CartaCurso *) * 6);
    crearCartas(cartas);

    // Punteros a funciones
    typedef void (*playFunction)(void *, void *);
    playFunction aprobarFunction;
    aprobarFunction = usarAprobar;
    playFunction reprobarFunction;
    reprobarFunction = usarReprobar;

    // Asignar punteros a funcion en cartas
    unsigned int k;
    for (k = 0; k<6; k++){
        cartas[k]->aprobar = aprobarFunction;
        cartas[k]->reprobar = reprobarFunction;
    }

    char *NombreJugador = malloc(sizeof(int) * LARGONOMBREMAXIMO);
    // Iniciar El programa y pedir el nombre
    iniciarPrograma(NombreJugador, Jugador, PC);
    void* MazoOficial;
    MazoOficial = (tLista *)malloc(sizeof(tLista));
    initialize(MazoOficial);
    
    // Crear cartas posibles y repartir a cada jugador
    crearMazo(MazoOficial,cartas);
    giveCards(Jugador, MazoOficial);
    crearMazo(MazoOficial,cartas);
    giveCards(PC, MazoOficial);


    // Comenzar el juego
    int parar = 0;
    unsigned int ronda = 0;
    int i;
    for (i = 0;i < CARDSNUMBER*2; ++i) {
        // Verificar termino del juego
        if(PC->prioridad <= 0){
            printf(ANSI_COLOR_BLUE "***** %s ha ganado el juego (Prioridad de %s es 0) *****\n" ANSI_COLOR_RESET,Jugador->nombre,PC->nombre);
            parar = 1;
            break;
        }
        else if(Jugador->prioridad <= 0){
            printf(ANSI_COLOR_BLUE "***** %s ha ganado el juego (Prioridad de %s es 0) *****\n" ANSI_COLOR_RESET,PC->nombre,Jugador->nombre);
            parar = 1;
            break;
        }
        // Jugar
        if (i % 2 == 0) {
            jugar(Jugador, 0, PC, ronda);
        } else {
            jugar(PC, 1, Jugador, ronda);
            ronda++;
        }
    }
    // Gana el que tiene mayor prioridad
    if(parar == 0){
        system("clear");
        if(PC->prioridad > Jugador->prioridad){
            printf(ANSI_COLOR_BLUE "***** %s ha ganado la partida Prioridad %d vs %d *****\n" ANSI_COLOR_RESET, PC->nombre, PC->prioridad, Jugador->prioridad);
        }
        else if(PC->prioridad < Jugador->prioridad){

            printf(ANSI_COLOR_BLUE "***** %s ha ganado la partida Prioridad %d vs %d *****\n" ANSI_COLOR_RESET, Jugador->nombre, Jugador->prioridad, PC->prioridad);
        }
        else{
            printf(ANSI_COLOR_BLUE "***** Los jugadores empatan con una prioridad de %d *****" ANSI_COLOR_RESET,Jugador->prioridad);
        }
    }
    // Liberar memoria
    free(NombreJugador);
    free_linked(Jugador->mazo);
    free_linked(PC->mazo);
    free_linked(MazoOficial);
    free(Jugador);
    free(PC);
    freeCards(cartas);
}