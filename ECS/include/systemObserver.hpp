#ifndef systemObserver_hpp
#define systemObserver_hpp

#include <vector>

namespace ECS {
    class Entity;
    class ReactiveSystem;
    
    class SystemObserver {
        public :
        static void Subscribe(ReactiveSystem* system);
        static void Unsubscribe(ReactiveSystem* system);
        static void Notify(Entity* ent);
        
        private :
        static std::vector<ReactiveSystem*> subscribedSystems;
    };
}

#endif
