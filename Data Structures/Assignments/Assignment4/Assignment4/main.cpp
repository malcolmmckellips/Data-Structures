//
//  main.cpp
//  Assignment4
//
//  Created by Malcolm McKellips on 2/16/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include <iostream>
#include "CommunicationNetwork.hpp"
using namespace std;

void printMenu(){
    cout<<"======Main Menu======"<<endl;
    cout<<"1. Build Network"<<endl;
    cout<<"2. Print Network Path"<<endl;
    cout<<"3. Transmit Message Coast-To-Coast-To-Coast"<<endl;
    cout<<"4. Add City"<<endl;
    cout<<"5. Delete City"<<endl;
    cout<<"6. Clear Network"<<endl;
    cout<<"7. Quit"<<endl;
}

int main(int argc, char * argv[]) {
    int choice=0;
    CommunicationNetwork net;
    while (choice!=7){
        printMenu();
        cin>>choice;
        if (choice==1){
            net.buildNetwork();
            net.printNetwork();
        }
        if (choice==2){
            net.printNetwork();
        }
        if (choice==3){
            net.transmitMsg(argv[1]);
        }
        if (choice==4){
            string newCity,prevCity;1
            
            cout<<"Enter a city name: "<<endl;
            cin>>newCity;
            cout<<"Enter a previous city name: "<<endl;
            cin>>prevCity;
            net.addCity(newCity,prevCity);
        }
        if (choice==5){
            string target;
            cout<<"Enter a city name: "<<endl;
            cin>>target;
            net.deleteCity(target);
        }
        if (choice==6){
            net.deleteNetwork();
        }
        if (choice==7){
            cout<<"Goodbye!"<<endl;
        }
    }
}
