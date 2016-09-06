#include "main.h"

int main(){

    pcg32_random_t rng;

    pcg32_srandom_r(&rng,(uint64_t) time(NULL) ^ (intptr_t)&printf,
                    (uint64_t) "1");

    // Jugadores
    struct Sansano* Jugador = malloc(sizeof(struct Sansano));
    Jugador->mazo = malloc(sizeof(tLista));
    initialize(Jugador->mazo);
    struct Sansano* PC = malloc(sizeof(struct Sansano));
    PC->mazo = malloc(sizeof(tLista));
    initialize(PC->mazo);
    // Cartas
    CartaCurso* mate = malloc(sizeof(CartaCurso));
    CartaCurso* fisica = malloc(sizeof(CartaCurso));
    CartaCurso* lp = malloc(sizeof(CartaCurso));
    CartaCurso* progra = malloc(sizeof(CartaCurso));
    CartaCurso* ed = malloc(sizeof(CartaCurso));
    CartaCurso* edd = malloc(sizeof(CartaCurso));
    CartaCurso* cartas[6] = {mate,fisica,lp,progra,ed,edd};

    // Punteros a funciones
    typedef void (*playFunction)(void *, void *);
    playFunction aprobarFunction;
    aprobarFunction = usarAprobar;
    playFunction reprobarFunction;
    reprobarFunction = usarReprobar;

    // Inicializar Cartas
    mate->nombre = "Matematicas";
    mate->descripcion = "";
    mate->ataque = 550;
    mate->defensa = 200;
    mate->aprobar = aprobarFunction;
    mate->reprobar = reprobarFunction;

    fisica->nombre = "Fisica";
    fisica->descripcion = "";
    fisica->ataque = 450;
    fisica->defensa = 150;
    fisica->aprobar = aprobarFunction;
    fisica->reprobar = reprobarFunction;

    lp->nombre = "Lenguajes de Programación";
    lp->descripcion = "";
    lp->ataque = 510;
    lp->defensa = 180;
    lp->aprobar = aprobarFunction;
    lp->reprobar = reprobarFunction;

    progra->nombre = "Programación";
    progra->descripcion = "";
    progra->ataque = 110;
    progra->defensa = 300;
    progra->aprobar = aprobarFunction;
    progra->reprobar = reprobarFunction;

    ed->nombre = "Estructura de Datos";
    ed->descripcion = "";
    ed->ataque = 470;
    ed->defensa = 160;
    ed->aprobar = aprobarFunction;
    ed->reprobar = reprobarFunction;

    edd->nombre = "Estructura Discretas";
    edd->descripcion = "";
    edd->ataque = 430;
    edd->defensa = 120;
    edd->aprobar = aprobarFunction;
    edd->reprobar = reprobarFunction;



    char *NombreJugador = malloc(sizeof(int) * LARGONOMBREMAXIMO);
    // Iniciar El programa y pedir el nombre
    iniciarPrograma(NombreJugador, Jugador, PC);
    void* MazoOficial;
    MazoOficial = (tLista *)malloc(sizeof(tLista));
    initialize(MazoOficial);
    crearMazo(MazoOficial,cartas);

    giveCards(Jugador, MazoOficial,rng);
    crearMazo(MazoOficial,cartas);
    giveCards(PC, MazoOficial,rng);


    // Comenzar el juego
    int parar = 0;
    for (int i = 0;i < CARDSNUMBER*2; ++i) {
        // Jugar
        if (i % 2 == 0) {
            jugar(Jugador, 0, PC, rng);
        } else {
            jugar(PC, 1, Jugador, rng);
        }
        // Verificar termino del juego
        if(Jugador->prioridad <= 0){
            printf("%s ha ganado el juego (Prioridad de %s es 0)\n",Jugador->nombre,PC->nombre);
            parar = 1;
        }
        else if(PC->prioridad <= 0){
            printf("%s ha ganado el juego (Prioridad de %s es 0)\n",PC->nombre,Jugador->nombre);
            parar = 1;
        }
    }
    // Gana el que tiene mayor prioridad
    if(parar == 0){
        system("clear");
        if(PC->prioridad > Jugador->prioridad){

            printf("%s ha ganado la partida Prioridad %d vs %d\n", PC->nombre, PC->prioridad, Jugador->prioridad);
        }
        else if(PC->prioridad < Jugador->prioridad){

            printf("%s ha ganado la partida Prioridad %d vs %d\n", Jugador->nombre, Jugador->prioridad, PC->prioridad);
        }
        else{
            printf("Los jugadores empatan con una prioridad de %d",Jugador->prioridad);
        }
    }





    free(NombreJugador);
    free_linked(Jugador->mazo);
    free_linked(PC->mazo);
    free_linked(MazoOficial);
    free(Jugador);
    free(PC);
    free(mate);
    free(fisica);
    free(lp);
    free(progra);
    free(ed);
    free(edd);
}