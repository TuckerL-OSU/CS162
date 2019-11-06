CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Main.o FileHandler.o Letters.o

SRCS = Main.cpp FileHandler.cpp Letters.cpp

HEADERS = FileHandler.hpp Letters.hpp
	
Lab2_Lavell_Tucker: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Lab2_Lavell_Tucker
	
FileHandler: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o FileHandler
	
Letters: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Letters
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

	
clean:
	rm *.o
	rm Lab2_Lavell_Tucker