#ifndef Component_hpp
#define Component_hpp

namespace ECS {
    class Entity;
    
    class Component {
        public :
        Entity* entity = 0;
        virtual long unique_id() = 0;
    };
}

#endif
