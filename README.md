# ECS

|Languages|
---
|[C#](https://github.com/adizhavo/ECS)|
|[C++](https://github.com/adizhavo/ECS_Cpp)|

ECS is a simple [entity component system](https://en.wikipedia.org/wiki/Entity_component_system) framework.
It uses generics to achieve composition without having the need to write new code inside the container class which is called entity.

An entity is composed by small chunks of data or behaviours. 
Systems are listeners and they are ready to reach any modified entity which matches the defined filter of components.

# How to build

To build the static library, in the ```./ECS``` directory run the ```make``` command.
To run the tests, in the same directory run the ```make test``` command.

# How it works

### Component

To implement a component include ```component.hpp```, there are two way to setup it up, one is by using the macro:
```C++
#include "component.hpp"

CREATE_COMPONENT(FooComponent)
// put variables / methods here
ENDCOMP
```

```FooComponent``` is the class definition, this way works only if it doesn't need to inherit from multiple classes.

The second way allows multiple inheritance :

```C++
#include "component.hpp"

class FooComponent : public ECS::Component /*other dependecies*/ {
    // put variables / methods here
    RETURN_ID(SampleComponent)
    // put variables / methods here
};
```
In the second way is a must to use the ```RETURN_ID``` macro since provides the implementation for the component unique id.  The id is a ```long```.
Is possible to get or compute any component id by using the macro ```COMP_ID``` in ```component.hpp```

[Sample components](https://github.com/adizhavo/ECS_Cpp/blob/master/ECS/examples/sampleComponents.hpp)

### Entity
An entity simply contains a vector of components. Is possible to add, remove them by type or id and doing additional checks this way:

```C++
#include "entity.hpp"

entity.AddComponent(&foo);

// doesn't notify the systems
entity.AddComponent(&foo, false)

bool hasComp = entity.HasComponent<FooComponent>();
bool hasComp = entity.HasComponent(COMP_ID(FooComponent));

entity.RemoveComponent<FooComponent>();
entity.RemoveComponent(COMP_ID(FooComponent));

Component* fooComp = entity.GetComponent<FooComponent>();
Component* fooComp = entity.GetComponent(COMP_ID(FooComponent));
```

The entity subscribes and unsubscribes from the entity matcher when created or destroyed.

### Entity matcher

The entity matcher contains all the subscribed entities. As said above, an entity interacts with the matcher when created or destroyed but is also possible (not recommended) to manually unsubscribe an entity.

The main role of the matcher is to provide a way to gather entities and group them based on a filter.

```C++
#include "entityMatcher.hpp"

std::vector<Entity*> rocks = EntityMatcher::FilterGroup(rockFilter);
```

### Filters
Filters area used to check if a specfic entity matches the requirements. As in the example above, is possible to get a specific group of entities from the matcher based on the filter which is passed as an argument.

There are three methods to build up a filter with different components id, used later to match an entity:
```C++
#include "filter.hpp"
#include "component.hpp" // we have to use the COMP_ID macro to extract the id

filter.AllOf(2, COMP_ID(FooComponent1), COMP_ID(FooComponent2))
      .AnyOf(1, COMP_ID(FooComponent3))
      .NoneOf(1, COMP_ID(FooComponent4));
      
bool match = filter.DoesMatch(&entity);
filter.Reset();
```

### Reactive systems
Reactive system are objects which are notified if a component is added to an entity that matcher the system's filter. To create a reactive system, the class should inherit from ```ECS::ReactiveSystem``` like in [this example](https://github.com/adizhavo/ECS_Cpp/blob/master/ECS/examples/sampleReactiveSystem.hpp), the default implementation of the reactive system subscribes and unsubscribes to [system observer](https://github.com/adizhavo/ECS_Cpp/blob/master/ECS/include/systemObserver.hpp) when created or destroyed, but this implementation can be ignored at will.

Have a look at the [test cases](https://github.com/adizhavo/ECS_Cpp/blob/master/ECS/tests/reactiveSystemTest.cpp) for the reactive system. 

# What to improve
1. Add ```ReplaceComponent``` method in the entity.
2. Notify reactive system when a component is updated, replaced or removed.

To better understand the system, check also the [test cases](https://github.com/adizhavo/ECS_Cpp/tree/master/ECS/tests) of the project.


