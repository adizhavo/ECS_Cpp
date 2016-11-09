#ifndef entity_hpp
#define entity_hpp

#include <vector>
#include "component.hpp"
#include "ecsmacros.hpp"

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
            VECTOR_FOR_EACH (cmp_index, components){
                T* comp = CAST_COMP(cmp_index, components, T);
                if (comp != NULL) {
                    static_cast<Component*>(comp)->entity = 0;
                    VECTOR_REMOVE(comp, components);
                    break;
                }
            }
        }
        
        template<typename T> T* GetComponent() {
            VECTOR_FOR_EACH (cmp_index, components){
                T* comp = CAST_COMP(cmp_index, components, T);
                if (comp != NULL)
                    return comp;
            }
            return NULL;
        }
        
        template<typename T> bool HasComponent() {
            VECTOR_FOR_EACH (cmp_index, components){
                T* comp = CAST_COMP(cmp_index, components, T);
                if (comp != NULL)
                    return true;
            }
            return false;
        }
    };
}

#endif
