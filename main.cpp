#include <iostream>
#include <vector>
#include "Frac.h"
#include "MemoryLimitException.h"
#include "MyException.h"
#include "VectorFrac.h"

using namespace std;

int main() {

    VectorFrac vf;
    vf.add(Frac(2,4));
    vf.add(Frac(1,3));
    vf.add(Frac(1,5));

    cout << "orig\n";
    for (auto i=0; i<vf.size(); i++) {
        cout << vf[i] << endl;
    }

    VectorFrac cvf = VectorFrac::copyFrom(vf, 3);

    cout << "orig~\n";
    for (auto i=0; i<vf.size(); i++) {
        cout << vf[i] << endl;
    }

    cout << "copy\n";
    for (auto i=0; i<cvf.size(); i++) {
        cout << cvf[i] << endl;
    }


    return 0;
}