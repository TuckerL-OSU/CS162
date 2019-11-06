/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 4: OSU Info System
* Instructor.hpp
******************************************************************************/
#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP
#include "Person.hpp"


class Instructor : public Person {
public:
	Instructor();
	Instructor(double, string, int);
	~Instructor();

	int do_work();
	void printInfo();
	void printWork();

	void setRating(double);
	virtual double getRating();

private:
	double rating;
};

#endif // !INSTRUCTOR_HP