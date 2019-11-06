CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Main.o Determinant.o ReadMatrix.o

SRCS = Main.cpp Determinant.cpp ReadMatrix.cpp

HEADERS = Determinant.hpp ReadMatrix.hpp
	
Lab1_Lavell_Tucker: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Lab1_Lavell_Tucker
	
Determinant: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Determinant
	
ReadMatrix: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o ReadMatrix
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

	
clean:
	rm *.o
	rm Lab1_Lavell_Tucker