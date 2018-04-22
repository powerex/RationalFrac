#include <iostream>
#include <vector>
#include "Frac.h"
#include "VectorFrac.h"

using namespace std;

template<typename... T>
void f(const T&... args) {
    for (auto&& p : std::initializer_list<Frac>{args...})
        cout << p.getNumerator() << '/' << p.getDenomionator() << '\t';
}

template<typename E, typename... T>
void ext(VectorFrac<E>& container, const T&... args) {
    for (auto&& p : std::initializer_list<Frac>{args...})
        container.add(p);
}

int main() {

    VectorFrac<Frac> vf;
    vf.add(Frac(2,4));
    vf.add(Frac(1,3));
    vf.add(Frac(1,5));

    cout << "orig\n";
    vf.out();

//    VectorFrac cvf = VectorFrac::copyFrom(vf, 3);
//
//    cout << "orig~\n";
//    vf.out();
//
//    cout << "copy\n";
//    vf.out();

//    vf.extendWithFunction(2, randomFrac);
//    vf.out();

    cout << "\n ===== \n";
    Frac a1(7,11);
    Frac a2(5,7);
    Frac a3(3,7);
    ext(vf, a1, a2, a3);
    vf.out();

    cout << endl;
    f(Frac{11, 12}, Frac{22, 23});

    return 0;
}