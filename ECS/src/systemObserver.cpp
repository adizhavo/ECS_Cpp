#include "systemObserver.hpp"
#include "reactiveSystem.hpp"
#include "filter.hpp"
#include "ecsmacros.hpp"

namespace ECS {
    std::vector<ReactiveSystem*>SystemObserver::subscribedSystems;
    
    void SystemObserver::Subscribe(ReactiveSystem* system) {
        subscribedSystems.push_back(system);
    }
    
    void SystemObserver::Unsubscribe(ReactiveSystem* system) {
        VECTOR_FOR_EACH(index, subscribedSystems)
        if (subscribedSystems.at(index) != NULL && subscribedSystems.at(index) == system)
            VECTOR_REMOVE(system, subscribedSystems);
    }
    
    void SystemObserver::Notify(Entity *ent) {
        VECTOR_FOR_EACH(index, subscribedSystems)
        if (subscribedSystems.at(index)->GetFilter().DoesMatch(ent))
            subscribedSystems.at(index)->Execute(ent);
    }
}
