//
//  BST.hpp
//  R7
//
//  Created by Malcolm McKellips on 3/1/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>
using namespace std;

struct node{
    int key;
    node* left = nullptr;
    node* right = nullptr;
};

class BST{
private:
    node* createNode(int data);
    node* root;
    
    /** since root is a private member we need helper functions
     to access root for insertion, searching and printing **/
    node* insertNodeHelper(node*, int);
    bool searchKeyHelper(node*, int);
    void printTreeHelper(node*);
    /**Destructor will call this function to recursively delete all node**/
    void destroyNode(node *root);
public:
    bool searchKey( int);// function to search a data in the tree
    void insertNode(int);// function to insert a node in the tree.
    void printTree();//function to print the tree
    BST(); // default constructor
    BST(int data); // parameterized constructor
    ~BST();// destructor
};
#endif /* BST_hpp */
