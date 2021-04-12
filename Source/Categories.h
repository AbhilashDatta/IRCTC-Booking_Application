#ifndef CATEGORIES_H
#define CATEGORIES_H

#include "BookingCategory.h"

class General : public BookingCategory{

protected:
    //default ctor
    General();

    //default dtor 
    ~General();

public:
    static General & Type() {
        static General theObject; 
        return theObject;
    }

};

class Priority : public BookingCategory{

protected:
    //default ctor
    Priority();

    //default dtor 
    virtual ~Priority();

};

class Tatkal :public Priority {

protected:
    //default ctor
    Tatkal();

    //default dtor 
    ~Tatkal();

public:
    static Tatkal & Type() {
        static Tatkal  theObject; 
        return theObject;
    }

};

class PremiumTatkal :public Priority {

protected:
    //default ctor
    PremiumTatkal();

    //default dtor 
    ~PremiumTatkal();

public:
    static PremiumTatkal & Type() {
        static PremiumTatkal  theObject; 
        return theObject;
    }

};

class Concessional : public BookingCategory{

protected:

    //default ctor
    Concessional();

    //default dtor 
    virtual ~Concessional();

};

class SeniorCitizen :public Concessional {

protected:
    //default ctor
    SeniorCitizen();

    //default dtor 
    ~SeniorCitizen();

public:
    static SeniorCitizen & Type() {
        static SeniorCitizen  theObject; 
        return theObject;
    }

};

class Divyaang : public Concessional {

protected:
    //default ctor
    Divyaang();

    //default dtor 
    virtual ~Divyaang();

};

class Blind : public Divyaang {

protected:
    //default ctor
    Blind();

    //default dtor 
    ~Blind();

public:
    static Blind& Type() {
        static Blind  theObject; 
        return theObject;
    }

};

class OH : public Divyaang {

protected:
    //default ctor
    OH();

    //default dtor 
    ~OH();

public:
    static OH& Type() {
        static OH  theObject; 
        return theObject;
    }

};

class TB : public Divyaang {

protected:
    //default ctor
    TB();

    //default dtor 
    ~TB();

public:
    static TB& Type() {
        static TB theObject; 
        return theObject;
    }

};

class Cancer : public Divyaang {

protected:
    //default ctor
    Cancer();

    //default dtor 
    ~Cancer();

public:
    static Cancer& Type() {
        static Cancer theObject; 
        return theObject;
    }
};

#endif