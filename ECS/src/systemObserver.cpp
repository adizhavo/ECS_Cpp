#include "systemObserver.hpp"
#include "reactiveSystem.hpp"
#include "filter.hpp"
#include <cstddef>

#define VECTOR_REMOVE(element, vector)                                          \
vector.erase(std::remove(vector.begin(), vector.end(), element), vector.end())  \

namespace ECS {
    std::vector<ReactiveSystem*>SystemObserver::subscribedSystems;
    
    void SystemObserver::Subscribe(ReactiveSystem* system) {
        subscribedSystems.push_back(system);
    }
    
    void SystemObserver::Unsubscribe(ReactiveSystem* system) {
        for (ReactiveSystem* rs : subscribedSystems )
        if (rs != NULL && rs == system)
            VECTOR_REMOVE(system, subscribedSystems);
    }
    
    void SystemObserver::Notify(Entity *ent) {
        for (ReactiveSystem* rs : subscribedSystems )
        if (rs->GetFilter().DoesMatch(ent))
            rs->Execute(ent);
    }
}
