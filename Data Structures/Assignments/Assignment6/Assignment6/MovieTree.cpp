//
//  MovieTree.cpp
//  Assignment6
//
//  Created by Malcolm McKellips on 3/1/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include "MovieTree.hpp"
#include <iostream>
using namespace std;

MovieTree::MovieTree(){
    root=nullptr;
}

MovieTree::~MovieTree(){
    DeleteAll(root);
}

bool InTree(MovieNodeBST *root, char target){
    if (root==nullptr)
        return false;
    if (root->letter==target)
        return true;
    if (target < root->letter){
        if (root->leftChild == nullptr)
            return false;
        else
            return InTree(root->leftChild,target);
    }
    else if (target > root->letter){
        if (root-> rightChild == nullptr)
            return false;
        else
            return InTree(root->rightChild,target);
    }
    return false;
}

void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity) {
    MovieNodeLL *newMovie = new MovieNodeLL(ranking,title,releaseYear,quantity);
    MovieNodeBST *newLetter = new MovieNodeBST(title[0]);
    if (root==nullptr){
        root= newLetter;
        root->head=newMovie;
    }
    else{
        if (InTree(root, title[0])){ //The first letter of the new movie is in the tree
            MovieNodeBST *foundLetter = searchBST(root, title);
            MovieNodeLL *current=foundLetter->head;
            if (title < current->title){ //new movie is less than the first element so it is the new head
                newMovie->next=current;
                foundLetter->head=newMovie;
            }
            else{
                while (current!=nullptr){
                    if (current->next==nullptr){
                        newMovie->next=nullptr;
                        current->next=newMovie;
                        current=nullptr;
                    }
                    else{
                        if (title > current->next->title)
                            current=current->next;
                        else{
                            newMovie->next=current->next;
                            current->next=newMovie;
                            current=nullptr;
                        }
                    }
                }
            }
        }
        else { //The first letter of the new movie is not in the tree so we must insert it
            newLetter->head=newMovie;
            MovieNodeBST *temp = root;
            MovieNodeBST *prev=nullptr;
            while (temp!=nullptr){
                prev=temp;
                if (newLetter->letter < temp->letter)
                    temp=temp->leftChild;
                else
                    temp=temp->rightChild;
            }
            if (prev==nullptr)
                root=newLetter;
            else if (newLetter->letter < prev->letter){
                prev->leftChild = newLetter;
                newLetter->parent=prev;
            }
            else{
                prev->rightChild = newLetter;
                newLetter->parent=prev;
            }
        }
    }
}

MovieNodeBST* MovieTree::searchBST(MovieNodeBST *node, std::string title){
    if (node!=nullptr){
        if (node->letter == title[0])
            return node;
        else if (node->letter > title[0])
            return searchBST(node->leftChild,title);
        else
            return searchBST(node->rightChild,title);
    }
    else
        return nullptr;
}

void MovieTree::printMovieInventory(MovieNodeBST * node){
    if (node->leftChild!=nullptr){
        printMovieInventory(node->leftChild);
    }
    MovieNodeLL *current=node->head;
    while(current!=nullptr){
        cout<<"Movie: "<<current->title<<" "<<current->quantity<<endl;
        current=current->next;
    }
    if (node->rightChild!=nullptr){
        printMovieInventory(node->rightChild);
    }
}

void MovieTree::printMovieInventory(){
    printMovieInventory(root);
}

MovieNodeLL* MovieTree::searchLL(MovieNodeLL* head, std::string title){
    MovieNodeLL *current=head;
    while (current!=nullptr){
        if (current->title==title)
            return current;
        else
            current=current->next;
    }
    return nullptr;
}

void MovieTree::findMovie(std::string title){
    MovieNodeBST *foundLetter =searchBST(root,title);
    if (foundLetter==nullptr){
        cout<<"Movie not found."<<endl;
    }
    else{
        MovieNodeLL *foundMovie=searchLL(foundLetter->head, title);
        if (foundLetter!=nullptr && foundMovie!=nullptr){
            cout<<"Movie Info:"<<endl;
            cout<<"==========="<<endl;
            cout<<"Ranking:"<<foundMovie->ranking<<endl;
            cout<<"Title:"<<foundMovie->title<<endl;
            cout<<"Year:"<<foundMovie->year<<endl;
            cout<<"Quantity:"<<foundMovie->quantity<<endl;
        }
        else
            cout<<"Movie not found."<<endl;
    }
}

void MovieTree::rentMovie(std::string title){
    MovieNodeBST *foundLetter =searchBST(root,title);
    if (foundLetter==nullptr){
        cout<<"Movie not found."<<endl;
    }
    else{
        MovieNodeLL *foundMovie=searchLL(foundLetter->head, title);
        if (foundLetter!=nullptr && foundMovie!=nullptr){
            if (foundMovie->quantity>0){
                foundMovie->quantity--;
                cout<<"Movie has been rented."<<endl;
                cout<<"Movie Info:"<<endl;
                cout<<"==========="<<endl;
                cout<<"Ranking:"<<foundMovie->ranking<<endl;
                cout<<"Title:"<<foundMovie->title<<endl;
                cout<<"Year:"<<foundMovie->year<<endl;
                cout<<"Quantity:"<<foundMovie->quantity<<endl;
            }
            if (foundMovie->quantity==0){
                deleteMovieNode(title);
            }
        }
        else
            cout<<"Movie not found."<<endl;
    }
}

