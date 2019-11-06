CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Queue.o Stack.o Menu.o Support.o

SRCS = Queue.cpp Stack.cpp Menu.cpp Support.cpp

HEADERS = Queue.hpp Stack.hpp Menu.hpp Support.hpp
	
Lab9_Lavell_Tucker: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Lab9_Lavell_Tucker
	
Queue: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Queue
		
Stack: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Stack
	
Menu: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Menu
		
Support: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Support
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o
	rm Lab9_Lavell_Tucker