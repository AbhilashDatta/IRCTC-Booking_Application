//Abhilash Datta 19CS30001

Source.zip

Total Number of files = 23 (including README)
Compiler used: g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0

----------------------------------------------------------------------------------------------------------------------------
Implementation files

HEADER                  C++ SOURCE

Station.h               Station.cpp                 contains Station class
Date.h                  Date.cpp                    contains Date class
Railways.h              Railways.cpp                contains Railways class
Gender.h		Gender.cpp		    contains Gender class
MyHashFunction.h        MyHashFunction.cpp          contains Hash functor for unordered map
BookingClasses.h        BookingClasses.cpp          contains BookingClass class and hierarchy
BookingCategory.h	BookingCategory.cpp	    contains Booking category (abstract)	
Categories.h		Categories.cpp		    contains hierarchy of BookingCategory
Exceptions.h		Exception.cpp		    contains exception class and hiearchy 
Booking.h               Booking.cpp                 contains Booking class and hierarchy
Passenger.h             Passenger                   contains Passenger class
----------------------------------------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------------------------------------
Testing Files

C++ SOURCE

UnitTesting.cpp                     contains unittesting method calls
BookingApplication.cpp               contains application testing calls
----------------------------------------------------------------------------------------------------------------------------

To compile UnitTesting.cpp : g++ compiler
CODE:
g++ UnitTesting.cpp Booking.cpp Station.cpp BookingCategory.cpp Categories.cpp BookingClasses.cpp Passenger.cpp Date.cpp Railways.cpp MyHashFunction.cpp Exceptions.cpp Gender.cpp
To compile BookingApplication.cpp : g++ compiler
CODE:
g++ g++ BookingApplication.cpp Booking.cpp Station.cpp BookingCategory.cpp Categories.cpp BookingClasses.cpp Passenger.cpp Date.cpp Railways.cpp MyHashFunction.cpp Exceptions.cpp Gender.cpp