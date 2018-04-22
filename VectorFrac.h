#ifndef RATIONALFRAC_VECTORFRAC_H
#define RATIONALFRAC_VECTORFRAC_H

#include <vector>
#include "Frac.h"
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include "MemoryLimitException.h"
#include <sys/sysinfo.h> // Unix
//#include <Windows.h> // Windows
#include <functional>

using namespace std;

template <class T>
class Additable {
public:
    virtual void add(T value) = 0;
};

template <class T>
class VectorFrac: public Additable<T> {
private:
    vector<T> vec;
    VectorFrac(const vector<T> &vec);

public:
    VectorFrac();
    static VectorFrac copyFrom(VectorFrac& source, unsigned int n);

    void add(T f);
    //void addWithFunction(unsigned int n, function func);
    void extendWithFunction(int n, T (*generator)(void)); // передача функції як параметр через вказівник на функцію
    T& operator[] (unsigned int index);
    unsigned long size();
    void out();
    vector<T>* getVec();

    virtual ~VectorFrac();
};

template <class T>
VectorFrac<T>::VectorFrac() {}

template <class T>
VectorFrac<T>::VectorFrac(const vector<T> &vec) : vec(vec) {}

template <class T>
VectorFrac<T>::~VectorFrac() {
    vector<T>().swap(vec);
}

template <class T>
void VectorFrac<T>::add(const T f) {
    vec.push_back(f);
}

template <class T>
T &VectorFrac<T>::operator[](unsigned int index) {
    return vec.at(index);
}

template <class T>
unsigned long VectorFrac<T>::size() {
    return vec.size();
}

template <class T>
VectorFrac<T> VectorFrac<T>::copyFrom(VectorFrac<T> &source, unsigned int n) {

    unsigned long free;
    /* Windows
    MEMORYSTATUS info;
    GlobalMemoryStatus(&info);
    free = info.dwAvailPhys;
    //*/

    //* Unix
    struct sysinfo info;
    sysinfo(&info);
    free = info.freeram;
    //*/
    unsigned long mem = source.vec.size() * sizeof(T);
    if (mem > free)
        throw MemoryLimitException("copyFrom", "too big vector");
    //printf("Обсяг доступної пам\'яті: %lu (%lu MB)\n", info.freeram, info.freeram/(1024*1024));
    vector<Frac> tmp = source.vec;
    sort(tmp.begin(), tmp.begin()+n);
    return tmp;
}

template <class T>
void VectorFrac<T>::extendWithFunction(int n, T (*generator)(void)) {
    for (int i=0; i<n; i++) {
        this->add(generator());
    }
}

template <class T>
void VectorFrac<T>::out() {
    for (auto i=0; i<vec.size(); i++) {
        cout << vec.at(i) << endl;
    }
}

template <class T>
vector<T>* VectorFrac<T>::getVec() {
    return &vec;
}

Frac randomFrac() {
    return Frac(rand()%10, rand()%9+1);
}
#endif //RATIONALFRAC_VECTORFRAC_H
