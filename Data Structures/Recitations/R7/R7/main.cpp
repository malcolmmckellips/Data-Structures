//
//  main.cpp
//  R7
//
//  Created by Malcolm McKellips on 3/1/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include <iostream>
#include "BST.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    BST b;
    b.insertNode(10);
    b.insertNode(69);
    b.insertNode(35);
    b.insertNode(4);
    b.insertNode(65);
    b.insertNode(33);
    b.printTree();
    cout<<endl;
    cout<<b.searchKey(11)<<endl;
    return 0;
}
