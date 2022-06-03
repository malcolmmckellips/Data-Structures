//
//  priorityQueueHeap.hpp
//  Final_Project
//
//  Created by Malcolm McKellips on 5/1/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#ifndef priorityQueueHeap_hpp
#define priorityQueueHeap_hpp
#include <stdio.h>
#include <iostream>
#include "priorityQueueLL.hpp"
using namespace std;

class priorityQueueHeap{
public:
    priorityQueueHeap(int);
    ~priorityQueueHeap();
    void push(patient);
    patient pop();
    patient peek();
    void printHeap();
    void popAll();
private:
    patient *heap;
    int size;
    int capacity;
    void minHeapify(int);
    int parent (int);
    int left(int);
    int right(int);
    void swap(patient*,patient*);
};


#endif /* priorityQueueHeap_hpp */
