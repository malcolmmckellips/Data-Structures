//
//  priorityQueueHeap.cpp
//  Final_Project
//
//  Created by Malcolm McKellips on 5/1/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include "priorityQueueHeap.hpp"
#include <iostream>
using namespace std;

/*
class priorityQueueHeap{
public:
    priorityQueueHeap();
    ~priorityQueueHeap();
    void push(patient);
    patient pop();
    patient peek();
    void printHeap();
private:
    patient *heap;
    int size;
    void minHeapify(int);
    int parent (int);
    int left(int);
    int right(int);
    void swap(patient*,patient*);
};
 */

priorityQueueHeap::priorityQueueHeap(int cap){
    size = 0;
    capacity = cap;
    heap = new patient[capacity];
}

priorityQueueHeap::~priorityQueueHeap(){
    
}

void priorityQueueHeap::push(patient newPatient){
    if (size == capacity){
        cout<<"Queue is full, cannot add any more items!"<<endl;
    }
    else{
        size++;
        int i = size-1;
        heap[i]=newPatient;
        while (i!=0 && heap[parent(i)] > heap[i]){
            swap(&heap[i], &heap[parent(i)]);
            i = parent(i);
        }
    }
}

patient priorityQueueHeap::pop(){
    if (size<=0){
        cout<<"Error, heap is empty. Nothing to pop!"<<endl;
        patient empty("Empty",0,0);
        return empty;
    }
    if (size == 1){
        size--;
        return heap[0];
    }
    patient poppedValue = heap[0];
    heap[0] = heap[size - 1];
    size --;
    minHeapify(0);
    return poppedValue;
}

patient priorityQueueHeap::peek(){
    return heap[0];
}

void priorityQueueHeap::printHeap(){
    if (size <= 0)
        cout<<"The heap is empty."<<endl;
    else{
        cout<<"The patients in the heap array are: "<<endl;
        for (int i = 0; i < size; i++)
        {
            cout<<"Element: "<< i <<" Name: "<<heap[i].name<<" Priority: "<<heap[i].priority<<" Treatment: "<<heap[i].treatment<<endl;
        }
    }
}

void priorityQueueHeap::minHeapify(int index){
    int leftChild = left(index);
    int rightChild = right(index);
    int smallest = index;
    if (leftChild<size && heap[leftChild] < heap[index])
        smallest = leftChild;
    if (rightChild<size && heap[rightChild] < heap[smallest])
        smallest = rightChild;
    if (smallest != index){
        swap(&heap[index], &heap[smallest]);
        minHeapify(smallest);
    }
}

void priorityQueueHeap::popAll(){
    int elements = size;
    for (int i = 0; i<elements ; i++){
        pop();
    }
}

int priorityQueueHeap::parent(int index){
    return (index-1)/2;
}

int priorityQueueHeap::left(int index){
    return (2*index)+1;
}

int priorityQueueHeap::right(int index){
    return (2*index)+2;
}

void priorityQueueHeap::swap(patient* first, patient* second){
    patient temp = *first;
    *first = *second;
    *second = temp;
}



