#include <stdio.h>
#include "testMacro.hpp"
#include "entity.hpp"
#include "filter.hpp"
#include "entityMatcher.hpp"

using namespace ECS;

namespace UnitTest {
#define TEARDOWN                        \
testEntity.RemoveAllComponents();       \
filter.Reset();                         \
first = new FirstTestComponent();       \
second = new SecondTestComponent();     \

    START_TEST(EntityMatcherTest, "EntityMatcher")
    int return_error = 0;
    Entity testEntity;
    FirstTestComponent* first = new FirstTestComponent();
    SecondTestComponent* second = new SecondTestComponent();
    Filter filter;
    
    testEntity.AddComponent(first);
    filter.AnyOf(1, COMP_ID(FirstTestComponent));
    ASSERT_TRUE(EntityMatcher::FilterGroup(filter).size() == 1, "Component should subscribe to the matcher when created")
    TEARDOWN
    
    testEntity.AddComponent(first);
    testEntity.AddComponent(second);
    filter.AnyOf(1, COMP_ID(FirstTestComponent), COMP_ID(SecondTestComponent));
    ASSERT_TRUE(EntityMatcher::FilterGroup(filter).size() == 1, "Entity matcher should return the correct group")
    TEARDOWN
    
    END_TEST(return_error)
}
