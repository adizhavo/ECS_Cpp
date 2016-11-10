#include "entityMatcher.hpp"
#include "filter.hpp"

#define VECTOR_REMOVE(element, vector)                                          \
vector.erase(std::remove(vector.begin(), vector.end(), element), vector.end())  \

namespace ECS {
    std::vector<Entity*>EntityMatcher::subscribedEntities;
    
    void EntityMatcher::Subscribe(ECS::Entity* entity) {
        subscribedEntities.push_back(entity);
    }
    
    void EntityMatcher::UnSubscribe(ECS::Entity* entity) {
        for (Entity* e : subscribedEntities )
        if (e != NULL && e == entity)
            VECTOR_REMOVE(entity, subscribedEntities);
    }
    
    std::vector<Entity*> EntityMatcher::FilterGroup(Filter f){
        std::vector<Entity*> entities;
        for (Entity* e : subscribedEntities )
        if (e != NULL && f.DoesMatch(e))
            entities.push_back(e);
        return entities;
    }
}
