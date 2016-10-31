#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include <algorithm>
#include <list>

#include "Component.hpp"

namespace ECS {
    class Entity {
        public :
        Entity();
        ~Entity();
        
        Entity AddComponent(Component component, bool notifySystems);
        Entity ReplaceComponent(Component component, bool notifySystems);
        void RemoveAllComponents();
        
        template<typename T> void RemoveComponent(T type);
        template<typename T> T GetComponent(T type);
        template<typename T> std::list<T> GetComponents(T type);
        template<typename T> bool HasComponent(T type);
        //        bool HasAnyComponent(Matchers matchers[]);
        //        bool HasAllComponents(Matchers matchers[]);
        //        bool HasNoneComponents(Matchers matchers[]);
        //        bool DoesMatchFilter(Filter request);
        
        std::list<Component> GetComponents();
        
        private :
        std::list<Component> components;
    };
}

#endif /* Entity_hpp */
