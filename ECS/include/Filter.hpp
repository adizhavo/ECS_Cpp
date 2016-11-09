#ifndef filter_hpp
#define filter_hpp

#include <vector>

namespace ECS {
    class Entity;
    
    class Filter {
        public:
        ~Filter();
        Filter AllOf(int size, ...);
        Filter AnyOf(int size, ...);
        Filter NoneOf(int size, ...);
        void Reset();
        bool DoesMatch(Entity* entity);
        
        private:
        bool HasAnyMatcher(Entity* entity);
        bool HasAllMatchers(Entity* entity);
        bool HasNoneMatcher(Entity* entity);
        
        std::vector<long> anyOf;
        std::vector<long> allOf;
        std::vector<long> noneOf;
    };
}

#endif
