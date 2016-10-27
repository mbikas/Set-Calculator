//
//  SetAsList.cpp
//  SetCalculator
//
//  Created by Bikas on 12/1/14.
//  Copyright (c) 2014 bikas. All rights reserved.
//

#include "SetAsList.h"
#include <iostream>

using namespace std;

//implementation of default constructor
SetAsList::SetAsList()
{
    head_ = (Node *) NULL;
    elements_ = 0;
}

//copy constructor
SetAsList::SetAsList(const SetAsList& rhs):Set (rhs)
{
    head_=rhs.head_;
    elements_ = rhs.elements_;
    
}

//virtual destructor of SetAsList
SetAsList::~SetAsList()
{
    //deleting all the nodes from the set
    Node *pDelete = head_;
    /* Traverse the list and delete the node one by one from the head */
    while (pDelete != NULL) {
        /* take out the head node */
        head_ = head_->next_;
        delete pDelete;
        /* update the head node */
        pDelete = head_;
    }
    /* Reset the head */
    head_ = NULL;
    elements_ = 0;
}

//virtual assigment oerator
//simulating deep copy
void SetAsList:: operator = (Set* rhs)
{
    if(rhs == this)return;
    
    //freeing the memory first deleting all the nodes
	this->removeAll();
    
    Node* givenNode = ((SetAsList*)rhs)->head_;
    if(givenNode != NULL)
    {
        
        Node* tempNode = new Node();
        tempNode->data_ = givenNode->data_;
        this->head_ = tempNode;
        givenNode = givenNode->next_;
    
        this->setSize(rhs->size());
    
        Node* currentNode = this->head_;
        while(givenNode != NULL)
        {
            Node* newNode = new Node();
            newNode->data_ = givenNode->data_;
            currentNode->next_ = newNode;
            givenNode = givenNode->next_;
            currentNode=newNode;
        }
        currentNode->next_ = NULL;
        
        this->elements_ = rhs->size();
    }
}

//returning this pointer for a shallow copy
//overloaded assignment operator(=)for deep copy purpose
SetAsList* SetAsList::copy()
{
    return this;
}

//virtual index operator
//return the element at the given index
int* SetAsList:: operator [] (int index)
{
    if( this->head_ == NULL || index < 0 || index >= size_)
        return NULL;
    
    int i = 0;
    Node* currentNode = this->head_;
    while(i < index)
    {
        if(currentNode == NULL) return NULL;
        currentNode = currentNode->next_;
        i++;
    }
    return &currentNode->data_;
}

//adding an integer element to the set (LinkedList)
int SetAsList::add(int element)
{
    
    if(contains(element) == true)
    {
        //cout << "Element " << element << " already present in the set" << endl;
        return 0;
    }
    
    Node* newNode = new Node();
    newNode->data_ = element;
    elements_++;
    size_ = elements_;
    
    
    //if this is the first element of the set
	if(this->head_ == NULL)
	{
	    head_ = newNode;
        head_->next_ = NULL;
	    return 1;
	}
    
    //otherwise adding the element at the end of the list
    Node* tempNode = this->head_;
    while(tempNode->next_ != NULL)
        tempNode = tempNode->next_;
    
    tempNode->next_ = newNode;
    return 1;
    
    
}

//remove the given element from the set
bool SetAsList::remove(int element)
{
    if(elements_ == 0)return false;
    
    Node* pPrevious = NULL;
    Node* pDelele =  NULL;
    
    //Checking if the elements is the head, if yes delete and updating head node
    if (head_->data_ == element)
    {
        pDelele = head_;
        head_ = pDelele->next_;
        delete pDelele;
        elements_--;
        size_=elements_;
        return true;
    }
    
    pPrevious = head_;
    pDelele = head_->next_;
    
    //now traversing the set and checking each node
    while (pDelele != NULL)
    {
        if (pDelele->data_ == element)
        {
            // Updating the list
            pPrevious->next_ = pDelele->next_;
            delete pDelele;
            elements_--;
            size_=elements_;
            return true;
        }
        pPrevious = pDelele;
        pDelele = pDelele->next_;
    }
    return false;
    
	
}


//delete all the Nodes from the set
void SetAsList::removeAll()
{
    if(this->head_ != NULL)
    {
        Node* currentNode = this->head_;
        Node* nextNode = NULL;
        while(currentNode->next_ != NULL)
        {
            nextNode = currentNode->next_;
            delete currentNode;
            currentNode = nextNode;
        }
        delete currentNode;
        this->head_ = NULL;
        
        this->elements_ = 0;
    }
}

//swap receiver and rhs
void SetAsList::swap(Set* rhs)
{
    Set* temp = new SetAsList();
    *temp = rhs->copy();
    *rhs = this->copy();
    *this = temp->copy();
    delete temp;
}

//checking if the elements contains in the set
bool SetAsList::contains(int element)
{
    
    if(this->head_ != NULL)
    {
        Node* currentNode = this->head_;
        while(currentNode != NULL)
        {
            if(currentNode->data_ == element)
                return true;
            currentNode = currentNode->next_;
        }
    }
    return false;
    
}

//set union of receiver and B
void SetAsList::setUnion(Set* b)
{
    Node* givenNode = ((SetAsList&)*b).head_;
    while(givenNode != NULL)
    {
        this->add(givenNode->data_);
        givenNode = givenNode->next_;
    }
    delete givenNode;
}

//set intersection of receiver and B
void SetAsList::setIntersection(Set* b)
{
    Set* temp = new SetAsList();
    Node* givenNode = ((SetAsList&)*b).head_;
    while(givenNode != NULL)
    {
        //if the elements in B contains A
        //storing it in a temporary Set
        if(this->contains(givenNode->data_))
            temp->add(givenNode->data_);
        givenNode = givenNode->next_;
    }
    delete givenNode;
    this->removeAll();
    *this = temp->copy();
    delete temp;
}

//display the current elements of the set
void SetAsList::printSet()
{
    Node* currentNode = this->head_;
    while(currentNode != NULL)
    {
        cout <<  currentNode->data_ << " ";
        currentNode = currentNode->next_;
    }
    cout << endl;
}

//set the size of the set
void SetAsList::setSize(int sz)
{
    this->size_ = sz;
}
//returns the length of the set
int SetAsList::size()
{
    //cout << "Size called " <<endl;
    return elements_;
}