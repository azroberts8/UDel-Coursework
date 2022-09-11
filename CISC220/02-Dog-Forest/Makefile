CC=gcc
CCFLAGS=-lstdc++

all:
	$(CC) -o dogForest mainGame.cpp Board.cpp Dog.cpp $(CCFLAGS)

run: all
	./dogForest

clean:
	rm -f ./dogForest

rebuild:
	make clean
	make all

rerun:
	make rebuild
	make run
