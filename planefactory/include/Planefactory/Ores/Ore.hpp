#pragma once

#include <CoreARGC/Entity.hpp>
#include <CoreARGC/Item.hpp>

class Ore : public CoreARGC::Entity {
public:
   static constexpr const char* TYPE = "Ore";

   Ore(float amount);

   float GetAmount() const;
   virtual std::string_view GetType() const override;
   virtual std::unique_ptr<CoreARGC::Item> GetDropItem() const = 0;

   virtual void CopyFrom(const Entity& other) override;

   // return the amount mined
   float Mine(float amount);
   virtual void Logic(CoreARGC::GameContext& ctx) override;

protected:
   float _amount;
};
