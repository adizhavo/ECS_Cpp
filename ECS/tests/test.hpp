#ifndef test_hpp
#define test_hpp

#include <stdio.h>
#include <iostream>

#include "Component.hpp"

CREATE_COMPONENT(FirstTestComponent)
ENDCOMP

CREATE_COMPONENT(SecondTestComponent)
ENDCOMP

#define START_TEST(T)                           \
class T {                                       \
public :                                        \
static int runTest () {                         \
std::cout << "[P F] Pass, Fail"<<"\n";          \
std::string graph;                              \
std::string text;                               \

#define ASSERT_TRUE(b, n)                       \
graph = b ? "[x -] " : "[- x] ";                \
std::cout << graph << n << "\n";              \

#define END_TEST(r)                             \
std::cout << "\n\n";                            \
return r; }};                                   \

#endif
