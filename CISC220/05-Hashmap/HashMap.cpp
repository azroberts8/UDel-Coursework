#include "HashMap.hpp"
#include "HashNode.hpp"
#include <iostream>
#include <math.h>
using namespace std;

const int primeSizes[] = {97, 197, 397, 797, 1597, 3203, 6421, 12853, 25717, 51437, 102877, 205759, 411527, 823117};

hashMap::hashMap(bool hash1, bool coll1) {
    numKeys, collisions, hashcoll, primeIndex = 0;
    mapSize = primeSizes[primeIndex];
    map = new hashNode*[mapSize]();
    hashfn = hash1;
    collfn = coll1;
    first = "";
}

void hashMap::addKeyValue(string k , string v) {
    int index = getIndex(k);
    if(map[index] == NULL) {
        map[index] = new hashNode(k);
        numKeys++;
    }
    map[index]->addValue(v);
}

int hashMap::getIndex(string k) {
    if((float)numKeys / (float)mapSize >= 0.7) reHash();

    return findSpace(k);
}

int hashMap::calcHash1(string k) {
    int hash = 0;
    unsigned int temp;
    for(int i = 0; i < k.length(); i++) {
        temp = hash + (int)k[i] * (int)pow((double)7, (double)i);
        hash = temp % mapSize;
    }
    return hash;
}

int hashMap::calcHash2(string k) {
    int hash = 0;
    unsigned int temp;
    for(int i = 0; i < k.length(); i++) {
        temp = hash + (int)k[i] * (int)pow((double)17, (double)i);
        hash = temp % mapSize;
    }
    return hash;
}

void hashMap::getClosestPrime() {
    mapSize = primeSizes[primeIndex++];
}

void hashMap::reHash() {
    // copy old map and size into temporary variables
    int oldSize = mapSize;
    hashNode** oldMap = map;

    // increment mapSize and generate new map
    getClosestPrime();
    map = new hashNode*[mapSize]();
    int i;

    // copy old values to new map
    int index;
    for(i = 0; i < oldSize; i++) {
        if(oldMap[i] == NULL) continue;

        index = findSpace(oldMap[i]->keyword);

		map[index] = oldMap[i];
    }

    delete oldMap;
}

int hashMap::coll1(int h, int i, string k) {
    // implementing linear probing (i and k are not used)
    return (h+1) % mapSize;
}

int hashMap::coll2(int h, int i, string k) {
    // implementing rehashing (i is not used)

    string seed = k + (char)h;
    if(hashfn) return calcHash1(seed);
    else return calcHash2(seed);
}

int hashMap::findSpace(string k) {
    int index;
    if(hashfn) index = calcHash1(k);
    else index = calcHash2(k);

    while(map[index] != NULL) {
        if(map[index]->keyword == k) break;
        if(collfn) index = coll1(index, 0, k);
        else index = coll2(index, 0, k);
    }
    return index;
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
