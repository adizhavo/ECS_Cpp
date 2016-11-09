#ifndef reactiveSystem_hpp
#define reactiveSystem_hpp

#include <typeinfo>

#define CREATE_SYST(s, filter)     \
using namespace ECS;               \
class s : public ReactiveSystem {  \
    public :                       \
    Filter GetFilter() {           \
        return filter;             \
    }                              \

#define RECEIVE_MATCHED_ENT        \
void Execute(Entity* entity) {     \

#define END };

#include "filter.hpp"
#include "entity.hpp"
#include "ecsmacros.hpp"

namespace ECS {
    class ReactiveSystem {
        public :
        ReactiveSystem();
        ~ReactiveSystem();
        
        virtual Filter GetFilter() = 0;
        // if a component is added and if the entity matches the filter,
        // the systems is notified
        virtual void Execute(Entity* entity) = 0;
    };
}

#endif
