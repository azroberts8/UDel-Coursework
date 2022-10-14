CC=gcc
CCFLAGS=-lstdc++

all:
	$(CC) -o BST *.cpp $(CCFLAGS)

run: all
	./BST

clean:
	rm -f ./BST

rebuild:
	make clean
	make all

rerun:
	make rebuild
	make run
