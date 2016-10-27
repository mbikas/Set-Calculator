//
//  SetManager.h
//  SetCalculator
//
//  Created by Bikas on 12/1/14.
//  Copyright (c) 2014 bikas. All rights reserved.
//

#ifndef __SetCalculator__SetManager__
#define __SetCalculator__SetManager__

#include <iostream>
#include "SetAsList.h"
#include "Set.h"
#include "SetAsOC.h"

using namespace std;

//this class is responsible for managing all the operations of the two set A and B (either SetAsOC or SetAsList)
class SetManager
{
public:
    //deafult constructor
    SetManager();
    
    //member functions for doing set operations
    //the purpose of these functions is to class apprpriate methods
    //from either SetAsOC or SetAsList basen on the main class input
    void initializeSetLists();
    void initializeSetOrderedCollection();
    void eraseSet();
    void switchSets();
    void copySet();
    void displaySet();
    void addElement(int element);
    void setUnion();
    void setIntersection();
    
    //to enable debug messages
    static const bool DEBUG_MESSAGE = true;
    
protected:
    Set* A;                     //Polymorphic identifiers for Set A can be bound be either SetAsOC or SetAsList
    Set* B;                     //Polymorphic identifiers for Set A can be bound be either SetAsOC or SetAsList
    
};

#endif /* defined(__SetCalculator__SetManager__) */
