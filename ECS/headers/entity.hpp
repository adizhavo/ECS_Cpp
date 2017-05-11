#ifndef entity_hpp
#define entity_hpp

#include <vector>
#include "component.hpp"
#include <cstddef>
#include <algorithm>

#define VECTOR_REMOVE(element, vector)                                          \
vector.erase(std::remove(vector.begin(), vector.end(), element), vector.end())  \


namespace ECS {
    class Entity {
        private :
        std::vector<Component*> components;
        
        public :
        Entity();
        ~Entity();
        
        Entity* AddComponent(Component* component, bool notifySystems = true);
        Component* GetComponent(long id);
        bool HasComponent(long component_id);
        void RemoveComponent(long component_id, bool freeComponent = true);
        void RemoveAllComponents();
        std::vector<Component*> GetComponents();
        
        template<typename T> void RemoveComponent(bool freeComponent = true) {
            for (Component* cmp : components){
                T* comp = dynamic_cast<T*>(cmp);
                if (comp != NULL) {
                    static_cast<Component*>(comp)->entity = 0;
                    VECTOR_REMOVE(comp, components);
                    if (freeComponent)
                    {
                        delete cmp;
                        cmp = NULL;
                    }
                    return;
                }
            }
        }
        
        template<typename T> T* GetComponent() {
            for (Component* cmp : components) {
                T* comp = dynamic_cast<T*>(cmp);
                if (comp != NULL)
                    return comp;
            }
            return NULL;
        }
        
        template<typename T> bool HasComponent() {
            for (Component* cmp : components){
                T* comp = dynamic_cast<T*>(cmp);
                if (comp != NULL)
                    return true;
            }
            return false;
        }
        
        template<typename T> std::vector<T*> GetComponents() {
            std::vector<T*> comps;
            for (Component* cmp : components) {
                T* comp = dynamic_cast<T*>(cmp);
                if (comp != NULL)
                    comps.push_back(comp);
            }
            return comps;
        }
    };
}

#endif
