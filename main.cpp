#include <ctime>
#include "Frac.h"
#include "VectorFrac.h"

using namespace std;

mt19937 gen = mt19937(time(nullptr));

Frac randomFrac() {
    return Frac(gen()%10, static_cast<unsigned int>(gen() % 9 + 1));
}

//
//Frac concreteFrac(long n, unsigned int d) {
//    return Frac(n, d);
//}

int main() {
//    gen = new mt19937(static_cast<unsigned long>(time(nullptr)));

    ExtenderFracs concreteFrac(3, 8);

    VectorFrac<Frac> vf;
    vf.add(Frac(2,4));
    vf.add(Frac(1,3));
    vf.add(Frac(1,5));

    cout << "orig\n";
    vf.out();

    VectorFrac<Frac> cvf = VectorFrac<Frac>::copyFrom(vf, 3);

    cout << "orig~\n";
    vf.out();

    cout << "copy\n";
    vf.out();

    cout << "\n ===== pointer func ===== \n";
    vf.extendWithFunction(2, randomFrac);
    vf.out();

    cout << "\n ===== pointer func ===== \n";
    vf.extendWithClassFunction(1, concreteFrac);
    vf.out();

    cout << "\n ===== \n";
    Frac a1(7,11);
    Frac a2(5,7);
    Frac a3(3,7);
    ext(vf, a1, a2, a3);
    vf.out();

//    delete gen;
    return 0;
}