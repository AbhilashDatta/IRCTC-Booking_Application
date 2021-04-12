//Abhilash Datta 19CS30001

#ifndef PASSENGER_H
#define PASSENGER_H

#include<iostream>
#include "Date.h"
#include "Gender.h"
using namespace std;

class Passenger{

    string firstName_;
    string middleName_;
    string lastName_;
    string name_;
    string aadhar_;
    Date dateOfBirth_;
    const Gender& gender_;
    string mobile_;
    string disabilityType_;
    string disabilityID_;
    
public:
    //ctor
    Passenger(const string& aadhar, const Date& dob, const Gender& gender, string firstName = "", string middleName = "", string lastName = "", const string& mobile = "", const string& disabilityType = "", const string& disabilityID = "");
    
    //default dtor
    ~Passenger();

    //returns gender
    string GetGender();

    //returns dob
    Date GetDateOfBirth();

    //return disabilityType
    string GetDisabilityType();

    //validating passenger
    bool ValidatePassenger();

    //overloaded ostream
    friend ostream& operator<<(ostream& os, const Passenger& p);
    
    static void UnitTest();
};

inline string Passenger::GetGender(){ return this->gender_.GetName(); }
inline Date Passenger::GetDateOfBirth(){ return this->dateOfBirth_;}
inline string Passenger::GetDisabilityType(){ return this->disabilityType_; }

#endif