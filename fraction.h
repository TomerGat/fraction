#pragma once
#include <string>
#include <iostream>
#include <numeric>
#include <sstream>

//general function declarations
int find_lcm(int num1, int num2);
int find_gcd(int num1, int num2);

//class declaration
class Fraction {
public:
    //class values
    int numerator;
    int denominator;

    //constructor declarations
    Fraction(int num, int denom);
    Fraction(int num);
    Fraction();
    Fraction(std::string);

    //class function declarations
    std::string str(); //return fraction as string
    void print_fraction();
    void reduce(); //minimize functions (divide numerator and denominator by gcd)

    //declarations for assignment operators
    Fraction& operator +=(const Fraction& rhs);
    Fraction& operator *=(const Fraction& rhs);
    Fraction& operator -=(const Fraction& rhs);
    Fraction& operator /=(const Fraction& rhs);

    //declarations for arithmetic operators
    Fraction operator *(const Fraction& rhs) const;
    Fraction operator +(const Fraction& rhs) const;
    Fraction operator -(const Fraction& rhs) const;
    Fraction operator /(const Fraction& rhs) const;

    //declarations for relational operators
    bool operator == (const Fraction& rhs);
    bool operator > (const Fraction& rhs);
    bool operator < (const Fraction& rhs);
    bool operator >= (const Fraction& rhs);
    bool operator <= (const Fraction& rhs);

    //declaration for print operator function
    friend void operator<<(std::ostream& os, const Fraction& toprint);
};