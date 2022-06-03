//
//  Queue.cpp
//  A5
//
//  Created by Malcolm McKellips on 2/22/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include "Queue.hpp"
#include <iostream>
#include <sstream>
using namespace std;

Queue::Queue(int qs) {
    queueSize = qs;
    arrayQueue = new std::string[queueSize];
    queueHead = 0;
    queueTail = 0;
    queueCount = 0;
}

Queue::~Queue() {
    delete [] arrayQueue;
    arrayQueue = nullptr;
}

void Queue::enqueue(std::string word){
    if (queueIsFull())
        cout<<"Queue is full"<<endl;
    else{
        arrayQueue[queueTail]=word;
        queueCount++;
        queueTail++;
        if (queueTail>=queueSize){
            queueTail=0;
        }
        cout<<"E: "<<word<<endl;
        cout<<"H: "<<queueHead<<endl;
        cout<<"T: "<<queueTail<<endl;
    }
}

void Queue::dequeue(){
    if (queueIsEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        string word=arrayQueue[queueHead];
        arrayQueue[queueHead]="";
        queueHead++;
        queueCount--;
        if (queueHead>=queueSize){
            queueHead=0;
        }
        cout<<"H: "<<queueHead<<endl;
        cout<<"T: "<<queueTail<<endl;
        cout<<"word: "<<word<<endl;
    }
}

bool Queue::queueIsFull(){
    if (queueCount==queueSize)
        return true;
    else
        return false;
}

bool Queue::queueIsEmpty(){
    if (queueCount==0)
        return true;
    else
        return false;
}

void Queue::printQueue(){
    if (queueIsEmpty()){
        cout<<"Empty"<<endl;
    }
    else{
        if (queueHead==queueTail){
            int current=queueHead;
            cout<<current<<": "<<arrayQueue[current]<<endl;
            current++;
            while (current!=queueTail){
                cout<<current<<": "<<arrayQueue[current]<<endl;
                current++;
                if (current>=queueSize){
                    current=0;
                }
            }
        }
        else{
            int index=queueHead;
            while (index!=queueTail){
                cout<<index<<": "<<arrayQueue[index]<<endl;
                index++;
                if (index>=queueSize){
                    index=0;
                }
            }
        }
    }
}

void Queue::enqueueSentence(string sentence){
    stringstream ss;
    ss<<sentence;
    string word;
    while (getline(ss,word,' ')){
        enqueue(word);
    }
}


