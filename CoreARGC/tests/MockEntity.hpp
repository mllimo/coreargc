#pragma once

#include <CoreARGC/Entity.hpp>
#include <CoreARGC/Item.hpp>

using namespace CoreARGC;

class MockEntity : public Entity {
public:
   MockEntity(std::string_view type = "MockEntity") : _type(type) {}
   std::string_view GetType() const override { return _type; }
   std::unique_ptr<Entity> Clone() const override {
      return std::make_unique<MockEntity>(*this);
   }

private:
   std::string _type;
};

class MockItem : public Item {
public:
   MockItem(std::string_view id) : Item(id, Entity()) {}
};
