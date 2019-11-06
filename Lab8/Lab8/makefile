CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = BinarySearch.o File.o LinearSearch.o Menu.o Sort.o Support.o

SRCS = BinarySearch.cpp File.cpp LinearSearch.cpp Menu.cpp Sort.cpp Support.cpp

HEADERS = BinarySearch.hpp File.hpp LinearSearch.hpp Menu.hpp Sort.hpp Support.hpp
	
Lab8_Lavell_Tucker: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Lab8_Lavell_Tucker
	
BinarySearch: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o BinarySearch
		
File: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o File
	
LinearSearch: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o LinearSearch
	
Menu: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Menu
	
Sort: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Sort
	
Support: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Support
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o
	rm Lab8_Lavell_Tucker