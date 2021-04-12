//Abhilash Datta 19CS30001

#include "BookingClasses.h"

BookingClass::BookingClass(const string& name): name_(name){}
BookingClass::~BookingClass(){}    

//static declarations
template<>
const string BookingClass::AC2Tier::sName = "AC2Tier";
template<>
const string BookingClass::AC3Tier::sName = "AC3Tier";
template<>
const string BookingClass::ACChairCar::sName = "ACChairCar";
template<>
const string BookingClass::ACFirstClass::sName = "ACFirstClass";
template<>
const string BookingClass::SecondSitting::sName = "SecondSitting";
template<>
const string BookingClass::Sleeper::sName = "Sleeper";
template<>
const string BookingClass::ExecutiveChairCar::sName = "ExecutiveChairCar";
template<>
const string BookingClass::FirstClass::sName = "FirstClass";

//setting parameters for booking classes
template<>
void BookingClass::AC2Tier::setParameters(){
    this->fareLoadFactor_ = 4.00;
    this->sitting_ = false;
    this->AC_ = true;
    this->numOfTiers_ = 2;
    this->luxury_ = false;
    this->reservationCharge_ = 50;
    this->minTatkalCharge_ = 400;
    this->maxTatkalCharge_ = 500;
    this->minTatkalDistance_ = 500;
    this->tatkalLoadFactor_ = 0.3;
}
template<>
void BookingClass::AC3Tier::setParameters(){
    this->fareLoadFactor_ = 2.50;
    this->sitting_ = false;
    this->AC_ = true;
    this->numOfTiers_ = 3;
    this->luxury_ = false;
    this->reservationCharge_ = 40;
    this->minTatkalCharge_ = 300;
    this->maxTatkalCharge_ = 400;
    this->minTatkalDistance_ = 500;
    this->tatkalLoadFactor_ = 0.3;
}
template<>
void BookingClass::ACChairCar::setParameters(){
    this->fareLoadFactor_ = 2.00;
    this->sitting_ = true;
    this->AC_ = true;
    this->numOfTiers_ = 0;
    this->luxury_ = false;
    this->reservationCharge_ = 40;
    this->minTatkalCharge_ = 125;
    this->maxTatkalCharge_ = 225;
    this->minTatkalDistance_ = 250;
    this->tatkalLoadFactor_ = 0.3;
}
template<>
void BookingClass::ACFirstClass::setParameters(){
    this->fareLoadFactor_ = 6.50;
    this->sitting_ = false;
    this->AC_ = true;
    this->numOfTiers_ = 2;
    this->luxury_ = true;
    this->reservationCharge_ = 60;
    this->minTatkalCharge_ = 400;
    this->maxTatkalCharge_ = 500;
    this->minTatkalDistance_ = 500;
    this->tatkalLoadFactor_ = 0.3;
}
template<>
void BookingClass::SecondSitting::setParameters(){
    this->fareLoadFactor_ = 0.60;
    this->sitting_ = true;
    this->AC_ = false;
    this->numOfTiers_ = 0;
    this->luxury_ = false;
    this->reservationCharge_ = 15;
    this->minTatkalCharge_ = 10;
    this->maxTatkalCharge_ = 15;
    this->minTatkalDistance_ = 100;
    this->tatkalLoadFactor_ = 0.1;
}
template<>
void BookingClass::Sleeper::setParameters(){
    this->fareLoadFactor_ = 1.00;
    this->sitting_ = false;
    this->AC_ = false;
    this->numOfTiers_ = 3;
    this->luxury_ = false;
    this->reservationCharge_ = 20;
    this->minTatkalCharge_ = 100;
    this->maxTatkalCharge_ = 200;
    this->minTatkalDistance_ = 500;
    this->tatkalLoadFactor_ = 0.3;
}
template<>
void BookingClass::ExecutiveChairCar::setParameters(){
    this->fareLoadFactor_ = 5.00;
    this->sitting_ = true;
    this->AC_ = true;
    this->numOfTiers_ = 0;
    this->luxury_ = true;
    this->reservationCharge_ = 60;
    this->minTatkalCharge_ = 400;
    this->maxTatkalCharge_ = 500;
    this->minTatkalDistance_ = 250;
    this->tatkalLoadFactor_ = 0.3;
}
template<>
void BookingClass::FirstClass::setParameters(){
    this->fareLoadFactor_ = 3.00;
    this->sitting_ = false;
    this->AC_ = false;
    this->numOfTiers_ = 2;
    this->luxury_ = true;
    this->reservationCharge_ = 50;
    this->minTatkalCharge_ = 400;
    this->maxTatkalCharge_ = 500;
    this->minTatkalDistance_ = 500;
    this->tatkalLoadFactor_ = 0.3;

}

