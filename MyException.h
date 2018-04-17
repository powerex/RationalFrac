#ifndef RATIONALFRAC_EXCEPTION_H
#define RATIONALFRAC_EXCEPTION_H

#include <string>

using namespace std;

class MyException {
protected:
    string method;
    string description;
public:
    virtual void showInfo()const;
};


#endif //RATIONALFRAC_EXCEPTION_H
