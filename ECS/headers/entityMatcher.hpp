#ifndef entityMatcher_hpp
#define entityMatcher_hpp

#include <vector>

namespace ECS {
    class Entity;
    class Filter;
    
    class EntityMatcher {
        public :
        static void Subscribe(Entity* entity);
        static void UnSubscribe(Entity* entity);
        static std::vector<Entity*> FilterGroup(Filter f);
        
        private:
        static std::vector<Entity*> subscribedEntities;
    };
}

#endif
