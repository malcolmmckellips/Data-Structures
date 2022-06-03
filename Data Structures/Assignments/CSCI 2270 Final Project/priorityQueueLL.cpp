//
//  priorityQueueLL.cpp
//  Final_Project
//
//  Created by Malcolm McKellips on 4/30/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include "priorityQueueLL.hpp"
#include <iostream>
#include <vector>
using namespace std;

/*
public:
priorityQueueLL();
~priorityQueueLL();
void enqueue(patient);
patient dequeue();
void printQueue();
bool isEmpty();
private:
LLnode *head;
LLnode *tail;
*/

/*
struct LLnode{
    LLnode *next;
    LLnode *prev;
    patient pat;
    LLnode (){};
    LLnode(LLnode *n, LLnode *p,patient pa){
        next = n;
        prev = p;
        pat = pa;
    }
};
*/

priorityQueueLL::priorityQueueLL(){
    head = nullptr;
    tail = nullptr;
}

priorityQueueLL::~priorityQueueLL(){}

void priorityQueueLL::enqueue(patient newPatient){
    if (isEmpty()){ //Adding the first node
        LLnode *newNode = new LLnode;
        newNode->pat = newPatient;
        head = newNode;
        head->next = nullptr;
        head->prev = nullptr;
    }
    else {
        LLnode *newNode = new LLnode;
        newNode->pat = newPatient;
        LLnode *walker = head;
        bool inserted = false;
        while (inserted == false){
            if (newNode->pat < head->pat){ //We are inserting the new node at the beggining of the LL
                head->prev=newNode;
                newNode->next=head;
                newNode->prev=nullptr;
                head=newNode;
                inserted = true;
            }
            else if (newNode->pat < walker->pat){ //we're inserting the node, check this for the equals condition.
                newNode->next = walker;
                newNode->prev = walker->prev;
                walker->prev->next=newNode;
                walker->prev = newNode;
                inserted = true;
            }
            else if (newNode->pat.treatment == walker->pat.treatment && newNode->pat.priority == walker->pat.priority ){ //we are inserting a node with identical priority to walker.
                newNode->next = walker;
                newNode->prev = walker->prev;
                walker->prev->next=newNode;
                walker->prev = newNode;
                inserted = true;
            }
            else if (walker->next == nullptr){ //We are inserting the new node at the end of the LL
                walker->next = newNode;
                newNode->next = nullptr;
                newNode->prev = walker;
                tail = newNode;
                inserted = true;
            }
            else{
                walker = walker -> next;
            }
        }
    }
}

patient priorityQueueLL::dequeue(){
    if (head->next == nullptr){
        LLnode *front= head;
        head = nullptr;
        return front->pat;
    }
    else{
        LLnode *front= head;
        head->next->prev=nullptr;
        head = head->next;
        return front->pat;
    }
}

void priorityQueueLL::printQueue(){
    if (isEmpty())
        cout<<"Queue is currently empty. Nothing to print."<<endl;
    else{
        LLnode *current = head;
        int rank = 1;
        /*
        while (current != nullptr){
            cout<<"Rank: "<< rank << " Patient: "<<current->pat.name<<" Priority: "<<current->pat.priority<<" Treatment: "<<current->pat.treatment<<endl;
            rank++;
            current = current -> next;
        }*/
        cout<<"Rank\tpatient,  Priority,  Treatment"<<endl;
        while (current != nullptr){
            cout<< rank << ":\t"<<current->pat.name<<",  "<<current->pat.priority<<",  "<<current->pat.treatment<<endl;
            rank++;
            current = current -> next;
        }
    }
}

void priorityQueueLL::dequeueAll(){
    LLnode *current = head;
    while (current!=nullptr){
        dequeue();
        current=current->next;
    }
}

bool priorityQueueLL::isEmpty(){
    if (head == nullptr)
        return true;
    return false;
}




