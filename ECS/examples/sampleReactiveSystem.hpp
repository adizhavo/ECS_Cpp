#ifndef sampleReactiveSystem_hpp
#define sampleReactiveSystem_hpp

#include "reactiveSystem.hpp"
#include "sampleComponents.hpp"
#include <iostream>

class SampleReactiveSystem : public ECS::ReactiveSystem {
    public :
    SampleReactiveSystem() {
        filter.AnyOf(2, COMP_ID(FirstComponent), COMP_ID(SecondComponent));
    }
    
    void Execute(Entity* entity) {
        std::cout << "Entity received\n";
        std::cout << "Entity has FirstComponent: " << entity->HasComponent<FirstComponent>() << "\n";
        std::cout << "Entity has SecondComponent: " << entity->HasComponent<SecondComponent>() << "\n";
        std::cout << "\n";
    }
    
    Filter GetFilter () {
        return filter;
    }
    
    private :
    Filter filter;
};

#endif
