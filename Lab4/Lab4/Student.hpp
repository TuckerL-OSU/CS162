/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 4: OSU Info System
* Student.hpp
******************************************************************************/
#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "Person.hpp"

class Student : public Person {
public:
	Student();
	Student(double, string, int);
	~Student();

	int do_work();
	void printInfo();
	void printWork();

	void setGPA(double);
	virtual double getGPA();

private:
	double GPA;
};

#endif // !STUDENT_HPP