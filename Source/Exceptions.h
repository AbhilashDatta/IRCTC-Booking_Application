#ifndef EXCEPTIONS_H
#define EXCEPIONS_H

#include <iostream>
#include <exception>
using namespace std;


class Exceptions : public exception {

public:

    virtual const char* what() const noexcept;

    static void UnitTest();

};

class Bad_Date : public Exceptions{

public:
  
    const char* what() const noexcept;

};

class Bad_Passenger : public Exceptions{

public:

    virtual const char* what() const noexcept;

};

class Bad_Booking : public Exceptions{

public:

    virtual const char* what() const noexcept;

};

class Bad_Railways : public Exceptions{

public:

    virtual const char* what() const noexcept;

};

class Bad_Stations : public Bad_Railways{

public:

    virtual const char* what() const noexcept;

};

class Name_Error : public Bad_Passenger{

public:

    virtual const char* what() const noexcept;

};

class Age_Error : public Bad_Passenger{

public:

    virtual const char* what() const noexcept;

};

class Aadhar_Error : public Bad_Passenger{

public:

    virtual const char* what() const noexcept;

};

class Mobile_Error : public Bad_Passenger{

public:

    virtual const char* what() const noexcept;

};

class Date_Of_Booking_Error : public Bad_Booking{

public:

    virtual const char* what() const noexcept;

};

class Ladies_Error : public Bad_Booking{

public:

    virtual const char* what() const noexcept;

};

class Senior_Citizen_Error : public Bad_Booking{

public:

    virtual const char* what() const noexcept;

};

class Divyaang_Error : public Bad_Booking{

public:

    virtual const char* what() const noexcept;

};

class Tatkal_Error : public Bad_Booking{

public:

    virtual const char* what() const noexcept;

};


#endif