cmake_minimum_required(VERSION 3.8)
project(RAtionalFrac)

set(CMAKE_CXX_STANDARD 11)

add_executable(RAtionalFrac main.cpp Frac.cpp Frac.h MemoryLimitException.cpp MemoryLimitException.h VectorFrac.h AriphmeticException.cpp AriphmeticException.h MyException.cpp MyException.h Functions.h)