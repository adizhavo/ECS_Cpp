#include "ReactiveSystem.hpp"
#include "SystemObserver.hpp"

namespace ECS {
    ReactiveSystem::ReactiveSystem() {
        SystemObserver::Subscribe(this);
    }
    
    ReactiveSystem::~ReactiveSystem() {
        SystemObserver::Unsubscribe(this);
    }
}
