CC=gcc
CFLAGS=-I.
DEPS = functions.h
OBJ = main.o createWorld.o createFutureWorld.o printWorld.o updateCurWorld.o updateFutureWorld.o writeWorldToFile.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)