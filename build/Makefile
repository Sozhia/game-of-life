CC=g++
CFLAGS=-I.
DEPS = ../lib/Cell.hpp ../lib/Grid.hpp 
OBJ = ../game-of-life.o ../lib/Grid.o ../lib/Cell.o

./%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

game-of-life: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS) 

clean:
		rm -rf *o game-of-life