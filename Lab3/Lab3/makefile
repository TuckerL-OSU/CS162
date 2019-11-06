CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Game.o Die.o LoadedDie.o

SRCS = Game.cpp Die.cpp LoadedDie.cpp

HEADERS = Game.hpp Die.hpp LoadedDie.hpp
	
Lab3_Lavell_Tucker: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Lab3_Lavell_Tucker
	
Game: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Game
	
Die: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Die

LoadedDie: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o LoadedDie
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o
	rm Lab3_Lavell_Tucker