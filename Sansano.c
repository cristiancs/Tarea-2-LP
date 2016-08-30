//funciones de configuracion de Sansano
#include "Sansano.h"

void iniciarPrograma(char * NombreJugador, struct Sansano Jugador, struct Sansano PC){
    printf("Bienvenido a SansaStone, ¿Cual es su nombre? (Espacios no permitidos)\n");
    scanf("%s", NombreJugador);
    printf("Hola %s, tu prioridad inicial es de 4500\n", NombreJugador);

    Jugador.nombre = NombreJugador;
    Jugador.prioridad = 4500;
    PC.nombre = "Universidad";
    PC.prioridad = 4500;
}


void  giveCards(struct Sansano *Jugador){
    printf("%s",Jugador->nombre);
    /* Deal some cards */
    enum { SUITS = 4, NUMBERS = 13, CARDS = 52 };
    char cards[CARDS];

    for (int i = 0; i < CARDS; ++i)
        cards[i] = i;

    for (int i = CARDS; i > 1; --i) {
        int chosen = pcg32_boundedrand(i);
        char card = cards[chosen];
        cards[chosen] = cards[i - 1];
        cards[i - 1] = card;
    }

    printf("  Cards:");
    static const char number[] = {'A', '2', '3', '4', '5', '6', '7',
                                  '8', '9', 'T', 'J', 'Q', 'K'};
    static const char suit[] = {'h', 'c', 'd', 's'};
    for (int i = 0; i < CARDS; ++i) {
        printf(" %c%c", number[cards[i] / SUITS], suit[cards[i] % SUITS]);
        if ((i + 1) % 22 == 0)
            printf("\n\t");
    }
    printf("\n");

}
