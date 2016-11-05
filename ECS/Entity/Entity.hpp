#ifndef Entity_hpp
#define Entity_hpp

#include <vector>
#include "Component.hpp"
#include "Matcher.hpp"

namespace ECS {
    class Entity {
        private :
        std::vector<Component*> components;
        
        public :
        Entity();
        ~Entity();
        
        Entity AddComponent(Component* component, bool notifySystems = true);
        bool HasComponent(long component_id);
        void RemoveComponent(long component_id);
        void RemoveAllComponents();
        std::vector<Component*> GetComponents();
        
        template<typename T> void RemoveComponent() {
            for (int cmp_index = 0; cmp_index < this->components.size(); cmp_index ++) {
                T* comp = static_cast<T*>(this->components.at(cmp_index));
                if (comp != NULL) {
                    static_cast<Component*>(comp)->entity = 0;
                    this->components.erase(std::remove(this->components.begin(), this->components.end(), comp), this->components.end());
                    break;
                }
            }
        }
        
        template<typename T> T* GetComponent() {
            for (int cmp_index = 0; cmp_index < this->components.size(); cmp_index ++) {
                T* comp = static_cast<T*>(this->components.at(cmp_index));
                if (comp != NULL)
                    return comp;
            }
            return NULL;
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
