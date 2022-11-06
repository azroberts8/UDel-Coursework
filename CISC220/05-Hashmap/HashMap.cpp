

#include "HashMap.hpp"
#include "HashNode.hpp"
#include <iostream>
#include <math.h>
using namespace std;

hashMap::hashMap(bool hash1, bool coll1) {
	mapSize = 97;
	map = new hashNode*[mapSize];
	numKeys, collisions, hashcoll, primeIndex = 0;
	hashfn = hash1;
	collfn = coll1;
	first = "";

	// Array of 14 primes where each prime is at least 2x previous starting at 97 (used in getClosestPrime())
	primeSizes = new int[97, 197, 397, 797, 1597, 3203, 6421, 12853, 25717, 51437, 102877, 205759, 411527, 823117];
}
void hashMap::addKeyValue(string k, string v) {

}
int hashMap::getIndex(string k) {
}

int hashMap::calcHash2(string k){
	int hash = 0;
	for(int i = 0; i < k.length(); i++) {
		hash = (hash + (int)k[i] * (int)pow((double)17, (double)i)) % mapSize;
	}
	return hash;
}

int hashMap::calcHash1(string k){
	int hash = 0;
	for(int i = 0; i < k.length(); i++) {
		hash = (hash + (int)k[i] * (int)pow((double)7, (double)i)) % mapSize;
	}
	return hash;
}

void hashMap::getClosestPrime() {
	// Work smarter not harder; who needs a BST when most of the values are never used
	mapSize = primeSizes[primeIndex++];
}

void hashMap::reHash() {
}
int hashMap::coll1(int h, int i, string k) {
}
int hashMap::coll2(int h, int i, string k) {
}

void hashMap::printMap() {
	cout << "In printMap()" << endl;
	for (int i = 0; i < mapSize; i++) {
		//cout << "In loop" << endl;
		if (map[i] != NULL) {
			cout << map[i]->keyword << ": ";
			for (int j = 0; j < map[i]->currSize;j++) {
				cout << map[i]->values[j] << ", ";
			}
			cout << endl;
		}
	}
}


