//
//  Set.cpp
//  SetCalculator
//
//  Created by Bikas on 12/1/14.
//  Copyright (c) 2014 bikas. All rights reserved.
//

#include "Set.h"
#include <typeinfo>
#include "SetAsList.h"
#include "SetAsOC.h"

using namespace std;

//default constructor
Set::Set()
{
    size_= 0;
}

//virtual copy constructor
Set::Set(const Set& set){}

//virtual destructor
Set::~Set(){}

//virtual copy function
Set* Set::copy()
{
    Set* newSet = (*this).copy();
    return newSet;
}

//set union of A and B
void Set::setUnion(Set* b)
{
    
    if(typeid(*this)==typeid(SetAsList))
        ((SetAsList&)*this).setUnion(b);
    else
        ((SetAsOC&)*this).setUnion(b);
}

//set intersection of of A and B
void Set::setIntersection(Set* b)
{
    if(typeid(*this)==typeid(SetAsList))
        ((SetAsList&)*this).setIntersection(b);
    else
        ((SetAsOC&)*this).setIntersection(b);
}