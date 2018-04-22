#ifndef RATIONALFRAC_FRAC_H
#define RATIONALFRAC_FRAC_H

#include <fstream>
#include <cmath>

using namespace std;

class Frac {
private:
    unsigned int numerator;
    long int denomionator;
    unsigned long gcd(unsigned long a, unsigned long b);
    void simplify();
public:
    Frac(long numerator, unsigned int denomionator);

    unsigned int getNumerator() const;

    void setNumerator(unsigned int numerator);

    long getDenomionator() const;

    void setDenomionator(long denomionator);

    bool operator< (Frac& that);

    explicit operator double();

    friend ostream& operator<<(ostream& cout, Frac& frac);
};

#endif //RATIONALFRAC_FRAC_H
