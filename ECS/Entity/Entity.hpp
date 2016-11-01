#ifndef Entity_hpp
#define Entity_hpp

#include <vector>
#include "Component.hpp"

namespace ECS {
    class Entity {
        public :
        Entity();
        ~Entity();
        
        Entity AddComponent(Component component, bool notifySystems);
        void RemoveAllComponents();
        
        template<typename T> void RemoveComponent();
        template<typename T> T GetComponent();
        template<typename T> std::vector<T> GetComponents();
        template<typename T> bool HasComponent();
        //        bool HasAnyComponent(Matchers matchers[]);
        //        bool HasAllComponents(Matchers matchers[]);
        //        bool HasNoneComponents(Matchers matchers[]);
        //        bool DoesMatchFilter(Filter request);
        
        std::vector<Component> GetComponents();
        
        private :
        std::vector<Component> components;
    };
}

#endif /* Entity_hpp */
