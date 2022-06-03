//
//  main.cpp
//  R10
//
//  Created by Malcolm McKellips on 3/22/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Graph.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream myfile;
    myfile.open("mat.txt");
    if (myfile.fail()){
        cout<<"file open failed!"<<endl;
    }
    Graph mygraph;
    string line;
    stringstream s;
    getline (myfile,line);
    s<<line;
    getline (s,line,' ');
    vector <string> verts;
    while (getline (s, line, ' ')){
        mygraph.addVertex(line);
        verts.push_back(line);
    }
    while (getline(myfile,line)){
        stringstream ss;
        ss<<line;
        string firstVert;
        getline (ss, firstVert, ' ');
        int vertNumber=0;
        int weight;
        string stringWeight;
        while (getline(ss,stringWeight,' ')){
            weight=stoi(stringWeight);
            mygraph.addEdge(firstVert, verts[vertNumber], weight);
            vertNumber++;
        }
    }
    mygraph.displayEdges();
    myfile.close();
    return 0;
}
