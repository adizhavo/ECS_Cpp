#ifndef sampleComponents_hpp
#define sampleComponents_hpp

#include "component.hpp"

// simple component
CREATE_COMPONENT(FirstComponent)
// put variables / methods here
ENDCOMP

// component with multiple inheritance
class SecondComponent : public ECS::Component /*other dependecies*/ {
    // put variables / methods here
    RETURN_ID(SecondComponent)
    // put variables / methods here
};

#endif
