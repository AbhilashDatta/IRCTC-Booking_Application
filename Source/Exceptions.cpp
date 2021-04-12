#include"Exceptions.h"

inline char const * Exceptions::what() const noexcept{ 
    return "Unknown Error"; 
}

inline char const * Bad_Date::what() const noexcept{ 
    return "Bad Date"; 
}

inline char const * Bad_Passenger::what() const noexcept{ 
    return "Bad_Passenger"; 
}

inline char const * Bad_Booking::what() const noexcept{ 
    return "Bad_Booking"; 
}

inline char const * Bad_Railways::what() const noexcept{ 
    return "Bad_Railways"; 
}

inline char const * Bad_Stations::what() const noexcept{ 
    return "Same To and From station"; 
}

inline char const * Name_Error::what() const noexcept{ 
    return "Bad_Name"; 
}

inline char const * Age_Error::what() const noexcept{ 
    return "Bad_Age"; 
}

inline char const * Aadhar_Error::what() const noexcept{ 
    return "Bad_Aadhar"; 
}

inline char const * Mobile_Error::what() const noexcept{ 
    return "Bad_Mobile"; 
}

inline char const * Date_Of_Booking_Error::what() const noexcept{ 
    return "Bad Date of Booking"; 
}

inline char const * Ladies_Error::what() const noexcept{ 
    return "Bad_Ladies"; 
}

inline char const * Senior_Citizen_Error::what() const noexcept{ 
    return "Bad_Senior_Citizen"; 
}

inline char const * Divyaang_Error::what() const noexcept{ 
    return "Bad_Divyaang"; 
}

inline char const * Tatkal_Error::what() const noexcept{ 
    return "Bad_Tatkaal"; 
}

//Unit Testing of the Exception hierarchy
void Exceptions::UnitTest(){
    cout<<"+++ Throwing all kinds of possible exceptions\n";
    
    try{
        throw Bad_Date{};
    }
    catch( Bad_Date& e){
        cout<<e.what()<<endl;
    }
    try{
        throw Bad_Passenger{};
    }
    catch( Bad_Passenger& e){
        cout<<e.what()<<endl;
    }
    try{
        throw Bad_Booking{};
    }
    catch( Bad_Booking& e){
        cout<<e.what()<<endl;
    }
    try{
        throw Bad_Railways{};
    }
    catch( Bad_Railways& e){
        cout<<e.what()<<endl;
    }
    try{
        throw Bad_Stations{};
    }
    catch( Bad_Stations& e){
        cout<<e.what()<<endl;
    }
    try{
        throw Name_Error{};
    }
    catch( Name_Error& e){
        cout<<e.what()<<endl;
    }
    try{
        throw Age_Error{};
    }
    catch( Age_Error& e){
        cout<<e.what()<<endl;
    }
    try{
        throw Aadhar_Error{};
    }
    catch( Aadhar_Error& e){
        cout<<e.what()<<endl;
    }
    try{
        throw Mobile_Error{};
    }
    catch( Mobile_Error& e){
        cout<<e.what()<<endl;
    }
    try{
        throw Date_Of_Booking_Error{};
    }
    catch( Date_Of_Booking_Error& e){
        cout<<e.what()<<endl;
    }
    try{
        throw Ladies_Error{};
    }
    catch( Ladies_Error& e){
        cout<<e.what()<<endl;
    }
    try{
        throw Senior_Citizen_Error{};
    }
    catch( Senior_Citizen_Error& e){
        cout<<e.what()<<endl;
    }
    try{
        throw Divyaang_Error{};
    }
    catch( Divyaang_Error& e){
        cout<<e.what()<<endl;
    }
    try{
        throw Tatkal_Error{};
    }
    catch( Tatkal_Error& e){
        cout<<e.what()<<endl;
    }
    return;
}
