CC = g++
FLAGS = -g
BIN = DSP
OBJS = Dijkstra.o graphMain.o

all: ${OBJS}
	${CC} ${FLAGS} -o ${BIN} ${OBJS}

run: all
	./${BIN}

.cpp.o:
	${CC} ${FLAGS} -c $<

Dijkstra.o: Dijkstra.cpp Dijkstra.hpp
graphMain.o: graphMain.cpp Dijkstra.hpp

clean:
	rm -f ${BIN} ${OBJS}