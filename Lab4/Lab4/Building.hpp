/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 4: OSU Info System
* Building.hpp
******************************************************************************/
#ifndef BUILDING_HPP
#define BUILDING_HPP
#include <string>

using std::string;

class Building
{
public:
	Building();
	~Building();

	void setBuildName(string);
	virtual string getBuildName();

	void setBuildAddress(string);
	virtual string getBuildAddress();

	void setBuildSize(int);
	virtual int getBuildSize();

private:
	string buildName;
	string buildAddress;
	int buildSize;
};

#endif // !BUILDING_HPP