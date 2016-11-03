#include "Filter.hpp"
#include <stdarg.h>

namespace ECS {
    Filter::~Filter() {
        Reset();
    }
    
    void Filter::AllOf(ECS::Matcher m, ...) {
        va_list matchers;
        va_start(matchers, m);
        for(int m_index = 0; m_index < m; m_index ++) {
            ECS::Matcher match = static_cast<ECS::Matcher>(va_arg(matchers, int));
            this->allOf.push_back(match);
        }
    }
    
    void Filter::AnyOf(ECS::Matcher m, ...) {
        va_list matchers;
        va_start(matchers, m);
        for(int m_index = 0; m_index < m; m_index ++) {
            ECS::Matcher match = static_cast<ECS::Matcher>(va_arg(matchers, int));
            this->anyOf.push_back(match);
        }
    }
    
    void Filter::NoneOf(ECS::Matcher m, ...) {
        va_list matchers;
        va_start(matchers, m);
        for(int m_index = 0; m_index < m; m_index ++) {
            ECS::Matcher match = static_cast<ECS::Matcher>(va_arg(matchers, int));
            this->noneOf.push_back(match);
        }
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
        return false;
    }
    
    bool Filter::HasAllMatchers(Entity* entity) {
        int componentCounter = 0;
        for (int m = 0; m < this->allOf.size(); m ++)
            if (entity->HasComponent(this->allOf.at(m)))
                componentCounter ++;
        return componentCounter == this->allOf.size();
    }
    
    bool Filter::HasNoneMatcher(Entity* entity) {
        for (int m = 0; m < this->anyOf.size(); m ++)
            if (entity->HasComponent(this->anyOf.at(m)))
                return false;
        return true;
    }
}
