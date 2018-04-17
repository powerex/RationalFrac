#include <iostream>
#include "MyException.h"

void MyException::showInfo()const {
    cerr << "Error:\t" << description << "\n"
         << " in " << method << " method\n";
}