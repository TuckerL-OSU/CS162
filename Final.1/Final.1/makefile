CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Player.o Backpack.o Board.o Space.o EmptyRoom.o HomeRoom.o ItemRoom.o RocketRoom.o Quest.o Support.o

SRCS = Player.cpp Backpack.cpp Board.cpp Space.cpp EmptyRoom.cpp HomeRoom.cpp ItemRoom.cpp RocketRoom.cpp Quest.cpp Support.cpp

HEADERS = Player.hpp Backpack.hpp Board.hpp Space.hpp EmptyRoom.hpp HomeRoom.hpp ItemRoom.hpp RocketRoom.hpp Quest.hpp Support.hpp
	
FinalProject_Lavell_Tucker: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o FinalProject_Lavell_Tucker
	
Player: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Player
		
Backpack: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Backpack
	
Board: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Board
		
Space: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Space
	
EmptyRoom: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o EmptyRoom

HomeRoom: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o HomeRoom

ItemRoom: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o ItemRoom

RocketRoom: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o RocketRoom

Quest: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Quest

Support: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Support

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o
	rm FinalProject_Lavell_Tucker