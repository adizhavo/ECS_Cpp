#include "Entity.hpp"

namespace ECS {
    Entity::Entity() {
        // TODO : subscibe to the matcher
    }
    
    Entity::~Entity() {
        // TODO : unsubscribe to the matcher
        RemoveAllComponents();
    }
    
    Entity Entity::AddComponent(ECS::Component component, bool notifySystems) {
        this->components.push_back(component);
        component.entity = this;
        
        if (notifySystems) {
            // TODO : notify systems
        }
        return *this;
    }
    
    void Entity::RemoveAllComponents() {
        this->components.clear();
    }
    
    template<typename T> void Entity::RemoveComponent() {
        int erase_index = -1;
        for (int cmp_index = 0; cmp_index < this->components.size(); cmp_index ++) {
            T comp = dynamic_cast<T>(this->components.at(cmp_index));
            if (comp != NULL)
                erase_index = cmp_index;
        }
        
        if (erase_index > 0) this->components.erase(this->components.begin() + erase_index);
    }
    
    template<typename T> T Entity::GetComponent() {
        for (int cmp_index = 0; cmp_index < this->components.size(); cmp_index ++) {
            T comp = dynamic_cast<T>(this->components.at(cmp_index));
            if (comp != NULL)
                return comp;
        }
        return NULL;
    }
    
    template<typename T> std::vector<T> Entity::GetComponents() {
        std::vector<T> requested_components;
        for (int cmp_index = 0; cmp_index < this->components.size(); cmp_index ++) {
            T comp = dynamic_cast<T>(this->components.at(cmp_index));
            if (comp != NULL)
                requested_components.push_back(comp);
        }
        return requested_components;
    }
    
    template<typename T> bool Entity::HasComponent() {
        for (int cmp_index = 0; cmp_index < this->components.size(); cmp_index ++) {
            T comp = dynamic_cast<T>(this->components.at(cmp_index));
            if (comp != NULL)
                return true;
        }
        return false;
    }
    
    std::vector<Component> Entity::GetComponents() {
        return this->components;
    }
}