CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Paper.o play_game.o Rock.o RPSGame.o Scissors.o Support.o Tool.o

SRCS = Paper.cpp play_game.cpp Rock.cpp RPSGame.cpp Scissors.cpp Support.cpp Tool.cpp

HEADERS = Paper.hpp Rock.hpp RPSGame.hpp Scissors.hpp Support.hpp Tool.hpp
	
Group26: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Group26
	
Paper: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Paper
		
play_game: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o play_game
	
Rock: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Rock
	
RPSGame: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o RPSGame
	
Scissors: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Scissors
	
Support: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Support
	
Tool: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Tool
	
clean:
	rm *.o
	rm Group26