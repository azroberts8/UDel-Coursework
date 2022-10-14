/*
 * bst.cpp
 */

#include "bst.hpp"
using namespace std;

bool bst::insert(string f, string l, int n, string j) {

}

BSTNode* bst::find(string l, string f) {

}

void bst::printTreeIO(BSTNode* n) {

}

void bst::printTreePre(BSTNode* n) {

}

void bst::printTreePost(BSTNode* n) {
    
}

BSTNode* bst::remove(string l, string f) {

}

BSTNode* bst::removeNoKids(BSTNode* tmp) {

}

BSTNode* bst::removeOneKid(BSTNode* tmp, bool leftFlag) {

}

void bst::setHeight(BSTNode* n) {

}

/* Constructors provided by Yarrington */
bst::bst() {
    root = NULL;
}

bst::bst(string f, string l, int n, string j) {
    root = new BSTNode(f, l, n, j);
}

/* Provided by Yarrington */
void bst::clearTree() {
    // this calls the recursive clearTree with the root node
    if(root == NULL) {
        cout << "Tree already empty" << endl;
    } else {
        cout << "Tree already empty" << endl;
        clearTree(root);
        root = NULL;
    }
}

void bst::clearTree(BSTNode* tmp) {
    if(tmp == NULL) {
        return;
    } else {
        clearTree(tmp->left);
        clearTree(tmp->right);
        tmp->printNode();
        delete(tmp);
    }
}

// continue at her NOTE line in the instructions

void bst::printTreeIO() {
    if(root == NULL) {
        cout << "Empty Tree" << endl;
    } else {
        cout << endl << "Printing In Order:" << endl;
        printTreeIO(root);
    }
}

void bst::printTreePre() {
    if(root == NULL) {
        cout << "Empty Tree" << endl;
    } else {
        cout << endl << "Printing PreOrder:" << endl;
        printTreePre(root);
    }
}

void bst::printTreePost() {
    if(root == NULL) {
        cout << "Empty Tree" << endl;
    } else {
        cout << endl << "Printing PostOrder:" << endl;
    }
}