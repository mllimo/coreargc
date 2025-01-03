#pragma once

#include <Planefactory/Ores/Ore.hpp>
#include <Planefactory/Ores/Iron.hpp>

class IronOre : public Ore {
public:
   static constexpr const char* TYPE = "IronOre";

   using Ore::Ore;

   std::string_view GetType() const override;
   std::unique_ptr<CoreARGC::Item> GetDropItem() const override;

   std::unique_ptr<CoreARGC::Entity> Clone() const override;

   void Start(CoreARGC::GameContext& ctx) override;
};
