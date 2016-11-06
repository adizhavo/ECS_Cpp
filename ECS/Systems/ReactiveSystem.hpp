#ifndef ReactiveSystem_hpp
#define ReactiveSystem_hpp

#include "Filter.hpp"
#include "Entity.hpp"

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
