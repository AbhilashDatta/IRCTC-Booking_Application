//Abhilash Datta 19CS30001

#include "Passenger.h"
#include "Date.h"
#include "Gender.h"
#include "Exceptions.h"

Passenger::Passenger(const string& aadhar, const Date& dob, const Gender& gender, string firstName, string middleName, string lastName , const string& mobile, const string& disabilityType, const string& disabilityID): gender_(gender){
        this->aadhar_ = aadhar;
        //cout<<"OK"<<endl;
        this->dateOfBirth_ = dob;
        //this->gender_ = gender;
        this->firstName_ = firstName;
        this->middleName_ = middleName;
        this->lastName_ = lastName;
        //cout<<"OK2"<<endl;
        this->name_ = firstName+" "+middleName+" "+lastName;
        this->mobile_ = mobile;
        //cout<<"OK3"<<endl;
        this->disabilityID_ = disabilityID;
        this->disabilityType_ = disabilityType;    
}
    
Passenger::~Passenger(){ }

bool Passenger::ValidatePassenger(){
    try{
        if(this->aadhar_!="" && this->aadhar_.size()!=12) throw Aadhar_Error{};
        if(this->firstName_=="" && this->middleName_=="" && this->lastName_=="") throw Name_Error{};
        if(this->mobile_.size()!=10 && this->mobile_!="") throw Mobile_Error{};
    }
    catch (Bad_Passenger& e){
        cout << e.what() <<endl;
        return false;
    }
    return true;
}

ostream& operator<<(ostream& os, const Passenger& p){
    os<<p.gender_.GetTitle()<<" ";
    os<<p.name_<<endl;
    os<<" : Date of Birth: "<<p.dateOfBirth_<<endl;
    os<<" : Gender: "<<p.gender_.GetName()<<endl;
    os<<" : Aadhar: "<<p.aadhar_<<endl;
    if(p.mobile_!="") os<<" : Mobile: "<<p.mobile_<<endl;
    if(p.disabilityType_!="") os<<" : Disability Type: "<<p.disabilityType_<<endl;
    if(p.disabilityID_!="") os<<" : Disability ID: "<<p.disabilityID_<<endl;
    return os;
}

void Passenger::UnitTest(){
    Passenger p("d8d73g28h123",Date(28,2,2001),Gender::Male::Type(),"azad","hind","foug", "7602045111","Cancer","1ow1");
    if(p.ValidatePassenger()==true) cout<<p<<endl;
    
    //Wrong Passenger - this wont print
    Passenger p2("d8d73g28h12",Date(28,2,2001),Gender::Male::Type(),"Abd","","tg", "7602045111","Blind","1ow1");
    if(p2.ValidatePassenger()==true) cout<<p2<<endl;
}
