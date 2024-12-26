#include <gtest/gtest.h>

#include <CoreARGC/Item.hpp>
#include <CoreARGC/Entity.hpp>

#include "MockEntity.hpp"

TEST(EntityTest, DefaultConstructorInitializesCorrectly) {
   Entity entity;
   EXPECT_EQ(entity.GetPosition().x, 0);
   EXPECT_EQ(entity.GetPosition().y, 0);
}

TEST(EntityTest, SetAndGetPosition) {
   Entity entity;
   Vector2 position = { 10.0f, 20.0f };
   entity.SetPosition(position);

   EXPECT_EQ(entity.GetPosition().x, position.x);
   EXPECT_EQ(entity.GetPosition().y, position.y);
}

TEST(EntityTest, CloneCreatesIdenticalEntity) {
   MockEntity entity("TestType");
   entity.SetPosition({ 15.0f, 25.0f });

   auto cloned = entity.Clone();
   EXPECT_EQ(cloned->GetPosition().x, 15.0f);
   EXPECT_EQ(cloned->GetPosition().y, 25.0f);
   EXPECT_EQ(cloned->GetType(), "TestType");
}
