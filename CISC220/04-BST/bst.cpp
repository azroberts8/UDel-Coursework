/*
 * bst.cpp
 */

#include "bst.hpp"
using namespace std;

bool bst::insert(string f, string l, int n, string j) {
    BSTNode* node = new BSTNode(f, l, n, j);
    node->left = NULL;
    node->right = NULL;
    
    int cmp;
    bool side;
    BSTNode* next = root;
    while(next != NULL) {
        node->parent = next;
        cmp = next->student->last.compare(l);

        if(cmp == 0) {
            // last names are equal; use first names
            if(next->student->first.compare(f) < 0) {
                next = next->left;
                side = false;
            } else {
                next = next->right;
                side = true;
            }
        } else if(cmp < 0) {
            next = next->left;
            side = false;
        } else {
            next = next->right;
            side = true;
        }
        node->height += 1;
    }

    if(node->parent == NULL) {
        // this is the first element
        root = node;
    } else if(side) {
        node->parent->right = node;
    } else {
        node->parent->left = node;
    }
    
    return true; // I'm not sure how this could "fail" to insert the data?
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