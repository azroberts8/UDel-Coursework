/*
 * Dog.cpp
 *
 *  Created on: Sep 8, 2022
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


bool changeStrength(int amt)
{
	strength += amt;
	printDog();

	if(strength > 0){
		return true;
	}else{
		die();
	}




}// end of changeStrength function

void Dog::die()
{

}//end of die function

void Dog::printDog()
{

}//end of printDog function

void Dog::won()
{

}//end of won function

void Dog::reset()
{

}//end of reset function









