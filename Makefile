TARGET   = test
OBJ      = \
	StringHelper.o\
	main.o

CXXFLAGS = -Wall -std=c++0x

all:${TARGET}

${TARGET}:${OBJ}
	${CXX} ${CXXFLAGS} -o $@ $^

%.o:%.cpp
	${CXX} -c ${CXXFLAGS} $^

clean:
	${RM} *.o ${TARGET}

