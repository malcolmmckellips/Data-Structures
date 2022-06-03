//
//  main.cpp
//  Final_Project
//
//  Created by Malcolm McKellips on 4/30/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "priorityQueueLL.hpp"
#include "priorityQueueHeap.hpp"
#include <queue>
#include <time.h>
#include <math.h>
using namespace std;

double mean(vector<double> v){
    double sum=0;
    for (int i=0; i<(int)v.size(); i++){
        sum=sum+v[i];
    }
    return (double)(sum/v.size());
}

double stdDev(vector<double> v){
    double avg = mean(v);
    double sum = 0;
    double difference = 0;
    for (int i = 0; i<(int)v.size(); i++){
        difference = v[i] - avg;
        sum = sum + pow( difference , 2 );
    }
    return sqrt( sum / ((double)v.size()-1) );
}

void TimeLLEnqueue(int size,vector <patient> patientArray){
    double startTime,endTime;
    vector <double> EnqueLLTimes;
    priorityQueueLL TimingLLPQ;
    double execTime = 0;
    for (int i = 0; i<5000 ; i++){
        startTime = clock();
        for (int j=0;j<size;j++){
            TimingLLPQ.enqueue(patientArray[j]);
        }
        endTime = clock();
        execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
        EnqueLLTimes.push_back(execTime);
        TimingLLPQ.dequeueAll();
    }
    cout<<"Enqueing "<<size<< " elements in a linked list PQ took on average "<<mean(EnqueLLTimes)<<" seconds with a standard deviation of "<<stdDev(EnqueLLTimes)<<endl;
}

void TimeHeapPush(int size,vector <patient> patientArray){
    double begin,ending;
    vector <double> EnqueueHeapTimes;
    priorityQueueHeap TimingheapPQ(size);
    double totalTime = 0;
    for (int i = 0; i<5000 ; i++){
        begin = clock();
        for (int j=0; j<size ; j++){
            TimingheapPQ.push(patientArray[j]);
        }
        ending = clock();
        totalTime = (double)(ending-begin)/CLOCKS_PER_SEC;
        EnqueueHeapTimes.push_back(totalTime);
        TimingheapPQ.popAll();
    }
    cout << "Pushing "<<size<<" elements in an array heap PQ took on average "<<mean(EnqueueHeapTimes)<<" seconds with a standard deviation of "<<stdDev(EnqueueHeapTimes)<<endl;
}

void TimeSTLPush(int size,vector <patient> patientArray){
    double starter,ender;
    vector <double> EnqueueSTLTimes;
    priority_queue<patient,vector<patient>,greater<patient>> TimingSTLPQ;
    double ellapsed = 0;
    for (int i=0 ; i<5000 ; i++){
        starter = clock();
        for (int j=0 ; j<size ; j++){
            TimingSTLPQ.push(patientArray[j]);
        }
        ender = clock();
        ellapsed = (double)(ender-starter)/CLOCKS_PER_SEC;
        EnqueueSTLTimes.push_back(ellapsed);
        while (!TimingSTLPQ.empty()){
            TimingSTLPQ.pop();
        }
    }
    cout << "Pushing "<<size<<" elements in an STL PQ took on average "<<mean(EnqueueSTLTimes)<<" seconds with a standard deviation of "<<stdDev(EnqueueSTLTimes)<<endl;
}

void TimeLLDequeue(int size, vector <patient> patientArray){
    priorityQueueLL TimingDQLLPQ;
    double alpha, omega;
    vector <double> DequeueLLTimes;
    double interim = 0;
    for (int i=0; i<5000; i++){
        for (int j=0; j<size; j++){
            TimingDQLLPQ.enqueue(patientArray[j]);
        }
        alpha = clock();
        TimingDQLLPQ.dequeueAll();
        omega = clock();
        interim = (double)(omega-alpha)/CLOCKS_PER_SEC;
        DequeueLLTimes.push_back(interim);
    }
    cout<<"Dequeueing "<<size<<" elements in a linked list PQ took on average "<<mean(DequeueLLTimes)<<" seconds with a standard deviation of "<<stdDev(DequeueLLTimes)<<endl;
}


void TimeHeapDequeue(int size, vector <patient> patientArray){
    priorityQueueHeap TimingDQheapPQ(880);
    double nexus, revelation;
    vector <double> HeapDequeueTimes;
    double life = 0;
    for (int i=0 ; i<5000 ; i++){
        for (int j=0 ; j<size ; j++){
            TimingDQheapPQ.push(patientArray[j]);
        }
        nexus = clock();
        TimingDQheapPQ.popAll();
        revelation = clock();
        life = (double)(revelation - nexus)/CLOCKS_PER_SEC;
        HeapDequeueTimes.push_back(life);
    }
    cout<<"Popping "<<size<<" elements in a heap array PQ took on average "<<mean(HeapDequeueTimes)<<" seconds with a standard deviation of "<<stdDev(HeapDequeueTimes)<<endl;
}

