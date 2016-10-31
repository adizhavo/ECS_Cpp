#include "Entity.hpp"

namespace ECS {
    Entity::Entity() {
        // TODO : subscibe to the matcher
    }
    
    Entity::~Entity() {
        // Remove All component
    }
    
    Entity Entity::AddComponent(ECS::Component component, bool notifySystems) {
        
        return *this;
    }
    
    Entity Entity::ReplaceComponent(ECS::Component component, bool notifySystems) {
        
        return *this;
    }
    
    template<typename T> void Entity::RemoveComponent(T type) {
        
    }
    
    template<typename T> T Entity::GetComponent(T type) {
        
    }
    
    template<typename T> std::list<T> Entity::GetComponents(T type) {
        
    }
    
    template<typename T> bool HasComponent (T type) {
        
    }
    
    std::list<Component> Entity::GetComponents() {
        return this->components;
    }
}