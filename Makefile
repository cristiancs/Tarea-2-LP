GCC=gcc
FLAGS=-Wall

default: ejecutable

ejecutable: pcg_basic.o CartaCurso.o Sansano.o lista.o main.o
	$(GCC) $^ -o $@

pcg_basic.o: libraries/pcg-c-basic-0.9/pcg_basic.c
	$(GCC) $(FLAGS) -c $<

%.o: %.c
	$(GCC) $(FLAGS) -c $<

clean:
	rm *.o ejecutable