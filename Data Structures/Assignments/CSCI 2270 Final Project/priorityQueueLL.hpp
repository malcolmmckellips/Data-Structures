//
//  priorityQueueLL.hpp
//  Final_Project
//
//  Created by Malcolm McKellips on 4/30/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#ifndef priorityQueueLL_hpp
#define priorityQueueLL_hpp
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct patient
{
    string name;
    int priority;
    int treatment;
    patient() {};
    patient(string n, int p, int t) : name(n), priority(p), treatment(t) {};
    bool operator<(const patient & p)const{
        if( this->priority < p.priority ) return true;
        else if( this->priority > p.priority ) return false;
        else if( this->treatment < p.treatment ) return true;
        return false;
    }
    bool operator>(const patient & p)const{
        if( this->priority > p.priority ) return true;
        else if( this->priority < p.priority ) return false;
        else if( this->treatment > p.treatment ) return true;
        return false;
    }
};

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

class priorityQueueLL{
public:
    priorityQueueLL();
    ~priorityQueueLL();
    void enqueue(patient);
    patient dequeue();
    void printQueue();
    void dequeueAll();
    bool isEmpty();
private:
    LLnode *head;
    LLnode *tail;
};
#endif /* priorityQueueLL_hpp */
