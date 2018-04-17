#include <iostream>
#include "MemoryLimitException.h"

MemoryLimitException::MemoryLimitException(const string &method, const string &description) {
    this->method = method;
    this->description = description;
}

MemoryLimitException::MemoryLimitException() {
    this->method = "Unknown";
    this->description = "General error";
}

const string &MemoryLimitException::getMethod() const {
    return method;
}

const string &MemoryLimitException::getDescription() const {
    return description;
}
