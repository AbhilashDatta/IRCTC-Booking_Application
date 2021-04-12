// Abhilash 19CS30001
#include <iostream>
using namespace std;

#include "Gender.h"

// Names defined as static constants
template<>
const string Gender::Male::sName = "Male";

template<>
const string Gender::Female::sName = "Female";

// Salutations defined as static constants
template<>
const string Gender::Male::sSalutation = "Mr.";

template<>
const string Gender::Female::sSalutation = "Ms.";

void Gender::UnitTest(){
    //Testing Getname
    if(Gender::Male::Type().GetName()!="Male") cout<<"Error in GetName\n";
    if(Gender::Female::Type().GetName()!="Female") cout<<"Error in GetName\n";
    //Testing GetTitle
    if(Gender::Male::Type().GetTitle()!="Mr.") cout<<"Error in GetTitle\n";
    if(Gender::Female::Type().GetTitle()!="Ms.") cout<<"Error in GetTitle\n";
    //Testing IsMale
    if(Gender::IsMale(Gender::Male::Type())!=true) cout<<"Error in IsMale\n";
    cout<<"If nothing is printed till now, that means no error.\n";
} 
