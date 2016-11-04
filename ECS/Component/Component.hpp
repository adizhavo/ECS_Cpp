#ifndef Component_hpp
#define Component_hpp

#include "Matcher.hpp"

namespace ECS {
    class Entity;
    
    class Component {
        public :
        Entity* entity = 0;
        virtual Matcher GetMatcher() = 0;
    };
}

#endif
