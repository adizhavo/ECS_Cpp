#include "Entity.hpp"

namespace ECS {
    Entity::Entity() {
        // TODO : subscibe to the matcher
    }
    
    Entity::~Entity() {
        // Remove All component
    }
    
    std::list<Component> Entity::Components() {
        return components;
    }
}