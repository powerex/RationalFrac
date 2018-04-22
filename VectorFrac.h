#ifndef RATIONALFRAC_VECTORFRAC_H
#define RATIONALFRAC_VECTORFRAC_H

#include <vector>
#include "Frac.h"
#include <algorithm>
#include <cstdio>
#include <iostream>
#include "MemoryLimitException.h"
#include "Functions.h"

#include <stdio.h>

#if defined(__linux__) // any linux distribution
    #define PLATFORM "linux"
    #include <sys/sysinfo.h>
#elif defined(_WIN32) // any windows system
    #define PLATFORM "windows"
    #include <Windows.h>
#else
    #define PLATFORM "Is not linux or windows"
#endif

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

    explicit VectorFrac(const vector<T> &vec);

public:
    VectorFrac();
    static VectorFrac copyFrom(VectorFrac& source, unsigned int n);

    virtual void add(T value);
    void extendWithFunction(int n, T (*generator)()); // передача функції як параметр через вказівник на функцію
    void extendWithClassFunction(int n, ExtenderFracs extender); // передача функції як параметр через вказівник на функцію
    T& operator[] (unsigned int index);
    unsigned long size();
    void out();
    vector<T>* getVec();

    virtual ~VectorFrac();
};

template <class T>
VectorFrac<T>::VectorFrac() = default;

template <class T>
VectorFrac<T>::VectorFrac(const vector<T> &vec) : vec(vec) {}

template <class T>
VectorFrac<T>::~VectorFrac() {
    vector<T>().swap(vec);
}

template <class T>
void VectorFrac<T>::add(T value) {
    vec.push_back(value);
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

#if PLATFORM == "windows"
    MEMORYSTATUS info;
    GlobalMemoryStatus(&info);
    free = info.dwAvailPhys;
#endif

#if PLATFORM == "linux"
    struct sysinfo info;
    sysinfo(&info);
    free = info.freeram;
    //*/
#endif

    unsigned long mem = source.vec.size() * sizeof(T);
    if (mem > free)
        throw MemoryLimitException("copyFrom", "too big vector");
    //printf("Обсяг доступної пам\'яті: %lu (%lu MB)\n", info.freeram, info.freeram/(1024*1024));
    vector<Frac> tmp = source.vec;
    sort(tmp.begin(), tmp.begin()+n);
    return VectorFrac<Frac>(tmp);
}

template <class T>
void VectorFrac<T>::extendWithFunction(int n, T (*generator)(void)) {
    for (int i=0; i<n; i++) {
        this->add(generator());
    }
}


template<class T>
void VectorFrac<T>::extendWithClassFunction(int n, ExtenderFracs extender) {
    for (int i=0; i<n; i++) {
        this->add(extender());
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

// template function to batch addition
template<typename E, typename... T>
void ext(VectorFrac<E>& container, const T&... args) {
    for (auto&& p : std::initializer_list<Frac>{args...})
        container.add(p);
}

//template<typename... T>
//void f(const T&... args) {
//    for (auto&& p : std::initializer_list<Frac>{args...})
//        std::cout <<  p.getNumerator() << '/' << p.getDenomionator() << '\t';
//}


#endif //RATIONALFRAC_VECTORFRAC_H
