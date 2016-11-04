#include "Filter.hpp"
#include <stdarg.h>

#include <iostream>

namespace ECS {
    Filter::~Filter() {
        Reset();
    }
    
    Filter Filter::AllOf(int size, ...) {
        va_list matchers;
        va_start(matchers, size);
        for(int m_index = 0; m_index < size; m_index ++) {
            ECS::Matcher match = static_cast<ECS::Matcher>(va_arg(matchers, int));
            this->allOf.push_back(match);
        }
        return *this;
    }
    
    Filter Filter::AnyOf(int size, ...) {
        va_list matchers;
        va_start(matchers, size);
        for(int m_index = 0; m_index < size; m_index ++) {
            ECS::Matcher match = static_cast<ECS::Matcher>(va_arg(matchers, int));
            this->anyOf.push_back(match);
        }
        return *this;
    }
    
    Filter Filter::NoneOf(int size, ...) {
        va_list matchers;
        va_start(matchers, size);
        for(int m_index = 0; m_index < size; m_index ++) {
            ECS::Matcher match = static_cast<ECS::Matcher>(va_arg(matchers, int));
            this->noneOf.push_back(match);
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
        for (int m = 0; m < this->anyOf.size(); m ++)
            if (entity->HasComponent(this->anyOf.at(m)))
                return true;
        return this->anyOf.size() == 0;
    }
    
    bool Filter::HasAllMatchers(Entity* entity) {
        int componentCounter = 0;
        for (int m = 0; m < this->allOf.size(); m ++)
            if (entity->HasComponent(this->allOf.at(m)))
                componentCounter ++;
        return this->allOf.size() == 0 || (componentCounter != 0 && componentCounter == this->allOf.size());
    }
    
    bool Filter::HasNoneMatcher(Entity* entity) {
        for (int m = 0; m < this->noneOf.size(); m ++)
            if (entity->HasComponent(this->noneOf.at(m)))
                return false;
        return true;
    }
}
