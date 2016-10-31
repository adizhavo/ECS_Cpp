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
        
        template<typename T> void RemoveComponent(T);
        template<typename T> T GetComponent(T);
        template<typename T> std::list<T> GetComponents(T);
        template<typename T> bool HasComponent(T);
        //        bool HasAnyComponent(Matchers matchers[]);
        //        bool HasAllComponents(Matchers matchers[]);
        //        bool HasNoneComponents(Matchers matchers[]);
        //        bool DoesMatchFilter(Filter request);
        
        std::list<Component> Components();
        
        private :
        std::list<Component> components;
    };
}

#endif /* Entity_hpp */
