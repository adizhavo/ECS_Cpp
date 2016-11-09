#ifndef component_hpp
#define component_hpp

#define CREATE_COMPONENT(c)       \
using namespace ECS;              \
class c : public Component {      \
    public :                      \
    long unique_id() {            \
        return COMP_ID(c);        \
    }                             \

#define ENDCOMP };

#include "ecsmacros.hpp"

namespace ECS {
    class Entity;
    
    class Component {
        public :
        Entity* entity;
        virtual long unique_id() = 0;
        Component() {
            this->entity = 0;
        }
    };
}

#endif
