#include "entity.hpp"
#include "systemObserver.hpp"
#include "entityMatcher.hpp"

namespace ECS {
    Entity::Entity() {
        EntityMatcher::Subscribe(this);
    }
    
    Entity::~Entity() {
        EntityMatcher::UnSubscribe(this);
        RemoveAllComponents();
    }
    
    Entity* Entity::AddComponent(Component* component, bool notifySystems) {
        if (!HasComponent(component->unique_id())) {
            components.push_back(component);
            component->entity = this;
            
            if (notifySystems)
                SystemObserver::Notify(this);
        }
        return this;
    }
    
    Component* Entity::GetComponent(unsigned long component_id) {
        for (Component* cmp : components)
            if (cmp->unique_id() == component_id)
                return cmp;
        return NULL;
    }
    
    bool Entity::HasComponent(unsigned long component_id) {
        for (Component* cmp : components)
        if (cmp->unique_id() == component_id)
            return true;
        return false;
    }
    
    void Entity::RemoveComponent(unsigned long component_id, bool freeComponent) {
        for (Component* cmp : components)
        if (cmp->unique_id() == component_id) {
            cmp->entity = 0;
            VECTOR_REMOVE(cmp, components);
            if (freeComponent)
            {
                delete cmp;
                cmp = NULL;
            }
            return;
        }
    }
    
    void Entity::RemoveAllComponents() {
        for (Component* cmp : components)
        {
            delete cmp;
            cmp = NULL;
        }
        components.clear();
    }
    
    std::vector<Component*> Entity::GetComponents() {
        return components;
    }
}
