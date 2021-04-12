//Abhilash Datta 19CS30001

#include "MyHashFunction.h"

size_t MyHashFunction::operator()(const pair<Station,Station>& p) const{ 
    return p.first.GetName().length()*3 + p.second.GetName().length(); 
} 