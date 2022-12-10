#include "fraction20mau.h"
#include <iostream>
#include <algorithm>
Fraction::Fraction(){
    fractionTop = 0;
    fractionBottom = 1;
}

Fraction::Fraction(int single){
    fractionTop = single;
    fractionBottom = 1;
}

Fraction::Fraction(int num, int denom){
    fractionTop = num;
    fractionBottom = denom;
    if (fractionBottom == 0) // check for devision by 0
        throw FractionException();

    if ((fractionTop < 0) ^ (fractionBottom < 0)){ // use or logic to check for negative fractions
        fractionTop = -1 * abs(fractionTop);
        fractionBottom = abs(fractionBottom);
    } else {
        fractionTop = abs(fractionTop);
        fractionBottom = abs(fractionBottom);
    }
    int greatestCommonDenom = std::__gcd(abs(fractionTop), abs(fractionBottom)); // used to simplify fractions
    fractionTop /= greatestCommonDenom;
    fractionBottom /= greatestCommonDenom;
}

Fraction Fraction::operator+(const Fraction& frac){
    int newNumerator, newDenomiator, lowestCommonMultiple, greatestCommonDenominator;
    greatestCommonDenominator = std::__gcd(fractionBottom, frac.fractionBottom);
    lowestCommonMultiple = abs(fractionBottom * frac.fractionBottom) / greatestCommonDenominator;

    newNumerator = (fractionTop * (lowestCommonMultiple / fractionBottom)) + (frac.fractionTop * (lowestCommonMultiple / frac.fractionBottom));
    newDenomiator = lowestCommonMultiple;

    return Fraction(newNumerator, newDenomiator);
}

Fraction Fraction::operator-(const Fraction& frac){
    int newNumerator, newDenomiator, lowestCommonMultiple, greatestCommonDenominator;
    greatestCommonDenominator = std::__gcd(fractionBottom, frac.fractionBottom);
    lowestCommonMultiple = abs(fractionBottom * frac.fractionBottom) / greatestCommonDenominator;

    newNumerator = (fractionTop * (lowestCommonMultiple / fractionBottom)) - (frac.fractionTop * (lowestCommonMultiple / frac.fractionBottom));
    newDenomiator = lowestCommonMultiple;

    return Fraction(newNumerator, newDenomiator);
}

Fraction Fraction::operator-(const int& sub){
    Fraction frac(sub, 1);
    int newNumerator, newDenomiator, lowestCommonMultiple, greatestCommonDenominator;
    greatestCommonDenominator = std::__gcd(fractionBottom, frac.fractionBottom);
    lowestCommonMultiple = abs(fractionBottom * frac.fractionBottom) / greatestCommonDenominator;

    newNumerator = (fractionTop * (lowestCommonMultiple / fractionBottom)) - (frac.fractionTop * (lowestCommonMultiple / frac.fractionBottom));
    newDenomiator = lowestCommonMultiple;

    return Fraction(newNumerator, newDenomiator);
}
    
Fraction Fraction::operator*(const Fraction& frac){
    return Fraction((fractionTop* frac.fractionTop), (fractionBottom * frac.fractionBottom));
}

Fraction Fraction::operator/(Fraction frac){
    int temp;
    temp = frac.fractionTop;
    frac.fractionTop = frac.fractionBottom;
    frac.fractionBottom = temp;
    return (*this * frac);
}

Fraction Fraction::operator++(){
    fractionTop += fractionBottom;
    return *this;
}

Fraction Fraction::operator++(int){
    Fraction temp(fractionTop, fractionBottom);
    ++*this;
    return temp;
}

void Fraction::operator+=(const Fraction& frac){
    Fraction temp = *this + frac;
    *this = temp;
}

bool Fraction::operator==(const Fraction& frac){
    if (fractionTop == 0 && frac.fractionTop == 0)
        return true;
    return (fractionTop == frac.fractionTop && fractionBottom == frac.fractionBottom);
}

bool Fraction::operator!=(const Fraction& frac){
    return !(*this == frac);
}

bool Fraction::operator!=(const int& num){
    Fraction frac(num, 1);
    return(*this != frac);
}

