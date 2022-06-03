//
//  terrible_dynamic_size_array_unsorted.cpp terrible_dynamic_size_array_unsorted.hpp
//  R13
//
//  Created by Malcolm McKellips on 4/19/18.
//  Copyright © 2018 Malcolm McKellips. All rights reserved.
//

#ifndef terrible_dynamic_size_array_unsorted_cpp_terrible_dynamic_size_array_unsorted_hpp
#define terrible_dynamic_size_array_unsorted_cpp_terrible_dynamic_size_array_unsorted_hpp

#include <stdio.h>
#include <iostream>

struct int_array {
    int *data;
    unsigned int count;
    unsigned int capacity;
    static const unsigned int DEFAULT_CAPACITY = 20;
};

void init(int_array& arr);

void destr(int_array& arr);

void resize(int_array& arr);

void clear(int_array& arr);

void add(int_array& arr, const int& payload);

bool contains(const int_array& arr, const int& target);

bool remove(int_array& arr, const int& target);

void print(const int_array& arr);

#endif /* terrible_dynamic_size_array_unsorted_cpp_terrible_dynamic_size_array_unsorted_hpp */
