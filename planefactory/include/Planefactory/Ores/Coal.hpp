#pragma once

#include <CoreARGC/Item.hpp>

class Coal : public CoreARGC::Item {
public:
   static constexpr const char* TYPE = "Coal";

   Coal();

   std::string_view GetType() const override;

   std::unique_ptr<CoreARGC::Entity> Clone() const override;

   void Start(CoreARGC::GameContext& ctx) override;
};
