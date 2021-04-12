//Abhilash Datta 19CS30001

#include "Booking.h"
#include "BookingClasses.h"
#include "Passenger.h"
#include "Station.h"
#include "BookingCategory.h"
#include "Categories.h"
#include <algorithm>


Booking::Booking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass, const BookingCategory& bookingCategory,Passenger* p): bookingClass_(bookingClass), bookingCategory_(bookingCategory) {
    this->fromStation_ = fromStation;
    this->toStation_ = toStation;
    this->dateOfBooking_ = dateOfBooking;
    this->dateOfReservation_ = dateOfReservation;
    this->p_ = p;
    this->bookingStatus_ = true;
    this->bookingMessage_ = "BOOKING SUCCEEDED";
    this->PNR_ = this->sBookingPNRSerial;
    //this->fare_ = this->ComputeFare();
    AddBooking(this);
}

Booking::~Booking() {}

void Booking::AddBooking(Booking *a) {
    this->sBookings.push_back(a);
    this->sBookingPNRSerial++;
}

int Booking::GetPNR(){
    return this->PNR_;
}

ostream& operator<<(ostream& os, const Booking& b){
    os<<b.bookingMessage_<<":"<<endl;
    os<<"PNR Number = "<<b.PNR_<<endl;
    os<<"From Station = "<<b.fromStation_<<endl;
    os<<"To Station = "<<b.toStation_<<endl;
    os<<"Reservation Date = "<<b.dateOfReservation_<<endl;
    os<<"Travel Date = "<<b.dateOfBooking_<<endl;
    os<<"Travel Class = "<<b.bookingClass_;
    os<<"Fare = "<<b.fare_<<endl;
    return os;
}

//STATIC INITIALIZATION
double Booking::sBaseFarePerKM = 0.5;
vector<Booking*> Booking::sBookings = {};
int Booking::sBookingPNRSerial = 1;


GeneralBooking::GeneralBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass, const BookingCategory& bookingCategory,Passenger* p): Booking( fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory,p) {
    this->fare_ = this->ComputeFare();
}

GeneralBooking::~GeneralBooking(){}

double GeneralBooking::ComputeFare(){
    double dist = Railways::Railway().GetDistance(this->fromStation_, this->toStation_);
    double bFare = dist*Booking::sBaseFarePerKM;
    double lFare = bFare * this->bookingClass_.GetLoadFactor();
    double fFare = lFare + this->bookingClass_.GetReservationCharge(); 
    return round(fFare);
}

PriorityBooking::PriorityBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass, const BookingCategory& bookingCategory,Passenger* p): Booking( fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory,p) {}

PriorityBooking::~PriorityBooking(){}

ConcessionalBooking::ConcessionalBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass, const BookingCategory& bookingCategory,Passenger* p): Booking( fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory,p) {}

ConcessionalBooking::~ConcessionalBooking(){}

TatkalBooking::TatkalBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass, const BookingCategory& bookingCategory,Passenger* p): PriorityBooking( fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory,p) {
    this->fare_ = this->ComputeFare();
}

TatkalBooking::~TatkalBooking(){}

double TatkalBooking::ComputeFare(){
    double dist = Railways::Railway().GetDistance(this->fromStation_, this->toStation_);
    double bFare = dist*Booking::sBaseFarePerKM;
    double lFare = bFare * this->bookingClass_.GetLoadFactor();
    
    if(dist<this->bookingClass_.GetMinTatkalDistance()){
        lFare = bFare * this->bookingClass_.GetLoadFactor();
    }
    else{
        double tcharge = this->bookingClass_.GetTatkalLoadFactor()*lFare;

        if(tcharge < this->bookingClass_.GetMinTatkalCharge()){
            tcharge = this->bookingClass_.GetMinTatkalCharge();
        }
        else if(tcharge > this->bookingClass_.GetMaxTatkalCharge()){
            tcharge = this->bookingClass_.GetMaxTatkalCharge();
        }  
        lFare += tcharge;
    }
    double fFare = lFare + this->bookingClass_.GetReservationCharge(); 
    return round(fFare);
}

PremiumTatkalBooking::PremiumTatkalBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass, const BookingCategory& bookingCategory,Passenger* p): PriorityBooking( fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory,p) {
    this->fare_ = this->ComputeFare();
}

PremiumTatkalBooking::~PremiumTatkalBooking(){}

double PremiumTatkalBooking::ComputeFare(){
    double dist = Railways::Railway().GetDistance(this->fromStation_, this->toStation_);
    double bFare = dist*Booking::sBaseFarePerKM;
    double lFare = bFare * this->bookingClass_.GetLoadFactor();
    
    if(dist<this->bookingClass_.GetMinTatkalDistance()){
        lFare = bFare * this->bookingClass_.GetLoadFactor();
    }
    else{
        double tcharge = this->bookingClass_.GetTatkalLoadFactor()*lFare;

        if(tcharge < this->bookingClass_.GetMinTatkalCharge()){
            tcharge = this->bookingClass_.GetMinTatkalCharge();
        }
        else if(tcharge > this->bookingClass_.GetMaxTatkalCharge()){
            tcharge = this->bookingClass_.GetMaxTatkalCharge();
        }  
        lFare += 2*tcharge;
    }
    double fFare = lFare + this->bookingClass_.GetReservationCharge(); 
    return round(fFare);
}

