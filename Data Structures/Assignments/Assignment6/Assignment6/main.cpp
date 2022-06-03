//
//  main.cpp
//  Assignment6
//
//  Created by Malcolm McKellips on 3/1/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include "MovieTree.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    MovieTree myTree;
    ifstream myfile;
    myfile.open(argv[1]);
    //myfile.open("Movies.txt");
    string line,rankstring,titlestring,yearstring,quantstring;
    while (getline(myfile,line)){
        stringstream ss;
        ss<<line;
        getline(ss,rankstring,',');
        getline(ss,titlestring,',');
        getline(ss,yearstring,',');
        getline(ss,quantstring,',');
        myTree.addMovieNode(stoi(rankstring), titlestring, stoi(yearstring), stoi(quantstring));
    }
    myfile.close();
    int choice=0;
    while (choice != 6){
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Find a movie"<<endl;
        cout<<"2. Rent a movie"<<endl;
        cout<<"3. Print the inventory"<<endl;
        cout<<"4. Delete a movie"<<endl;
        cout<<"5. Count the movies"<<endl;
        cout<<"6. Quit"<<endl;
        cin>>choice;
        if (choice==1){
            string title;
            cout<<"Enter title: "<<endl;
            cin.ignore();
            getline(cin,title);
            myTree.findMovie(title);
        }
        if (choice==2){
            string rental;
            cout<<"Enter title: "<<endl;
            cin.ignore();
            getline(cin,rental);
            myTree.rentMovie(rental);
        }
        if (choice==3){
            myTree.printMovieInventory();
        }
        if (choice==4){
            string deletion;
            cout<<"Enter title: "<<endl;
            cin.ignore();
            getline(cin,deletion);
            myTree.deleteMovieNode(deletion);
        }
        if (choice==5){
            cout<<"Tree contains: "<<myTree.countMovieNodes()<<" movies."<<endl;
        }
        if (choice==6){
            cout<<"Goodbye!"<<endl;
        }
    }
    return 0;
}
