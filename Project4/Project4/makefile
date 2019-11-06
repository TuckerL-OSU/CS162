CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Barbarian.o BlueMen.o Character.o Die.o Game.o HarryPotter.o Medusa.o Support.o Vampire.o Queue.o

SRCS = Barbarian.cpp BlueMen.cpp Character.cpp Die.cpp Game.cpp HarryPotter.cpp Medusa.cpp Support.cpp Vampire.cpp Queue.cpp

HEADERS = Barbarian.hpp BlueMen.hpp Character.hpp Die.hpp Game.hpp HarryPotter.hpp Medusa.hpp Support.hpp Vampire.hpp Queue.hpp
	
Project4_Lavell_Tucker: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Project4_Lavell_Tucker

Support: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Support

Die: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Die

Character: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Character
	
Barbarian: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Barbarian
		
BlueMen: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o BlueMen
		
HarryPotter: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o HarryPotter
	
Medusa: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Medusa
		
Vampire: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Vampire

Queue: ${OBJ} ${Headers}
	${CXX} ${OBJS} -o Queue

Game: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Game

	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o
	rm Project4_Lavell_Tucker