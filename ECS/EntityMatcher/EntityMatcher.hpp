#ifndef EntityMatcher_hpp
#define EntityMatcher_hpp

#include <vector>

namespace ECS {
    class Entity;
    
    class EntityMatcher {
        public :
        static void Subscribe(Entity* entity);
        static void UnSubscribe(Entity* entity);
        
        private:
        static std::vector<Entity*> subscribedEntities;
    };
}

#endif
