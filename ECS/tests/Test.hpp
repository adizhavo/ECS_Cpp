#ifndef Test_hpp
#define Test_hpp

#include <stdio.h>
#include <iostream>

#define START_TEST(T)                           \
int main (int argc, char* argv[]) {             \
std::cout << "[P F] Pass, Fail"<<"\n";          \
std::string graph;                              \
std::string text;                               \
std::cout << "Test title: " << T << "\n";       \

#define ASSERT_TRUE(b, n)                       \
graph = b ? "[x -] " : "[- x] ";                \
text = b ? "passed\n" : "failed\n";             \
std::cout << graph << n << ": " << text;        \

#define END_TEST                                \
std::cout << "\n\n";                            \
return 0; }                                     \

#endif
