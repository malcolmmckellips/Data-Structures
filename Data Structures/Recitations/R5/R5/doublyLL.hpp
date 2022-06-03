//
//  doublyLL.hpp
//  R5
//
//  Created by Malcolm McKellips on 2/15/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#ifndef doublyLL_hpp
#define doublyLL_hpp
#include <stdio.h>
#include <iostream>

using namespace std;

struct Node {
    int id=-1;
    Node* prev = nullptr;
    Node* next = nullptr;
};

class doublyLL {
private:
    Node* createNode(int,Node*,Node*);
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    bool insertNodeAtEnd(int);
    void deleteNode(int);
    void printList();
    doublyLL();    //default constructor
    doublyLL(int);    //overloaded constructor
    ~doublyLL();    //destructor
};

#endif /* doublyLL_hpp */
