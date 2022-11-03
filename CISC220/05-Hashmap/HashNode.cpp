

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
	currSize += 1;
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

	delete oldValues;
}

string hashNode::getRandValue() {
	return values[rand() % currSize];
}
