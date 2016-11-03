#ifndef Filter_hpp
#define Filter_hpp

#include <vector>
#include "Matcher.hpp"
#include "Entity.hpp"

namespace ECS {
    class Filter {
        public:
        ~Filter();
        void AnyOf(Matcher m, ...);
        void AllOf(Matcher m, ...);
        void NoneOf(Matcher m, ...);
        bool DoesMatch(Entity* entity);
        void Reset();
        
        private:
        bool HasAnyMatcher(Entity* entity);
        bool HasAllMatchers(Entity* entity);
        bool HasNoneMatcher(Entity* entity);
        
        std::vector<Matcher> anyOf;
        std::vector<Matcher> allOf;
        std::vector<Matcher> noneOf;
    };
}

#endif
