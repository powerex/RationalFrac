#ifndef RATIONALFRAC_ARIPHMETICEXCEPTION_H
#define RATIONALFRAC_ARIPHMETICEXCEPTION_H


#include "MyException.h"

class AriphmeticException: public MyException {
public:
    AriphmeticException();
    AriphmeticException(const string &method);
};


#endif //RATIONALFRAC_ARIPHMETICEXCEPTION_H
