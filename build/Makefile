CC=g++
CFLAGS=-I.
DEPS = ../lib/Grid.hpp \
			 ../lib/State.hpp \
			 ../lib/Cell.hpp \
			 ../lib/StateDead.hpp \
			 ../lib/StateAdult.hpp \
			 ../lib/StateEgg.hpp \
			 ../lib/StateLarva.hpp \
			 ../lib/StatePupa.hpp \
			 ../game-of-life.cpp \

OBJ =  ../lib/Cell.o \
			 ../lib/Grid.o \
			 ../lib/StateDead.o \
			 ../lib/StateAdult.o \
			 ../lib/StateEgg.o \
			 ../lib/StateLarva.o \
			 ../lib/StatePupa.o \
			 ../game-of-life.o	\

./%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

game-of-life: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS) 

clean:
		rm -rf *o ./game-of-life
		rm -rf *o ../lib/*.o
		rm -rf *o ../*.o