#ifndef RATIONALFRAC_VECTORFRAC_H
#define RATIONALFRAC_VECTORFRAC_H

#include <vector>
#include "Frac.h"
#include <algorithm>
#include <stdio.h>
#include <sys/sysinfo.h>

using namespace std;

class VectorFrac {
private:
    vector<Frac> vec;
    VectorFrac(const vector<Frac> &vec);

public:
    VectorFrac();
    static VectorFrac copyFrom(VectorFrac& source, unsigned int n);

    void add(Frac f);
    Frac& operator[] (unsigned int index);
    unsigned long size();

    virtual ~VectorFrac();
};


#endif //RATIONALFRAC_VECTORFRAC_H