DivyaangBooking::DivyaangBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass, const BookingCategory& bookingCategory,Passenger* p): ConcessionalBooking( fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory,p) {}

DivyaangBooking::~DivyaangBooking(){}

SeniorCitizenBooking::SeniorCitizenBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass, const BookingCategory& bookingCategory,Passenger* p): ConcessionalBooking( fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory,p) {
    this->fare_ = this->ComputeFare();
}

SeniorCitizenBooking::~SeniorCitizenBooking(){}

double SeniorCitizenBooking::ComputeFare(){
    double dist = Railways::Railway().GetDistance(this->fromStation_, this->toStation_);
    double bFare = dist*Booking::sBaseFarePerKM;
    // cout<<bFare<<endl;
    double lFare = bFare * this->bookingClass_.GetLoadFactor();
    // cout<<lFare<<endl;
    this->concessionFactor_ = 0;
    string g = this->p_->GetGender();
    transform(g.begin(),g.end(),g.begin(), ::toupper);
    if(this->dateOfReservation_.ComputeAge(this->p_->GetDateOfBirth())>60 && g=="MALE"){
        this->concessionFactor_ = 0.4;
    }
    else if(this->dateOfReservation_.ComputeAge(this->p_->GetDateOfBirth())>58 && g=="FEMALE"){
        this->concessionFactor_ = 0.5;
    }
    
    lFare = lFare - this->concessionFactor_*lFare;
    // cout<<lFare<<endl;
    double fFare = lFare + this->bookingClass_.GetReservationCharge(); 
    return round(fFare);
}

BlindBooking::BlindBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass, const BookingCategory& bookingCategory,Passenger* p): DivyaangBooking( fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory,p) {
    this->fare_ = this->ComputeFare();
}

BlindBooking::~BlindBooking(){}

double BlindBooking::ComputeFare(){
    double dist = Railways::Railway().GetDistance(this->fromStation_, this->toStation_);
    double bFare = dist*Booking::sBaseFarePerKM;
    double lFare = bFare * this->bookingClass_.GetLoadFactor();
    
    if(&(this->bookingClass_) == &(BookingClass::ACFirstClass::Type())){
        this->concessionFactor_ = 0.5;
    }
    if(&(this->bookingClass_) == &(BookingClass::ExecutiveChairCar::Type())){
        this->concessionFactor_ = 0.75;
    }
    if(&(this->bookingClass_) == &(BookingClass::AC2Tier::Type())){
        this->concessionFactor_ = 0.75;
    }
    if(&(this->bookingClass_) == &(BookingClass::FirstClass::Type())){
        this->concessionFactor_ = 0.75;
    }
    if(&(this->bookingClass_) == &(BookingClass::AC3Tier::Type())){
        this->concessionFactor_ = 0.75;
    }
    if(&(this->bookingClass_) == &(BookingClass::ACChairCar::Type())){
        this->concessionFactor_ = 0.75;
    }
    if(&(this->bookingClass_) == &(BookingClass::Sleeper::Type())){
        this->concessionFactor_ = 0.75;
    }
    if(&(this->bookingClass_) == &(BookingClass::SecondSitting::Type())){
        this->concessionFactor_ = 0.75;
    }

    lFare = lFare - this->concessionFactor_*lFare;
    double fFare = lFare + this->bookingClass_.GetReservationCharge(); 
    return round(fFare);    
}

OHBooking::OHBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass, const BookingCategory& bookingCategory,Passenger* p): DivyaangBooking( fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory,p) {
    this->fare_ = this->ComputeFare();
}

OHBooking::~OHBooking(){}

double OHBooking::ComputeFare(){
    double dist = Railways::Railway().GetDistance(this->fromStation_, this->toStation_);
    double bFare = dist*Booking::sBaseFarePerKM;
    double lFare = bFare * this->bookingClass_.GetLoadFactor();
    
    if(&(this->bookingClass_) == &(BookingClass::ACFirstClass::Type())){
        this->concessionFactor_ = 0.5;
    }
    if(&(this->bookingClass_) == &(BookingClass::ExecutiveChairCar::Type())){
        this->concessionFactor_ = 0.75;
    }
    if(&(this->bookingClass_) == &(BookingClass::AC2Tier::Type())){
        this->concessionFactor_ = 0.75;
    }
    if(&(this->bookingClass_) == &(BookingClass::FirstClass::Type())){
        this->concessionFactor_ = 0.75;
    }
    if(&(this->bookingClass_) == &(BookingClass::AC3Tier::Type())){
        this->concessionFactor_ = 0.75;
    }
    if(&(this->bookingClass_) == &(BookingClass::ACChairCar::Type())){
        this->concessionFactor_ = 0.75;
    }
    if(&(this->bookingClass_) == &(BookingClass::Sleeper::Type())){
        this->concessionFactor_ = 0.75;
    }
    if(&(this->bookingClass_) == &(BookingClass::SecondSitting::Type())){
        this->concessionFactor_ = 0.75;
    }

    lFare = lFare - this->concessionFactor_*lFare;
    double fFare = lFare + this->bookingClass_.GetReservationCharge(); 
    return round(fFare);    
}

