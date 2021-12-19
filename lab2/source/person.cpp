#include <iostream>

#include "person.h"

using namespace std;

/* ===================================================
    TODO: Complete the other constructor.
          Initialize the Person object by shallow copying the TennisBall and TennisCourt objects.
   =================================================== */ 
Person::Person(TennisBall *tennisball, TennisCourt *tenniscourt)
{
    // Finish constructing with printing.
    cout << "Person Constructed!" << endl;
}


/* ===================================================
    TODO: Complete the copy constructor.
          Deep copy the data members of the "other" dish
    HINT: Usage of a Ternary operator:
          (condition) ? (value_if_true) : (value_if_false);
   =================================================== */ 
Person::Person(const Person &other)
{

    
    // Finish constructing with printing.
    cout << "Person Copied!" << endl;
}

/* ===================================================
    TODO: Complete the destructor.
          Destruct all the data members
   =================================================== */ 
Person::~Person()
{


    // Finish constructing with printing.
    cout << "Person Destructed." << endl;
}