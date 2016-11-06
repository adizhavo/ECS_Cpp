#include "Entity.hpp"
#include "SystemObserver.hpp"
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
        if (!HasComponent(component->unique_id())) {
            components.push_back(component);
            component->entity = this;
            
            if (notifySystems)
                SystemObserver::Notify(this);
        }
        return *this;
    }
    
    bool Entity::HasComponent(long component_id) {
        VECTOR_FOR_EACH (cmp_index, components)
        if (components.at(cmp_index)->unique_id() == component_id)
            return true;
        return false;
    }
    
    void Entity::RemoveComponent(long component_id) {
        VECTOR_FOR_EACH (cmp_index, components) {
            Component* cmp = components.at(cmp_index);
            if (cmp->unique_id() == component_id) {
                cmp->entity = 0;
                VECTOR_REMOVE(cmp, components);
                break;
            }
        }
    }
    
    void Entity::RemoveAllComponents() {
        VECTOR_FOR_EACH (cmp_index, components)
        components.at(cmp_index)->entity = 0;
        components.clear();
    }
    
    std::vector<Component*> Entity::GetComponents() {
        return components;
    }
}
