CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Menu.o Queue.o Support.o

SRCS = Menu.cpp Queue.cpp Support.cpp

HEADERS = Queue.hpp Support.hpp
	
Lab7_Lavell_Tucker: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Lab7_Lavell_Tucker
	
Menu: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Menu
	
Queue: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Queue

Support: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Support
	
		
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

	
clean:
	rm *.o
	rm Lab7_Lavell_Tucker