

#include "HashMap.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;



hashNode::hashNode(string s){
	keyword = s;
	values = new string[100];
	valuesSize = 100;
	currSize = 0;
	srand(time(NULL));
}
hashNode::hashNode(){
	keyword = "";
	values = new string[100];
	valuesSize = 100;
	currSize = 0;
	srand(time(NULL));
}
hashNode::hashNode(string s, string v){
	keyword = s;
	values = new string[100];
	values[0] = v;
	valuesSize = 100;
	currSize = 1;
}
void hashNode::addValue(string v) {
	currSize++;
	//cout << "\"" << keyword << "\".addValue(" << v << "): Size is now " << currSize << endl;
	if(currSize == valuesSize) dblArray();
	values[currSize] = v;
}

void hashNode::dblArray() {
	valuesSize += valuesSize;
	string* oldValues = values;
	values = new string[valuesSize];

	for(int i = 0; i < valuesSize/2; i++) {
		values[i] = oldValues[i];
	}

	//delete oldValues;  <-- Causes a seg fault
}

string hashNode::getRandValue() {
	cout << "getRandValue() 0" << endl;
	//cout << "Word: " << keyword << endl;
	int foo = rand();
	//cout << "Rand: " << foo << ", currSize: " << currSize << ", values[0]: " << values[0] << endl;
	int temp = foo % currSize;
	cout << "getRandValue() 1" << endl;
	return values[temp];
}
