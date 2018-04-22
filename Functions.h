#ifndef RATIONALFRAC_FUNCTIONS_H
#define RATIONALFRAC_FUNCTIONS_H

#include <vector>
#include <algorithm>
#include <cstdarg>
#include <iostream>
#include "Frac.h"


class ExtenderFracs {
private:
    long n;
    unsigned int d;
public:
    ExtenderFracs(long n, unsigned int d): n(n), d(d) {}

    inline Frac operator()() {
        return {n, d};
    }
};

/*
template <class T>
void extender(std::vector<T> container, int argc, ...) {
    va_list args;
    while(argc--) {
        container.push_back(va_arg(args, T));
    }
    va_end(args);
}
*/

#endif //RATIONALFRAC_FUNCTIONS_H
