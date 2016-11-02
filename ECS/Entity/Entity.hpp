#ifndef Entity_hpp
#define Entity_hpp

#include <vector>
#include "Component.hpp"

namespace ECS {
    class Entity {
        private :
        std::vector<Component*> components;
        
        public :
        Entity();
        ~Entity();
        
        Entity AddComponent(Component* component, bool notifySystems);
        void RemoveAllComponents();
        std::vector<Component*> GetComponents();
        
        template<typename T> void RemoveComponent() {
            int erase_index = -1;
            for (int cmp_index = 0; cmp_index < this->components.size(); cmp_index ++) {
                T comp = dynamic_cast<T>(this->components.at(cmp_index));
                if (comp != NULL)
                    erase_index = cmp_index;
            }
            
            if (erase_index > 0)
                this->components.erase(this->components.begin() + erase_index);
        }
        
        template<typename T> T* GetComponent() {
            for (int cmp_index = 0; cmp_index < this->components.size(); cmp_index ++) {
                T* comp = static_cast<T*>(this->components.at(cmp_index));
                if (comp != NULL)
                    return comp;
            }
            return NULL;
        }
        
        template<typename T> std::vector<T*> GetComponents() {
            std::vector<T*> requested_components;
            for (int cmp_index = 0; cmp_index < this->components.size(); cmp_index ++) {
                T* comp = static_cast<T*>(this->components.at(cmp_index));
                if (comp != NULL)
                    requested_components.push_back(comp);
            }
            return requested_components;
        }
        
        template<typename T> bool HasComponent() {
            for (int cmp_index = 0; cmp_index < this->components.size(); cmp_index ++) {
                T* comp = static_cast<T*>(this->components.at(cmp_index));
                if (comp != NULL)
                    return true;
            }
            return false;
        }
    };
}

#endif
