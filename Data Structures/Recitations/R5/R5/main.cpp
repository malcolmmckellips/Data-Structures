//
//  main.cpp
//  R5
//
//  Created by Malcolm McKellips on 2/15/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include <iostream>
#include "doublyLL.hpp"

int main(int argc, const char * argv[]) {
    doublyLL mylist;
    for (int i=0;i<20;i++){
        if (i%4==0){
            mylist.insertNodeAtEnd(4);
        }
        else{
            mylist.insertNodeAtEnd(i);
        }
    }
    mylist.insertNodeAtEnd(4);
    mylist.printList();
    cout<<endl;
    mylist.deleteNode(4);
    mylist.printList();
    cout<<endl;
    return 0;
}
