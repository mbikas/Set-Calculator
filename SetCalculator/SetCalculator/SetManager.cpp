//
//  SetManager.cpp
//  SetCalculator
//
//  Created by Bikas on 12/1/14.
//  Copyright (c) 2014 bikas. All rights reserved.
//

#include "SetManager.h"

//deafult constructor of SetManager
//by default initializing linked list
SetManager::SetManager()
{
    A = NULL;
    B = NULL;
    initializeSetLists();
}

//Initialize two new sets A and B using the linked list implementation of sets.
//The current sets A and B, if they exist, is deleted.
void SetManager::initializeSetLists()
{
    //if not null then release the memory otherwise initialize A
    if(A != NULL) delete A;
    A = new SetAsList();
    
    //if not null then release the memory otherwise initialize A
    if(B != NULL) delete B;
    B = new SetAsList();
    
    if(DEBUG_MESSAGE)
        cout << "Set A and B inittialized as SetAsList" << endl;
}

//Initialize two new sets A and B using the OrderedCollection implementation of sets.
//The current sets A and B, if they exist, is deleted.
void SetManager::initializeSetOrderedCollection()
{
    //if not null then release the memory otherwise initialize A
    if(A != NULL) delete A;
    A = new SetAsOC();
    
    //if not null then release the memory otherwise initialize A
    if(B != NULL) delete B;
    B = new SetAsOC();
    
    if(DEBUG_MESSAGE)
        cout << "Set A and B inittialized as OrderedCollection" << endl;
}

//delete the current A set. The previous value stored in A is lost.
//A is bound to a new, empty set after this command is complete
void SetManager::eraseSet()
{
    A->removeAll();
    if(DEBUG_MESSAGE)
        cout << "Set A successfully erased" << endl;
    
}

//The sets associated with A and B are swapped,
//A will receive the previous B set and vice versa
void SetManager::switchSets()
{
    A->swap(B);
    if(DEBUG_MESSAGE)
        cout << "Set A and B successfully swapped" << endl;
}

//Set A is deep copied into B. The previous content of B is lost.
//The content of A is not affected.
void SetManager::copySet()
{
    *B = A->copy();
    if(DEBUG_MESSAGE)
        cout << "Set A deep copied into Set B" << endl;
}

//Display set contents of A and B.
//The integers stored in the two sets are displayed on the standard output stream.
void SetManager::displaySet()
{
    
    cout << "SET A: ";
    A->printSet();
    
    cout << "SET B: ";
    B->printSet();
    
}

//Add a new integer to A. The value is obtained.
//No action is taken if the integer in question is already in the set
void SetManager::addElement(int element)
{
    int status = A->add(element);
    if(DEBUG_MESSAGE == true)
    {
        if(status == 0)
        {
            cout << "Element " << element << " already present in the set" << endl;
        }
        else
        {
            cout << "Element " << element << " succesfully added to Set A" << endl;
        }
    }
}

//set union of A and B and stores the resulting value in A.
//The previous content of A is lost. Set B is not modified by this operation.
void SetManager::setUnion()
{
    A->setUnion(B);
    if(DEBUG_MESSAGE)
        cout << "A union B operation successfully occured" << endl;
    
}

//Set intersection of A and B and stores the resulting value in A.
//The previous content of A is lost. Set B is not modified by this operation
void SetManager::setIntersection()
{
    A->setIntersection(B);
    if(DEBUG_MESSAGE)
        cout << "A intersection B operation successfully occured" << endl;
}
