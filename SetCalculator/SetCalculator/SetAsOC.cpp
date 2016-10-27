//
//  SetAsOC.cpp
//  SetCalculator
//
//  Created by Bikas on 12/1/14.
//  Copyright (c) 2014 bikas. All rights reserved.
//

#include "SetAsOC.h"
#include <iostream>
#include <cstring>

using namespace std;

 int SetAsOC::INITIAL_SIZE = 15;


//the default constructor of SetAsOC
SetAsOC::SetAsOC()
{
    //initially started with size INITIAL_SIZE
    //initializing the collection
    intCollection = new int[INITIAL_SIZE];
    //setting all the values to 0 initailly
    memset(intCollection, 0, INITIAL_SIZE);
    this->size_ = 0;
}

//copy constructor
SetAsOC::SetAsOC(const SetAsOC& aSetAsOC): Set(aSetAsOC)
{
    intCollection = aSetAsOC.intCollection;
}

//virtual destructor for SetAsOC
SetAsOC::~SetAsOC()
{
    //releasing the memory
    this->removeAll();
    //if(intCollection)
    delete[] intCollection;
}

//the deepcopy assigment operator
void SetAsOC:: operator = (Set* rhs)
{
    this->removeAll();
    
    //creating a new array from rhs
    int newSize = ((SetAsOC*)rhs)->size();
    int *anArray = new int[ newSize ];
    this->intCollection = anArray;
    
    //now adding all the elements one by one
    for(int i = 0; i < (((SetAsOC*)rhs)->size_); i++)
        ((SetAsOC*)this)->add(((SetAsOC*)rhs)->intCollection[i]);
}

//returning this pointer for a shallow copy
//overloaded assignment operator(=)for deep copy purpose
SetAsOC* SetAsOC::copy()
{
    // returning this pointer for a shallow copy
    return this;
}

//the index operator
//return the value with the given index
int* SetAsOC:: operator [] (int index)
{
    if(this->intCollection == NULL)
        return NULL;
    else if(index < this->size_)
        return &this->intCollection[index];
    return NULL;
}


bool SetAsOC::contains(int element)
{
    if(this->intCollection == NULL)
        return false;
    for(int i=0;i< this->size_;i++)
    {
        if(this->intCollection[i] == element)
            return true;
    }
    return false;
}

int SetAsOC::add(int element)
{
    
    //checking if the element all the contains
    if(contains(element) == true)
    {
        //cout << "Element " << element << " already present in the set" << endl;
        return 0;
    }
    
    if(size_ < INITIAL_SIZE)
    {
        this->intCollection[size_] = element;
        this->size_++;
        return 1;
    }
    
    //doubling the size of OC
    SetAsOC::INITIAL_SIZE = INITIAL_SIZE * 2;
    int newSize = INITIAL_SIZE;
    int* ptr = new int[newSize];
    
    int i;
    for(i=0;i<size_;i++)
        ptr[i] = this->intCollection[i];
    this->size_ = i;
    delete[] this->intCollection;
    this->intCollection = ptr;
    this->intCollection[size_] = element;
    this->size_++;
    
    return 1;
}





//remove the given element
bool SetAsOC::remove(int element)
{
    if(this->intCollection == NULL)
        return false;
    
    bool found = false;
    int pos = 0;
    for(pos=0;pos < this->size_;pos++)
    {
        if(this->intCollection[pos] == element)
        {
            found = true;
            break;
        }
    }
    
    //found the element need to delete
    if(found)
    {
        //shifting all the elements to the one position left
        for(int i=pos+1;i < this->size_;i++)
            this->intCollection[i-1] = this->intCollection[i];
        
        //now adjusting the size
        //deducting one
        this->size_--;
        return true;
    }
    return false;
}

//remove all the elementes from the Set
void SetAsOC::removeAll()
{
    while(size_ > 0)
        this->remove(this->intCollection[0]);
    this->size_=0;
    INITIAL_SIZE = 15;
    
    
}


//swap receiver and rhs
void SetAsOC::swap(Set* rhs)
{
    Set* temp = new SetAsOC();
    *temp = this;
    *this = rhs;
    *rhs = temp;
    delete temp;
    
}

//set union of receiver and B
void SetAsOC::setUnion(Set* b)
{
    SetAsOC* temp = new SetAsOC();
    *temp = b->copy();
    
    ((SetAsOC*)b)->removeAll();
    
    for(int i=0;i < temp->size();i++)
    {
        this->add(temp->intCollection[i]);
    }
    
    *b = temp->copy();
    
}

//set intersection of receiver and B
void SetAsOC::setIntersection(Set* b)
{
    
    Set* temp = new SetAsOC();
    
    for(int i = 0; i < ((SetAsOC&)*b).size(); i++)
    {
        int val = ((SetAsOC&)*b).intCollection[i];
        if(this->contains(val))
            temp->add(val);
    }
    this->removeAll();
    *this = temp;
    delete temp;
    
    
}


//printing the whole set
void SetAsOC::printSet()
{
    int index = 0;
    while(index < this->size_)
    {
        cout << this->intCollection[index] << " ";
        index++;
    }
    cout << endl;
}

//return the current size of the set
int SetAsOC::size()
{
    return (this->size_);
}