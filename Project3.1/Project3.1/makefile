CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Barbarian.o BlueMen.o Character.o Die.o Game.o HarryPotter.o Medusa.o Support.o Vampire.o

SRCS = Barbarian.cpp BlueMen.cpp Character.cpp Die.cpp Game.cpp HarryPotter.cpp Medusa.cpp Support.cpp Vampire.cpp

HEADERS = Barbarian.hpp BlueMen.hpp Character.hpp Die.hpp Game.hpp HarryPotter.hpp Medusa.hpp Support.hpp Vampire.hpp
	
Project3_Lavell_Tucker: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Project3_Lavell_Tucker
	
Barbarian: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Barbarian
		
BlueMen: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o BlueMen
	
Character: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Character
	
Die: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Die
	
Game: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Game
	
HarryPotter: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o HarryPotter
	
Medusa: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Medusa
	
Support: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Support
	
Vampire: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Vampire
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o
	rm Project3_Lavell_Tucker