//Abhilash Datta 19CS30001

#ifndef BOOKING_H
#define BOOKING_H

#include "Station.h"
#include "Railways.h"
#include "Date.h"
#include "Passenger.h"
#include "BookingClasses.h"
#include "BookingCategory.h"
#include <vector>
#include <map>
#include <cmath>


//Abstract Base Class
class Booking{

protected:
    // HAS-A
    Station fromStation_;
    Station toStation_;
    Date dateOfBooking_;
    Date dateOfReservation_;
    const BookingCategory& bookingCategory_;
    const BookingClass& bookingClass_;
    Passenger* p_;

    int PNR_; //to store current PNR
    double fare_;
    bool bookingStatus_; //true
    string bookingMessage_; //BOOKING SUCCEEDED

    static double sBaseFarePerKM;
    static int sBookingPNRSerial;

    //ctor
    Booking( Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass, const BookingCategory& bookingCategory,Passenger* p);
    
    //virtual dtor
    virtual ~Booking();

public:
    //a static vector of type Booking pointer to store all bookings that took place
    static vector<Booking*> sBookings;

    //adds this to a static vector of all bookings
    void AddBooking(Booking* a);

    //computes the fare for travelling between the two stations using a particular Booking Class
    virtual double ComputeFare() = 0;

    //returns the current(assigned) value of PNR as type integer
    int GetPNR();

    //returns the fare
    double GetFare();

    //Overloaded operator to print the booking message, PNR, from & to Stations, travel date and class, and computed Fare 
    friend ostream& operator<<(ostream& os, const Booking& b);

    //Unit testing of booking means testing of Booking application
};

inline double Booking::GetFare(){ return this->fare_; }

class GeneralBooking: public Booking{

public:
    //default ctor
    GeneralBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass,const BookingCategory& bookingCategory,Passenger* p);

    //default dtor 
    ~GeneralBooking();

    //computing fare
    double ComputeFare();

};

class PriorityBooking: public Booking{

protected:
    //default ctor
    PriorityBooking( Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass, const BookingCategory& bookingCategory,Passenger* p);
    
    //default dtor 
    virtual ~PriorityBooking();

};

class TatkalBooking:public PriorityBooking{

public:
    //default ctor
    TatkalBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass,const BookingCategory& bookingCategory,Passenger* p);

    //default dtor 
    ~TatkalBooking();

    //computing fare
    double ComputeFare();

};

class PremiumTatkalBooking:public PriorityBooking{

public:
    //default ctor
    PremiumTatkalBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass,const BookingCategory& bookingCategory,Passenger* p);

    //default dtor 
    ~PremiumTatkalBooking();

    //computing fare
    double ComputeFare();

};

class ConcessionalBooking: public Booking{

protected:
    double concessionFactor_;

    //default ctor
    ConcessionalBooking( Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass, const BookingCategory& bookingCategory,Passenger* p);

    //default dtor 
    virtual ~ConcessionalBooking();

};

class SeniorCitizenBooking:public ConcessionalBooking{

public:
    //default ctor
    SeniorCitizenBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass,const BookingCategory& bookingCategory,Passenger* p);

    //default dtor 
    ~SeniorCitizenBooking();

    //computing fare
    double ComputeFare();

};

class DivyaangBooking: public ConcessionalBooking{

protected:
    //default ctor
    DivyaangBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass, const BookingCategory& bookingCategory,Passenger* p);

    //default dtor 
    virtual ~DivyaangBooking();

};

class BlindBooking: public DivyaangBooking{

public:
    //default ctor
    BlindBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass,const BookingCategory& bookingCategory,Passenger* p);

    //default dtor 
    ~BlindBooking();

    //computing fare
    double ComputeFare();

};

class OHBooking: public DivyaangBooking{

public:
    //default ctor
    OHBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass,const BookingCategory& bookingCategory,Passenger* p);

    //default dtor 
    ~OHBooking();

    //computing fare
    double ComputeFare();

};

class TBBooking: public DivyaangBooking{

public:
    //default ctor
    TBBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass,const BookingCategory& bookingCategory,Passenger* p);

    //default dtor 
    ~TBBooking();

    //computing fare
    double ComputeFare();

};

class CancerBooking: public DivyaangBooking{

public:
    //default ctor
    CancerBooking(Station fromStation, Station toStation, Date dateOfBooking, Date dateOfReservation,const BookingClass& bookingClass,const BookingCategory& bookingCategory,Passenger* p);

    //default dtor 
    ~CancerBooking();

    //computing fare
    double ComputeFare();

};

#endif