TBBooking::TBBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass, const BookingCategory& bookingCategory,Passenger* p): DivyaangBooking( fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory,p) {
    this->fare_ = this->ComputeFare();
}

TBBooking::~TBBooking(){}

double TBBooking::ComputeFare(){
    double dist = Railways::Railway().GetDistance(this->fromStation_, this->toStation_);
    double bFare = dist*Booking::sBaseFarePerKM;
    double lFare = bFare * this->bookingClass_.GetLoadFactor();
    
    if(&(this->bookingClass_) == &(BookingClass::ACFirstClass::Type())){
        this->concessionFactor_ = 0;
    }
    if(&(this->bookingClass_) == &(BookingClass::ExecutiveChairCar::Type())){
        this->concessionFactor_ = 0;
    }
    if(&(this->bookingClass_) == &(BookingClass::AC2Tier::Type())){
        this->concessionFactor_ = 0;
    }
    if(&(this->bookingClass_) == &(BookingClass::FirstClass::Type())){
        this->concessionFactor_ = 0.75;
    }
    if(&(this->bookingClass_) == &(BookingClass::AC3Tier::Type())){
        this->concessionFactor_ = 0;
    }
    if(&(this->bookingClass_) == &(BookingClass::ACChairCar::Type())){
        this->concessionFactor_ = 0;
    }
    if(&(this->bookingClass_) == &(BookingClass::Sleeper::Type())){
        this->concessionFactor_ = 0.75;
    }
    if(&(this->bookingClass_) == &(BookingClass::SecondSitting::Type())){
        this->concessionFactor_ = 0.75;
    }

    lFare = lFare - this->concessionFactor_*lFare;
    double fFare = lFare + this->bookingClass_.GetReservationCharge(); 
    return round(fFare);    
}

CancerBooking::CancerBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass, const BookingCategory& bookingCategory,Passenger* p): DivyaangBooking( fromStation, toStation, dateOfBooking, dateOfReservation, bookingClass, bookingCategory,p) {
    this->fare_ = this->ComputeFare();
}

CancerBooking::~CancerBooking(){}

double CancerBooking::ComputeFare(){
    double dist = Railways::Railway().GetDistance(this->fromStation_, this->toStation_);
    double bFare = dist*Booking::sBaseFarePerKM;
    double lFare = bFare * this->bookingClass_.GetLoadFactor();
    
    if(&(this->bookingClass_) == &(BookingClass::ACFirstClass::Type())){
        this->concessionFactor_ = 0.5;
    }
    if(&(this->bookingClass_) == &(BookingClass::ExecutiveChairCar::Type())){
        this->concessionFactor_ = 0.75;
    }
    if(&(this->bookingClass_) == &(BookingClass::AC2Tier::Type())){
        this->concessionFactor_ = 0.5;
    }
    if(&(this->bookingClass_) == &(BookingClass::FirstClass::Type())){
        this->concessionFactor_ = 0.75;
    }
    if(&(this->bookingClass_) == &(BookingClass::AC3Tier::Type())){
        this->concessionFactor_ = 1;
    }
    if(&(this->bookingClass_) == &(BookingClass::ACChairCar::Type())){
        this->concessionFactor_ = 1;
    }
    if(&(this->bookingClass_) == &(BookingClass::Sleeper::Type())){
        this->concessionFactor_ = 1;
    }
    if(&(this->bookingClass_) == &(BookingClass::SecondSitting::Type())){
        this->concessionFactor_ = 1;
    }

    lFare = lFare - this->concessionFactor_*lFare;
    double fFare = lFare + this->bookingClass_.GetReservationCharge(); 
    return round(fFare);    
}


//Unit Test of Booking Class and its hierarchy
//provided in booking application

// int main(){
//     Station s1("Mumbai"), s2("Delhi");
//     Passenger p("17r91g",Date(28,2,1955),"feMale","Abhilash");
//     TatkalBooking c1(s1,s2,Date(1,5,2021),Date(2,5,2021),BookingClass::AC3Tier::Type(),Tatkal::Type(),&p);
//     PremiumTatkalBooking c2(s2,s1,Date(1,5,2021),Date(2,5,2021),BookingClass::AC3Tier::Type(),PremiumTatkal::Type(),&p);
//     cout<<c1<<endl;
//     cout<<c2<<endl;
// }
