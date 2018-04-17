//
// Created by azbest on 17.04.18.
//

#include "AriphmeticException.h"

AriphmeticException::AriphmeticException() {}

AriphmeticException::AriphmeticException(const string &method) {
    this->method = method;
    this->description = "Division by zero";
}

