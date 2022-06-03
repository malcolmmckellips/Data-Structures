//
//  MovieTree.hpp
//  Assignment6
//
//  Created by Malcolm McKellips on 3/1/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//
#include <iostream>
#ifndef MovieTree_hpp
#define MovieTree_hpp
#include <string>
using namespace std;

struct MovieNodeLL{
    int ranking;
    std::string title;
    int year;
    int quantity;
    MovieNodeLL* next;
    MovieNodeLL(){};
    
    MovieNodeLL(int in_ranking, std::string in_title, int in_year, int in_quantity)
    {
        ranking = in_ranking;
        title = in_title;
        year = in_year;
        quantity = in_quantity;
        next = NULL;
    };
};

struct MovieNodeBST{
    char letter;
    MovieNodeBST* parent;
    MovieNodeBST* leftChild;
    MovieNodeBST* rightChild;
    MovieNodeLL* head;
    
    MovieNodeBST(){};
    
    MovieNodeBST(char in_letter)
    {
        letter = in_letter;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
        head = NULL;
    };
    
};

class MovieTree
{
    
public:
    MovieTree(); //done
    ~MovieTree(); //started
    void printMovieInventory(); //done
    int countMovieNodes(); //done
    void deleteMovieNode(std::string title); //checked and correct
    void addMovieNode(int ranking, std::string title, int releaseYear, int quantity); //checked and correct
    void findMovie(std::string title); //checked and correct
    void rentMovie(std::string title); //checked and correct
    
protected:
    
private:
    void DeleteAll(MovieNodeBST * node); //use this for the post-order traversal deletion of the tree
    void printMovieInventory(MovieNodeBST * node); //done
    void countMovieNodes(MovieNodeBST *node, int *c); //checked and correct
    MovieNodeBST* searchBST(MovieNodeBST *node, std::string title); //use this recursive function to find a pointer to a node in the BST, given a MOVIE TITLE //checked and correct
    MovieNodeLL* searchLL(MovieNodeLL* head, std::string title); //use this to return a pointer to a node in a linked list, given a MOVIE TITLE and the head of the linked list //done
    MovieNodeBST* treeMinimum(MovieNodeBST *node); //use this to find the left most leaf node of the BST, you'll need this in the delete function //checked and correct
    MovieNodeBST* root; //member
};

#endif /* MovieTree_hpp */
