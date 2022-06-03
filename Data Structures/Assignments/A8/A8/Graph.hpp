//
//  Graph.hpp
//  A8
//
//  Created by Malcolm McKellips on 3/22/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//
#include <iostream>
#include <vector>
#ifndef Graph_hpp
#define Graph_hpp
using namespace std;
#include <stdio.h>

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
    std::vector<adjVertex> adj;
};

class Graph
{
public:
    Graph();  // Already implemented
    ~Graph(); // Already implemented
    void addEdge(std::string v1, std::string v2, int weight);
    void addVertex(std::string name);
    int isAdjacent(std::string v1, std::string v2);
    void displayEdges();
protected:
private:
    std::vector<vertex> vertices;
};

#endif /* Graph_hpp */
