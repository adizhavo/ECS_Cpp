#ifndef ReactiveSystem_hpp
#define ReactiveSystem_hpp

namespace ECS {
    class Entity;
    class Filter;
    
    class ReactiveSystem {
        public :
        virtual Filter GetFilter() = 0;
        // if a component is added and if the entity matches the filter,
        // the systems is notified
        vitual void Execute(Entity* entity) = 0;
    };
}

#endif
