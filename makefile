CC=g++
CFLAGS=-I.
DEPS = ./lib/*.hpp
OBJ = ./build/game-of-life.o

%.o:  %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

game-of-life: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf ../*o game-of-life 