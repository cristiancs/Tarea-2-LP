GCC=gcc
CFLAGS=-Wall

default: ejecutable

ejecutable: CartaCurso.o Sansano.o Lista.o main.o

%.o %.c
    $(GCC) $(FLAGS) -c $<

clean:
    rm *.o ejecutable