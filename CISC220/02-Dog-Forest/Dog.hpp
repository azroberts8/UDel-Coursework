/*
 * Dog.hpp
 *
 *  Created on: Sep 8, 2022
 *      Author: stephenwiafe
 */
#include <string>
using namespace std;

#ifndef DOG_HPP_
#define DOG_HPP_

class Dog
{
	friend class Board;
public:
	Dog(string n);
	Dog();
	bool changeStrength(int amt);
	void die();
	void printDog();
	void won();
	void reset();

private:
	string name;
	int strength;
	int x;
	int y;
}; // end of class

#endif /* DOG_HPP_ */
