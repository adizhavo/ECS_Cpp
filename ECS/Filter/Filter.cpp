#include "Filter.hpp"
#include <stdarg.h>

namespace ECS {
    Filter::~Filter() {
        Reset();
    }
    
    Filter Filter::AllOf(int size, ...) {
        va_list ids;
        va_start(ids, size);
        for(int i = 0; i < size; i ++) {
            long unique_id = va_arg(ids, long);
            this->allOf.push_back(unique_id);
        }
        return *this;
    }
    
    Filter Filter::AnyOf(int size, ...) {
        va_list ids;
        va_start(ids, size);
        for(int i = 0; i < size; i ++) {
            long unique_id = va_arg(ids, long);
            this->anyOf.push_back(unique_id);
        }
        return *this;
    }
    
    Filter Filter::NoneOf(int size, ...) {
        va_list ids;
        va_start(ids, size);
        for(int i = 0; i < size; i ++) {
            long unique_id = va_arg(ids, long);
            this->noneOf.push_back(unique_id);
        }
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
        for (int i = 0; i < this->anyOf.size(); i ++)
            if (entity->HasComponent(this->anyOf.at(i)))
                return true;
        return this->anyOf.size() == 0;
    }
    
    bool Filter::HasAllMatchers(Entity* entity) {
        int componentCounter = 0;
        for (int i = 0; i < this->allOf.size(); i ++)
            if (entity->HasComponent(this->allOf.at(i)))
                componentCounter ++;
        return this->allOf.size() == 0 || (componentCounter != 0 && componentCounter == this->allOf.size());
    }
    
    bool Filter::HasNoneMatcher(Entity* entity) {
        for (int i = 0; i < this->noneOf.size(); i ++)
            if (entity->HasComponent(this->noneOf.at(i)))
                return false;
        return true;
    }
}
