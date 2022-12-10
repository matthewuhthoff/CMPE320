#include <iostream>


class Fraction{
    private:
        int fractionTop; // private ints for numerator and denominator, cannot be nammed as such for confusing with numerator(), denominator()
        int fractionBottom;

    public:
        Fraction(); //constructors for fraction class
        Fraction(int single);
        Fraction(int num, int denom);

        inline int numerator() {return fractionTop;} //inline functions to get numerator and denominator
        inline int denominator() {return fractionBottom;}
    
        Fraction operator+ (const Fraction& frac); //operator overloading, const when possible to indicate purpose of method, by reference to save memory
        Fraction operator- (const Fraction& frac);
        Fraction operator- (const int& sub);
        Fraction operator* (const Fraction& frac);
        Fraction operator/ (Fraction frac);
        Fraction operator++();
        Fraction operator++(int);
        void operator+=(const Fraction& frac); // increments fraction in memory, return type void
        bool operator==(const Fraction& frac); // bool return for comparison operators
        bool operator!=(const Fraction& frac);
        bool operator!=(const int& num);
        bool operator>(Fraction& frac);
        bool operator<(Fraction& frac);
        bool operator>(const int& num);
        bool operator<(const int& num);
        bool operator<=(Fraction& frac);
        bool operator>=(Fraction& frac);
        friend bool operator< (const int& num, Fraction Frac); // friend method because the calling argument is not of type Fraction
        friend bool operator> (const int& num, Fraction Frac);
        friend std::istream& operator>> (std::istream& stream, Fraction& frac); // operator overloading must return reference to istream for input
        friend std::ostream& operator<< (std::ostream& stream, const Fraction& frac); // operator overloading must return reference to ostream for output
        friend Fraction operator+ (const int& add, const Fraction& frac);
        friend Fraction operator- (const int& sub, Fraction frac);
        friend Fraction operator-(Fraction& frac);
};



/// @brief simple class for outputing fraction error
class FractionException : std::exception{
    public:
        FractionException() = default;
        std::string what();
};