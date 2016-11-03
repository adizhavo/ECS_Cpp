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
        if (!this->HasComponent(component->GetMatcher())) {
            this->components.push_back(component);
            component->entity = this;
            
            if (notifySystems) {
                // TODO : notify systems
            }
        }
        return *this;
    }
    
    bool Entity::HasComponent(ECS::Matcher matcher) {
        for (int cmp_index = 0; cmp_index < this->components.size(); cmp_index ++) {
            if (this->components.at(cmp_index)->GetMatcher() == matcher)
                return true;
        }
        
        return false;
    }
    
    void Entity::RemoveComponent(ECS::Matcher matcher) {
        for (int cmp_index = 0; cmp_index < this->components.size(); cmp_index ++) {
            Component* cmp = this->components.at(cmp_index);
            if (cmp->GetMatcher() == matcher) {
                cmp->entity = 0;
                this->components.erase(std::remove(this->components.begin(), this->components.end(), cmp));
                break;
            }
        }
    }
    
    void Entity::RemoveAllComponents() {
        for (int cmp_index = 0; cmp_index < this->components.size(); cmp_index ++) {
            Component* comp = static_cast<Component*>(this->components.at(cmp_index));
            if (comp != NULL) comp->entity = 0;
        }
        this->components.clear();
    }
    
    std::vector<Component*> Entity::GetComponents() {
        return this->components;
    }
}
