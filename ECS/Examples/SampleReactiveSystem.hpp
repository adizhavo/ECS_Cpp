#ifndef SampleReactiveSystem_hpp
#define SampleReactiveSystem_hpp

#include "ReactiveSystem.hpp"
#include "ECSMacros.hpp"

using namespace ECS;

class SampleReactiveSystem : public ReactiveSystem {
    public :
    SampleReactiveSystem() {
        f_matcher.AnyOf(1, COMP_ID(FirstComponent));
    }
    
    void Execute(Entity* entity) {
        std::cout << "\nEntity received\n";
    };
    
    Filter GetFilter() {
        return f_matcher;
    }
    
    private :
    Filter f_matcher;
};

#endif
