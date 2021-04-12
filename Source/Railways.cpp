//Abhilash Datta 19CS30001

#include "Railways.h"
#include "Exceptions.h"

Railways::Railways(string name): name_(name) {}
    
Railways::~Railways() {}

const Railways& Railways::Railway(string name){
    static Railways myRailway(name);
    return myRailway;
}

double Railways::GetDistance(const Station& s1, const Station& s2) const{
    try{
        if(s1==s2) throw Bad_Stations{};
        if(sDistStations[make_pair(s1,s2)]!=0) return sDistStations[make_pair(s1,s2)];
        else throw Bad_Date{};
    }
    catch(Bad_Stations& e){
        cout<<e.what()<<endl;
        return -1;
    }
    catch(...){
        cout<<"Bad_Stations\n";
        return -1;
    }
}

vector<Station> Railways::sStations = {Station("Mumbai"),Station("Delhi"),Station("Bangalore"),Station("Kolkata"),Station("Chennai")};

unordered_map<pair<Station,Station>,double,MyHashFunction> GetUMap(){
    unordered_map<pair<Station,Station>,double,MyHashFunction> temp;

    temp[make_pair(Station("Mumbai"),Station("Delhi"))] = 1447;
    temp[make_pair(Station("Delhi"),Station("Mumbai"))] = 1447;

    temp[make_pair(Station("Mumbai"),Station("Bangalore"))] = 981;
    temp[make_pair(Station("Bangalore"),Station("Mumbai"))] = 981;

    temp[make_pair(Station("Mumbai"),Station("Kolkata"))] = 2014;
    temp[make_pair(Station("Kolkata"),Station("Mumbai"))] = 2014;

    temp[make_pair(Station("Mumbai"),Station("Chennai"))] = 1338;
    temp[make_pair(Station("Chennai"),Station("Mumbai"))] = 1338;

    temp[make_pair(Station("Delhi"),Station("Bangalore"))] = 2150;
    temp[make_pair(Station("Bangalore"),Station("Delhi"))] = 2150;

    temp[make_pair(Station("Delhi"),Station("Kolkata"))] = 1472;
    temp[make_pair(Station("Kolkata"),Station("Delhi"))] = 1472;

    temp[make_pair(Station("Delhi"),Station("Chennai"))] = 2180;
    temp[make_pair(Station("Chennai"),Station("Delhi"))] = 2180;

    temp[make_pair(Station("Bangalore"),Station("Kolkata"))] = 1871;
    temp[make_pair(Station("Kolkata"),Station("Bangalore"))] = 1871;

    temp[make_pair(Station("Bangalore"),Station("Chennai"))] = 350;
    temp[make_pair(Station("Chennai"),Station("Bangalore"))] = 350;

    temp[make_pair(Station("Kolkata"),Station("Chennai"))] = 1659;
    temp[make_pair(Station("Chennai"),Station("Kolkata"))] = 1659;

    return temp;
}

ostream& operator<<(ostream& os, const Railways& r){
    os<<"Name: "<<r.name_<<endl;
    os<<"\nStations:\n";
    for(auto i:r.sStations) cout<<i.GetName()<<endl;
        os<<"\nDistances:\n";
    for(auto i:r.sDistStations ){
        os<<i.first.first.GetName()<<" to "<<i.first.second.GetName()<<": "<<i.second<<endl;
    }
    return os;
}

unordered_map<pair<Station,Station>,double,MyHashFunction> Railways::sDistStations = GetUMap();

void Railways::UnitTest(){
    cout<<"\n+++ Testing operator << +++\n"<<Railways::Railway()<<endl;
    Station s1("Mumbai"), s2("Delhi");
    cout<<"+++ Testing GetDistance() Method +++\nDistance between Mumbai and Delhi: "<<Railways::Railway().GetDistance(s1,s2)<<endl;
    
    if(Railways::Railway().GetDistance(s1,s2)!=1447){ cout<<"Error in GetDistance Method\n"; }
    
    Station s3("Kolkata"), s4("Chennai");

    if(Railways::Railway().GetDistance(s3,s4)!=1659){ cout<<"Error in GetDistance Method\n"; }

    return;
}