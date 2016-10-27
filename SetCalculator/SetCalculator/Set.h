//
//  Set.h
//  SetCalculator
//
//  Created by Bikas on 12/1/14.
//  Copyright (c) 2014 bikas. All rights reserved.
//

#ifndef __SetCalculator__Set__
#define __SetCalculator__Set__

#include <iostream>

class Set
{
public:
    //virtual member functions
    virtual ~Set();                                         //virtual Destructor
    virtual Set* copy();                                    //virtual copy function
    
    //pure virtual operator overloading functions
    virtual void operator=(Set*)=0;                         //pure virtual assignment operator
    virtual int* operator[](int)=0;                         //pure virtual index operator [] function
    
    //common pure virtual functions concrete classes will implement
    virtual int add(int)=0;                                 //pure virtual add function
    virtual bool remove(int)=0;                             //pure virtual remove function
    virtual void removeAll()=0;                             //pure virtual removeAll function
    virtual void swap(Set*)=0;                              //pure virtual function to swap
    virtual int size()=0;                                   //pure virtual function to get the size of the set
    virtual void printSet()=0;                              //pure virtual displaySet function
    
    //member functions only implemented in this Set Base class
    void setUnion(Set*);                                    //union of set
    void setIntersection(Set*);                             //intersection of set
    
    
protected:
    //constructors
    Set();                                                  //deafult constructor
    Set(const Set&);                                        //copy constructor
    
    int size_;                                              //data memeber to keep track of the size of the set
    
    
};

#endif /* defined(__SetCalculator__Set__) */
