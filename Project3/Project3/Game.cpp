#include "Character.hpp"
#include "Barbarian.hpp"

int main() {
	//Die *attack;
	//attack = new Die(6, 2);
	//cout << "attack: ";
	//attack->roll();
	//cout << attack;
	srand(time(NULL));

	Character *barb1 = new Barbarian(12, 89);
	barb1->setName("First_Barb");
	Character *barb2 = new Barbarian(121, 39);
	barb2->setName("Second_Barb");

	Character::battle(barb1, barb2);
	

	//Die *die = new Die(6, 2);
	//cout << die->roll() << endl;
	//cout << die->roll() << endl;
	//cout << die->roll() << endl;
	//cout << die->roll() << endl;
	//cout << die->roll() << endl;
	//cout << die->roll() << endl;


	//Die *die2 = new Die(6, 2);
	//cout << die2->roll() << endl;
	//cout << die2->roll() << endl;
	//cout << die2->roll() << endl;
	//cout << die2->roll() << endl;
	//cout << die2->roll() << endl;
	//cout << die2->roll() << endl;

	return 0;


}