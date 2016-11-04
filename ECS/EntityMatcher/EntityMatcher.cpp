#include "EntityMatcher.hpp"

namespace ECS {
    std::vector<Entity*>EntityMatcher::subscribedEntities;
    
    EntityMatcher::~EntityMatcher() {
        subscribedEntities.clear();
    }
    
    void EntityMatcher::Subscribe(ECS::Entity* entity) {
        subscribedEntities.push_back(entity);
    }
    
    void EntityMatcher::UnSubscribe(ECS::Entity* entity) {
        for (int index = 0; index < subscribedEntities.size(); index ++) {
            if (subscribedEntities[index] == entity)
                subscribedEntities.erase(std::remove(subscribedEntities.begin(), subscribedEntities.end(), entity), subscribedEntities.end());
        }
    }
}
