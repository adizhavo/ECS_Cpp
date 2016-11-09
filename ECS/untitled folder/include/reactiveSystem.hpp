#ifndef reactiveSystem_hpp
#define reactiveSystem_hpp

namespace ECS {
    class Filter;
    class Entity;
    
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
