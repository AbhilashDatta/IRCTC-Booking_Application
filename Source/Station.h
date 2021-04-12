//Abhilash Datta 19CS30001

#ifndef STATION_H
#define STATION_H

#include<iostream>
#include<string>
using namespace std;

class Station{
protected:
    string name_;

public:
    Station(string name = "");
    
    ~Station();

    string GetName() const;

    double GetDistance(const Station& other) const;

    bool operator==(const Station& s) const;

    friend ostream& operator<<(ostream& os, const Station& s);

    static void UnitTest();
};

#endif