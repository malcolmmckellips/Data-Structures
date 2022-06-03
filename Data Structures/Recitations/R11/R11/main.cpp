//
//  main.cpp
//  R11
//
//  Created by Malcolm McKellips on 4/5/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct vertex;

struct adjVertex {
    vertex* v;
    int weight;
};

struct vertex {
    string key;
    vector<adjVertex> adjacent;
    bool visited = false;
};

class Graph {
private:
    //vertices
    vector<vertex> vertices;
    vertex* findVertex(string);
public:
    //methods for accessing graphs
    Graph();
    ~Graph();
    void insertVertex(string);    //identifier of the vertex
    void insertEdge(string,string,int);    //start, end, weight
    void printGraph();
    void DFSpath(string, string);
    void findNodeWithMaximumAdjacent(string);
    
};

Graph::Graph() {}

Graph::~Graph() {}

void Graph::insertVertex(string value) {
    bool found = false;
    int i=0;
    while (i<vertices.size() && !found) {
        if (vertices[i].key == value) {
            found = true;
        }
        i++;
    }
    if (!found) {
        vertex v;
        v.key = value;
        vertices.push_back(v);
    }
    else {
        cout << "There is already a vertex " << value << " in this graph" << endl;
    }
}

vertex* Graph::findVertex(string value) {
    int i=0;
    while (i<vertices.size()) {
        if (vertices[i].key == value) {
            return &vertices[i];
        }
        i++;
    }
    return nullptr;
}



void Graph::insertEdge(string v1, string v2, int weight) {
    vertex *vStart = findVertex(v1);
    vertex *vEnd = findVertex(v2);
    if (vStart!=nullptr && vEnd!=nullptr) {
        //this code assumes that an edge doesn't exist
        //write some error checking to handle when it does
        adjVertex v1v2Edge;
        v1v2Edge.weight = weight;
        v1v2Edge.v = vEnd;
        vStart->adjacent.push_back(v1v2Edge);
    }
    else {
        if (vStart == nullptr) {
            cout << "no vertex with name " << v1 << " in this graph" << endl;
        }
        if (vEnd == nullptr) {
            cout << "no vertex with name " << v2 << " in this graph" << endl;
        }
    }
}

void Graph::findNodeWithMaximumAdjacent(string start) {
    vertex *vert = findVertex(start);
    vert -> visited = true;
    queue <vertex*> q;
    q.push(vert);
    long int maxAdj=0;
    vector <string> maxAdjKeys;
    cout<<vert->key<<" ";
    while (! q.empty()){
        vertex *n;
        n=q.front();
        q.pop();
        if (n->adjacent.size() > maxAdj){
            maxAdj=n->adjacent.size();
            maxAdjKeys.clear();
            maxAdjKeys.push_back(n->key);
        }
        else if (n->adjacent.size() == maxAdj){
           // maxAdj=n->adjacent.size();
            maxAdjKeys.push_back(n->key);
        }
        for (int x=0; x < n->adjacent.size() ; x++){
            if (! n->adjacent[x].v->visited){
                n->adjacent[x].v->visited = true;
                cout<<n->adjacent[x].v->key<<" ";
                q.push(n->adjacent[x].v);
            }
        }
    }
    cout<<endl;
    for (int i =0; i< maxAdjKeys.size();i++)
        cout<<maxAdjKeys[i]<<" ";
    cout<<endl;
}


void Graph::DFSpath(string src, string dst) {
    
}

int main() {
    
    Graph myGraph;
    
    myGraph.insertVertex("A");
    myGraph.insertVertex("B");
    myGraph.insertVertex("C");
    myGraph.insertVertex("D");
    myGraph.insertVertex("E");
    myGraph.insertVertex("F");
    myGraph.insertVertex("G");
    
    myGraph.insertEdge("A", "B", 0); myGraph.insertEdge("B", "A", 0);
    myGraph.insertEdge("A", "C", 0); myGraph.insertEdge("C", "A", 0);
    myGraph.insertEdge("B", "D", 0); myGraph.insertEdge("D", "B", 0);
    myGraph.insertEdge("C", "D", 0); myGraph.insertEdge("D", "C", 0);
    myGraph.insertEdge("E", "D", 0); myGraph.insertEdge("D", "E", 0);
    myGraph.insertEdge("E", "B", 0); myGraph.insertEdge("B", "E", 0);
    myGraph.insertEdge("E", "G", 0); myGraph.insertEdge("G", "E", 0);
    myGraph.insertEdge("F", "G", 0); myGraph.insertEdge("G", "F", 0);
    
    myGraph.findNodeWithMaximumAdjacent("A");
}
