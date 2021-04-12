//Abhilash Datta 19CS30001

#ifndef MYHASHFUNCTION_H
#define MYHASHFUNCTION_H

#include<iostream>
#include "Station.h"
using namespace std;

//Functor of Hash for unordered map
class MyHashFunction { 
public:  
    size_t operator()(const pair<Station,Station>& p) const;
};

#endif