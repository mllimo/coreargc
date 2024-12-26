#include <gtest/gtest.h>

#include <CoreARGC/Stack.hpp>

#include "MockEntity.hpp"

TEST(StackTest, ConstructorInitializesCorrectly) {
   MockItem prototype("prototype_id");
   Stack stack(10, prototype);

   EXPECT_EQ(stack.GetCountItems(), 0);
   EXPECT_EQ(stack.GetLimitItems(), 10);
   EXPECT_EQ(stack.GetItem().GetID(), "prototype_id");
}

TEST(StackTest, AddItemsWithinLimit) {
   MockItem prototype("prototype_id");
   Stack stack(10, prototype);

   unsigned added = stack.AddItems(5);
   EXPECT_EQ(added, 5);
   EXPECT_EQ(stack.GetCountItems(), 5);
}

TEST(StackTest, AddItemsExceedingLimit) {
   MockItem prototype("prototype_id");
   Stack stack(10, prototype);

   unsigned added = stack.AddItems(12);
   EXPECT_EQ(added, 10);
   EXPECT_EQ(stack.GetCountItems(), 10);
}

TEST(StackTest, RemoveItemsWithinCurrentCount) {
   MockItem prototype("prototype_id");
   Stack stack(10, prototype);

   stack.AddItems(7);
   unsigned removed = stack.RemoveItems(3);
   EXPECT_EQ(removed, 3);
   EXPECT_EQ(stack.GetCountItems(), 4);
}

TEST(StackTest, RemoveItemsExceedingCurrentCount) {
   MockItem prototype("prototype_id");
   Stack stack(10, prototype);

   stack.AddItems(7);
   unsigned removed = stack.RemoveItems(10);
   EXPECT_EQ(removed, 7);
   EXPECT_EQ(stack.GetCountItems(), 0);
}

TEST(StackTest, AddAndRemoveItemsCombined) {
   MockItem prototype("prototype_id");
   Stack stack(10, prototype);

   stack.AddItems(6);
   stack.RemoveItems(2);
   stack.AddItems(4);
   EXPECT_EQ(stack.GetCountItems(), 8);

   stack.RemoveItems(5);
   EXPECT_EQ(stack.GetCountItems(), 3);
}

TEST(StackTest, GetItemReturnsCorrectPrototype) {
   MockItem prototype("prototype_id");
   Stack stack(10, prototype);

   const Item& item = stack.GetItem();
   EXPECT_EQ(item.GetID(), "prototype_id");
}
