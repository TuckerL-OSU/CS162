/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 4: OSU Info System
* Person.hpp
******************************************************************************/
#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>
#include <iostream>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

class Person
{
public:
	Person();
	Person(string, int);
	~Person();

	void setName(string);
	virtual string getName();

	void setAge(int);
	virtual int getAge();

	virtual int do_work();
	virtual void printWork();

	virtual void printInfo();

protected:
	string name;
	int age;

private:
};

#endif // !PERSON_HPP