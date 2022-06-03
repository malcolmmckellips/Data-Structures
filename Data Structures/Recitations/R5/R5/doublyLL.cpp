//
//  doublyLL.cpp
//  R5
//
//  Created by Malcolm McKellips on 2/15/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include "doublyLL.hpp"

doublyLL::doublyLL() {
    
}

doublyLL::doublyLL(int nodeID) {
    //create head node
    head = createNode(nodeID, nullptr, nullptr);
    tail = head;
}

doublyLL::~doublyLL() {
    
}


Node* doublyLL::createNode(int nodeID, Node* nodePrev, Node* nodeNext) {
    Node* newNode = new Node;
    newNode->id = nodeID;
    newNode->next = nodeNext;
    newNode->prev = nodePrev;
    
    return newNode;
}

bool doublyLL::insertNodeAtEnd(int nodeID) {
    if (head == nullptr) {
        //nothing in the list
        head = createNode(nodeID, nullptr, nullptr);
        tail = head;
    }
    else {
        Node* newNode = createNode(nodeID, tail, nullptr);
        tail->next = newNode;
        tail = newNode;
    }
    return true;
}

void doublyLL::printList(){
    Node* current=new Node;
    current=head;
    while (current!=nullptr){
        cout<<current->id<<" ";
        current=current->next;
    }
}

void doublyLL::deleteNode(int nodeID){
    Node* current=new Node;
    current=head;
    while (current!=nullptr){
        if (current->id==nodeID){
            if (current->next==nullptr){
                tail=current->prev;
                current->prev->next=nullptr;
            }
            else if (current->prev==nullptr){
                head=current->next;
                current->next->prev=nullptr;
            }
            else{
                current->prev->next=current->next;
                current->next->prev=current->prev;
            }
        }
        current=current->next;
    }
}

