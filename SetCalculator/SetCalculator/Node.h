//
//  Node.h
//  SetCalculator
//
//  Created by Bikas on 12/1/14.
//  Copyright (c) 2014 bikas. All rights reserved.
//

#ifndef __SetCalculator__Node__
#define __SetCalculator__Node__

#include <iostream>

class Node
{
    friend class SetAsList;
private:
    int data_;      //  data, for this project assuming it will be only integers
    Node* next_;     //  pointer to the next node
    
public:
    
    //default Constructors,  with No Arguments
    Node(void): next_(NULL)
    { }
    
    //Constructors with a given element
    Node(int element): data_(element), next_(NULL)
    { }
    
    // Constructors with a given element and a link of the next node
    Node(int element, Node* next): data_(element), next_(next)
    {}
    
    // Getters
    int getValue()
    { return data_; }
    
    Node* getNext()
    { return next_; }
    
};

#endif /* defined(__SetCalculator__Node__) */
