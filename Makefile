GCC=gcc
CFLAGS=-Wall

default: ejecutable

ejecutable: pcg_basic.o CartaCurso.o Sansano.o lista.o main.o
	$(GCC) $^ -o $@

%.o: %.c
	$(GCC) $(FLAGS) -c $<

clean:
	rm *.o ejecutable