#ifndef component_hpp
#define component_hpp

namespace ECS {
    class Entity;
    
    class Component {
        public :
        Entity* entity;
        virtual long unique_id() = 0;
        Component() {
            this->entity = 0;
        }
    };
}

#endif
