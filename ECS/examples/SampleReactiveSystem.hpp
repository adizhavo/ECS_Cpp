#ifndef sampleReactiveSystem_hpp
#define sampleReactiveSystem_hpp

#include "reactiveSystem.hpp"
#include "sampleComponents.hpp"
#include <iostream>

Filter filter;

CREATE_SYST(SampleReactiveSystem, filter.AnyOf(2, COMP_ID(FirstComponent), COMP_ID(SecondComponent)))
RECEIVE_MATCHED_ENT
    std::cout << "Entity received\n";
    std::cout << "Entity has FirstComponent: " << entity->HasComponent<FirstComponent>() << "\n";
    std::cout << "Entity has SecondComponent: " << entity->HasComponent<SecondComponent>() << "\n";
    std::cout << "\n";
END
END

#endif
