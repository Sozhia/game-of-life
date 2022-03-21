CC=g++
CFLAGS=-I.
DEPS = ../lib/Grid.hpp \
			 ../lib/GridWithFrozenBorder.hpp \
			 ../lib/GridWithOpenBorder.hpp \
			 ../lib/GridWithPeriodicBorder.hpp \
			 ../lib/GridWithReflectiveBorder.hpp \
			 ../lib/State.hpp \
			 ../lib/Cell.hpp \
			 ../lib/StateDead.hpp \
			 ../lib/StateAlive.hpp \
			 ../game-of-life.cpp \

OBJ =  ../lib/Cell.o \
			 ../lib/GridWithFrozenBorder.o \
			 ../lib/GridWithOpenBorder.o \
			 ../lib/GridWithPeriodicBorder.o \
			 ../lib/GridWithReflectiveBorder.o \
			 ../lib/StateDead.o \
			 ../lib/StateAlive.o \
			 ../game-of-life.o	\

./%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

game-of-life: $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS) 

clean:
		rm -rf *o ./game-of-life
		rm -rf *o ../lib/*.o
		rm -rf *o ../*.o