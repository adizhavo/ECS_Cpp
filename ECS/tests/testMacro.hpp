#ifndef testMacro_hpp
#define testMacro_hpp

#include <stdio.h>
#include <iostream>

#include "component.hpp"
#include "reactiveSystem.hpp"

CREATE_COMPONENT(FirstTestComponent)
ENDCOMP

CREATE_COMPONENT(SecondTestComponent)
ENDCOMP

class TestReactiveSystem : public ReactiveSystem {
    public :
    TestReactiveSystem(Filter* f) {
        filter = f;
    }
    
    void Execute(Entity* entity) {
        isExecute = true;
    }
    
    Filter GetFilter () {
        return *filter;
    }
    
    bool isExecute = false;
    void Reset() {
        isExecute = false;
    }
    
    private :
    Filter* filter;
};

#define START_TEST(C, T)                        \
class C {                                       \
public :                                        \
static int runTest () {                         \
std::cout << T << "\n";                         \
std::cout << "[P F] Pass, Fail"<<"\n";          \
std::string graph;                              \
std::string text;                               \

#define ASSERT_TRUE(b, n)                       \
graph = b ? "[x -] " : "[- x] ";                \
std::cout << graph << n << "\n";                \

#define END_TEST(r)                             \
std::cout << "\n\n";                            \
return r; }};                                   \

#endif