//overloading << operator 
ostream& operator<<(ostream& os, const BookingClass& b){
    os<<b.GetName()<<endl;
    os<<" : Fare Load Factor: "<<b.fareLoadFactor_<<endl;
    if(b.IsSitting()) os<<" : Mode: Sitting\n";
    else os<<" : Mode: Sleeping\n";
    if(b.IsAC()) os<<" : Comfort: AC\n";
    else os<<" : Comfort: Non-AC\n";
    os<<" : Bunks: "<<b.GetNumberOfTiers()<<endl;
    if(b.IsLuxury()) os<<" : Luxury: Yes\n";
    else os<<" : Luxury: No\n";
    os<<" : Reservation Charge: "<<b.reservationCharge_<<endl;
    os<<" : Min Tatkal Charge : "<<b.minTatkalCharge_<<endl;
    os<<" : Max Tatkal Charge : "<<b.maxTatkalCharge_<<endl;
    os<<" : Min Tatkal Distance : "<<b.minTatkalDistance_<<endl;
    return os;
}

//Unit testing of Booking class and various booking classes
void BookingClass::UnitTest(){
    
    cout<<"\n+++ Testing operator << for every Booking Class +++\n"<<endl;
    const BookingClass& b1 = BookingClass::ACFirstClass::Type();
    cout<<b1<<endl;
    const BookingClass& b2 = BookingClass::AC2Tier::Type();
    cout<<b2<<endl;
    const BookingClass& b3 = BookingClass::AC3Tier::Type();
    cout<<b3<<endl;
    const BookingClass& b4 = BookingClass::ACChairCar::Type();
    cout<<b4<<endl;
    const BookingClass& b5 = BookingClass::ExecutiveChairCar::Type();
    cout<<b5<<endl;
    const BookingClass& b6 = BookingClass::FirstClass::Type();
    cout<<b6<<endl;
    const BookingClass& b7 = BookingClass::SecondSitting::Type();
    cout<<b7<<endl;
    const BookingClass& b8 = BookingClass::Sleeper::Type();
    cout<<b8<<endl;


    cout<<"Fare Loaded Factor of "<<b1.GetName()<<" from Virtual GetLoadFactor() Method = "<<b1.GetLoadFactor()<<endl;
    if(b1.GetLoadFactor()!=6.5) cout<<"Error in GetLoadFactor Method\n";

    cout<<"Fare Loaded Factor of "<<b2.GetName()<<" from Virtual GetLoadFactor() Method = "<<b2.GetLoadFactor()<<endl;
    if(b2.GetLoadFactor()!=4) cout<<"Error in GetLoadFactor Method\n";

    cout<<"Fare Loaded Factor of "<<b3.GetName()<<" from Virtual GetLoadFactor() Method = "<<b3.GetLoadFactor()<<endl;
    if(b3.GetLoadFactor()!=2.5) cout<<"Error in GetLoadFactor Method\n";

    cout<<"Fare Loaded Factor of "<<b4.GetName()<<" from Virtual GetLoadFactor() Method = "<<b4.GetLoadFactor()<<endl;
    if(b4.GetLoadFactor()!=2) cout<<"Error in GetLoadFactor Method\n";

    cout<<"Fare Loaded Factor of "<<b5.GetName()<<" from Virtual GetLoadFactor() Method = "<<b5.GetLoadFactor()<<endl;
    if(b5.GetLoadFactor()!=5) cout<<"Error in GetLoadFactor Method\n";

    cout<<"Fare Loaded Factor of "<<b6.GetName()<<" from Virtual GetLoadFactor() Method = "<<b6.GetLoadFactor()<<endl;
    if(b6.GetLoadFactor()!=3) cout<<"Error in GetLoadFactor Method\n";

    cout<<"Fare Loaded Factor of "<<b7.GetName()<<" from Virtual GetLoadFactor() Method = "<<b7.GetLoadFactor()<<endl;
    if(b7.GetLoadFactor()!=0.6) cout<<"Error in GetLoadFactor Method\n";

    cout<<"Fare Loaded Factor of "<<b8.GetName()<<" from Virtual GetLoadFactor() Method = "<<b8.GetLoadFactor()<<endl;
    if(b8.GetLoadFactor()!=1) cout<<"Error in GetLoadFactor Method\n";

    return;
}
