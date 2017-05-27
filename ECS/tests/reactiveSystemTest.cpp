#include "testMacro.hpp"
#include "entity.hpp"

namespace UnitTest {
#define TEARDOWN                        \
filter.Reset();                         \
testSystem.Reset();                     \
testEntity.RemoveAllComponents();       \
first = new FirstTestComponent();       \
second = new SecondTestComponent();     \

    START_TEST(ReactiveSystemTest, "ReactiveSystem")
    Entity testEntity;
    FirstTestComponent* first = new FirstTestComponent();
    SecondTestComponent* second = new SecondTestComponent();
    Filter filter;
    TestReactiveSystem testSystem = TestReactiveSystem(&filter);
    
    
    filter.AnyOf(1, COMP_ID(FirstTestComponent));
    testEntity.AddComponent(first);
    ASSERT_TRUE(testSystem.isExecute, "System should receive the event ang get the specified entity")
    TEARDOWN
    
    filter.AnyOf(1, COMP_ID(SecondTestComponent));
    testEntity.AddComponent(first);
    ASSERT_TRUE(!testSystem.isExecute, "System not should receive the event and get the specified entity")
    TEARDOWN
    
    
    END_TEST(0)
}
