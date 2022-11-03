CC = g++
FLAGS = -g
BIN = hashmap
OBJS = HashMap.o HashNode.o mainHash.o MakeSeuss.o

all: ${OBJS}
	${CC} ${FLAGS} ${FLAGS} -o ${BIN} ${OBJS}

run: all
	./${BIN}

.cpp.o:
	${CC} ${FLAGS} -c $<

HashMap.o: HashMap.cpp HashMap.hpp hashNode.hpp
MashNode.o: HashNode.cpp HashNode.hpp 
mainHash.o: mainHash.cpp MakeSeuss.hpp
MakeSeuss.o: MakeSeuss.cpp MakeSeuss.hpp HashMap.hpp

clean:
	rm -f ${BIN} ${OBJS}