//
//  main.cpp
//  A8
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
    while (choice != 3){
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Print vertices"<<endl;
        cout<<"2. Vertex adjacent"<<endl;
        cout<<"3. Quit"<<endl;
        cin>>choice;
        if (choice == 1){
            mygraph.displayEdges();
        }
        if (choice == 2){
            cout<<"Enter first city: "<<endl;
            cin.ignore();
            string firstCity,secondCity;
            getline(cin,firstCity);
            cout<<"Enter second city:"<<endl;
            getline(cin,secondCity);
            bool adjacent=true;
            adjacent = mygraph.isAdjacent(firstCity, secondCity);
            if (adjacent == true)
            cout<<"True"<<endl;
            else
            cout<<"False"<<endl;
        }
        if (choice == 3){
            cout<<"Goodbye!"<<endl;
        }
    }
    return 0;
}
