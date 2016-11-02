#include "Entity.hpp"

namespace ECS {
    Entity::Entity() {
        // TODO : subscibe to the matcher
    }
    
    Entity::~Entity() {
        // TODO : unsubscribe to the matcher
        RemoveAllComponents();
    }
    
    Entity Entity::AddComponent(Component* component, bool notifySystems) {
        this->components.push_back(component);
        component->entity = this;
        
        if (notifySystems) {
            // TODO : notify systems
        }
        return *this;
    }
    
    void Entity::RemoveAllComponents() {
        this->components.clear();
    }
    
    std::vector<Component*> Entity::GetComponents() {
        return this->components;
    }
}
