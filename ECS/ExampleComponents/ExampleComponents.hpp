#ifndef ExampleComponents_hpp
#define ExampleComponents_hpp

#include <typeinfo>
#include "Component.hpp"

#define ID(c) IdProvider::ID<typeof(*c)>()

using namespace ECS;

class FirstComponent : public Component {
    public :
    long unique_id() {
        return ID(this);
    };
};

class SecondComponent : public Component {
    public :
    long unique_id() {
        return ID(this);
    };
};

#endif