void TimeSTLDequeue(int size, vector <patient> patientArray){
    priority_queue<patient,vector<patient>,greater<patient>> TimingDQSTLPQ;
    double genesis, exodus;
    vector <double> STLDequeueTimes;
    double torah = 0;
    for (int i=0; i<5000; i++){
        for (int j=0 ; j<size ; j++){
            TimingDQSTLPQ.push(patientArray[j]);
        }
        genesis = clock();
        while (!TimingDQSTLPQ.empty()){
            TimingDQSTLPQ.pop();
        }
        exodus = clock();
        torah = (double)(exodus - genesis)/CLOCKS_PER_SEC;
        STLDequeueTimes.push_back(torah);
    }
    cout<<"Popping "<<size<<" elements in an STL PQ took on average "<<mean(STLDequeueTimes)<<" seconds with a standard deviation of "<<stdDev(STLDequeueTimes)<<endl;
}

void printMenu(){
    cout<<"*********** MENU ***********"<<endl;
    cout<<"1. Test LL PQ"<<endl;
    cout<<"2. Test Heap PQ"<<endl;
    cout<<"3. Test STL PQ"<<endl;
    cout<<"4. Time Enqueueing in LL PQ"<<endl;
    cout<<"5. Time Enqueueing in Heap PQ"<<endl;
    cout<<"6. Time Enqueueing in STL PQ"<<endl;
    cout<<"7. Time Dequeueing in LL PQ"<<endl;
    cout<<"8. Time Dequeueing in Heap PQ"<<endl;
    cout<<"9. Time Dequeueing in STL PQ"<<endl;
    cout<<"10. QUIT"<<endl;
}



