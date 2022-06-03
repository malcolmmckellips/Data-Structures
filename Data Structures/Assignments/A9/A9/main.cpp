//
//  main.cpp
//  A9
//
//  Created by Malcolm McKellips on 4/14/18.
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
    //myfile.open(argv[1]);
    myfile.open("zombieCities.txt");
    if (myfile.fail()){
        cout<<"file open failed!"<<endl;
    }
    Graph mygraph;
    string line;
    stringstream s;
    getline (myfile,line);
    s<<line;
    getline (s,line,',');
    vector <string> verts;
    while (getline (s, line, ',')){
        mygraph.addVertex(line);
        verts.push_back(line);
    }
    while (getline(myfile,line)){
        stringstream ss;
        ss<<line;
        string firstVert;
        getline (ss, firstVert, ',');
        int vertNumber=0;
        int weight;
        string stringWeight;
        while (getline(ss,stringWeight,',')){
            weight=stoi(stringWeight);
            if (weight != -1)
                mygraph.addEdge(firstVert, verts[vertNumber], weight);
            vertNumber++;
        }
    }
    myfile.close();
    int choice = 0;
    while (choice != 5){
        cout << "======Main Menu======" << endl;
        cout << "1. Print vertices" << endl;
        cout << "2. Find districts" << endl;
        cout << "3. Find shortest path" << endl;
        cout << "4. Find shortest weighted path" << endl;
        cout << "5. Quit" << endl;
        cin>>choice;
        if (choice == 1){
            mygraph.displayEdges();
        }
        if (choice == 2){
            mygraph.assignDistricts();
        }
        if (choice == 3){
            cin.ignore();
            string startC,endC;
            cout << "Enter a starting city:" << endl;
            getline(cin,startC);
            cout << "Enter an ending city:" << endl;
            getline(cin,endC);
            mygraph.shortestPath(startC, endC);
        }
        if (choice == 4){
            cin.ignore();
            string starterC,enderC;
            cout << "Enter a starting city:" << endl;
            getline(cin,starterC);
            cout << "Enter an ending city:" << endl;
            getline(cin,enderC);
            mygraph.shortestWeightedPath(starterC, enderC);
        }
        if (choice == 5){
            cout<<"Goodbye!"<<endl;
        }
    }
    return 0;
}
