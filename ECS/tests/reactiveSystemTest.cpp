#include "testMacro.hpp"
#include "entity.hpp"

namespace UnitTest {
#define TEARDOWN                        \
filter.Reset();                         \
testSystem.Reset();                     \
testEntity.RemoveAllComponents();       \

    START_TEST(ReactiveSystemTest)
    Entity testEntity;
    FirstTestComponent first;
    SecondTestComponent second;
    Filter filter;
    TestReactiveSystem testSystem = TestReactiveSystem(&filter);
    
    
    filter.AnyOf(1, COMP_ID(FirstTestComponent));
    testEntity.AddComponent(&first);
    ASSERT_TRUE(testSystem.isExecute, "System should receive the event ang get the specified entity")
    TEARDOWN
    
    testEntity.AddComponent(&first);
    filter.AnyOf(1, COMP_ID(SecondTestComponent));
    ASSERT_TRUE(testSystem.isExecute, "System not should receive the event and get the specified entity")
    TEARDOWN
    
    
    END_TEST(0)
}
