#ifndef RATIONALFRAC_FUNCTIONS_H
#define RATIONALFRAC_FUNCTIONS_H

#include <vector>
#include <algorithm>

template <class T>
void extender(std::vector<T> container, int argc, T argv, ...) {
    T* value = &argv;
    while(argc--) {
        container.push_back(*value);
        value++;
    }
}

#endif //RATIONALFRAC_FUNCTIONS_H
