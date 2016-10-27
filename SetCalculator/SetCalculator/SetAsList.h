//
//  SetAsList.h
//  SetCalculator
//
//  Created by Bikas on 12/1/14.
//  Copyright (c) 2014 bikas. All rights reserved.
//

#ifndef __SetCalculator__SetAsList__
#define __SetCalculator__SetAsList__

#include <iostream>
#include "Node.h"
#include "Set.h"

//implementation of Set as Linked List
class SetAsList:public Set
{
public:
    //constructor
    SetAsList();                                            //deafult constructor
    SetAsList(const SetAsList&);                            //copy constructor
    
    //virtual copy function and destructor
    virtual SetAsList* copy();                              //virtual copy function
    virtual ~SetAsList();                                   //virtual Destructor
    
    //member function for operator overloading
    virtual void operator=(Set*);                           //virtual assignment operator
    virtual int* operator[](int);                           //virtual index operator [] function
    
    //supreclass pure virtual member functions implemened here
    virtual int add(int);                                   //add element to set
    virtual bool remove(int);                               //remove given element from set
    virtual void removeAll();                               //clear whole set
    virtual void swap(Set*);                                //swap given set with the receiver
    virtual int size();                                     //returns the size of the set
    virtual void printSet();                                //prints the elements of the Set
    
    //member functions only implemented in this Set Base class
    void setUnion(Set*);                                    //union of set
    void setIntersection(Set*);                             //intersection of set
    bool contains(int);                                     //checks if any element is present in the set
    void setSize(int);                                      //set the size of the set
    
protected:
    Node* head_;                                            // head of the set for linked list
    int elements_;                                          // the size of the set
    
};
#endif /* defined(__SetCalculator__SetAsList__) */
