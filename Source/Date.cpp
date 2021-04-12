//Abhilash Datta 19CS30001

#include "Date.h"
#include "Exceptions.h"

Date::Date(unsigned int d , unsigned int m , unsigned int y ) : date_(d), month_(m), year_(y) {}

Date::~Date() {}

int Date::getDay(){ return this->date_; }
int Date::getMonth(){ return this->month_; }
int Date::getYear(){ return this->year_; }
        
bool Date::ValidDate(){		//checks whether the constructed date is valid or not 
    try{
        if(this->year_ >= 1900 && this->year_ <= 2099){
            if(this->month_<=12 && this->month_>=1){
                if(this->month_==1 || this->month_==3 || this->month_==5 || this->month_==7 || this->month_==8 || this->month_==10 || this->month_==12){
                    if(!(this->date_>=1 && this->date_<=31)) throw Bad_Date{};
                }
                else{
                    if(this->month_!=2){
                        if(!(this->date_>=1 && this->date_<=30)) throw Bad_Date{};
                    }
                    else if(this->year_%4==0){
                        if(!(this->date_>=1 && this->date_<=29)) throw Bad_Date{};
                    }
                    else if(!(this->date_>=1 && this->date_<=28)) throw Bad_Date{};
                }
            }
            else throw Bad_Date{};
        }
        else throw Bad_Date{};
    }
    catch(Bad_Date& e){
        cout << e.what() <<endl;
        return false;
    }
    return true;
}

int Date::ComputeAge(const Date& other){
	int y = (other.year_ - this->year_)>=0?(other.year_ - this->year_):(this->year_ - other.year_);
    if(other.year_ >= this->year_ && other.month_ >= this->month_) return abs(y);
    else if(other.year_ >= this->year_ && other.month_ < this->month_) return abs(y-1);
    else if(other.year_ <= this->year_ && other.month_ <= this->month_ ) return abs(y);
    else if(other.year_ <= this->year_ && other.month_ > this->month_) return abs(y-1);
    return y;
}

ostream& operator<<(ostream& os, const Date& d){
    os<< d.date_ << "/" << d.month_ << "/" << d.year_;
    return os;
}

bool Date::operator==(const Date& other){
    return date_==other.date_ && month_==other.month_ && year_==other.year_;
}

void Date::UnitTest(){
    cout<<"\n+++ Testing Construction and Validity+++\n";
    Date d(28,2,2001);
    if(d.ValidDate()) cout<<"Valid Date\n";
    cout<<"Address of Constructed Object: "<<&d<<endl;
    cout<<"+++ Testing operator << +++\n"<<d<<endl;
    Date d1 = Date(29,01,2001),d2 = Date(7,03,2021);
    if(d1.getDay()!=29 || d1.getMonth()!=01 || d1.getYear()!=2001)
        cout<<"Date: Error during construction of 29/Jan/2001"<<endl;
    if(d2.getDay()!=7 || d2.getMonth()!=03 || d2.getYear()!=2021)
        cout<<"Date: Error during construction of 7/Mar/2021"<<endl;
    Date d3 = Date(d1);
    if(d3.getDay()!=29 || d3.getMonth()!=01 || d3.getYear()!=2001)
        cout<<"Date: Error in copy constructor"<<endl;
    if(d1==d2 || !(d1==d3))  
        cout<<"Date: Error in comparison"<<endl;
    if(d1.ComputeAge(d2)!=20) cout<<"Error in age computation.\n";
    return;
}

// int main(){
//     Date::UnitTest();
// }