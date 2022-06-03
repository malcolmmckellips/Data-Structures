//
//  Graph.cpp
//  A8
//
//  Created by Malcolm McKellips on 3/22/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//
#include "Graph.hpp"
#include <vector>
#include <iostream>

using namespace std;

Graph::Graph(){}

Graph::~Graph(){}

void Graph::addEdge(std::string v1, std::string v2, int distance)
{
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = distance;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    /*adjVertex av2;
                     av2.v = &vertices[i];
                     av2.weight = weight;
                     vertices[j].adj.push_back(av2);*/
                }
            }
        }
    }
}

void Graph::addVertex(std::string name)
{
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == name){
            found = true;
            cout<<vertices[i].name<<" already in the graph."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = name;
        vertices.push_back(v);
        
    }
}

int Graph::isAdjacent(string v1, string v2){
    bool adjacent = false;
    for (int i=0; i<vertices.size(); i++){
        if (vertices[i].name == v1){
            for (int j=0 ; j<vertices[i].adj.size() ; j++){
                if (vertices[i].adj[j].v->name == v2){
                    adjacent = true;
                }
            }
        }
    }
    return adjacent;
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name;
            if (j != vertices[i].adj.size()-1)
            cout<<"***";
        }
        cout<<endl;
    }
}

