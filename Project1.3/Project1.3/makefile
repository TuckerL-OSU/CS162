CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Main.o Ant.o

SRCS = Main.cpp Ant.cpp

HEADERS = Ant.hpp Array.hpp
	
Project1_Lavell_Tucker: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Project1_Lavell_Tucker
	
Ant: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Ant
		
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

	
clean:
	rm *.o
	rm Project1_Lavell_Tucker_Lavell_Tucker