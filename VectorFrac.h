#ifndef RATIONALFRAC_VECTORFRAC_H
#define RATIONALFRAC_VECTORFRAC_H

#include <vector>
#include "Frac.h"
#include <algorithm>
#include <stdio.h>
#include <sys/sysinfo.h> // Unix
//#include <Windows.h> // Windows
#include <functional>

using namespace std;

class VectorFrac {
private:
    vector<Frac> vec;
    VectorFrac(const vector<Frac> &vec);

public:
    VectorFrac();
    static VectorFrac copyFrom(VectorFrac& source, unsigned int n);

    void add(Frac f);
    //void addWithFunction(unsigned int n, function func);
    void extendWithFunction(int n, Frac (*generator)(void)); // передача функції як параметр через вказівник на функцію
    Frac& operator[] (unsigned int index);
    unsigned long size();
    void out();
    vector<Frac>& getVec();

    virtual ~VectorFrac();
};


#endif //RATIONALFRAC_VECTORFRAC_H
