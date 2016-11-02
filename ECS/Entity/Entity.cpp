#include "Entity.hpp"
#include "EntityMatcher.hpp"

namespace ECS {
    Entity::Entity() {
        EntityMatcher::Subscribe(this);
    }
    
    Entity::~Entity() {
        EntityMatcher::UnSubscribe(this);
        RemoveAllComponents();
    }
    
    Entity Entity::AddComponent(Component* component, bool notifySystems) {
        if (!this->HasComponent<typeof(*component)>()) {
            this->components.push_back(component);
            component->entity = this;
            
            if (notifySystems) {
                // TODO : notify systems
            }
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