int main(int argc,char *argv[]){
    
    /********************************************/
    //Testing mean

    /*
    vector <double> myVect;
    myVect.push_back(2);
    myVect.push_back(3);
    myVect.push_back(111);
    cout<< "Vector is of size: "<<myVect.size()<<endl;
    cout<< "Average of vector is: "<<mean(myVect)<<endl;
     */
    
    /********************************************/
    
    //Testing Standard Deviation
    
    /*
    vector <double> myVect;
    myVect.push_back(2);
    myVect.push_back(7);
    myVect.push_back(95);
    myVect.push_back(13);
    myVect.push_back(1);
    myVect.push_back(400);
    myVect.push_back(0);
    myVect.push_back(523);
    myVect.push_back(0);
    myVect.push_back(4);
    
    cout<<"The standard deviation of the given vector is: "<<stdDev(myVect)<<endl;
    */
    
    /********************************************/
    
    //Reading in the file and storing data in a vector of Patient structs called patientArray
    
    ifstream myfile;
    string discard,line;
    priorityQueueLL linkedPQ;
    vector <patient> patientArray;
    //myfile.open("patientData2270.csv");
    myfile.open(argv[1]);
    getline(myfile,discard);
    while (getline(myfile,line)){
        string n,p,t;
        int nump,numt;
        stringstream ss;
        ss<<line;
        getline(ss,n,',');
        getline(ss,p,',');
        getline(ss,t,',');
        nump=stoi(p);
        numt=stoi(t);
        patient newPatient(n,nump,numt);
        patientArray.push_back(newPatient);
        //linkedPQ.enqueue(newPatient);
    }
    myfile.close();
    
    
    /********************************************/
    
    //BEGINNING OF MENU FUNCTION
    
    
    int choice = 0;
    while (choice != 10){
        printMenu();
        cin>>choice;
    /********************************************/
        
        //Testing Linked List Priority Queueue
        if (choice == 1){
            //Testing Enqueue
            
             for (int i=0;i<(int)patientArray.size();i++){
                linkedPQ.enqueue(patientArray[i]);
             }
             //linkedPQ.printQueue();
             //linkedPQ.dequeueAll();
             //linkedPQ.printQueue();
    
             //Testing Dequeue
    
             vector <patient> dequedPregos;
             for (int i=0;i<880;i++){
             dequedPregos.push_back(linkedPQ.dequeue());
             }
             int rank = 1;
             cout<<"Rank\tpatient,  Priority,  Treatment"<<endl;
             for (int i=0;i<880;i++){
             cout<< rank << ":\t"<<dequedPregos[i].name<<",  "<<dequedPregos[i].priority<<",  "<<dequedPregos[i].treatment<<endl;
             rank++;
             }
             
        }
    

    /********************************************/
    
        //Testing Heap Priority Queue
        else if (choice == 2){
             vector <patient> poppedPregos;
             priorityQueueHeap heapPQ(880);
             for (int i=0;i<(int)patientArray.size();i++){
                heapPQ.push(patientArray[i]);
             }
    
             for (int i=0; i<880; i++){
                poppedPregos.push_back(heapPQ.pop());
             }
             int rank2 = 1;
             cout<<"Rank\tpatient,  Priority,  Treatment"<<endl;
             for (int i=0;i<880;i++){
                cout<< rank2 << ":\t"<<poppedPregos[i].name<<",  "<<poppedPregos[i].priority<<",  "<<poppedPregos[i].treatment<<endl;
                rank2++;
             }
        }
    
    
    /********************************************/
    

    //Testing STL Priority Queue
        else if (choice == 3){
             priority_queue<patient,vector<patient>,greater<patient>> STLPQ;
             vector <patient> STLPregos;
             for (int i=0;i<(int)patientArray.size();i++){
                STLPQ.push(patientArray[i]);
             }
             for (int i=0; i<880; i++){
                STLPregos.push_back(STLPQ.top());
                STLPQ.pop();
             }
             int rank3 = 1;
             cout<<"Rank\tpatient,  Priority,  Treatment"<<endl;
             for (int i=0;i<880;i++){
                cout<< rank3 << ":\t"<<STLPregos[i].name<<",  "<<STLPregos[i].priority<<",  "<<STLPregos[i].treatment<<endl;
                rank3++;
             }
        }
    

    
    /********************************************/
    
    //Timing for enqueueing in the linked list
        else if (choice == 4){
             TimeLLEnqueue(100,patientArray);
             TimeLLEnqueue(200,patientArray);
             TimeLLEnqueue(300,patientArray);
             TimeLLEnqueue(400,patientArray);
             TimeLLEnqueue(500,patientArray);
             TimeLLEnqueue(600,patientArray);
             TimeLLEnqueue(700,patientArray);
             TimeLLEnqueue(800,patientArray);
             TimeLLEnqueue(880,patientArray);
        }
    
    
    /********************************************/
    
    //Timing for enqueueing in the heap
        else if (choice == 5){
             TimeHeapPush(100, patientArray);
             TimeHeapPush(200, patientArray);
             TimeHeapPush(300, patientArray);
             TimeHeapPush(400, patientArray);
             TimeHeapPush(500, patientArray);
             TimeHeapPush(600, patientArray);
             TimeHeapPush(700, patientArray);
             TimeHeapPush(800, patientArray);
             TimeHeapPush(880, patientArray);
        }
    
    /********************************************/
    
    //Timing for enqueueing in the STL
        else if (choice == 6){
             TimeSTLPush(100, patientArray);
             TimeSTLPush(200, patientArray);
             TimeSTLPush(300, patientArray);
             TimeSTLPush(400, patientArray);
             TimeSTLPush(500, patientArray);
             TimeSTLPush(600, patientArray);
             TimeSTLPush(700, patientArray);
             TimeSTLPush(800, patientArray);
             TimeSTLPush(880, patientArray);
        }
    
    
    /********************************************/
    
    //Timing for dequeueing in the Linked List
        else if (choice == 7) {
            
             TimeLLDequeue(100, patientArray);
             TimeLLDequeue(200, patientArray);
             TimeLLDequeue(300, patientArray);
             TimeLLDequeue(400, patientArray);
             TimeLLDequeue(500, patientArray);
             TimeLLDequeue(600, patientArray);
             TimeLLDequeue(700, patientArray);
             TimeLLDequeue(800, patientArray);
             TimeLLDequeue(880, patientArray);
    
        }
    /********************************************/
    
    //Timing for dequeueing in the Heap
        else if (choice == 8){
            
            TimeHeapDequeue(100, patientArray);
            TimeHeapDequeue(200, patientArray);
            TimeHeapDequeue(300, patientArray);
            TimeHeapDequeue(400, patientArray);
            TimeHeapDequeue(500, patientArray);
            TimeHeapDequeue(600, patientArray);
            TimeHeapDequeue(700, patientArray);
            TimeHeapDequeue(800, patientArray);
            TimeHeapDequeue(880, patientArray);
            
        }
    
    
    /********************************************/
    
    //Timing for dequeueing in the STL
        else if (choice == 9){
            
             TimeSTLDequeue(100, patientArray);
             TimeSTLDequeue(200, patientArray);
             TimeSTLDequeue(300, patientArray);
             TimeSTLDequeue(400, patientArray);
             TimeSTLDequeue(500, patientArray);
             TimeSTLDequeue(600, patientArray);
             TimeSTLDequeue(700, patientArray);
             TimeSTLDequeue(800, patientArray);
             TimeSTLDequeue(880, patientArray);
             
        }
        
        else if (choice == 10){
            cout<<"Goodbye!"<<endl;
            return 0;
        }
        
        else
            cout<<"Invalid selection, try again."<<endl;
    }
}
