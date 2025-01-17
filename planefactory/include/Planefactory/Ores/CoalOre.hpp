#pragma once

#include <Planefactory/Ores/Ore.hpp>
#include <Planefactory/Ores/Coal.hpp>


class CoalOre : public Ore {
public:
   static constexpr const char* TYPE = "CoalOre";

   using Ore::Ore;

   std::string_view GetType() const override;
   std::unique_ptr<CoreARGC::Item> GetDropItem() const override;

   std::unique_ptr<CoreARGC::Entity> Clone() const override;

   void Start(CoreARGC::GameContext& ctx) override;
};
