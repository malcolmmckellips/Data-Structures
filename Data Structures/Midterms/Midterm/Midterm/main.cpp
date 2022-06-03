//
//  main.cpp
//  Midterm
//
//  Created by Malcolm McKellips on 2/23/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include <iostream>
using namespace std;


int *makeNewArray(int inputArray[], int arraySize, int compareNum){
    int size=0;
    int foundArray[arraySize];
    for (int i=0;i<arraySize;i++){
        if (inputArray[i]>compareNum){
            foundArray[size]=inputArray[i];
            size++;
        }
    }
    int *newArray = new int[size];
    for (int i=0;i<size;i++){
        newArray[i]=foundArray[i];
    }
    return newArray;
}

struct node{
    int value;
    node *next;
    node *prev;
};

node *AddNewNodeSum (node *head, int value){
    node *current= new node;
    current=head;
    while (current!=NULL){
        if (current->value==value){
            node *temp= new node;
            temp->value=current->prev->value+current->next->value;
            temp->next=current->next;
            temp->prev=current;
            current->next=temp;
            return head;
        }
        current=current->next;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    int v1=2, v2=-1, *p1, *p2;
    p1 = & v1;
    p2= & v2;
    p2=p1;
    cout << *p2 << endl;
}
