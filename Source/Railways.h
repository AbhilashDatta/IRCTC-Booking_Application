//Abhilash Datta 19CS30001

#ifndef RAILWAYS_H
#define RAILWAYS_H

#include<iostream>
#include<vector>
#include<unordered_map>
#include "Station.h"
#include "MyHashFunction.h"
using namespace std;

//Singleton Class
class Railways{
protected:
    string name_; //IndianRailways
    static vector<Station> sStations; //a static list (vector) of Stations (known a priori) 
    static unordered_map<pair<Station,Station>,double,MyHashFunction> sDistStations ; //an unordered map (Hash Map) to store the distance between any pair of stations 

private:
    //private ctor / dtor
    Railways(string name = "IndianRailways");
    ~Railways();

public:
    //calls the constructor and initiates an object and returns its reference
    static const Railways& Railway(string name = "IndianRailways");   

    //returns the prior known distance between the two stations 
    double GetDistance(const Station& s1, const Station& s2) const;

    //Overloaded operator to print the Railways name (ie Indian Railways), the list of Stations, and the distance between every pair of Stations 
    friend ostream& operator<<(ostream& os, const Railways& r);

    //For Unit Testing
    static void UnitTest();
};

#endif