#Facultad de Ingeniería
#Universidad de Buenos Aires
#Algoritmos y programacion I (95.11)
#Profesor: Ing. Martín Cardozo
#Alumnos: Puy, Gonzalo - Reigada, Maximiliano Daniel
#Archivo: Makefile
#Descripción: Script de compilación

CFLAGS=-ansi -pedantic -Wall -o mp3explorer
CC=gcc

all: makefile clean

makefile: main_mp3explorer.o mp3explorer.o mp3.o track.o vector.o errors.o setup.o genres.o
	$(CC) $(CFLAGS) main_mp3explorer.o mp3explorer.o mp3.o track.o vector.o errors.o setup.o genres.o

main_mp3explorer.o: main_mp3explorer.c main_mp3explorer.h mp3explorer.h types.h errors.h
	$(CC) $(CFLAGS) -c main_mp3explorer.c -o main_mp3explorer.o

mp3explorer.o: mp3explorer.c types.h vector.h track.h mp3explorer.h mp3.h setup.h
	$(CC) $(CFLAGS) -c mp3explorer.c -o mp3explorer.o

mp3.o: mp3.c types.h mp3.h track.h vector.h
	$(CC) $(CFLAGS) -c mp3.c -o mp3.o

track.o: track.c track.h types.h genres.h
	$(CC) $(CFLAGS) -c track.c -o track.o

vector.o: vector.c vector.h types.h
	$(CC) $(CFLAGS) -c vector.c -o vector.o

errors.o: errors.c errors.h types.h
	$(CC) $(CFLAGS) -c errors.c -o errors.o

setup.o: setup.c setup.h types.h
	$(CC) $(CFLAGS) -c setup.c -o setup.o

clean:
	rm *.o
