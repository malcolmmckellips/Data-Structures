//
//  main.cpp
//  A5
//
//  Created by Malcolm McKellips on 2/22/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Queue.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    int choice=0;
    Queue q(10);
    while (choice!=5){
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Enqueue word"<<endl;
        cout<<"2. Dequeue word"<<endl;
        cout<<"3. Print queue"<<endl;
        cout<<"4. Enqueue sentence"<<endl;
        cout<<"5. Quit"<<endl;
        cin>>choice;
        if (choice==1){
            string word;
            cout<<"word: ";
            cin>>word;
            q.enqueue(word);
        }
        if (choice==2){
            q.dequeue();
        }
        if (choice==3){
            q.printQueue();
        }
        if (choice==4){
            string sentence;
            cout<<"sentence: ";
            cin.ignore();
            getline(cin,sentence);
            q.enqueueSentence(sentence);
        }
        if (choice==5){
            cout<<"Goodbye!"<<endl;
        }
    }
    return 0;
}
