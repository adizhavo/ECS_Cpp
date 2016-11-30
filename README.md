# ECS

|Languages|
---
|[C#](https://github.com/adizhavo/ECS)|
|[C++](https://github.com/adizhavo/ECS_Cpp)|

ECS is a simple [entity component system](https://en.wikipedia.org/wiki/Entity_component_system) framework.
It uses generics to achieve composition without having the need to write new code inside the container class which is called entity.

The class diagram below will make easier to understand how the system works. 
> missing diagram

As said before, an entity is simply composed by small chunks of data or behaviours. 
Systems are listeners and they are ready to reach any modified entity which matches the defined filter of components.

# How it works

### Component

To implement a component include ```component.hpp```, there are two way to setup a component, one is by using the macro:
```C++
#include "component.hpp"

CREATE_COMPONENT(SampleComponent)
// put variables / methods here
ENDCOMP
```

```SampleComponent``` is the class definition, this way of defining a component works only if it doesn't inherit from multiple classes.

The second way allows multiple inheritance this way :

```C++
#include "component.hpp"

class SampleComponent : public ECS::Component /*other dependecies*/ {
    // put variables / methods here
    RETURN_ID(SampleComponent)
    // put variables / methods here
};
```

[Sample components](https://github.com/adizhavo/ECS_Cpp/blob/master/ECS/examples/sampleComponents.hpp)

### Entity
> n/a

### Entity matcher
> n/a

### Filters
> n/a

### Systems
> n/a

# Conclusion
> n/a

# What to improve
> n/a
