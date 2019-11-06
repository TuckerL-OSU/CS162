CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Menu.o DoublyLinkedList.o Node.o Support.o

SRCS = Menu.cpp DoublyLinkedList.cpp Node.cpp Support.cpp

HEADERS = DoublyLinkedList.hpp Node.hpp Support.hpp
	
Lab6_Lavell_Tucker: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Lab6_Lavell_Tucker
	
Menu: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Menu
		
DoublyLinkedList: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o DoublyLinkedList
	
Node: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Node
	
Support: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Support
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o
	rm Lab6_Lavell_Tucker