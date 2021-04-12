//Abhilash Datta 19CS30001
//Application Testing

#include<iostream>
#include "Station.h"
#include "Railways.h"
#include "Date.h"
#include "Gender.h"
#include "Passenger.h"
#include "BookingClasses.h"
#include "BookingCategory.h"
#include "Booking.h"
#include "Categories.h"
#include "Exceptions.h"

using namespace std;

void CreateBooking(Station s1, Station s2, Date dob, Date dor, const BookingClass& bookingClass,string bookingCategory, Passenger *p){
    try{
        if(Railways::Railway().GetDistance(s1,s2)==-1) return;
        if(!dob.ValidDate() || !dor.ValidDate() || !p->GetDateOfBirth().ValidDate()) return;
        if(p->ValidatePassenger()==false) return;
        if(dob==dor || (dob.getYear()<dor.getYear()) || ((dob.getYear()==dor.getYear())&&(dob.getMonth()<dor.getMonth())) || ((dob.getYear()==dor.getYear())&&(dob.getMonth()==dor.getMonth())&&(dob.getDay()<dor.getDay()))) throw Date_Of_Booking_Error{};
        else if((dob.getYear()-dor.getYear())*365+(dob.getMonth()-dor.getMonth())*30+(dob.getDay()-dor.getDay()>365)) throw Date_Of_Booking_Error{}; 

        if(bookingCategory=="General" || bookingCategory=="Ladies"){
            cout<<GeneralBooking(s1,s2,dob,dor,bookingClass,General::Type(),p)<<endl;
        }
        else if(bookingCategory=="Senior Citizen"){
            int flag = 0;
            string g = p->GetGender();
            if(dor.ComputeAge(p->GetDateOfBirth())>60 && g=="Male"){
                flag = 1;
            }
            else if(dor.ComputeAge(p->GetDateOfBirth())>58 && g=="Female"){
                flag = 2;
            }
            else throw Senior_Citizen_Error{};

            cout<<SeniorCitizenBooking(s1,s2,dob,dor,bookingClass,SeniorCitizen::Type(),p)<<endl;
        }
        else if(bookingCategory=="Tatkal"){
            if(dob.getDay() - dor.getDay()!=1 && dob.getMonth()==dor.getMonth() && dor.getYear()==dob.getYear()) throw Tatkal_Error{};
            cout<<TatkalBooking(s1,s2,dob,dor,bookingClass,Tatkal::Type(),p)<<endl;
        }
        else if(bookingCategory=="Premium Tatkal"){
            if(dob.getDay() - dor.getDay()!=1 && dob.getMonth()==dor.getMonth() && dor.getYear()==dob.getYear()) throw Tatkal_Error{};
            cout<<PremiumTatkalBooking(s1,s2,dob,dor,bookingClass,PremiumTatkal::Type(),p)<<endl;
        }
        else if(bookingCategory=="Divyaang"){
            if(p->GetDisabilityType()=="Blind"){
                cout<<BlindBooking(s1,s2,dob,dor,bookingClass,Blind::Type(),p)<<endl;
            }
            else if(p->GetDisabilityType()=="Orthopaedically Handicapped"){
                cout<<OHBooking(s1,s2,dob,dor,bookingClass,OH::Type(),p)<<endl;
            }
            else if(p->GetDisabilityType()=="Cancer"){
                cout<<CancerBooking(s1,s2,dob,dor,bookingClass,Cancer::Type(),p)<<endl;
            }
            else if(p->GetDisabilityType()=="TB"){
                cout<<TBBooking(s1,s2,dob,dor,bookingClass,TB::Type(),p)<<endl;
            }
            else throw Divyaang_Error{};
        }
    }
    catch (Bad_Date &e){
        cout << e.what() <<endl;
        return;
    }
    catch (Bad_Railways &e){
        cout << e.what() <<endl;
        return;
    }
    catch (Bad_Passenger &e){
        cout << e.what() <<endl;
        return;
    }
    catch (Bad_Booking &e){
        cout << e.what() <<endl;
        return;
    }
    return;
}

