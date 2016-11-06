#include "EntityMatcher.hpp"
#include "ECSMacros.hpp"    

namespace ECS {
    std::vector<Entity*>EntityMatcher::subscribedEntities;
    
    void EntityMatcher::Subscribe(ECS::Entity* entity) {
        subscribedEntities.push_back(entity);
    }
    
    void EntityMatcher::UnSubscribe(ECS::Entity* entity) {
        VECTOR_FOR_EACH(index, subscribedEntities)
            if (subscribedEntities[index] != NULL && subscribedEntities[index] == entity)
                VECTOR_REMOVE(entity, subscribedEntities);
    }
}
