#include "Frac.h"
#include "AriphmeticException.h"

Frac::Frac(long numerator, unsigned int denomionator) : numerator(numerator), denomionator(denomionator) {
    if (denomionator == 0) {
        throw AriphmeticException("Frac constructor");
    }
    simplify();
}

unsigned int Frac::getNumerator() const {
    return numerator;
}

void Frac::setNumerator(unsigned int numerator) {
    Frac::numerator = numerator;
    simplify();
}

long Frac::getDenomionator() const {
    return denomionator;
}

void Frac::setDenomionator(long denomionator) {
    if (denomionator == 0) {
        throw AriphmeticException("setDenominator");
    }
    Frac::denomionator = denomionator;
    simplify();
}

bool Frac::operator<(Frac& that) {
    return (double)(*this) < (double)that;
}

Frac::operator double() {
    return (double)numerator / denomionator;
}

ostream &operator<<(ostream &cout, Frac &frac) {
    cout << frac.numerator << "/" << frac.denomionator;
    return cout;
}

void Frac::simplify() {
    unsigned long d = gcd(abs(numerator), denomionator);
    numerator /= d;
    denomionator /= d;
}

unsigned long Frac::gcd(unsigned long a, unsigned long b) {
    return (b)?gcd(b,a%b):a;
}