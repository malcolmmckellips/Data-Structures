//
//  Graph.cpp
//  A9
//
//  Created by Malcolm McKellips on 4/14/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include "Graph.hpp"
#include "Graph.hpp"
#include <vector>
#include <iostream>
#include <queue>
#include <stack>

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
        v.districtID = -1;
        vertices.push_back(v);
    }
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].districtID<<":"<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name;
            if (j != vertices[i].adj.size()-1)
                cout<<"***";
        }
        cout<<endl;
    }
}

void Graph::DFSLabel(std::string startingCity, int distID){
    vertex *start = NULL;
    for (int i = 0; i < (int)vertices.size(); i++) {
        if (vertices[i].name == startingCity) {
            start = &vertices[i];
        }
    }
    start->visited = true;
    stack <vertex*> s;
    s.push(start);
    while (!s.empty()){
        vertex *n = s.top();
        s.pop();
        n->districtID = distID;
        for (int i = 0;i<(int)n->adj.size();i++){
            if (!n->adj[i].v->visited){
                n->adj[i].v->visited = true;
                s.push(n->adj[i].v);
            }
        }
    }
}

void Graph::assignDistricts(){
    int distID = 1;
    for (int i=0; i<(int)vertices.size();i++){
        vertices[i].visited=false;
    }
    for (int i=0; i<(int)vertices.size();i++){
        if (vertices[i].visited == false){
            DFSLabel(vertices[i].name, distID);
            distID++;
        }
    }
}

void Graph::shortestPath(std::string startingCity, std::string endingCity){
    vertex *start=NULL, *end = NULL;
    if (vertices[0].districtID <=0)
        cout << "Please identify the districts before checking distances" << endl;
    else{
        for (int i = 0; i<(int)vertices.size();i++){
            vertices[i].visited = false;
            vertices[i].parent =NULL;
            vertices[i].unweightedDistance = INT_MAX;
            if (vertices[i].name == startingCity){
                start = &vertices[i];
            }
            if (vertices[i].name == endingCity){
                end = &vertices[i];
            }
        }
        if (start == NULL || end == NULL){
            cout << "One or more cities doesn't exist" << endl;
        }
        else if (start->districtID != end->districtID ){
            cout << "No safe path between cities" << endl;
        }
        else{
            queue <vertex*> q;
            q.push(start);
            start->visited = true;
            start->unweightedDistance = 0;
            while (!q.empty()){
                vertex *n = q.front();
                q.pop();
                for (int i=0; i<(int)n->adj.size();i++){
                    if (!n->adj[i].v->visited){
                        n->adj[i].v->unweightedDistance = n->unweightedDistance +1;
                        n->adj[i].v->visited=true;
                        q.push(n->adj[i].v);
                        n->adj[i].v->parent=n;
                    }
                }
            }
            vertex *temp = end;
            vector <vertex*> path;
            while (temp){
                path.push_back(temp);
                temp = temp->parent;
            }
            cout<<path.size()-1;
            for (int i = (int)path.size()-1; i>=0; i--){
                cout<<", "<<path[i]->name;
            }
            cout<<endl;
        }
    }
}

void Graph::shortestWeightedPath(std::string startingCity, std::string endingCity){
    vertex *start=NULL, *end = NULL;
    if (vertices[0].districtID <=0)
            cout << "Please identify the districts before checking distances" << endl;
    else{
        for (int i = 0; i<(int)vertices.size();i++){
            vertices[i].visited = false;
            vertices[i].parent =NULL;
            if (vertices[i].name == startingCity){
                start = &vertices[i];
            }
            if (vertices[i].name == endingCity){
                end = &vertices[i];
            }
        }
        if (start == NULL || end == NULL){
            cout << "One or more cities doesn't exist" << endl;
        }
        else if (start->districtID != end->districtID ){
            cout << "No safe path between cities" << endl;
        }
        else{
            start->visited = true;
            start->weightedDistance = 0;
            vector <vertex*> solved;
            solved.push_back(start);
            while (!end->visited){
                int mindist = INT_MAX;
                vertex * solvedV = NULL;
                vertex *parental = NULL;
                for (int i=0;i<(int)solved.size();i++){
                    vertex *s = solved[i];
                    for (int j=0;j<(int)s->adj.size();j++){
                        if (!s->adj[j].v->visited){
                            int dist = s->weightedDistance + s->adj[j].weight;
                            if (dist < mindist){
                                solvedV = s->adj[j].v;
                                mindist = dist;
                                parental = s; //not sure about this line
                            }
                        }
                    }
                }
                solvedV->weightedDistance = mindist;
                solvedV->parent = parental;
                solvedV->visited = true;
                solved.push_back(solvedV);
            }
            vertex *temp = end;
            vector <vertex*> path;
            while (temp){
                path.push_back(temp);
                temp = temp->parent;
            }
            cout<<end->weightedDistance;
            for (int i = (int)path.size()-1; i>=0; i--){
                cout<<", "<<path[i]->name;
            }
            cout<<endl;
        }
    }
}




