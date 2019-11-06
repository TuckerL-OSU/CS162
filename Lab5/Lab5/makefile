CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Recursion.o Validation.o

SRCS = Recursion.cpp Validation.cpp

HEADERS = Recursion.hpp Validation.hpp
	
Lab5_Lavell_Tucker: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Lab5_Lavell_Tucker
	
Recursion: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Recursion
		
Validation: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Validation
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o
	rm Lab5_Lavell_Tucker