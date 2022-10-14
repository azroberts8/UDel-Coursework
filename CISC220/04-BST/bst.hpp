/*
 * bst.hpp
 */

#ifndef bst_HPP_
#define bst_HPP_

#include "bstNode.hpp"

class bst {
    BSTNode* root;

    public:
        bst();
        bst(string f, string l, int n, string j);
        bool insert(string f, string l, int n, string j);
        BSTNode* find(string l, string f);
        void printTreeIO();
        void printTreeIO(BSTNode* n);
        void printTreePre();
        void printTreePre(BSTNode* n);
        void printTreePost();
        void printTreePost(BSTNode* n);
        void clearTree();
        void clearTree(BSTNode* tmp);
        BSTNode* removeNoKids(BSTNode* tmp);
        BSTNode* removeOneKid(BSTNode* tmp, bool leftFlag);
        BSTNode* remove(string f, string l);
        void setHeight(BSTNode* n);
};

#endif