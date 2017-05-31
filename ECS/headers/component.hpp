#ifndef component_hpp
#define component_hpp

#include <typeinfo>

#define COMP_ID(c)                \
typeid(c).hash_code()             \

#define RETURN_ID(c)              \
 unsigned long unique_id() {      \
return COMP_ID(c);                \
}                                 \

#define CREATE_COMPONENT(c)       \
using namespace ECS;              \
class c : public Component {      \
    public :                      \
    RETURN_ID(c)                  \

#define ENDCOMP };

#define CREATE_ABSTRACT_COMPONENT(c) \
using namespace ECS;                 \
class c : public Component {         \
    public :                         \
    virtual unsigned long unique_id() = 0; \

#define ENDCOMP };

namespace ECS {
    class Entity;
    
    class Component {
        public :
        Entity* entity;
        virtual unsigned long unique_id() = 0;
        Component() {
            this->entity = 0;
        }
        
        virtual ~Component(){
            this->entity = 0;
        }
    };
}

#endif
