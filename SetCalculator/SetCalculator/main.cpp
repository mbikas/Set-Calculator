//
//  main.cpp
//  SetCalculator
//
//  Created by Bikas on 12/1/14.
//  Copyright (c) 2014 bikas. All rights reserved.
//

#include <iostream>
#include "SetAsList.h"
#include "Set.h"
#include "SetAsOC.h"
#include "SetManager.h"

using namespace std;

int main(int argc, const char * argv[])
{
    
    /*
    //Testing SetAsList == LinkedList
    Set* A = new SetAsList();
    Set* B = new SetAsList();
    
    //Testing SetAsOC == OrderedCollection
    //Set* A = new SetAsOC();
    //Set* B = new SetAsOC();
    
    //testing add
    A->add(1);
    A->add(1);
    A->add(2);
    A->add(3);
    A->add(4);
    A->add(5);
    A->add(6);
    A->add(7);
    cout << "A: "; A->printSet();
    cout << "B: "; B->printSet();
    
    //testing swap
    A->swap(B);
    cout << "A: "; A->printSet();
    cout << "B: "; B->printSet();
    //testing size
    cout<<"Size of the Linked List A is " << A->size() << endl;
    cout<<"Size of the Linked List B is " << B->size() << endl;
    
    //testing copy
    A->add(10);
    A->add(20);
    A->add(30);
    *B = A->copy();
    cout << "A: "; A->printSet();
    cout << "B: "; B->printSet();
    
    //testing revome
    A->remove(10);
    A->remove(1);
    cout << "A: "; A->printSet();
    cout << "B: "; B->printSet();
    
    //testing overloaded index operator []
    int* i=(*A)[0];
    int* j=(*B)[0];
    if(i != NULL)cout<<"the 1st value in the Set A is " << *i << endl;
    if(j != NULL)cout<<"the 1st value in the Set B is " << *j << endl;
    
    //testing removeAll
    A->removeAll();
    cout << "A: "; A->printSet();
    cout << "B: "; B->printSet();
    
    //testing set union
    B->add(10);
    B->add(20);
    B->add(5);
    A->setUnion(B);
    cout << "A: "; A->printSet();
    cout << "B: "; B->printSet();
    
    //testing set intersection
    A->remove(10);
    A->remove(20);
    A->remove(30);
    A->setIntersection(B);
    cout << "A: "; A->printSet();
    cout << "B: "; B->printSet();
    */
    
    
    //SetManager instance to do all necessarry Set operations of the two set A and B (either SetAsOC or SetAsList)
    SetManager setManager;
    
    char input;
    int element = 0;
    bool start = true;
    while(1)
    {
        if(start)
        {
            cout << "By default Set A and B is initialized with LinkedList" << endl << endl;
            start = false;
        }
        cout << "Press l : To initialize Set A and B as LinkedList" << endl;
        cout << "Press o : To initialize Set A and B as OrderedCollection" << endl;
        cout << "Press e : To Erase all the elements from Set A" << endl;
        cout << "Press s : To Switch between Set A and B" << endl;
        cout << "Press c : For copying elements from Set A to Set B" << endl;
        cout << "Press d : For Displaying Set A and B" << endl;
        cout << "Press a : For Adding element to A" << endl;
        cout << "Press u : For Union. A = A union B " << endl;
        cout << "Press i : For Intersection. A = A intersection B" << endl;
        cout << "Press q : Quit Set Manager" << endl;
        
        cin >> input;
        
        if( input == 'l' || input == 'L')
            setManager.initializeSetLists();
        else if( input == 'o' || input == 'O')
                setManager.initializeSetOrderedCollection();
        else if( input == 'e' || input == 'E')
            setManager.eraseSet();
        else if( input == 's' || input == 'S')
            setManager.switchSets();
        else if( input == 'c' || input == 'C')
            setManager.copySet();
        else if( input == 'd' || input == 'D')
            setManager.displaySet();
        else if( input == 'a' || input == 'A')
        {
            cout << "Please enter the value to add (integer only)" << endl;
            cin >> element;
            setManager.addElement(element);
        }
        else if( input == 'u' || input == 'U')
            setManager.setUnion();
        else if( input == 'i' || input == 'I')
            setManager.setIntersection();
        else if( input == 'q' || input == 'Q')
            break;
        else
            cout << "Invalid input" << endl;
        
        
    }
    cout << "Thanks for using SET Manager Application" << endl;
    return 0;
}
