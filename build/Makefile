CC=g++
CFLAGS=-I.
DEPS = ../lib/Cell.hpp ../lib/Grid.hpp ../lib/IState.hpp ../lib/StateEgg.hpp ../lib/StateLarva.hpp ../lib/StatePupa.hpp ../lib/StateAdult.hpp ../lib/StateDead.hpp
OBJ = ../game-of-life.o ../lib/Grid.o ../lib/Cell.o ../lib/IState.o ../lib/StateEgg.o ../lib/StateLarva.o ../lib/StatePupa.o ../lib/StateAdult.o ../lib/StateDead.o

./%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

game-of-life: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS) 

clean:
		rm -rf *o ./game-of-life
		rm -rf *o ../lib/*.o
		rm -rf *o ../*.o