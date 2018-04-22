#include <iostream>
#include <vector>
#include "Frac.h"
#include "VectorFrac.h"
#include "Functions.h"

using namespace std;

Frac randomFrac() {
    return Frac(rand()%10, rand()%9+1);
}
//
//Frac concreteFrac(long n, unsigned int d) {
//    return Frac(n, d);
//}

int main() {
    srand(time(NULL));

    ExtenderFracs concreteFrac(3, 8);

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

    return 0;
}