//Abhilash Datta 19CS30001

#include "Station.h"

Station::Station(string name): name_(name) {}

Station::~Station() {}

string Station::GetName() const{
    return this->name_;
}

double Station::GetDistance(const Station& other) const{
    if(this->name_=="Mumbai"){
        if(other.name_=="Delhi") return 1447;
        if(other.name_=="Bangalore") return 981;
        if(other.name_=="Kolkata") return 2014;
        if(other.name_=="Chennai") return 1338;
    }
    if(this->name_=="Delhi"){
        if(other.name_=="Mumbai") return 1447;
        if(other.name_=="Bangalore") return 2150;
        if(other.name_=="Kolkata") return 1471;
        if(other.name_=="Chennai") return 2190;
    }
    if(this->name_=="Bangalore"){
        if(other.name_=="Mumbai") return 981;
        if(other.name_=="Delhi") return 2150;
        if(other.name_=="Kolkata") return 1871;
        if(other.name_=="Chennai") return 350;
    }
    if(this->name_=="Kolkata"){
        if(other.name_=="Mumbai") return 2014;
        if(other.name_=="Delhi") return 1471;
        if(other.name_=="Bangalore") return 1871;
        if(other.name_=="Chennai") return 1659;
    }
    if(this->name_=="Chennai"){
        if(other.name_=="Mumbai") return 1338;
        if(other.name_=="Delhi") return 2180;
        if(other.name_=="Bangalore") return 350;
        if(other.name_=="Kolkata") return 1659;
    }
    return -1;
}

bool Station::operator==(const Station& s) const{
    return this->name_== s.name_;
}

ostream& operator<<(ostream& os, const Station& s){
    os<<s.GetName();
    return os;
}

void Station::UnitTest(){
    cout<<"\n+++ Testing Construction +++\n";
    Station s("Kolkata");
    cout<<"Address of Constructed Object: "<<&s<<endl;
    cout<<"+++ Testing GetName() Method +++\nName: "<<s.GetName()<<endl;
    
    if(s.GetName()!="Kolkata"){ cout<<"Error on GetName Method\n"; }
    
    Station other("Mumbai");
    cout<<"+++ Testing operator << +++\n"<<s<<" "<<other<<endl;
    cout<<"+++ Testing GetDistance() Method +++\nDistance= "<<s.GetDistance(other)<<endl;

    if(s.GetDistance(other)!= 2014){ cout<<"Error on GetDistance Method\n"; }

    Station x("Chennai");
    cout<<"Distance between Chennai and Kolkata = "<<s.GetDistance(x)<<endl;

    if(s.GetDistance(x)!= 1659){ cout<<"Error on GetDistance Method\n"; }

    return;
}
