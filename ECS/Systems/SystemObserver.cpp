#include "SystemObserver.hpp"
#include "ReactiveSystem.hpp"
#include "Filter.hpp"
#include "ECSMacros.hpp"

namespace ECS {
    std::vector<ReactiveSystem*>SystemObserver::subscribedSystems;
    
    void SystemObserver::Subscribe(ReactiveSystem* system) {
        subscribedSystems.push_back(system);
    }
    
    void SystemObserver::Unsubscribe(ReactiveSystem* system) {
        VECTOR_FOR_EACH(index, subscribedSystems)
        if (subscribedSystems[index] != NULL && subscribedSystems[index] == system)
            VECTOR_REMOVE(system, subscribedSystems);
    }
    
    void SystemObserver::Notify(Entity *ent) {
        VECTOR_FOR_EACH(index, subscribedSystems)
        if (subscribedSystems[index]->GetFilter().DoesMatch(ent))
            subscribedSystems[index]->Execute(ent);
    }
}
