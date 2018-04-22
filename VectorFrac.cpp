#include "VectorFrac.h"
#include "MemoryLimitException.h"

VectorFrac::VectorFrac() {}

VectorFrac::VectorFrac(const vector<Frac> &vec) : vec(vec) {}

VectorFrac::~VectorFrac() {
    vector<Frac>().swap(vec);
}

void VectorFrac::add(const Frac f) {
    vec.push_back(f);
}

Frac &VectorFrac::operator[](unsigned int index) {
    return vec.at(index);
}

unsigned long VectorFrac::size() {
    return vec.size();
}

VectorFrac VectorFrac::copyFrom(VectorFrac &source, unsigned int n) {

    unsigned long free;
    //* Windows
    MEMORYSTATUS info;
    GlobalMemoryStatus(&info);
    free = info.dwAvailPhys;
    //*/

    /* Unix
    struct sysinfo info;
    sysinfo(&info);
    free = info.freeramж
    //*/
    unsigned long mem = source.vec.size() * sizeof(Frac);
    if (mem > free)
        throw MemoryLimitException("copyFrom", "too big vector");
    //printf("Обсяг доступної пам\'яті: %lu (%lu MB)\n", info.freeram, info.freeram/(1024*1024));
    vector<Frac> tmp = source.vec;
    sort(tmp.begin(), tmp.begin()+n);
    return tmp;
}
//
//void VectorFrac::addWithFunction(unsigned int n, function func) {
//    for (unsigned int i=0; i<n; i++) {
//        add(func());
//    }
//}


