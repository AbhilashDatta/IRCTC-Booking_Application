//Abhilash Datta 19CS30001

#include "Station.h"
#include "Date.h"
#include "MyHashFunction.h"
#include "Railways.h"
#include "BookingClasses.h"
#include "Gender.h"
#include "BookingCategory.h"
#include "Categories.h"
#include "Passenger.h"
#include "Exceptions.h"
#include "Booking.h"
#include <iostream>
using namespace std;

int main(){
    cout<<"\n===Testing Station Class==="<<endl;
    Station::UnitTest();
    
    cout<<"\n===Testing Date Class==="<<endl;
    Date::UnitTest();

    cout<<"\n===Testing Passenger Class==="<<endl;
    Passenger::UnitTest();

    cout<<"\n===Testing Gender Class==="<<endl;
    Gender::UnitTest();

    cout<<"\n===Testing BookingCategory Class==="<<endl;
    BookingCategory::UnitTest();
    
    cout<<"\n===Testing Railways Class==="<<endl;
    Railways::Railway().UnitTest();
    
    cout<<"\n===Testing Exceptions Class==="<<endl;
    Exceptions::UnitTest();    

    cout<<"\n===Testing BookingClasses==="<<endl;
    BookingClass::UnitTest();

    cout<<"END OF UNIT TESTING\n";
    return 0;
}