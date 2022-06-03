//
//  CommunicationNetwork.cpp
//  Assignment4
//
//  Created by Malcolm McKellips on 2/16/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include "CommunicationNetwork.hpp"
#include <iostream>
#include <fstream>
using namespace std;


CommunicationNetwork::CommunicationNetwork(){
    head=nullptr;
    tail=nullptr;
}

CommunicationNetwork::~CommunicationNetwork(){
    deleteNetwork();
    head=nullptr;
    tail=nullptr;
}

City* createCity(string newName, City* cityPrev, City* cityNext) {
    City* newCity = new City;
    newCity->cityName = newName;
    newCity->next = cityNext;
    newCity->previous = cityPrev;
    newCity->message="";
    return newCity;
}

City* findCity (string target,City *head){
    City *current=new City;
    current=head;
    while (current!=nullptr){
        if (current->cityName==target)
            return current;
        current=current->next;
    }
    return nullptr;
}

void CommunicationNetwork::addCity(string newCityName, string previousCityName){
    if (head==nullptr){
        head=createCity(newCityName, nullptr, nullptr);
        tail=head;
    }
    else if (previousCityName==""){
        City *newTail;
        newTail=createCity(newCityName, tail, nullptr);
        tail->next=newTail;
        tail=newTail;
    }
    else if (previousCityName=="First"){
        City *newHead;
        newHead=createCity(newCityName, nullptr, head);
        head=newHead;
    }
    else{
        City *newCity,*prevCity;
        prevCity=findCity(previousCityName, head);
        newCity=createCity(newCityName, prevCity, prevCity->next);
        prevCity->next=newCity;
    }
}

void CommunicationNetwork::transmitMsg(char *filename){
    ifstream myfile;
    myfile.open(filename);
    string word;
    if (myfile.fail())
        cout<<"open failed"<<endl;
    if (!myfile.fail()){
        City *current=new City;
        while (myfile>>word){
            current=head;
            while (current!=nullptr){
                if (current->previous!=nullptr)
                    current->previous->message="";
                current->message=word;
                cout<<current->cityName<<" received "<<current->message<<endl;
                current=current->next;
            }
            current=tail->previous;
            while (current!=nullptr){
                current->message=word;
                cout<<current->cityName<<" received "<<current->message<<endl;
                current=current->previous;
            }
        }
    }
}

void CommunicationNetwork::printNetwork(){
    cout<<"===CURRENT PATH==="<<endl;
    cout<<"NULL <- ";
    City *temp=new City;
    temp=head;
    while (temp->next!=nullptr){
        cout<<temp->cityName<<" <-> ";
        temp=temp->next;
    }
    cout<<tail->cityName<<" -> ";
    cout<<"NULL"<<endl;
    cout<<"=================="<<endl;
}

void CommunicationNetwork::buildNetwork(){
    string cityArray[10]={"Los Angeles","Phoenix","Denver","Dallas","St. Louis","Chicago","Atlanta","Washington, D.C.","New York","Boston"};
    head=new City(cityArray[0],nullptr,nullptr,"");
    City *temp, *current;
    current=head;
    head->cityName=cityArray[0];
    head->message="";
    head->next=nullptr;
    current=head;
    for (int i=1;i<10;i++){
        temp=new City;
        temp->cityName=cityArray[i];
        temp->next=nullptr;
        temp->previous=current;
        temp->message="";
        current->next=temp;
        current=temp;
    }
    tail=current;
}

void CommunicationNetwork::deleteCity(std::string removeCity){
    City *current=new City;
    current=head;
    bool found=false;
    while (current!=nullptr){
        if (current->cityName==removeCity){
            found=true;
            if (current->previous==nullptr){
                head=current->next;
                current->next->previous=nullptr;
            }
            else if (current->next==nullptr){
                tail=current->previous;
                current->previous->next=nullptr;
            }
            else{
                current->next->previous=current->previous;
                current->previous->next=current->next;
            }
        }
        current=current->next;
    }
    if (found==false)
        cout<<removeCity<<" not found"<<endl;
}

void CommunicationNetwork::deleteNetwork(){
    City *current=new City;
    current=head;
    while (current!=nullptr){
        cout<<"deleting "<<current->cityName<<endl;
        deleteCity(current->cityName);
        current=current->next;
    }
}
