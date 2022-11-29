#include "fraction.h"

int find_lcm(int num1, int num2) {
    int larger = num1;
    if (num2 > num1) {
        larger = num2;
    }
    int max = num1 * num2;
    int multiple = 1;
    while (multiple < max) {
        if (multiple % num1 == 0 && multiple % num2 == 0) {
            return multiple;
        }
        else {
            multiple += 1;
        }
    }
    return max;
}

int find_gcd(int num1, int num2) {
    int smaller = num1;
    if (num2 < num1) {
        smaller = num2;
    }
    if (smaller == 1) {
        return 1;
    }
    int divisor = smaller;
    while (divisor > 0) {
        if (num1 % divisor == 0 && num2 % divisor == 0) {
            return divisor;
        }
        else {
            divisor -= 1;
        }
    }
    return 1;
}

// class constructors
Fraction::Fraction(int num, int denom) : numerator{ num }, denominator{ denom } {
    auto factor = find_gcd(num, denom);
    numerator /= factor;
    denominator /= factor;
}

Fraction::Fraction(int num) : numerator{ num }, denominator{ 1 } {}

Fraction::Fraction() : numerator{ 0 }, denominator{ 1 } {}

Fraction::Fraction(const std::string frac) { //passing fraction by value so I can pass a string without declaring it as a variable
    std::stringstream ss;
    char temp;
    ss << frac;
    ss >> numerator;
    ss >> temp;
    ss >> denominator;
    this->reduce();
}

// class functions
void Fraction::print_fraction() {
    std::cout << numerator << "/" << denominator << std::endl;
}

std::string Fraction::str() {
    std::stringstream ss;
    ss << numerator;
    ss << "/";
    ss << denominator;
    return ss.str();
}

void Fraction::reduce() {
    auto factor = find_gcd(numerator, denominator);
    numerator /= factor;
    denominator /= factor;
}

// assignment operator implementations
Fraction& Fraction::operator +=(const Fraction& rhs) {
    int multiple = find_lcm(denominator, rhs.denominator);
    int new_denominator = multiple;
    int new_numerator = (numerator * new_denominator / denominator) + (rhs.numerator * new_denominator / rhs.denominator);
    Fraction temp(new_numerator, new_denominator);
    *this = temp;
    return *this;
}

Fraction& Fraction::operator *=(const Fraction& rhs) {
    Fraction temp(numerator * rhs.numerator, denominator * rhs.denominator);
    *this = temp;
    return *this;
}

Fraction& Fraction::operator -=(const Fraction& rhs) {
    int multiple = find_lcm(denominator, rhs.denominator);
    int new_denominator = multiple;
    int new_numerator = (numerator * new_denominator / denominator) - (rhs.numerator * new_denominator / rhs.denominator);
    Fraction temp(new_numerator, new_denominator);
    *this = temp;
    return *this;
}
Fraction& Fraction::operator /=(const Fraction& rhs) {
    Fraction temp(numerator * rhs.denominator, denominator * rhs.numerator);
    *this = temp;
    return *this;
}

// arithmetic operator implementations
Fraction Fraction::operator *(const Fraction& rhs) const {
    return Fraction(numerator * rhs.numerator, denominator * rhs.denominator);
}

Fraction Fraction::operator +(const Fraction& rhs) const {
    int multiple = find_lcm(denominator, rhs.denominator);
    int new_denominator = multiple;
    int new_numerator = (numerator * new_denominator / denominator) + (rhs.numerator * new_denominator / rhs.denominator);
    return Fraction(new_numerator, new_denominator);
}

Fraction Fraction::operator -(const Fraction& rhs) const {
    int multiple = find_lcm(denominator, rhs.denominator);
    int new_denominator = multiple;
    int new_numerator = (numerator * new_denominator / denominator) - (rhs.numerator * new_denominator / rhs.denominator);
    return Fraction(new_numerator, new_denominator);
}

Fraction Fraction::operator /(const Fraction& rhs) const {
    return Fraction(numerator * rhs.denominator, denominator * rhs.numerator);
}

// relational operator implementations
bool Fraction::operator ==(const Fraction& rhs) {
    return ((numerator == rhs.numerator) && (denominator == rhs.denominator));
}

bool Fraction::operator > (const Fraction& rhs) {
    Fraction temp = *this - rhs;
    if (temp.numerator > 0) { return true; }
    return false;
}

bool Fraction::operator < (const Fraction& rhs) {
    Fraction temp = *this - rhs;
    if (temp.numerator < 0) { return true; }
    return false;
}

bool Fraction::operator >= (const Fraction& rhs) {
    Fraction temp = *this - rhs;
    if (temp.numerator >= 0) { return true; }
    return false;
}

bool Fraction::operator <= (const Fraction& rhs) {
    Fraction temp = *this - rhs;
    if (temp.numerator <= 0) { return true; }
    return false;
}

// print operator implementation
void operator<<(std::ostream& os, const Fraction& toprint) {
    os << toprint.numerator << "/" << toprint.denominator;
}