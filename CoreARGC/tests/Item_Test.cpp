#include <gtest/gtest.h>

#include <CoreARGC/Item.hpp>
#include <CoreARGC/Entity.hpp>

#include "MockEntity.hpp"

TEST(ItemTest, ConstructorInitializesCorrectly) {
   MockEntity prototype("EntityPrototype");
   Item item("item_id", prototype);

   EXPECT_EQ(item.GetID(), "item_id");
   EXPECT_EQ(item.GetEntity().GetType(), "EntityPrototype");
}

TEST(ItemTest, CopyConstructorWorks) {
   MockEntity prototype("EntityPrototype");
   Item original("item_id", prototype);

   Item copy = original;
   EXPECT_EQ(copy.GetID(), original.GetID());
   EXPECT_EQ(copy.GetEntity().GetType(), original.GetEntity().GetType());
}

TEST(ItemTest, CopyFromWorks) {
   MockEntity prototype1("EntityPrototype1");
   MockEntity prototype2("EntityPrototype2");

   Item item1("item_1", prototype1);
   Item item2("item_2", prototype2);

   item2.CopyFrom(item1);

   EXPECT_EQ(item2.GetID(), item1.GetID());
   EXPECT_EQ(item2.GetEntity().GetType(), item1.GetEntity().GetType());
}

TEST(ItemTest, MoveConstructorWorks) {
   MockEntity prototype("EntityPrototype");
   Item original("item_id", prototype);

   Item moved = std::move(original);
   EXPECT_EQ(moved.GetID(), "item_id");
   EXPECT_EQ(moved.GetEntity().GetType(), "EntityPrototype");
}

TEST(ItemTest, AssignmentOperatorWorks) {
   MockEntity prototype1("EntityPrototype1");
   MockEntity prototype2("EntityPrototype2");

   Item item1("item_1", prototype1);
   Item item2("item_2", prototype2);

   item2 = item1;

   EXPECT_EQ(item2.GetID(), item1.GetID());
   EXPECT_EQ(item2.GetEntity().GetType(), item1.GetEntity().GetType());
}

TEST(ItemTest, MoveAssignmentOperatorWorks) {
   MockEntity prototype("EntityPrototype");
   Item original("item_id", prototype);

   Item moved("placeholder_id", prototype);
   moved = std::move(original);

   EXPECT_EQ(moved.GetID(), "item_id");
   EXPECT_EQ(moved.GetEntity().GetType(), "EntityPrototype");
}
