//
//  Graph.hpp
//  R10
//
//  Created by Malcolm McKellips on 3/22/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>

#include<vector>
#include<iostream>

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
    Graph();
    ~Graph();
    void addEdge(std::string v1, std::string v2, int weight);
    void addVertex(std::string name);
    void displayEdges();
protected:
private:
    //vector<edge> edges;
    std::vector<vertex> vertices;
    
};

#endif /* Graph_hpp */
