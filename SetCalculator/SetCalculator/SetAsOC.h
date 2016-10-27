//
//  SetAsOC.h
//  SetCalculator
//
//  Created by Bikas on 12/1/14.
//  Copyright (c) 2014 bikas. All rights reserved.
//

#ifndef __SetCalculator__SetAsOC__
#define __SetCalculator__SetAsOC__

#include <iostream>
#include "Set.h"

//implementation of Set as Ordered Collection
class SetAsOC:public Set
{
public:
    
    //constructor
    SetAsOC();                                              //deafult constructor
    SetAsOC(const SetAsOC&);                                //copy constructor
    
    
    //virtual copy function and destructor
    virtual SetAsOC* copy();                                //virtual copy function
    virtual ~SetAsOC();                                     //virtual Destructor
    
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
    
protected:
    int *intCollection;                                     //array to store values of the Ordered Collection

private:
    static int INITIAL_SIZE;                                //Initial size of the Orderd Collection
    
};

#endif /* defined(__SetCalculator__SetAsOC__) */
