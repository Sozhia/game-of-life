CC=g++
CFLAGS=-I.
DEPS = ../lib/State.hpp \
			 ../lib/Cell.hpp \
			 ../lib/Grid.hpp \
			 ../lib/StateDead.hpp \
			 ../lib/StateAdult.hpp \
			 ../lib/StateEgg.hpp \
			 ../lib/StateLarva.hpp \
			 ../lib/StatePupa.hpp \

OBJ = $(DEPS:.hpp=.o)

./%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

game-of-life: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS) 

clean:
		rm -rf *o ./game-of-life
		rm -rf *o ../lib/*.o
		rm -rf *o ../*.o