bool Fraction::operator>(Fraction& frac){ // can't be const because frac gets changed during the overload
    int lowestCommonMultiple, greatestCommonDenominator;
    greatestCommonDenominator = std::__gcd(fractionBottom, frac.fractionBottom);
    lowestCommonMultiple = abs(fractionBottom * frac.fractionBottom) / greatestCommonDenominator;
    fractionTop = (fractionTop * (lowestCommonMultiple / fractionBottom));
    frac.fractionTop = (frac.fractionTop * (lowestCommonMultiple / frac.fractionBottom));
    return fractionTop > frac.fractionTop;
}

bool Fraction::operator<(Fraction& frac){
    int lowestCommonMultiple, greatestCommonDenominator;
    greatestCommonDenominator = std::__gcd(fractionBottom, frac.fractionBottom);
    lowestCommonMultiple = abs(fractionBottom * frac.fractionBottom) / greatestCommonDenominator;
    fractionTop = (fractionTop * (lowestCommonMultiple / fractionBottom));
    frac.fractionTop = (frac.fractionTop * (lowestCommonMultiple / frac.fractionBottom));
    return fractionTop < frac.fractionTop;
}

bool Fraction::operator>(const int& num){
    Fraction temp(num, 1);
    return *this > temp;
}

bool Fraction::operator<(const int& num){
    Fraction temp(num, 1);
    return *this < temp;
}

bool Fraction::operator>=(Fraction& frac){
    int lowestCommonMultiple, greatestCommonDenominator;
    greatestCommonDenominator = std::__gcd(fractionBottom, frac.fractionBottom);
    lowestCommonMultiple = abs(fractionBottom * frac.fractionBottom) / greatestCommonDenominator;
    fractionTop = (fractionTop * (lowestCommonMultiple / fractionBottom));
    frac.fractionTop = (frac.fractionTop * (lowestCommonMultiple / frac.fractionBottom));
    return fractionTop >= frac.fractionTop;
}

bool Fraction::operator<=(Fraction& frac){
    int lowestCommonMultiple, greatestCommonDenominator;
    greatestCommonDenominator = std::__gcd(fractionBottom, frac.fractionBottom);
    lowestCommonMultiple = abs(fractionBottom * frac.fractionBottom) / greatestCommonDenominator;
    fractionTop = (fractionTop * (lowestCommonMultiple / fractionBottom));
    frac.fractionTop = (frac.fractionTop * (lowestCommonMultiple / frac.fractionBottom));
    return fractionTop <= frac.fractionTop;
}

bool operator>(const int& num, Fraction& frac){
    Fraction temp(num, 1);
    return temp > frac;
}

bool operator<(const int& num, Fraction frac){
    Fraction temp(num, 1);
    return temp < frac;
}

Fraction operator+(const int& add, const Fraction& frac){
    Fraction temp(add, 1);
    return (temp + frac);
}

Fraction operator-(const int& sub, Fraction frac){
    frac.fractionTop *= -1;
    Fraction newFrac(sub, 1);
    return (frac + newFrac);
}

Fraction operator-(Fraction& frac){
    frac.fractionTop *= -1;
    return frac;
}

std::ostream& operator<<(std::ostream& os, const Fraction& frac){
    os << frac.fractionTop << "/" << frac.fractionBottom;
    return os; 
}

/// @brief input must be in the format <int enter int>
/// @param is 
/// @param frac 
/// @return reference to istream object with input information
std::istream& operator>>(std::istream& is, Fraction& frac){
    is >> frac.fractionTop;
    is >> frac.fractionBottom;
    Fraction temp(frac.fractionTop, frac.fractionBottom); // doesnt actually do anything but need to make this call to make sure the inputted fraction denominator isn't zero
    //Actually a little confused, if you go step by step the input never calls any of the constructors, but the following += in the testing code still runs fine without the 
    //Fraction object being constructed, I'm wondering if there's any default copy constructor or something running in the background but I'm not sure, I overloaded the = 
    //operator but that didn't get called during the sequence either
    return is;
}


std::string FractionException::what(){
    return "Cannot devide by 0";
}