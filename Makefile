TARGET   = split
SRC      = main.cpp split.cpp
OBJ      = main.o split.o

CXXFLAGS = -Wall -std=c++0x

all:${TARGET}

${TARGET}:${OBJ}
	${CXX} ${CXXFLAGS} -o $@ $^

${OBJ}:${SRC}
	${CXX} -c ${CXXFLAGS} $^

clean:
	${RM} *.o ${TARGET}

