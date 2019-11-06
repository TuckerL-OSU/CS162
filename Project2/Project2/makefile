CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Game.o Animal.o Tiger.o Penguin.o Turtle.o Zoo.o Validation.o

SRCS = Game.cpp Animal.cpp Tiger.cpp Penguin.cpp Turtle.cpp Zoo.cpp Validation.cpp

HEADERS = Game.hpp Animal.hpp Tiger.hpp Penguin.hpp Turtle.hpp Zoo.hpp Validation.hpp
	
Project2_Lavell_Tucker: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Project2_Lavell_Tucker
	
Game: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Game
	
Animal: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Animal

Tiger: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Tiger
	
Penguin: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Penguin

Turtle: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Turtle

Zoo: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Zoo
	
Validation: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Validation
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o
	rm Project2_Lavell_Tucker