//Abhilash Datta 19CS30001

#include "BookingCategory.h"
#include "Categories.h"

BookingCategory::BookingCategory() {}

BookingCategory::~BookingCategory() {}

//Unit test for BookingCategory class and its inherited classes
void BookingCategory::UnitTest(){
    //Test for singleton
    const BookingCategory& b1 = General::Type();
    const BookingCategory& b2 = General::Type();
    if(&b1 != &b2) cout<<"Not a single-ton";

    const BookingCategory& b3 = Tatkal::Type();
    const BookingCategory& b4 = Tatkal::Type();
    if(&b3 != &b4) cout<<"Not a single-ton";

    const BookingCategory& b5 = PremiumTatkal::Type();
    const BookingCategory& b6 = PremiumTatkal::Type();
    if(&b5 != &b6) cout<<"Not a single-ton";

    const BookingCategory& b7 = SeniorCitizen::Type();
    const BookingCategory& b8 = SeniorCitizen::Type();
    if(&b7 != &b8) cout<<"Not a single-ton";

    const BookingCategory& b9 = Blind::Type();
    const BookingCategory& b10 = Blind::Type();
    if(&b9 != &b10) cout<<"Not a single-ton";

    const BookingCategory& b11 = OH::Type();
    const BookingCategory& b12 = OH::Type();
    if(&b11 != &b12) cout<<"Not a single-ton";

    const BookingCategory& b13 = TB::Type();
    const BookingCategory& b14 = TB::Type();
    if(&b13 != &b14) cout<<"Not a single-ton";

    const BookingCategory& b15 = Cancer::Type();
    const BookingCategory& b16 = Cancer::Type();
    if(&b15 != &b16) cout<<"Not a single-ton";
    cout<<"If nothing prints, it has no error.\n";
}
