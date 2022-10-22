/*
 * bstNode.cpp
 */

#include "bstNode.hpp"
#include <stdlib.h>
using namespace std;

BSTNode::BSTNode() {
    left = right = parent = NULL;
    student = NULL;
    height = 1;
}

BSTNode::BSTNode(string fName, string lName, int favNum, string joke) {
    left = right = parent = NULL;
    student = new Student(fName, lName, favNum, joke);
    height = 1;
}

BSTNode::~BSTNode() {
    // Only calling delete on student because clearTree() recursively deletes nodes causing seg fault if added here
    cout << "Deleting " << student->first << " " << student->last << endl << endl;
    left = NULL;
    right = NULL;
    parent = NULL;
    delete student;
    student = NULL;
}

void BSTNode::printNode() {
    cout << "Node height: " << height << " Student: " << student->first << " " << student->last << endl << "Joke: " << student->joke << endl << "--------------------------------------------------------------" << endl;
}
