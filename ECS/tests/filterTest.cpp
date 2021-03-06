#include "testMacro.hpp"
#include "entity.hpp"
#include "filter.hpp"

#define TEARDOWN                        \
testEntity.RemoveAllComponents();       \
filter.Reset();                         \
first = new FirstTestComponent();       \
second = new SecondTestComponent();     \


namespace UnitTest {
START_TEST(FilterTest, "Filter")
    int return_error = 0;
    Entity testEntity;
    FirstTestComponent* first = new FirstTestComponent();
    SecondTestComponent* second = new SecondTestComponent();
    Filter filter;
    
    testEntity.AddComponent(first);
    filter.AnyOf(1, COMP_ID(FirstTestComponent));
    ASSERT_TRUE(filter.DoesMatch(&testEntity), "Should match one (AnyOf) to entity with 1 component")
    TEARDOWN
    
    testEntity.AddComponent(first);
    testEntity.AddComponent(second);
    filter.AnyOf(1, COMP_ID(SecondTestComponent));
    ASSERT_TRUE(filter.DoesMatch(&testEntity), "Should match one (AnyOf) to entity with 2 components")
    TEARDOWN
    
    testEntity.AddComponent(first);
    filter.AllOf(1, COMP_ID(FirstTestComponent));
    ASSERT_TRUE(filter.DoesMatch(&testEntity), "Should match one (AllOf) to entity with 1 component")
    TEARDOWN
    
    testEntity.AddComponent(first);
    filter.AllOf(2, COMP_ID(FirstTestComponent), COMP_ID(SecondTestComponent));
    ASSERT_TRUE(!filter.DoesMatch(&testEntity), "Should not match two (AllOf) to entity with 1 component")
    TEARDOWN
    
    testEntity.AddComponent(first);
    testEntity.AddComponent(second);
    filter.AllOf(2, COMP_ID(FirstTestComponent), COMP_ID(SecondTestComponent));
    ASSERT_TRUE(filter.DoesMatch(&testEntity), "Should match two (AllOf) to entity with 2 components")
    TEARDOWN
    
    testEntity.AddComponent(second);
    filter.NoneOf(1, COMP_ID(FirstTestComponent));
    ASSERT_TRUE(filter.DoesMatch(&testEntity), "Should match one (NoneOf) to entity with 1 component")
    TEARDOWN
    
    testEntity.AddComponent(first);
    filter.NoneOf(1, COMP_ID(FirstTestComponent));
    ASSERT_TRUE(!filter.DoesMatch(&testEntity), "Should not match one (NoneOf) to entity with 1 component")
    TEARDOWN
    
    testEntity.AddComponent(first);
    testEntity.AddComponent(second);
    filter.NoneOf(1, COMP_ID(FirstTestComponent));
    ASSERT_TRUE(!filter.DoesMatch(&testEntity), "Should not match one (NoneOf) to entity with 2 components")
    TEARDOWN
    
    TEARDOWN
    
END_TEST(return_error)
}