int main(){
    // TEST CASE 1
    //-
    Station s1("Mumbai"), s2("Delhi");
    Passenger p1("385829462922",Date(30,02,2001),Gender::Female::Type(),"Abhilash");
    CreateBooking(s1,s2,Date(2,5,2021),Date(1,5,2021),BookingClass::ACFirstClass::Type(),"General",&p1);
    cout<<endl;
    //+
    Passenger p2("385829462922",Date(3,02,2001),Gender::Female::Type(),"Abhilash");    
    CreateBooking(s1,s2,Date(2,5,2021),Date(1,5,2021),BookingClass::ACFirstClass::Type(),"General",&p2);
    cout<<endl;

    // TEST CASE 2
    //-
    Station s3("Mmbi"), s4("Delhi");
    Passenger p3("385829462922",Date(2,02,1951),Gender::Female::Type(),"Abhilash");
    CreateBooking(s3,s4,Date(2,5,2021),Date(1,5,2021),BookingClass::AC2Tier::Type(),"Senior Citizen",&p3);
    cout<<endl;
    //+
    Station s5("Mumbai"); 
    CreateBooking(s5,s4,Date(2,5,2021),Date(1,5,2021),BookingClass::AC2Tier::Type(),"Senior Citizen",&p3);
    cout<<endl;

    // TEST CASE 3
    //-
    Passenger p4("385829462922",Date(2,02,1951),Gender::Female::Type(),"");
    CreateBooking(s1,s2,Date(2,5,2021),Date(1,5,2021),BookingClass::ExecutiveChairCar::Type(),"Ladies",&p4);
    cout<<endl;
    //+
    CreateBooking(s1,s2,Date(2,5,2021),Date(1,5,2021),BookingClass::ExecutiveChairCar::Type(),"Ladies",&p3);
    cout<<endl;

    // TEST CASE 4
    //-
    Passenger p5("85829462922",Date(2,02,1951),Gender::Female::Type(),"Abhilash");
    CreateBooking(s1,s2,Date(2,5,2021),Date(1,5,2021),BookingClass::Sleeper::Type(),"Ladies",&p5);
    cout<<endl;
    //+
    CreateBooking(s1,s2,Date(2,5,2021),Date(1,5,2021),BookingClass::Sleeper::Type(),"Ladies",&p3);
    cout<<endl;

    // TEST CASE 5
    //-
    Passenger p6("385829462922",Date(2,02,1951),Gender::Female::Type(),"Abhilash","","","760204511");
    CreateBooking(s1,s2,Date(2,5,2021),Date(1,5,2021),BookingClass::ACFirstClass::Type(),"Ladies",&p6);
    cout<<endl;
    //+
    CreateBooking(s1,s2,Date(2,5,2021),Date(1,5,2021),BookingClass::ACFirstClass::Type(),"Ladies",&p3);
    cout<<endl;

    // TEST CASE 6
    //-
    CreateBooking(s1,s2,Date(1,5,2021),Date(2,5,2021),BookingClass::AC2Tier::Type(),"Ladies",&p2);
    cout<<endl;
    //+
    CreateBooking(s1,s2,Date(2,5,2021),Date(1,5,2021),BookingClass::AC2Tier::Type(),"Ladies",&p2);
    cout<<endl;

    // TEST CASE 7
    //-
    Passenger p7("385829462922",Date(2,02,2001),Gender::Male::Type(),"Abhilash");
    CreateBooking(s1,s2,Date(2,5,2021),Date(1,5,2021),BookingClass::ACChairCar::Type(),"Senior Citizen",&p7);
    cout<<endl;
    //+
    Passenger p8("385829462922",Date(2,02,1951),Gender::Male::Type(),"Abhilash");
    CreateBooking(s1,s2,Date(2,5,2021),Date(1,5,2021),BookingClass::ACChairCar::Type(),"Senior Citizen",&p8);
    cout<<endl;

    // TEST CASE 8
    //-
    Passenger p9("385829462922",Date(2,02,2001),Gender::Male::Type(),"Abhilash");
    CreateBooking(s1,s2,Date(2,5,2021),Date(1,5,2021),BookingClass::SecondSitting::Type(),"Divyaang",&p9);
    cout<<endl;
    //+
    Passenger p10("385829462922",Date(2,02,1951),Gender::Male::Type(),"Abhilash","","","","TB","123");
    CreateBooking(s1,s2,Date(2,5,2021),Date(1,5,2021),BookingClass::SecondSitting::Type(),"Divyaang",&p10);
    cout<<endl;

    // TEST CASE 9
    //-
    Passenger p11("385829462922",Date(2,02,2001),Gender::Male::Type(),"Abhilash");
    CreateBooking(s1,s2,Date(3,5,2021),Date(1,5,2021),BookingClass::AC2Tier::Type(),"Tatkal",&p11);
    cout<<endl;
    //+
    Passenger p12("385829462922",Date(2,02,1951),Gender::Male::Type(),"Abhilash","","","","TB","123");
    CreateBooking(s1,s2,Date(2,5,2021),Date(1,5,2021),BookingClass::AC2Tier::Type(),"Tatkal",&p12);
    cout<<endl;

    //All Test Cases over
}