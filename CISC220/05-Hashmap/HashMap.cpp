

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
	int index = getIndex(k);
	if (map[index]->keyword == k){
		map[index]->addValue(v);
	}
	else if (map[index]==NULL){
		map[index] = new hashNode(k);
		map[index]->addValue(v);
		numKeys = numKeys + 1;
	}
	if (numKeys/(mapSize * 1.0) >= .7){
		reHash();
	}
}

int hashMap::getIndex(string k) {
	int index;
	if(hashfn) index = calcHash1(k);
	else index = calcHash2(k);

	if(map[index]->keyword!=k && map[index] != NULL){
		hashcoll = hashcoll + 1;
		if (collfn){
			index = coll1(index,1,k);
			collisions = collisions - 1;
		}
		else{
			index = coll2(index,1,k);
			collisions = collisions - 1;
		}
	}
	return index;
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
	// copy old map and size into temporary variables
	int oldSize = mapSize;
	hashNode** oldMap = map;

	// increment mapSize and generate new map
	getClosestPrime();
	map = new hashNode*[mapSize];

	// copy old values to new map
	int index;
	for(int i = 0; i < oldSize; i++) {
		if(oldMap[i] == NULL) continue;

		if(hashfn) index = calcHash1(oldMap[i]->keyword);
		else index = calcHash2(oldMap[i]->keyword);

		map[index] = oldMap[i];
	}

	delete oldMap;
}

int hashMap::coll1(int h, int i, string k) {
	/*
	Only using h and k, not sure what i is needed for;
	Casts previously computed hash to a char, appends it to the end
	of the key and hashes this new string. If the newly calculated
	space is NULL or it's key matches the current key; it returns the
	hash. Otherwise, it recursively calls itself with the last hash
	*/

	// cut the used hash into a char and append it to the end of the key
	string newKey = k + (char)h;

	// hash the new key
	int newHash;
	if(hashfn) newHash = calcHash1(newKey);
	else newHash = calcHash2(newKey);

	if(map[newHash] == NULL || map[newHash]->keyword == k) return newHash;
	else return coll1(newHash, 0, k);
}

int hashMap::coll2(int h, int i, string k) {
	/*
	Only using h and k;
	Using probing with incrementation by 1 until space is NULL or
	key is equal to current key;
	*/

	while(map[h] != NULL && map[h]->keyword != k) {
		h++;
	}

	return h;
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


