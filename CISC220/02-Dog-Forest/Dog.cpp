/*
 * Dog.cpp
 *
 *  Created on: Sep 11, 2022
 *      Author: stephenwiafe
 */

#include <iostream>
#include "Dog.hpp"
using namespace std;

Dog::Dog(string n)
{
	name = n;
	strength = 50;
	x = 0;
	y = 0;

}//end of Dog constructor

Dog::Dog()
{
	strength = 50;
	x = 0;
	y = 0;

} //end of Dog(string) constructor


bool Dog::changeStrength(int amt)
{
	strength += amt;
	//printDog();

	if(strength > 0){
		return true;
	} else {
		die();
		return false;
	}
}// end of changeStrength function


void Dog::die()
{
	cout << "Dog died...ACK!!!" << endl;

}//end of die function

void Dog::printDog()
{
	cout << name << ": Strength: " << strength << endl;

}//end of printDog function

void Dog::won()
{
	cout << "CONGRATULATIONS!!!  You have successfully navigate fido through the evil forest!!!" << endl;

}//end of won function

void Dog::reset()
{
	strength = 50;
	x = 0;
	y = 0;

}//end of reset function




