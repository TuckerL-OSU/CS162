CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = Menu.o University.o Building.o Person.o Instructor.o Student.o Validation.o

SRCS = Menu.cpp University.cpp Building.cpp Person.cpp Instructor.cpp Student.cpp Validation.cpp

HEADERS = University.hpp Building.hpp Person.hpp Instructor.hpp Student.hpp Validation.hpp
	
Lab4_Lavell_Tucker: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Lab4_Lavell_Tucker
	
Menu: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Menu
	
University: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o University

Building: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Building
	
Person: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Person

Instructor: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Instructor

Student: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Student
	
Validation: ${OBJS} ${Headers}
	${CXX} ${OBJS} -o Validation
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o
	rm Lab4_Lavell_Tucker