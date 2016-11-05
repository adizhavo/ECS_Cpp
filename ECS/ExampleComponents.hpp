#ifndef ExampleComponents_hpp
#define ExampleComponents_hpp

#include <typeinfo>
#include "Component.hpp"

using namespace ECS;

class FirstComponent : public Component {
    public :
    long unique_id() {
        return IdProvider::ID<typeof(*this)>();
    };
};

class SecondComponent : public Component {
    public :
    long unique_id() {
        return IdProvider::ID<typeof(*this)>();
    };
};

#endif
