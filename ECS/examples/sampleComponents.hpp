#ifndef sampleComponents_hpp
#define sampleComponents_hpp

#include "component.hpp"
#include "ecsmacros.hpp"
#include <typeinfo>

using namespace ECS;

class FirstComponent : public Component {
    public :
    long unique_id() {
        return COMP_ID(FirstComponent);
    }
};

class SecondComponent : public Component {
    public :
    long unique_id() {
        return COMP_ID(SecondComponent);
    }
};

#endif
