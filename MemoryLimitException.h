#ifndef RATIONALFRAC_MEMORYLIMITEXCEPTION_H
#define RATIONALFRAC_MEMORYLIMITEXCEPTION_H

#include <string>
#include "MyException.h"

using namespace std;

class MemoryLimitException: public MyException {
public:
    MemoryLimitException();
    MemoryLimitException(const string &method, const string &description);
    const string &getMethod() const;
    const string &getDescription() const;
};


#endif //RATIONALFRAC_MEMORYLIMITEXCEPTION_H
