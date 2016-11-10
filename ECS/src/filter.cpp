#include <stdarg.h>

#include "filter.hpp"
#include "entity.hpp"

#define BUILD_FILTER(size, vector)                                              \
va_list ids;                                                                    \
va_start(ids, size);                                                            \
for(int i = 0; i < size; i ++) {                                                \
long unique_id = va_arg(ids, long);                                             \
vector.push_back(unique_id);                                                    \
}                                                                               \

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
        allOf.clear();
        anyOf.clear();
        noneOf.clear();
    }
    
    bool Filter::HasAnyMatcher(Entity* entity) {
        for (long id : anyOf)
        if (entity->HasComponent(id))
            return true;
        return this->anyOf.size() == 0;
    }
    
    bool Filter::HasAllMatchers(Entity* entity) {
        int componentCounter = 0;
        for (long id : allOf)
        if (entity->HasComponent(id))
            componentCounter ++;
        
        return this->allOf.size() == 0 || (componentCounter != 0 && componentCounter == allOf.size());
    }
    
    bool Filter::HasNoneMatcher(Entity* entity) {
        for (long id : noneOf)
        if (entity->HasComponent(id))
            return false;
        return true;
    }
}
