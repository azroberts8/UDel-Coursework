CC=gcc
CCFLAGS=-lstdc++

all:
	$(CC) -o DLL *.cpp $(CCFLAGS)

run: all
	./DLL

clean:
	rm -f ./DLL

rebuild:
	make clean
	make all

rerun:
	make rebuild
	make run
