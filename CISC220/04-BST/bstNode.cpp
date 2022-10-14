/*
 * bstNode.cpp
 */

#include "bstNode.hpp"
#include <stdlib.h>
using namespace std;

BSTNode::BSTNode() {
    left = right = parent = NULL;
    student = NULL;
    height = 0;
}

BSTNode::BSTNode(string fName, string lName, int favNum, string joke) {
    left = right = parent = NULL;
    student = new Student(fName, lName, favNum, joke);
    height = 0;
}

BSTNode::~BSTNode() {
    delete left;
    delete right;
    delete student;
}

void BSTNode::printNode() {
    cout << "Node height: " << height << " Student: " << student->first << " " << student->last << endl;
}