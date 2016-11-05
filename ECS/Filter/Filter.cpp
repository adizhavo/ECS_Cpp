#include <stdarg.h>

#include "Filter.hpp"
#include "ECSMacros.hpp"

namespace ECS {
    Filter::~Filter() {
        Reset();
    }
    
    Filter Filter::AllOf(int size, ...) {
        BUILD_FILTER(size, allOf);
        return *this;
    }
    
    Filter Filter::AnyOf(int size, ...) {
        BUILD_FILTER(size, anyOf);
        return *this;
    }
    
    Filter Filter::NoneOf(int size, ...) {
        BUILD_FILTER(size, noneOf);
        return *this;
    }
    
    bool Filter::DoesMatch(Entity* entity) {
        return HasAnyMatcher(entity) && HasAllMatchers(entity) && HasNoneMatcher(entity);
    }
    
    void Filter::Reset() {
        this->allOf.clear();
        this->anyOf.clear();
        this->noneOf.clear();
    }
    
    bool Filter::HasAnyMatcher(Entity* entity) {
        VECTOR_FOR_EACH(i, anyOf)
        if (entity->HasComponent(this->anyOf.at(i)))
            return true;
        return this->anyOf.size() == 0;
    }
    
    bool Filter::HasAllMatchers(Entity* entity) {
        int componentCounter = 0;
        VECTOR_FOR_EACH(i, allOf)
        if (entity->HasComponent(this->allOf.at(i)))
            componentCounter ++;
        
        return this->allOf.size() == 0 || (componentCounter != 0 && componentCounter == this->allOf.size());
    }
    
    bool Filter::HasNoneMatcher(Entity* entity) {
        VECTOR_FOR_EACH(i, noneOf)
        if (entity->HasComponent(this->noneOf.at(i)))
            return false;
        return true;
    }
}
