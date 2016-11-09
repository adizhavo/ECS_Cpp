#include "reactiveSystem.hpp"
#include "systemObserver.hpp"

namespace ECS {
    ReactiveSystem::ReactiveSystem() {
        SystemObserver::Subscribe(this);
    }
    
    ReactiveSystem::~ReactiveSystem() {
        SystemObserver::Unsubscribe(this);
    }
}
