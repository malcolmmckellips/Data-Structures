//
//  terrible_dynamic_size_array_unsorted.cpp terrible_dynamic_size_array_unsorted.cpp
//  R13
//
//  Created by Malcolm McKellips on 4/19/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#include "terrible_dynamic_size_array_unsorted.cpp terrible_dynamic_size_array_unsorted.hpp"

using namespace std;


void init(int_array& arr)
{
    arr.count = 0;
    arr.capacity = arr.DEFAULT_CAPACITY;
    arr.data = new int[arr.capacity];
}

void clear(int_array& arr)
{
    destr(arr);
    init(arr);
}

void destr(int_array& arr)
{
    //delete [] arr.data;
    arr.count = 0;
}

void print(const int_array& arr)
{
    for (unsigned int i = 0; i < arr.count; ++i)
        cout << arr.data[i] << " ";
    cout << endl;
}

bool contains(const int_array& arr, const int& target)
{
    unsigned int i;
    
    for (i = 0; i < arr.count; ++i)
    {
        if (arr.data[i] == target)
            return true;
    }
    return false;
}

void resize(int_array& arr)
{
    arr.capacity *= 2;
    int* new_data = new int[arr.capacity];
    for (unsigned int i = 0; i < arr.count; ++i)
    {
        new_data[i] = arr.data[i];
    }
    
    arr.data = new_data;
    delete [] arr.data;
    
}

void add(int_array& arr, const int& payload)
{
    
    if (arr.count == arr.capacity) //equality comparison with extraneous parentheses
        resize(arr);
    
    
    arr.data[++arr.count] = payload;
    
}

bool remove(int_array& arr, const int& target)
{
    unsigned int i = 0;
    
    if (arr.count == 0)
        return false;
    
    while (i < arr.count && arr.data[i] != target){
        if (arr.data[i]==target){
            
        }
        arr.count--;
        if (i == arr.count) //if statement has empty body
            return false;
        i++;
    }
    return true;
}
