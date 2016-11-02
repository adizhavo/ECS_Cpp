#ifndef Component_hpp
#define Component_hpp

namespace ECS {
    class Entity;
    
    class Component {
        public :
        Component();
        Entity *entity;
//        Matcher matcher;
    };
}

#endif
