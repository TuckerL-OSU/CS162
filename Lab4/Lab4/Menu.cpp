/******************************************************************************
* Tucker Lavell
* CS162 Fall 2017
* Lab 4: OSU Info System
* Menu.cpp
******************************************************************************/
#include "University.hpp"

void menu(University uni) {
	int input = 0;
	
	do {
		cout << "1. Info about buildings" << endl;
		cout << "2. Info about people of the University" << endl;
		cout << "3. Choose a person to do work" << endl;
		cout << "4. Exit" << endl;
		input = getValidIntegerInput("Choose the number of your action: ", 1, 4);

		switch (input) {
		case 1: uni.buildingInfo();
			break;
		case 2: uni.peopleInfo();
			break;
		case 3: uni.work();
			break;
		default: break;
		}
	} while (input != 4);

}

int main() {
	Student pers1;
	pers1.setAge(25);
	pers1.setName("Tucker");
	pers1.setGPA(4.0);

	Instructor pers2;
	pers2.setAge(43);
	pers2.setName("Mr. Teacher");
	pers2.setRating(5.0);

	Building build1;
	build1.setBuildName("Coastal Oceanography Lab");
	build1.setBuildAddress("891 SW 30th St, Corvallis, OR 97331");
	build1.setBuildSize(2416);

	Building build2;
	build2.setBuildName("Sackett Hall");
	build2.setBuildAddress("2901 SW Jefferson Way, Corvallis, OR 97331");
	build2.setBuildSize(137517);

	University uni;

	uni.addBuilding(&build1);
	uni.addBuilding(&build2);
	uni.addPerson(&pers1);
	uni.addPerson(&pers2);

	menu(uni);

	return 0;
}