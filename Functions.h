#ifndef RATIONALFRAC_FUNCTIONS_H
#define RATIONALFRAC_FUNCTIONS_H

#include <vector>
#include <algorithm>
#include <stdarg.h>
#include <iostream>


template <class T>
void extender(std::vector<T> container, int argc, ...) {
    va_list args;
    while(argc--) {
        container.push_back(va_arg(args, T));
    }
    va_end(args);
}


/*
void tt(int n, int ... argv) {

    int* v = &argv;
    while(n--) {
        std::cout << v[1] << " ";
    }
    std::cout << std::endl;
}
*/

#endif //RATIONALFRAC_FUNCTIONS_H
