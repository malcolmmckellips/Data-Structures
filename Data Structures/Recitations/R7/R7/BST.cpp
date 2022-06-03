//
//  BST.cpp
//  R7
//
//  Created by Malcolm McKellips on 3/1/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include "BST.hpp"
#include <iostream>
using namespace std;

/**
 Create a node with key as data
 **/
node* BST:: createNode(int data)
{
    node* nn = new node;
    nn->key = data;
    nn->left = nullptr;
    nn->right = nullptr;
    return nn;
}

BST::BST()
{
    
}
/**
 parameterized constructor. It will create the root and put the data in the root.
 **/
BST::BST(int data)
{
    root = createNode(data);
}
/**
 Destructor
 **/
BST::~BST(){
    
    destroyNode(root);
    
}
/**
 This function will destroy the subtree rooted at curNode.
 Think about in what order should you destroy.
 **/
void BST:: destroyNode(node *curNode){
    if(curNode)
    {
        destroyNode(curNode->left);
        destroyNode(curNode->right);
        delete curNode;
        root = nullptr;
    }
}

/** This function will search the data in a tree rooted at root
 We will call this function from searchKey.
 NOTE: As root is a private member of BST class, main function can not access root.
 So we need this helper function.
 **/
bool BST::searchKeyHelper(node* root, int data){
    if (root==nullptr)
        return false;
    if (root->key==data)
        return true;
    if (data < root->key){
        if (root->left == nullptr)
            return false;
        else
            return searchKeyHelper(root->left,data);
    }
    else if (data > root->key){
        if (root-> right == nullptr)
            return false;
        else
            return searchKeyHelper(root->right, data);
    }
    return false;
}
/**
 This function will search the data in the tree
 **/
bool BST::searchKey(int data){
    return searchKeyHelper(root, data);
}

/**
 This function will add the data in the tree rooted at curNode.
 We will call this function from insertNode.
 NOTE: root is a private member of BST. As root is a private member of BST class, main function can not access root.
 So we need this helper function. Implement your code for inserting a node in this function.
 **/
node* BST:: insertNodeHelper(node* curNode, int data){
    node *temp=curNode;
    node *n=new node;
    n->key=data;
    node *prev=nullptr;
    while (temp!=nullptr){
        prev=temp;
        if (n->key<temp->key)
            temp=temp->left;
        else
            temp=temp->right;
    }
    if (prev==nullptr)
        root=n;
    else if(n->key<prev->key)
        prev->left=n;
    else
        prev->right=n;
    return curNode;
}

/**
 This function will insert the data in the tree. As this function can not access the root
 it will call the insertNodeHelper function.
 **/
void BST:: insertNode( int data){
    if(root == NULL) // if the BST is empty create the root
        root = createNode(data);
    else // insert the data in the tree rooted at root
        insertNodeHelper(root, data);
}

/** This function will traverse the tree in-order and print out the node elements.
 printTree() function will call this function.
 NOTE: As root is a private member of BST class, main function can not access root. So printTree will
 call this helper function.
 **/
void BST:: printTreeHelper(node* curNode){
    if(curNode)
    {
        printTreeHelper( curNode->left);
        cout << " "<< curNode->key;
        printTreeHelper( curNode->right);
    }
}

void BST:: printTree(){
    printTreeHelper(root);
}
