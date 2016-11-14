#include "Test.hpp"
#include "entity.hpp"

using namespace ECS;

CREATE_COMPONENT(FirstTestComponent)
ENDCOMP

CREATE_COMPONENT(SecondTestComponent)
ENDCOMP

#define TEARDOWN testEntity.RemoveAllComponents();

START_TEST("Entity")
Entity testEntity;
FirstTestComponent first;
SecondTestComponent second;
long requestedComponentID;

testEntity.AddComponent(&first);
ASSERT_TRUE(testEntity.GetComponents().size() == 1, "Entity should add component")
TEARDOWN

testEntity.AddComponent(&first);
testEntity.AddComponent(&second);
ASSERT_TRUE(testEntity.GetComponents().size() == 2, "Entity should not add same component")
TEARDOWN

testEntity.RemoveComponent<FirstTestComponent>();
ASSERT_TRUE(testEntity.GetComponents().size() == 0, "Entity should remove component by type")
TEARDOWN

testEntity.AddComponent(&first);
testEntity.RemoveComponent(COMP_ID(FirstTestComponent));
ASSERT_TRUE(testEntity.GetComponents().size() == 0, "Entity should remove component by id")
TEARDOWN

testEntity.AddComponent(&first);
testEntity.AddComponent(&second);
testEntity.RemoveAllComponents();
ASSERT_TRUE(testEntity.GetComponents().size() == 0, "Entity should remove all components")
TEARDOWN

testEntity.AddComponent(&first);
ASSERT_TRUE(testEntity.HasComponent<FirstTestComponent>(), "Entity should have the requested component by type")
TEARDOWN

ASSERT_TRUE(!testEntity.HasComponent<FirstTestComponent>(), "Entity should not have the requested component by type")
TEARDOWN

testEntity.AddComponent(&first);
ASSERT_TRUE(testEntity.HasComponent(COMP_ID(FirstTestComponent)), "Entity should have the requested component, with macro")
TEARDOWN

ASSERT_TRUE(!testEntity.HasComponent(COMP_ID(FirstTestComponent)), "Entity should not have the requested component, with macro")
TEARDOWN

testEntity.AddComponent(&first);
ASSERT_TRUE(testEntity.HasComponent(first.unique_id()), "Entity should have the requested component by id")
TEARDOWN

ASSERT_TRUE(!testEntity.HasComponent(first.unique_id()), "Entity should not have the requested component by id")
TEARDOWN

testEntity.AddComponent(&first);
requestedComponentID = requestedComponentID = testEntity.GetComponent<FirstTestComponent>()->unique_id();
ASSERT_TRUE(requestedComponentID == first.unique_id(), "Should return component by id");

testEntity.AddComponent(&first);
requestedComponentID = requestedComponentID = testEntity.GetComponent(COMP_ID(FirstTestComponent))->unique_id();
ASSERT_TRUE(requestedComponentID == first.unique_id(), "Should return component by type");
TEARDOWN

Component* comp = testEntity.GetComponent<FirstTestComponent>();
ASSERT_TRUE(comp == NULL, "Should return null if the component is not available by type");
TEARDOWN

comp = testEntity.GetComponent(COMP_ID(FirstTestComponent));
ASSERT_TRUE(comp == NULL, "Should return null if the component is not available by id");
TEARDOWN

END_TEST










