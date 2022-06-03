//
//  Queue.hpp
//  A5
//
//  Created by Malcolm McKellips on 2/22/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Queue
{
public:
    Queue(int);
    ~Queue();
    //circular queue methods
    void enqueue(std::string);
    void dequeue();
    void printQueue();
    void enqueueSentence(std::string);
    bool queueIsFull(); //check when full
    bool queueIsEmpty(); //check when empty
protected:
private:
    int queueSize;
    int queueHead;
    int queueTail;
    int queueCount;
    std::string *arrayQueue;
};

#endif /* Queue_hpp */
