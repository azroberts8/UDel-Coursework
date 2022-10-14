/*
 * bstNode.hpp
 */

#include <stdlib.h>
#include "Student.hpp"
using namespace std;

class BSTNode {
    public:
        BSTNode* left;
        BSTNode* right;
        BSTNode* parent;
        int height;
        Student* student;
        BSTNode();
        BSTNode(string fName, string lName, int favNum, string joke);
        ~BSTNode();
        void printNode();
};