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
            if(next->student->first.compare(f) > 0) {
                next = next->left;
                side = false;
            } else {
                next = next->right;
                side = true;
            }
        } else if(cmp > 0) {
            next = next->left;
            side = false;
        } else {
            next = next->right;
            side = true;
        }
    }

    if(node->parent == NULL) {
        // this is the first element
        root = node;
    } else if(side) {
        node->parent->right = node;
    } else {
        node->parent->left = node;
    }

    setHeight(node);
    
    return true; // I'm not sure how this could "fail" to insert the data?
}

BSTNode* bst::find(string l, string f) {
    int comparisons = 1;
    BSTNode* node = root;
    while(node != NULL) {
        if(l.compare(node->student->last) == 0 && f.compare(node->student->first) == 0) {
            // first and last name are a match
            break;
        } else if(l.compare(node->student->last) < 0 || (l.compare(node->student->last) == 0 && f.compare(node->student->first) < 0)) {
            node = node->left;
        } else {
            node = node->right;
        }
        comparisons++;
    }
    node->printNode();
    cout << "Found " << node->student->first << " " << node->student->last << " in " << comparisons << " comparisons." << endl;
    return node;
}

void bst::printTreeIO(BSTNode* n) {
    if(n->left != NULL) printTreeIO(n->left);
    n->printNode();
    if(n->right != NULL) printTreeIO(n->right);
}

void bst::printTreePre(BSTNode* n) {
    n->printNode();
    if(n->left != NULL) printTreePre(n->left);
    if(n->right != NULL) printTreePre(n->right);
}

void bst::printTreePost(BSTNode* n) {
    if(n->left != NULL) printTreePost(n->left);
    if(n->right != NULL) printTreePost(n->right);
    n->printNode();
}

BSTNode* bst::remove(string l, string f) {
    BSTNode* node = find(l, f);
    if(node == NULL) return NULL;

    if(node->left == NULL && node->right == NULL) {
        return removeNoKids(node);
    } else if(node->left != NULL && node->right == NULL) {
        return removeOneKid(node, true);
    } else if(node->right != NULL && node->left == NULL) {
        return removeOneKid(node, false);
    } else {
        BSTNode* rightMost = node->left;
        while(rightMost->right != NULL) {
            rightMost = rightMost->right;
        }
        
        BSTNode* returnedNode = new BSTNode();
        returnedNode->student = node->student;
        node->student = rightMost->student;
        
        if(rightMost->left == NULL) removeNoKids(rightMost);
        else removeOneKid(rightMost, true);

        return returnedNode;
    }
}

BSTNode* bst::removeNoKids(BSTNode* tmp) {
    if(tmp->parent != NULL) {
        if(tmp->parent->left == tmp) tmp->parent->left = NULL;
        else tmp->parent->right = NULL;
        setHeight(tmp->parent);
    } else {
        root = NULL;
    }
    
    tmp->parent = NULL;
    return tmp;
}

BSTNode* bst::removeOneKid(BSTNode* tmp, bool leftFlag) {
    BSTNode* child;
    if(leftFlag) {
        child = tmp->left;
        tmp->left = NULL;
    } else {
        child = tmp->right;
        tmp->right = NULL;
    }

    if(tmp->parent != NULL) {
        if(tmp->parent->left == tmp) {
            tmp->parent->left = child;
            child->parent = tmp->parent;
        } else {
            tmp->parent->right = child;
            child->parent = tmp->parent;
        }
        setHeight(tmp->parent);
    } else {
        root = child;
    }

    tmp->parent = NULL;
    return tmp;
}

void bst::setHeight(BSTNode* n) {
    int maxChild = 0;
    if(n->left != NULL && n->left->height > maxChild) maxChild = n->left->height;
    if(n->right != NULL && n->right->height > maxChild) maxChild = n->right->height;

    n->height = maxChild + 1;
    if(n->parent != NULL) setHeight(n->parent);
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
        cout << endl << "Clearing Tree: " << endl;
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
        printTreePost(root);
    }
}