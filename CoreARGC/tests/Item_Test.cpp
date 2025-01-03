#include <gtest/gtest.h>

#include <CoreARGC/Item.hpp>
#include <CoreARGC/Entity.hpp>

#include "MockEntity.hpp"

TEST(MockItemTest, Constructor) {
   MockItem item("test_id");
   EXPECT_EQ(item.GetID(), "test_id");
}
TEST(MockItemTest, CopyFrom) {
   MockItem item1("original_id");
   MockItem item2("copy_id");

   item2.CopyFrom(item1);

   EXPECT_EQ(item2.GetID(), item1.GetID());
}

TEST(MockItemTest, Clone) {
   MockItem original("original_id");
   std::unique_ptr<Entity> clone = original.Clone();
   auto casted_clone = static_cast<Item*>(clone.get());

   EXPECT_EQ(casted_clone->GetID(), original.GetID());
   EXPECT_NE(clone.get(), &original);
}