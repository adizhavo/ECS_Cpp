#include "EntityMatcher.hpp"
#include "Filter.hpp"
#include "ECSMacros.hpp"

namespace ECS {
    std::vector<Entity*>EntityMatcher::subscribedEntities;
    
    void EntityMatcher::Subscribe(ECS::Entity* entity) {
        subscribedEntities.push_back(entity);
    }
    
    void EntityMatcher::UnSubscribe(ECS::Entity* entity) {
        VECTOR_FOR_EACH(index, subscribedEntities)
        if (subscribedEntities.at(index) != NULL && subscribedEntities.at(index) == entity)
            VECTOR_REMOVE(entity, subscribedEntities);
    }
    
    std::vector<Entity*> EntityMatcher::FilterGroup(Filter f){
        std::vector<Entity*> entities;
        VECTOR_FOR_EACH(index, subscribedEntities)
        if (subscribedEntities.at(index) != NULL && f.DoesMatch(subscribedEntities.at(index)))
            entities.push_back(subscribedEntities.at(index));
        return entities;
    }
}