void MovieTree::countMovieNodes(MovieNodeBST *node, int *c){
    if (node==nullptr)
        *c=0;
    else{
        if (node->leftChild!=nullptr){
            countMovieNodes(node->leftChild,c);
        }
        MovieNodeLL *current=node->head;
        while(current!=nullptr){
            *c=*c+1;
            current=current->next;
        }
        if (node->rightChild!=nullptr){
            countMovieNodes(node->rightChild,c);
        }
    }
}

int MovieTree::countMovieNodes(){
    int *c=new int;
    *c=0;
    countMovieNodes(root,c);
    return *c;
}

MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST *node){
    MovieNodeBST *temp=node;
    while (temp->leftChild!=nullptr)
        temp=temp->leftChild;
    return temp;
}

MovieNodeBST* FindMin(MovieNodeBST * nn){
    if(!nn) return nullptr;
    while(nn->leftChild)
        nn = nn->leftChild;
    return nn;
}

void DeleteHelper(MovieNodeBST *& dn, MovieNodeBST *& root){
    if (dn->leftChild==nullptr && dn->rightChild==nullptr){
        if (dn!=root){
            if (dn->parent->leftChild == dn){ //dn is the left child
                dn->parent->leftChild=nullptr;
            }
            else if (dn->parent->rightChild == dn){ //dn is the right child
                dn->parent->rightChild=nullptr;
            }
        }
        delete dn;
        dn = nullptr;
    }
    else if (dn->rightChild != nullptr){
        MovieNodeBST *mn=FindMin(dn->rightChild);
        dn->letter=mn->letter;
        dn->head=mn->head;
        DeleteHelper(mn, root);
    }
    else if (dn->leftChild != nullptr){
        if (dn!=root){
            if (dn->parent->leftChild == dn){
                dn->parent->leftChild=dn->leftChild;
            }
            else if (dn->parent->rightChild ==dn){
                dn->parent->rightChild=dn->leftChild;
            }
        }
        dn->leftChild->parent=dn->parent;
        delete dn;
        dn=nullptr;
    }
}

void MovieTree::deleteMovieNode(std::string title){
    MovieNodeBST *foundLetter=searchBST(root,title);
    if (foundLetter==nullptr){ //tree node was not found
        cout<<"Movie not found."<<endl;
    }
    else{ //Tree node was found
        MovieNodeLL *foundMovie=searchLL(foundLetter->head, title);
        if (foundLetter!=nullptr && foundMovie!=nullptr){ //movie has been found
            if (foundLetter->head==foundMovie && foundMovie->next==nullptr){//if linked list is now empty, delete the tree node
                if (foundLetter->head == foundMovie){ //we are deleting the head of the LL
                    foundLetter->head= foundMovie->next;
                    delete foundMovie;
                    foundMovie=nullptr;
                }
                else{//we are deleting an element of the LL that is not the head
                    MovieNodeLL *current=foundLetter->head;
                    while (current!=nullptr){
                        if (current->next==foundMovie){//current is the movie before the movie to be deleted
                            MovieNodeLL *temp=current->next;
                            current->next=current->next->next;
                            delete temp; //possible seg fault bait
                            temp = nullptr;
                        }
                        current=current->next;
                    }
                }
                MovieNodeBST *dn=searchBST(root, title);
                DeleteHelper(dn, root);
            }
            else{ //we are not deleting a tree node, we're just deleting a linked list node
                if (foundLetter->head == foundMovie){ //we are deleting the head of the LL
                    foundLetter->head= foundMovie->next;
                    delete foundMovie;
                    foundMovie=nullptr;
                }
                else{//we are deleting an element of the LL that is not the head
                    MovieNodeLL *current=foundLetter->head;
                    while (current!=nullptr){
                        if (current->next==foundMovie){//current is the movie before the movie to be deleted
                            MovieNodeLL *temp=current->next;
                            current->next=current->next->next;
                            delete temp; //possible seg fault bait
                            temp = nullptr;
                        }
                        current=current->next;
                    }
                }
            }
        }
        else //linked list node was not found
            cout<<"Movie not found."<<endl;
    }
}

void MovieTree::DeleteAll(MovieNodeBST * node){
    if (node->leftChild != nullptr)
        DeleteAll(node->leftChild);
    if (node->rightChild != nullptr)
        DeleteAll(node->rightChild);
    MovieNodeLL *current=node->head;
    while (current!=nullptr){
        MovieNodeLL *temp=current->next;
        cout<<"Deleting: "<<current->title<<endl;
        deleteMovieNode(current->title);
        current=temp;
    }
}

