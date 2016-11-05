#ifndef ExampleComponents_hpp
#define ExampleComponents_hpp

#include "Component.hpp"
#include "ECSMacros.hpp"

using namespace ECS;

class FirstComponent : public Component {
    public :
    long unique_id() {
        return COMP_ID(*this);
    };
};

class SecondComponent : public Component {
    public :
    long unique_id() {
        return COMP_ID(*this);
    };
};

#endif
